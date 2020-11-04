// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "AnimazerSystem.h"

using namespace std;

int main()
{
    AnimazerSystem* s = new AnimazerSystem();
    s->PerformImageInitialization("testData\\fake_image.txt");
    s->PerformImageSaving("testData\\saved_image.txt");
    s->PerformDataSetLoading("testData\\fake_dataset.txt");
    s->PerformDataSetSaving("testData\\saved__dataset.txt");
    s->PerformImageProcessing();
    s->PerformProcessorPreparing();
    s->PerformImageProcessing();
    return 0;
}

