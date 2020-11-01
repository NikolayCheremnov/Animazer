#pragma once

#include <string>

#include "Logger.h"

// image initialize interface
class IImageInitialize
{
public:
	virtual void Initialize(std::string path, Logger *lg) = 0;
};

