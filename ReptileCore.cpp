#include "pch.h"
#include "ReptileCore.h"

namespace Reptile
{
	std::string ReptileCore::generate_result()
	{
		auto src = ts.get_source();
		tp.execute(src);
		return src;
	}

	void TextProcessor::execute(std::string& src)
	{
		std::cout << src;
	}

	std::string TextSource::get_source()
	{
		return std::string("¹þ¹þ");
	}
}