// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Является точкой входа для программы и интерфейсом взаимодействия с системой Animazer

// common
#include "AnimazerSystem.h"

// special
#include "ProxyDataSetLoad.h"

using namespace std;

int main()
{
    AnimazerSystem* s = new AnimazerSystem("plug_animazer", new Logger(),
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
        cout << ex.what();
    }
    delete s;
    return 0;
}

