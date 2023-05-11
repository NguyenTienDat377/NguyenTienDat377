//
//  LTexture.hpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 17/04/2023.
//

#ifndef LTexture_hpp
#define LTexture_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

class LTexture{
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile(std::string path, SDL_Renderer* &renderer);
    
        //Creates image from font string
        bool loadFromRenderedText( std::string textureText, SDL_Color textColor, TTF_Font* &font, SDL_Renderer* &renderer);
    
        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(SDL_Renderer* &renderer, int x, int y, SDL_Rect* clip = NULL);

        //Gets image dimensions
        int getWidth();
        int getHeight();
        
};



#endif /* LTexture_hpp */
