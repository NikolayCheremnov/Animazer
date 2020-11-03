#include "DataSet.h"

DataSet::DataSet()
{
	ID = "some_id";
}

void DataSet::AddImage(Image* img)
{
	Images.push_back(img);
}
