#include "ProcessorVerifier.h"

ProcessorVerifier::ProcessorVerifier(string ID, IProcessor* processor)
{
	this->ID = ID;
	if (processor != nullptr) {
		this->processor = processor;
	}
	else
		throw exception("nullptr processor object");
	
}
