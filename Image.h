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
	Image();
	Image(string path);

	// setters and getters
	string Path() { return path; }
};

