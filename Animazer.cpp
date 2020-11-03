// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "AnimazerSystem.h"

using namespace std;

int main()
{
    AnimazerSystem* s = new AnimazerSystem();
    s->PerformImageInitialization("testData\\bad.txt");
    s->PerformImageSaving("testData\\s_test.txt");
    return 0;
}

