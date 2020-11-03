#pragma once

// external
#include <string>
// common
#include "IImageSave.h"
// special
#include "PlugImage.h"

using namespace std;

class PlugImageSave :
    public IImageSave
{
public:
    void Save(string path, Image* saved, Logger* lg);
};

