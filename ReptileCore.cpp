#include "pch.h"
#include "ReptileCore.h"

namespace Reptile
{
	void ReptileCore::generate_result() const
	{
		auto src = ts.get_source();
		auto result = tp.execute(src);
		set_result(result);
	}
}