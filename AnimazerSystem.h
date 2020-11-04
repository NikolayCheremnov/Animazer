#pragma once

// common
#include "Logger.h"
#include "Image.h"
#include "IImageInitialize.h"
#include "IImageSave.h"
#include "IProcessor.h"
#include "DataSetController.h"

// special
#include "PlugImage.h"
#include "PlugImageInitialize.h"
#include "PlugImageSave.h""
#include "PlugProcessor.h"

//	main system class - aggregation all main abstractions
class AnimazerSystem
{
private:
	string ID;
	Logger* lg = nullptr;
	// with image
	Image* imgObj = nullptr;
	IImageInitialize* InitializeImageAction = nullptr;
	IImageSave* SaveImageAction = nullptr;
	// with data set
	DataSetController* dscObj = nullptr;
	// with processor
	IProcessor* procObj = nullptr;
	
public:
	// constructors and destructor
	AnimazerSystem();
	~AnimazerSystem();

	// perform methods
	void PerformImageInitialization(string path);
	void PerformImageSaving(string path);
	void PerformDataSetSaving(string path);
	void PerformDataSetLoading(string path);
	void PerformProcessorPreparing();
	string PerformImageProcessing();
};

