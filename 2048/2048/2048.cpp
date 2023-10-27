// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "lib.h"
#include <string>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

std::string readDirection() {
    bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            return "up";
        case KEY_DOWN:
            return "down";
        case KEY_RIGHT:
            return "right";
        case KEY_LEFT:
            return "left";
        default:
            badKey = true;
            break;
        }
    }
}


void main()
{
    bool exit = false;
    std::cout << "Hello World!\n";
    Grid* grid = new Grid(4,4);

    char player_input;
    std::string key;

    while(!exit) {
        grid->print();
        std::cout << "Utilisez les touches directionelles pour déplacer les blocks";
        key = readDirection();
        if (key == "exit") {
            exit = true;
        }
        exit = grid->slide(key);
        grid->addBlock();
    }
}