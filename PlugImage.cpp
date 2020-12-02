#include "PlugImage.h"

PlugImage::PlugImage(string ID, string path): Image(ID, path)
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
