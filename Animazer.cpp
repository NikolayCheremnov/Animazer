// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Является точкой входа для программы и интерфейсом взаимодействия с системой Animazer

// common
#include "AnimazerSystem.h"

// special
#include "ProxyDataSetLoad.h"
#include "PlugProcessorVerifier.h"
#include "PlugImageInitialize.h"
#include "PlugDataSetSave.h"
#include "PlugProcessor.h"

using namespace std;

int main()
{
    list<string> paths = list<string>();
    paths.push_back("testData\\fake_image_1.txt");
    paths.push_back("testData\\fake_image_2.txt");
    AnimazerSystem* s;
    cout << "Adapter, decorator, composite" << endl;
    s = new AnimazerSystem("TestingStructuralPatterns", new Logger(),
        new PlugImageInitialize(),
        new PlugDataSetSave(), new ProxyDataSetLoad(),
        new PlugProcessor());
    try {
        s->PerformImageInitialization("testData\\fake_image.txt");  // load image
        s->PerformDataSetLoading("testData\\fake_dataset.txt");     // load dataset
        s->PerformProcessorPreparing();                             // preparing
        s->PerformImageProcessing();                                // processing
        s->setProcessor(new PlugProcessorVerifier("PlugProcessorVerifier", s->getProcessor())); // decoration
        s->PerformImageProcessing();                                // second processing
        s->PerformComplexImageInitialization(paths);                // load image set (composite)
        s->PerformComplexImageProcessing();                         // set processing
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
    delete s;

    return 0;
}

