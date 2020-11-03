#pragma once

#include <string>

// common
#include "Logger.h"
// special
#include "Image.h"

// image initialize interface
class IImageInitialize
{
public:
	virtual Image* Initialize(std::string path, Logger *lg) = 0;
};

