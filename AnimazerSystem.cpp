#include "AnimazerSystem.h"

AnimazerSystem::AnimazerSystem(string ID, Logger* lg, IImageInitialize* InitializeImageAction, IDataSetSave* SaveDataSetAction, IDataSetLoad* LoadDataSetAction, IProcessor* procObj)
{
	this->ID = ID;
	this->lg = lg;
	this->InitializeImageAction = InitializeImageAction;
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

void AnimazerSystem::PerformComplexImageInitialization(list<string> paths)
{
	if (imgObj != nullptr)
		delete imgObj;
	imgObj = new CompositeImages("ImageSet");
	for (string path : paths)
		imgObj->Add(InitializeImageAction->Initialize(path, lg));
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

list<string> AnimazerSystem::PerformComplexImageProcessing()
{
	list<string> res;
	CompositeImagesIterator it((CompositeImages*)imgObj);
	for (Image* img = it.Begin(); it.HasNext(); img = it.Next()) {
		res.push_back(procObj->Process(img, lg));
	}
	return res;
}
