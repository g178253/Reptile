#pragma once
#include "pch.h"

namespace Reptile
{
	class TextProcessor
	{
	public:
		std::string& execute(const std::string& src) const;
	};

	class TextSource
	{
	public:
		std::string& get_source() const;
	};

	class ReptileCore
	{
	protected:
		ReptileCore() {}
		ReptileCore(const TextSource& ts, const TextProcessor& tp)
			: ts{ts}, tp{tp} {}
		std::string& generate_result() const;
	
	private:
		TextSource ts;
		TextProcessor tp;
	};
}