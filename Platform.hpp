//
//  Platform.hpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 20/04/2023.
//

#ifndef Platform_hpp
#define Platform_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Core.hpp"
#include "initSDL.hpp"

class Platform{
public:
    
    float PPosX,PPosY;
    
    SDL_Rect PCollider;
    
    static const int PWIDTH = 68;
    static const int PHeight = 14;
    
    Platform();
    
    SDL_Rect getCollider();
    
    void render(SDL_Renderer* &renderer);
    
    void setterPosPlatform(float _x, float _y);
    
    void moving(float speed);
};

#endif /* Platform_hpp */
