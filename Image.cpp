#include "Image.h"

Image::Image()
{
	ID = "undefined";
}

Image::Image(string path)
{
	ID = "undefined";
	this->path = path;
}
