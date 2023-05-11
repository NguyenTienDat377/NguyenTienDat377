//
//  player.hpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 18/04/2023.
//

#ifndef player_hpp
#define player_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <vector>
#include "Core.hpp"
#include "initSDL.hpp"

class Player{
public:
    
    float VelX,VelY;
    
    int PosX,PosY;
    
    SDL_Rect mCollider;
    
    bool facingRight;
    
    constexpr static const float Vel = 3;
    constexpr static const float gravityVel = 0.1;
    constexpr static const float jumpVel = 10;
    
    static const int SizeX = 62;
    static const int SizeY = 60;
    
    Player();
    
    void handleEvent(SDL_Event &e);
    
    void move(int SCREEN_WIDTH);
    
    void render(SDL_Renderer* &renderer);
    
    SDL_Rect getCollider();
    
    int getX();
    int getY();
    int getVelY();
    
    void setterY(int _y);
    
    void jump();
    
    void gravityPull();
};



#endif /* player_hpp */
