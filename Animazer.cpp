// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Является точкой входа для программы и интерфейсом взаимодействия с системой Animazer

// common
#include "AnimazerSystem.h"

// special
#include "ProxyDataSetLoad.h"
#include "PlugProcessorVerifier.h"

using namespace std;

int main()
{
    AnimazerSystem* s;
    // proxy banned
    cout << "Adapter, decorator" << endl;
    s = new AnimazerSystem("TestingStructuralPatterns", new Logger(),
        new PlugImageInitialize(), new PlugImageSave(),
        new PlugDataSetSave(), new ProxyDataSetLoad(),
        new PlugProcessor());
    try {
        s->PerformImageInitialization("testData\\fake_image.txt");  // load image
        s->PerformDataSetLoading("testData\\fake_dataset.txt");     // load dataset
        s->PerformProcessorPreparing();                             // preparing
        s->PerformImageProcessing();                                // processing
        s->setProcessor(new PlugProcessorVerifier("PlugProcessorVerifier", s->getProcessor())); // decoration
        s->PerformImageProcessing();                                // second processing
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
    delete s;

    return 0;
}

