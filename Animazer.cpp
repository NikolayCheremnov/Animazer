// Animazer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

#include "BitMapInitialize.h"
#include "Logger.h"

using namespace std;

int main()
{
    Logger* lg = new Logger();
    BitMapInitialize *b = new BitMapInitialize();
    b->Initialize("foo", lg);
    return 0;
}

