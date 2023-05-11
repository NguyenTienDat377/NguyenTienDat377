//
//  initSDL.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 17/04/2023.
//

#include "initSDL.hpp"

bool initSDL(const char* windowName,int WIDTH,int HEIGHT, SDL_Window* &window, SDL_Renderer* &renderer){
    //initiate SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cerr << "Cannot init SDL. Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    //Create window
    window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    //Check whether window is successfully created
    if(window == NULL){
    std::cerr << "Cannot create window. Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    //Check Linear texture filtering
    if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        std::cerr << "Warning: Linear texture filtering not enabled!";
    }
    
    //Create renderer?
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    //Check renderer
    if(renderer == NULL){
        std::cerr << "Unable to create Renderer. Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
    //Initiate SDL_IMG
    int imgFlags = IMG_INIT_PNG;
    
    if(!(IMG_Init(imgFlags) & imgFlags)){
        std::cerr << "Cannot init IMG library. Error: " << IMG_GetError() << std::endl;
        return false;
    }
    
    if(TTF_Init() == -1){
        std::cerr << "Cannot init TTF library. Error: " << TTF_GetError() << std::endl;
        return false;
    }
    
    return true;
}

bool loadMedia(SDL_Renderer* &renderer, TTF_Font* &font){
    bool success = true;
    
    if(!backgroundTexture.loadFromFile("/Users/nguyentiendat/Desktop/FirstProject/Sprites/background.png", renderer)){
        std::cerr << "Unable to load background sprite" << std::endl;
        success = false;
    }
    
    if(!playerLeftTexture.loadFromFile("/Users/nguyentiendat/Desktop/FirstProject/Sprites/playerLeft.png", renderer)){
        std::cerr << "Unable to load player's left side sprite" << std::endl;
        success = false;
    }
    
    if(!playerRightTexture.loadFromFile("/Users/nguyentiendat/Desktop/FirstProject/Sprites/playerRight.png", renderer)){
        std::cerr << "Unable to load player's right side sprite" << std::endl;
        success = false;
    }
    
    if(!platformTexture.loadFromFile("/Users/nguyentiendat/Desktop/FirstProject/Sprites/platform.png", renderer)){
        std::cerr << "Unable to load background sprite" << std::endl;
        success = false;
    }
    font = TTF_OpenFont("/Users/nguyentiendat/Desktop/FirstProject/Sprites/DoodleJump.ttf", 32);
    
    if(font == nullptr){
        std::cerr << "Cannot open font " << std::endl;
        success = false;
    }
    
    return success;
}
