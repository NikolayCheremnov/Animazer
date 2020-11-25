#pragma once

#include <string>

using namespace std;

class Image
{
protected:
	string ID;
	string path;
public:
	// constructors and destructor
	Image(string ID, string path);
	virtual ~Image() {};	// virtual destructor
	
	// virtual methods
	virtual int GetSize() = 0;
	virtual void Add(Image* img) {};
	virtual bool RemoveWithID(string ID) { return false; };
	virtual Image* GetImageWithID(string ID) { return nullptr; };

	// setters and getters
	string Path() { return path; }
	string GetID() { return ID; }
};

