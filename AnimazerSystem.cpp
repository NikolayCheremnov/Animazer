#include "AnimazerSystem.h"

// first test constructor
AnimazerSystem::AnimazerSystem()
{
	ID = "some_id";
	// objects
	lg = new Logger();
	procObj = new PlugProcessor();
	// actions
	InitializeImageAction = new PlugImageInitialize();
	SaveImageAction = new PlugImageSave();
	SaveDataSetAction = new PlugDataSetSave();
	LoadDataSetAction = new PlugDataSetLoad();
}

AnimazerSystem::AnimazerSystem(string ID, Logger* lg, IImageInitialize* InitializeImageAction, IImageSave* SaveImageAction, IDataSetSave* SaveDataSetAction, IDataSetLoad* LoadDataSetAction, IProcessor* procObj)
{
	this->ID = ID;
	this->lg = lg;
	this->InitializeImageAction = InitializeImageAction;
	this->SaveImageAction = SaveImageAction;
	this->SaveDataSetAction = SaveDataSetAction;
	this->LoadDataSetAction = LoadDataSetAction;
	this->procObj = procObj;
}

AnimazerSystem::~AnimazerSystem()
{
	// objects
	if (imgObj != nullptr)
		delete imgObj;
	if (lg != nullptr)
		delete lg;
	if (procObj != nullptr)
		delete procObj;
	if (dsObj != nullptr)
		delete dsObj;
	// actions
	if (InitializeImageAction != nullptr)
		delete InitializeImageAction;
	if (SaveImageAction != nullptr)
		delete SaveImageAction;
	if (SaveDataSetAction != nullptr)
		delete SaveDataSetAction;
	if (LoadDataSetAction != nullptr)
		delete LoadDataSetAction;
}
 
void AnimazerSystem::PerformImageInitialization(string path)
{
	if (imgObj != nullptr)
		delete imgObj;
	imgObj = InitializeImageAction->Initialize(path, lg);
}

void AnimazerSystem::PerformImageSaving(string path)
{
	SaveImageAction->Save(path, imgObj, lg);
}

void AnimazerSystem::PerformDataSetSaving(string path)
{
	SaveDataSetAction->Save(path, dsObj, lg);
}

void AnimazerSystem::PerformDataSetLoading(string path)
{
	dsObj = LoadDataSetAction->Load(path, dsObj, lg);
}

void AnimazerSystem::PerformProcessorPreparing()
{
	procObj->ProcessorPreparing(dsObj, lg);
}

string AnimazerSystem::PerformImageProcessing()
{
	return procObj->Process(imgObj, lg);
}
