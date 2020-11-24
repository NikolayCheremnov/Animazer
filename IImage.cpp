#include "IImage.h"

void IImage::PerformProcessorPreparing(DataSet* dsObj, Logger* lg)
{
	if (procObj != nullptr)
		procObj->ProcessorPreparing(dsObj, lg);
}
