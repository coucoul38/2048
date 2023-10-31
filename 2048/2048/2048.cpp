#include <iostream>
#include <string>
#include <conio.h>
#include <SDL.h>

#include "Grid.h"
#include "Integration.h"
#include "Window.h"
#include "GameObject.h"

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

   

int main(int argc, char** argv)
{

    Window* windowEntity = new Window(1280,720);

    //LOAD IMAGES
    SDL_Surface* image = SDL_LoadBMP("../Assets/Images/image.bmp");

    GameObject* gameObject = new GameObject(windowEntity->GetWindow(), image);
    if (gameObject->Blit()) {
        std::cout << "Error while blitting bitmap\n";
    }

    /*SDL_Rect dest;
    dest.x = 10;
    dest.y = 10;

    SDL_BlitSurface(image, NULL, SDL_GetWindowSurface(windowEntity->GetWindow()), NULL);*/

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
    //IntegrationTest* test = new IntegrationTest();

    delete windowEntity;
    delete gameObject;
	

    return 0;
}