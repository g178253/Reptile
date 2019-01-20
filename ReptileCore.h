#pragma once
#include "pch.h"

namespace Reptile
{
	using namespace std;

	class TextSource
	{
	public:
		TextSource();
		~TextSource();

		string get_source(const string& url, const string& cmd);
	
	private:
		class Net;
		unique_ptr<Net> pNet;
	};

	class TextProcessor
	{
	public:
		void execute(string& src);
	};

	class ReptileCore
	{
	protected:
		virtual string get_url() = 0;
		virtual string get_command()=0;
		string generate_result();
	
	private:
		TextSource ts;
		TextProcessor tp;
	};
}