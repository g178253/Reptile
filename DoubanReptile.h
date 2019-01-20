#pragma once
#include "ReptileCore.h"

using namespace Reptile;

class DoubanReptile : public ReptileCore
{
public:
	void print();

	// Í¨¹ý ReptileCore ¼Ì³Ð¡£
	virtual string get_url() override;
	virtual string get_command() override;
};

