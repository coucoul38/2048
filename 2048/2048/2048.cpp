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

void createWindow(SDL_Window* window = NULL) {
	/* Creates a SDL window */
	window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
		SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
		SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
		WIDTH, /* Width of the window in pixels */
		HEIGHT, /* Height of the window in pixels */
		0); /* Additional flag(s) */
}


int main(int argc, char** argv)
{

    SDL_Window* window = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Error, couldn't initizialize SDL, error : " << SDL_GetError() << "\n";
    }else{
        std::cout << "Successfully initialized SDL\n";
    }

    createWindow(window);

    bool exit = false;
    std::cout << "Hello World!\n";
    //Grid* grid = new Grid(4,4);

    char player_input;
    std::string key;

    /*while (!exit) {
        grid->print();
        std::cout << "Utilisez les touches directionelles pour déplacer les blocks";
        key = readDirection();
        if (key == "exit") {
            exit = true;
        }
        exit = grid->slide(key);
        grid->addBlock();
    }*/

    //INTEGRATION TEST
    IntegrationTest* test = new IntegrationTest(1);


	/* Frees memory */
	SDL_DestroyWindow(window);

	/* Shuts down all SDL subsystems */
	SDL_Quit();

    return 0;
}