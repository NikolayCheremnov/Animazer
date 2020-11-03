#pragma once

// internal
#include <string>
// common
#include "Logger.h"
#include "Image.h"

// image save interface
class IImageSave
{
public:
	virtual void Save(std::string path, Image* saved, Logger *lg) = 0;
};

