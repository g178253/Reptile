#pragma once
#include "pch.h"
#include "ReptileCore.h"

namespace Reptile
{
	using namespace std;

	class TextSource::Net
	{
	public:
		void start(const string& url, const int port);
		void send_command(const string& cmd) const;
		string get_string() const;
		void stop();

	private:
		SOCKET client{ INVALID_SOCKET };
	};
}