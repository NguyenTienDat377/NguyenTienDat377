//
//  Platform.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 20/04/2023.
//

#include "Platform.hpp"
 
Platform::Platform(){
    PCollider.w = PWIDTH;
    PCollider.h = PHeight;
}

SDL_Rect Platform::getCollider(){
    return PCollider;
}

void Platform::render(SDL_Renderer* &renderer){
    platformTexture.render(renderer, PPosX, PPosY);
}

void Platform::setterPosPlatform(float _x, float _y){
    PPosX = _x;
    PPosY = _y;
    
    PCollider.x = _x;
    PCollider.y = _y;
}

void Platform::moving(float speed){
    PPosY += speed;
    PCollider.y = PPosY;
}
