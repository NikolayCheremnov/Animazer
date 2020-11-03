#include "PlugDataSet.h"

PlugDataSet::PlugDataSet()
{
}

PlugDataSet::~PlugDataSet()
{
	if (setData != nullptr)
		delete setData;
}

void PlugDataSet::SetSetData(char* val)
{
	if (setData != nullptr)
		delete setData;
	setData = val;
}
