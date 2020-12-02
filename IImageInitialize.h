#pragma once

// external
#include <string>

// common
#include "Logger.h"
#include "Image.h"

// image initialize interface
class IImageInitialize
{
public:
	virtual Image* Initialize(std::string path, Logger* lg) = 0;
};

