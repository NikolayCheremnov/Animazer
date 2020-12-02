#include "CompositeImages.h"

CompositeImages::CompositeImages(string ID) : Image(ID, "none")
{
}

CompositeImages::~CompositeImages()
{
    for (Image* img : images)
        delete img;                 // delete all images
}

bool CompositeImages::RemoveWithID(string ID)
{
    Image* removable = GetImageWithID(ID);
    if (removable != nullptr) {
        images.remove(removable);   // remove from list
        delete removable;          // free memory
        return true;
    }
    return false;
}

Image* CompositeImages::GetImageWithID(string ID)
{
    for (Image* img : images)
        if (img->GetID() == ID)
            return img;
    return nullptr;
}
