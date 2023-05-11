//
//  Core.hpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 20/04/2023.
//

#ifndef Core_hpp
#define Core_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "LTexture.hpp"
#include "initSDL.hpp"

static int WINDOW_WIDTH = 480;

static int WINDOW_HEIGHT = 640;

enum LButtonSprite{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_PLAY = 2,
    BUTTON_SPRITE_MOUSE_EXIT = 3,
    BUTTON_SPRITE_TOTAL = 4
};

bool checkCollision(SDL_Rect a, SDL_Rect b);

bool playAgain(LTexture displayMessage);

#endif /* Core_hpp */
