// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Является точкой входа для программы и интерфейсом взаимодействия с системой Animazer

// common
#include "AnimazerSystem.h"

// special
#include "ProxyDataSetLoad.h"

using namespace std;

int main()
{
    AnimazerSystem* s;
    // proxy banned
    cout << "1. Proxy banned" << endl;
    s = new AnimazerSystem("plug_animazer_with_proxy", new Logger(),
        new PlugImageInitialize(), new PlugImageSave(),
        new PlugDataSetSave(), new ProxyDataSetLoad(),
        new PlugProcessor());
    try {
        s->PerformImageInitialization("testData\\fake_image.txt");
        s->PerformImageSaving("testData\\saved_image.txt");
        s->PerformDataSetLoading("testData\\fake_dataset.txt"); // first loading
        s->PerformDataSetLoading("testData\\fake_dataset.txt"); // try load without savings
        s->PerformDataSetSaving("testData\\saved__dataset.txt");
        s->PerformImageProcessing();
        s->PerformProcessorPreparing();
        s->PerformImageProcessing();
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
    delete s;
    
    // good test (with proxy)
    cout << "2. Proxy accept" << endl;
    s = new AnimazerSystem("plug_animazer_with_proxy", new Logger(),
        new PlugImageInitialize(), new PlugImageSave(),
        new PlugDataSetSave(), new ProxyDataSetLoad(),
        new PlugProcessor());
    try {
        s->PerformImageInitialization("testData\\fake_image.txt");
        s->PerformImageSaving("testData\\saved_image.txt");
        s->PerformDataSetLoading("testData\\fake_dataset.txt");
        s->PerformDataSetSaving("testData\\saved__dataset.txt");
        s->PerformImageProcessing();
        s->PerformProcessorPreparing();
        s->PerformImageProcessing();
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
    delete s;

    // very good test wirhout proxy
    cout << "3. Without proxy but very good" << endl;
    s = new AnimazerSystem("plug_animazer_with_proxy", new Logger(),
        new PlugImageInitialize(), new PlugImageSave(),
        new PlugDataSetSave(), new DataSetLoadAdapter(),
        new PlugProcessor());
    try {
        s->PerformImageInitialization("testData\\fake_image.txt");
        s->PerformImageSaving("testData\\saved_image.txt");
        s->PerformDataSetLoading("testData\\fake_dataset.txt");
        s->PerformDataSetSaving("testData\\saved__dataset.txt");
        s->PerformProcessorPreparing();
        s->PerformImageProcessing();
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
    delete s;

    return 0;
}

