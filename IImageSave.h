#pragma once

// internal
#include <string>
// common
#include "Logger.h"
// special
#include "Image.h"

class IImageSave
{
public:
	virtual void Save(std::string path, Image* saved, Logger *lg) = 0;
};

