#pragma once
#include "IImageIterator.h"
#include "CompositeImages.h"

class CompositeImagesIterator :
    public IImageIterator
{
private:
    list<Image*> images;
    int currentIndex;
    list<Image*>::iterator begin;
public:
    CompositeImagesIterator(CompositeImages* images);

    // overloaded methods
    bool HasNext();
    Image* Begin();
    Image* Next();
};

