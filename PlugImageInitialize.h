#pragma once

// common
#include "IImageInitialize.h"
// special
#include "PlugImage.h"

using namespace std;

// plug image initializer
class PlugImageInitialize :
    public IImageInitialize
{
public:
    Image* Initialize(string path, Logger* lg);
};

