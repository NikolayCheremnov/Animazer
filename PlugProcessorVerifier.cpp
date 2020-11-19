#include "PlugProcessorVerifier.h"

void PlugProcessorVerifier::ProcessorPreparing(DataSet* data, Logger* lg)
{
	if (Verification(data)) {
		lg->log(__FUNCTION__, "decorator", "processor preparing", ID, "dataset is verified");
		processor->ProcessorPreparing(data, lg);
	} else
		lg->log(__FUNCTION__, "decorator", "processor preparing", ID, "dataset is not verified");
}

string PlugProcessorVerifier::Process(Image* processed, Logger* lg)
{
	if (Verification(processed)) {
		lg->log(__FUNCTION__, "decorator", "processing", ID, "image is verified");
		return processor->Process(processed, lg);
	}
	else {
		lg->log(__FUNCTION__, "decorator", "processing", ID, "image is not verified");
		return "unverified";
	}
}
