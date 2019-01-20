#pragma once
#include "pch.h"
#include "Net.h"
#include "ReptileCore.h"

namespace Reptile
{
	using namespace std;

	void TextSource::Net::start(const string& url, const int port)
	{
		WSADATA wsa_data;
		struct addrinfo *result = NULL,
						*ptr = NULL,
						hints;
		auto throw_error = [](string&& msg)
		{
			auto code = WSAGetLastError();
			WSACleanup();
			throw msg + to_string(code);
		};

		// 使用 socket 2.2 版本进行初始化。
		auto r = WSAStartup(MAKEWORD(2, 2), &wsa_data);
		if (r != 0)
			throw string{ "Socket 初始化失败" };

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		r = getaddrinfo(url.c_str(), to_string(port).c_str(), &hints, &result);
		if (r != 0)
			throw_error("getaddrinfo failed with error: ");

		for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
		{
			client = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
			if (client == INVALID_SOCKET)
				throw_error("socket failed with error: ");

			r = connect(client, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (r == SOCKET_ERROR) {
				closesocket(client);
				client = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);

		if (client == INVALID_SOCKET)
			throw_error("Unable to connect to server");
	}

	void TextSource::Net::stop()
	{
		closesocket(client);
		WSACleanup();
	}

	void TextSource::Net::send_command(const string& cmd) const
	{
		auto throw_if_error = [](int r, SOCKET s, string&& msg)
		{
			if (r == SOCKET_ERROR)
			{
				auto code = WSAGetLastError();
				closesocket(s);
				WSACleanup();
				throw msg + to_string(code);
			}
		};

		auto buf = cmd.c_str();
		auto r = send(client, buf, (int)strlen(buf), 0);
		throw_if_error(r, client, string{ "send failed with error: " });
		
		r = shutdown(client, SD_SEND);
		throw_if_error(r, client, string{ "shutdown failed with error: " });
	}

	string TextSource::Net::get_string() const
	{
		char buf[1024];
		memset(buf, 0, sizeof(buf));

		auto r = 0;
		do {
			r = recv(client, buf, sizeof(buf)-sizeof(char), 0);
			if (r > 0)
				printf("Bytes received: %d\n", r);
			else if (r == 0)
				printf("Connection closed\n");
			else
				printf("recv failed with error: %d\n", WSAGetLastError());
		} while (r > 0);
		
		return string{ buf };
	}
}