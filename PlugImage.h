 #pragma once

#include "Image.h"

class PlugImage :
    public Image
{
private:
    char* imgData;              // interpreting an image as a set of bytes
public:
    // constructors and destructor
    PlugImage(string path);
    ~PlugImage();

    // setters and getters
    char* GetImgData() { return imgData; }
    void SetImgData(char* val);
    
};

