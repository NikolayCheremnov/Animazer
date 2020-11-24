#include "Images.h"

Images::Images(string ID)
{
	this->ID = ID;
}

string Images::PerformImageProcessing(Logger* lg)
{
	for (Image* img : images)
		img->PerformImageProcessing(lg);
}

void Images::Add(Image* img)
{
	images.push_back(img);
}

bool Images::RemoveWithID(string imgID)
{
	Image* removeable = GetImageWithID(imgID);
	if (removeable != nullptr) {
		images.remove(removeable);
		return true;
	}
	else
		return false;
}

Image* Images::GetImageWithID(string ID)
{
	for (Image* img : images)
		if (img->getID() == ID)
			return img;
	return nullptr;
}
