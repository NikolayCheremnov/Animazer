#include "PlugImageSave.h"

void PlugImageSave::Save(string path, Image *saved, Logger *lg)
{
	try {
		PlugImage* imgObj = (PlugImage*)saved;	// type coercion
		ofstream fout(path);
		fout << imgObj->GetImgData();
		fout.close();
		lg->log(__FUNCTION__, "delegate", "save image object", "plug", "saved successful");
	}
	catch (exception ex) {
		lg->log(__FUNCTION__, "delegate", "save image object", "plug", ex.what());			// write exception log
		throw ex;																			// and throw an exception above
	}
}
