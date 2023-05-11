//
//  initSDL.hpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 17/04/2023.
//

#ifndef initSDL_hpp
#define initSDL_hpp

#include "Core.hpp"

extern LTexture playerRightTexture, playerLeftTexture;
extern LTexture backgroundTexture;
extern LTexture platformTexture;
extern LTexture displayMessage;

bool initSDL(const char* windowName,int WIDTH,int HEIGHT, SDL_Window* &window, SDL_Renderer* &renderer);

bool loadMedia(SDL_Renderer* &renderer, TTF_Font* &font);

#endif /* initSDL_hpp */
