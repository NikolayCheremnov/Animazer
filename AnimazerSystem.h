#pragma once

// common
#include "Logger.h"
#include "Image.h"
#include "IImageInitialize.h"
#include "IImageSave.h"
#include "IProcessor.h"
#include "DataSet.h"
#include "IDataSetLoad.h"
#include "IDataSetSave.h"

// special
#include "PlugImage.h"
#include "PlugImageInitialize.h"
#include "PlugImageSave.h""
#include "PlugProcessor.h"
#include "PlugDataSet.h"
#include "PlugDataSetSave.h"
#include "DataSetLoadAdapter.h"

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
	DataSet* dsObj = nullptr;
	IDataSetSave* SaveDataSetAction = nullptr;
	IDataSetLoad* LoadDataSetAction = nullptr; 
	// with processor
	IProcessor* procObj = nullptr;
	
public:
	// constructors and destructor
	AnimazerSystem();	// basic plug constructor
	AnimazerSystem(string ID, Logger* lg,
		IImageInitialize* InitializeImageAction, IImageSave* SaveImageAction,
		IDataSetSave* SaveDataSetAction, IDataSetLoad* LoadDataSetAction,
		IProcessor* procObj);													// polymorphic custom constructor
	~AnimazerSystem();

	// perform methods
	void PerformImageInitialization(string path);
	void PerformImageSaving(string path);
	void PerformDataSetSaving(string path);
	void PerformDataSetLoading(string path);
	void PerformProcessorPreparing();
	string PerformImageProcessing();
};

