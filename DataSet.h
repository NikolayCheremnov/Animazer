#pragma once

#include "Image.h"
#include <list>
#include <string>

// set of grouped images
class DataSet
{
protected:
	string ID;
	list<Image *> Images;

public:
	DataSet();
	void AddImage(Image *img);
};

