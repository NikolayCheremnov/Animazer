#pragma once

class Images :
    public IImage
{
private:
    list<IImage*> images = list<IImage*>(); // set of images
    
public:
    // constructors and destructor
    Images(string ID);

    // overloads
    string PerformImageProcessing(Logger* lg);

    // composite methods
    void Add(Image* img);
    bool RemoveWithID(string imgID);
    Image* GetImageWithID(string ID);
};

