#pragma once

// common
#include "Logger.h"
#include "Image.h"
#include "IImageInitialize.h"
#include "IImageSave.h"

// special
#include "PlugImage.h"
#include "PlugImageInitialize.h"
#include "PlugImageSave.h"

//	main system class - aggregation all main abstractions
class AnimazerSystem
{
private:
	Logger* lg = nullptr;
	Image* imgObj = nullptr;
	IImageInitialize* InitializeImageAction = nullptr;
	IImageSave* SaveImageAction = nullptr;
public:
	// constructors and destructor
	AnimazerSystem();
	~AnimazerSystem();

	// perform methods
	void PerformImageInitialization(string path);
	void PerformImageSaving(string path);
};

