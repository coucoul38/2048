// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "lib.h"


char readDirection(char direction) {

    if (direction == 'H' || direction == 'h') {
        std::cout << "Vers le haut";
        return 'h';
    }
    else if (direction == 'B' || direction == 'b') {
        std::cout << "Vers le bas";
        return 'b';
    }
    else if (direction == 'G' || direction == 'g') {
        std::cout << "Vers la gauche\n";
        return 'g';
    }
    else if (direction == 'D' || direction == 'd') {
        std::cout << "Vers la droite\n";
        return 'd';
    }
    else if (direction == 'E' || direction == 'e') {
        std::cout << "Exiting loop\n";
        return 'e';
    }
    else return '0';
}


void main()
{
    bool exit = false;
    std::cout << "Hello World!\n";
    Grid* grid = new Grid(4,4);

    char player_input;
    int key;

    while(!exit) {
        grid->print();
        std::cout << "B/H/D/G pour deplacer ou E pour sortir: ";
        std::cin >> player_input;
        key = readDirection(player_input);
        if (key == 'e') {
            exit = true;
        }
        else if (key!='0') {
            grid->addBlock();
        }
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage