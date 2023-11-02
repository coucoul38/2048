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
#define KEY_RIGHT 7




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

    std::cout << "Path: " << path << "\n";
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
    int window_w = 1280;
    int window_h = 720;

    Window* windowEntity = new Window(window_w, window_h);
    SDL_Renderer* renderer = windowEntity->GetRenderer();
    SDL_Window* window = windowEntity->GetWindow();

    //LOAD IMAGES
    SDL_Texture* IMGblockEmpty = loadImage("../Assets/Images/empty.bmp", renderer);
    SDL_Texture* IMGblock2 = loadImage("../Assets/Images/2.bmp", renderer);
    SDL_Texture* IMGblock4 = loadImage("../Assets/Images/4.bmp", renderer);

    bool exit = false;
    std::cout << "Hello World!\n";
    int size_x = 4;
    int size_y = 4;
    Grid* grid = new Grid(size_x, size_y, window, IMGblockEmpty, renderer);

    /*for (int i = 0; i < size_x; i++)
    {
        for (int p = 0; p < size_y; p++) {
            Block* block = new Block(window, IMGblockEmpty, renderer, i*15, p*15, 20, 20);
            block->Draw();
        }
    }*/

    //block->Move(100, 100);


    char player_input;
    std::string key;


    /*while (!exit) {
        grid->print();
        std::cout << "utilisez les touches directionelles pour deplacer les blocks\n";
        key = readDirection();
        if (key == "exit") {
            exit = true;
        }
        grid->slide(key);
        block->ChangeImg(IMGblock2);
        block->Move(100, 100);
        block->Draw();
        exit = grid->addBlock();
    }*/

    SDL_Event event;
    bool integration = true;
    if(!integration){
        while (SDL_PollEvent(&event) || !exit) {
            /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
            switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    //clear canvas
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    //render blocks
                    grid->slide("left");
                    grid->print();
                    //block->ChangeImg(IMGblock2);
                    //block->Move(100, 100);
                    //block->Draw();
                    exit = grid->addBlock();
                    break;
                case SDLK_RIGHT:
                    grid->slide("right");
                    grid->print();
                    exit = grid->addBlock();
                    break;
                case SDLK_UP:
                    grid->slide("up");
                    grid->print();
                    exit = grid->addBlock();
                    break;
                case SDLK_DOWN:
                    grid->slide("down");
                    grid->print();
                    exit = grid->addBlock();
                    break;
                default:
                    break;
                }
            case SDL_KEYUP:
                break;

            case SDL_QUIT: //close window
                exit = true;
                break;
            }
        }
    }

    //INTEGRATION TEST
    if (integration) {
        IntegrationTest* test = new IntegrationTest();
        int quit = 0;
        while (quit != 1) {
            std::cout << "Enter 1 to quit: ";
            std::cin >> quit;
        }
    }

    delete windowEntity;
    /*for (int i = 0; i < size_x; i++)
    {
        free(blockGrid[i])
    }
    free(blockGrid);*/

    return 0;
}