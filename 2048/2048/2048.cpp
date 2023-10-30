// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <SDL.h>

#include "grid.h"
#include "integration.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// Window size
#define WIDTH 800
#define HEIGHT 600

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

class createWindow(SDL_Window* window = NULL) {

#   
    //Destructor
    ~createWindow(){
		/* Frees memory */
		SDL_DestroyWindow(window);

		/* Shuts down all SDL subsystems */
		SDL_Quit();
    }
}

void deleteWindow(SDL_Window* window = NULL) {

    

}

int main(int argc, char** argv)
{

    SDL_Window* window = NULL;

    createWindow(window);

    bool exit = false;
    std::cout << "Hello World!\n";
    Grid* grid = new Grid(4,4);

    char player_input;
    std::string key;

    while (!exit) {
        grid->print();
        std::cout << "Utilisez les touches directionelles pour deplacer les blocks\n";
        key = readDirection();
        if (key == "exit") {
            exit = true;
        }
        grid->slide(key);
        exit = grid->addBlock();
    }

    //INTEGRATION TEST
    IntegrationTest* test = new IntegrationTest();

    //Destroy window
    deleteWindow();
	

    return 0;
}