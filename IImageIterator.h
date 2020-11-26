#pragma once
#include "Image.h"

// interator for image composition
class IImageIterator
{
public:
	// enumeration functionality
	virtual bool HasNext() = 0;
	virtual Image* Begin() = 0;
	virtual Image* Next() = 0;
};

