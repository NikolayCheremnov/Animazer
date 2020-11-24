#pragma once

// common
#include "IProcessor.h"

// Image interface
class IImage
{
protected:
	string ID;
	IProcessor* procObj;

public:
	// methods
	void PerformProcessorPreparing(DataSet* dsObj, Logger* lg);

	// virtual methods
	virtual string PerformImageProcessing(Logger* lg) = 0;
	virtual void Add(Image* img) = 0;
	virtual ~IImage() = 0;		// virtual destructor

	// setters and getters
	string getID() { return ID; }
	IProcessor* getProcessor() { return procObj; }
	void setProcessor(IProcessor* procObj) { this->procObj = procObj; } // possible memory leaks!!!
};

