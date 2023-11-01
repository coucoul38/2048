#include <iostream>
#include <string>
#include <conio.h>
#include <SDL.h>

#include "Grid.h"
#include "Integration.h"
#include "Window.h"
#include "Block.h"

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

SDL_Texture* loadImage(const char path[], SDL_Renderer* renderer) {
    SDL_Surface* tmp = NULL;
    SDL_Texture* texture = NULL;

    tmp = SDL_LoadBMP(path);
    if (tmp == NULL) {
        std::cout << "Error LoadBMP: " << SDL_GetError();
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if (texture == NULL) {
        std::cout << "Error CreateTextureFromSurface: " << SDL_GetError();
        return NULL;
    }
    return texture;
}

   

int main(int argc, char** argv)
{

    Window* windowEntity = new Window(1280,720);
    SDL_Renderer* renderer = windowEntity->GetRenderer();
    SDL_Window* window = windowEntity->GetWindow();

    //LOAD IMAGES
    /*SDL_Surface* image = SDL_LoadBMP("../Assets/Images/image.bmp");
    if (image == NULL) {
        std::cout << "Error loading image: " << SDL_GetError();
        exit(1);
    }*/
    SDL_Texture* IMGblockEmpty = loadImage("../Assets/Images/image.bmp", renderer);

    bool exit = false;
    std::cout << "Hello World!\n";
    int size_x = 4;
    int size_y = 4;
    Grid* grid = new Grid(size_x, size_y);

    //Visual grid creation
    Block** blockGrid = (Block**)malloc(sizeof(Block*) * size_x);
    for (int i = 0; i < size_x; i++)
    {
        Block* blockCol = (Block*)malloc(sizeof(Block) * size_y);
        for (int z = 0; z < size_y; z++)
        {
            Block* block = new Block(window, IMGblockEmpty, renderer);
            blockCol[z] = block;
        }
        blockGrid[i] = blockCol;
    }

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
    delete block;
	

    return 0;
}