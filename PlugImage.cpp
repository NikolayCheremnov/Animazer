#include "PlugImage.h"

PlugImage::PlugImage(string path): Image(path)
{
	// plugs
	imgData = nullptr;
}

PlugImage::~PlugImage()
{
	if (imgData != nullptr)
		delete []imgData;
}

void PlugImage::SetImgData(char* val)
{
	if (imgData != nullptr)
		delete imgData;
	imgData = val;
}
