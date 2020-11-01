#pragma once

#include <string>
#include <iostream>

#include "IImageInitialize.h"
#include "Logger.h"

using namespace std;

// bit map image initializer
class BitMapInitialize :
    public IImageInitialize
{
public:
    void Initialize(string path, Logger *lg);
};

