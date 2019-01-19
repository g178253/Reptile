#pragma once
#include "pch.h"

namespace Reptile
{
	class TextProcessor
	{
	public:
		void execute(std::string& src);
	};

	class TextSource
	{
	public:
		std::string get_source();
	};

	class ReptileCore
	{
	protected:
		ReptileCore() {}
		ReptileCore(const TextSource& ts, const TextProcessor& tp)
			: ts{ts}, tp{tp} {}
		std::string generate_result();
	
	private:
		TextSource ts;
		TextProcessor tp;
	};
}