// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "lib.h"
#include <string>

std::string readDirection(char direction) {

    if (direction == '8' || direction == 'z') {
        return "up";
    }
    else if (direction == '5' || direction == 's') {
        return "down";
    }
    else if (direction == '4' || direction == 'q') {
        return "left";
    }
    else if (direction == '6' || direction == 'd') {
        return "right";
    }
    else if (direction == '0' || direction == 'e') {
        std::cout << "Exiting loop\n";
        return "exit";
    }
    else return "not_valid";
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
        std::cout << "ZQSD pour deplacer ou E pour sortir: ";
        std::cin >> player_input;
        key = readDirection(player_input);
        if (key == "exit") {
            exit = true;
        }
        else if (key!="not_valid") {
            grid->slide(key);
            grid->addBlock();
        }
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage