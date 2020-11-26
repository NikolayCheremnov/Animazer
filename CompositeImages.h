#pragma once
#include "Image.h"
#include <list>

// images composite
class CompositeImages :
    public Image
{
private:
    list<Image*> images = list<Image*>();   // image set

public:
    // constructors and destructor
    CompositeImages(string ID);
    ~CompositeImages();

    // overloaded methods
    int GetSize();

    // composite methods
    void Add(Image* img) { images.push_back(img); }
    bool RemoveWithID(string ID);   // return: true <=> removed, false <=> image does not exist in list
    

    // setters and getters
    int GetImagesNumber() { return images.size(); }
    Image* GetImageWithID(string ID);
    list<Image*> GetImageList() { return images; }
};

