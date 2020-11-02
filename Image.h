#pragma once

#include <string>
#include "IImageInitialize.h"

using namespace std;

class Image
{
protected:
	string Path;
	IImageInitialize *InitializeAction;
public:
	Image();
	Image(string path);
};

