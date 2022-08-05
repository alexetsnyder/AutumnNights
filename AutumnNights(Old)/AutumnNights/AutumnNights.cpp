// AutumnNights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "World.h"

int main()
{
    World world(4, 4);
    std::cout << world.Draw();
}
