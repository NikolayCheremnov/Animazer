#include "AnimazerSystem.h"

// first test constructor
AnimazerSystem::AnimazerSystem()
{
	lg = new Logger();
	imgObj = nullptr;
	InitializeImageAction = new PlugImageInitialize();
	SaveImageAction = new PlugImageSave();
}

AnimazerSystem::~AnimazerSystem()
{
	if (imgObj != nullptr)
		delete imgObj;
	if (InitializeImageAction != nullptr)
		delete InitializeImageAction;
	if (SaveImageAction != nullptr)
		delete SaveImageAction;
	if (lg != nullptr)
		delete lg;
}

void AnimazerSystem::PerformImageInitialization(string path)
{
	imgObj = InitializeImageAction->Initialize(path, lg);
}

void AnimazerSystem::PerformImageSaving(string path)
{
	SaveImageAction->Save(path, imgObj, lg);
}