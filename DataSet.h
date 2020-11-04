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
	// constructors and destructor
	DataSet();
	 
	// setters and getters
	list<Image*> GetImages() { return Images; }
	// methods
	void AddImage(Image *img); 
};

