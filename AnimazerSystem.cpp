#include "AnimazerSystem.h"

// first test constructor
AnimazerSystem::AnimazerSystem()
{
	ID = "some_id";
	lg = new Logger();
	imgObj = nullptr;
	InitializeImageAction = new PlugImageInitialize();
	SaveImageAction = new PlugImageSave();
	SaveDataSetAction = new PlugDataSetSave();
	LoadDataSetAction = new PlugDataSetLoad();
}

AnimazerSystem::~AnimazerSystem()
{
	if (imgObj != nullptr)
		delete imgObj;
	if (InitializeImageAction != nullptr)
		delete InitializeImageAction;
	if (SaveImageAction != nullptr)
		delete SaveImageAction;
	if (SaveDataSetAction != nullptr)
		delete SaveDataSetAction;
	if (LoadDataSetAction != nullptr)
		delete LoadDataSetAction;
	if (lg != nullptr)
		delete lg;
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
	if (dsObj != nullptr)
		delete dsObj;
	dsObj = LoadDataSetAction->Load(path, lg);

}
