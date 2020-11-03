#include "PLugImageInitialize.h"


Image* PlugImageInitialize::Initialize(string path, Logger *lg)
{
	try {
		PlugImage* initialized = new PlugImage(path);
		char* buf = new char[50];
		ifstream fin(path);
		fin >> buf;
		fin.close();
		initialized->SetImgData(buf);
		lg->log(__FUNCTION__, "delegate", "initialize image object", "plug", "initialized successful");
		return initialized;
	}
	catch (exception ex) {
		lg->log(__FUNCTION__, "delegate", "initialize image object", "plug", ex.what());	// write exception log
		throw ex;																			// and throw an exception above
	}
}
