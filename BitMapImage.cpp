#include "BitMapImage.h"

BitMapImage::BitMapImage(string path): Image(path)
{
	InitializeAction = new BitMapInitialize();
}
