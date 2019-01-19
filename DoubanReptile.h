#pragma once
#include "ReptileCore.h"

using namespace Reptile;

class DoubanReptile : public Reptile::ReptileCore
{
public:
	DoubanReptile(const TextSource& ts, const TextProcessor& tp)
		: ReptileCore(ts, tp) {}
	void print();
};

