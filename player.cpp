//
//  player.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 18/04/2023.
//

#include "player.hpp"

Player::Player(){
    VelX = 0;
    VelY = 0;
    
    PosX = 480/2;
    PosY = 100;
    
    facingRight = true;
    
    mCollider.w = SizeX;
    mCollider.h = SizeY;
    mCollider.x = PosX;
    mCollider.y = PosY;
}

void Player::handleEvent(SDL_Event &e){
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_RIGHT: VelX += Vel; facingRight = true; break;
            case SDLK_LEFT: VelX -= Vel; facingRight = false; break;
        }
    }
    else if(e.type == SDL_KEYUP && e.key.repeat == 0){
        switch (e.key.keysym.sym) {
            case SDLK_RIGHT: VelX -= Vel; break;
            case SDLK_LEFT: VelX += Vel; break;
        }
    }
}

void Player::move(int SCREEN_WIDTH){
    PosX += VelX;
    mCollider.x = PosX;
    
    if(PosX < 0 || PosX + SizeX > SCREEN_WIDTH){
        PosX -= VelX;
        mCollider.x = PosX;
    }
}

void Player::render(SDL_Renderer* &renderer){
    if(facingRight == true){
        playerRightTexture.render(renderer, PosX, PosY);
    }
    else{
        playerLeftTexture.render(renderer, PosX, PosY);
    }
}

SDL_Rect Player::getCollider(){
    return mCollider;
}

int Player::getX(){
    return PosX;
}

int Player::getY(){
    return PosY;
}

void Player::jump(){
    VelY -= jumpVel;
    PosY += VelY;
    mCollider.y = PosY;
}

void Player::gravityPull(){
    VelY += gravityVel;
    PosY += VelY;
    mCollider.y = PosY;
    if(VelY > 5){
        VelY = 5;
    }
}

int Player::getVelY(){
    return VelY;
}

void Player::setterY(int _y){
    PosY = _y;
    mCollider.y = _y;
}
