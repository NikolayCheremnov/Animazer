#include "CompositeImagesIterator.h"

CompositeImagesIterator::CompositeImagesIterator(CompositeImages* images) {
    this->images = images->GetImageList();
    begin = this->images.begin();
    currentIndex = 0;
}

bool CompositeImagesIterator::HasNext()
{
    if (currentIndex == images.size())
        return false;
    return true;
}

Image* CompositeImagesIterator::Begin()
{
    return *begin;
}

Image* CompositeImagesIterator::Next()
{
    currentIndex++;
    if (currentIndex < images.size()) {
        list<Image*>::iterator tempIt = begin;
        advance(tempIt, currentIndex);
        return *tempIt;
    }
    else
        return *begin;
}
