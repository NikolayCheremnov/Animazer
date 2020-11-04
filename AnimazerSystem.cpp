#include "AnimazerSystem.h"

// first test constructor
AnimazerSystem::AnimazerSystem()
{
	ID = "some_id";
	lg = new Logger();
	dscObj = new DataSetController();
	// actions
	InitializeImageAction = new PlugImageInitialize();
	SaveImageAction = new PlugImageSave();
	procObj = new PlugProcessor();
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
	if (dscObj != nullptr)
		delete dscObj;
	// actions
	if (InitializeImageAction != nullptr)
		delete InitializeImageAction;
	if (SaveImageAction != nullptr)
		delete SaveImageAction;
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
	dscObj->PerformDataSetSaving(path, lg);
}

void AnimazerSystem::PerformDataSetLoading(string path)
{
	dscObj->PerformDataSetLoading(path, lg);
}

void AnimazerSystem::PerformProcessorPreparing()
{
	procObj->ProcessorPreparing(dscObj->GetDataSet(), lg);
}

string AnimazerSystem::PerformImageProcessing()
{
	return procObj->Process(imgObj, lg);
}
