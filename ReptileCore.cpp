#include "pch.h"
#include "ReptileCore.h"

namespace Reptile
{
	std::string& ReptileCore::generate_result() const
	{
		auto src = ts.get_source();
		auto result = tp.execute(src);
		return result;
	}
}