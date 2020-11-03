#include "DataSet.h"

DataSet::DataSet()
{
}

void DataSet::AddImage(Image* img)
{
	Images.push_back(img);
}
