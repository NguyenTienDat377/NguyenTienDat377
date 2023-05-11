//
//  LTexture.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 17/04/2023.
//

#include "LTexture.hpp"


LTexture::LTexture(){
    //Initialize the hardware texture
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture(){
    //Deallocate the texture
    free();
}

bool LTexture::loadFromFile(std::string path, SDL_Renderer* &renderer){
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ){
        std::cerr << "Unable to load image. SDL_image Error: \n" << IMG_GetError() << ' ';
    }
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(newTexture == NULL ){
        std::cerr << "Unable to create texture from file. SDL Error: \n" << SDL_GetError() << ' ';
    }
        //Get image dimensions
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* &font, SDL_Renderer* &renderer){
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    if( textSurface == NULL ){
        std::cerr << "Unable to render text surface! SDL_ttf Error: %s\n" << TTF_GetError() ;
    }
    else{
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( mTexture == NULL ){
            std::cerr << "Unable to create texture from rendered text! SDL Error: %s\n" << SDL_GetError();
        }
        else{
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return mTexture != NULL;
}

void LTexture::free(){
    //Free texture if it exists
    if( mTexture != NULL ){
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render(SDL_Renderer* &renderer, int x, int y, SDL_Rect* clip){
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL ){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy(renderer, mTexture, clip, &renderQuad );
}

int LTexture::getWidth(){
    return mWidth;
}

int LTexture::getHeight(){
    return mHeight;
}


