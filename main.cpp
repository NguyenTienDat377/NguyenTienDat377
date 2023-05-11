//
//  main.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 17/04/2023.
//

#include "Core.hpp"
#include "initSDL.hpp"
#include "player.hpp"
#include "platformMoving.hpp"
#include "Platform.hpp"

using namespace std;

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

TTF_Font* font = NULL;

int FRAME_RATE = 60; // The desired frame rate of the game
int FRAME_TIME = 1000.0 / FRAME_RATE; // The time in milliseconds for each frame

const char* WINDOW_NAME = "Doodle Jump";

LTexture playerRightTexture, playerLeftTexture;
LTexture backgroundTexture;
LTexture platformTexture;
LTexture displayMessage;

int main(int argc, char * argv[]) {
    srand(time(0));
    
    //Initiatie SDL, SDL_Image, SDL_TTF and WIndow
    if(!initSDL(WINDOW_NAME, WINDOW_WIDTH, WINDOW_HEIGHT, window, renderer)){
        cout << "Cannot init window" << endl;
    }

    //Load image from file
    if(!loadMedia(renderer, font)){
        cout << "Cannot load file" << endl;
    }
    
    //Initiate player, platform and event receiver
    int score = 0;
    
    Player player;
    
    Platform plat[15];
    
    MovingPlatform movingPlat;
    
    SDL_Event e;
    
    float height = 200;
    float velP = 5;
    
    bool quit = false;
    
    for(int i = 0; i < 15; i++){
        int x = rand() % WINDOW_WIDTH;
        int y = rand() % WINDOW_HEIGHT;
        
        bool overlap = false;
        for(int j = 0; j < i; j++){
            if(plat[j].PPosX - Platform::PWIDTH <= x && x <= plat[j].PPosX + Platform::PWIDTH && plat[j].PPosY - Platform::PHeight <= y && plat[j].PPosY + Platform::PHeight >= y){
                overlap = true;
                break;
            }
        }
        if(overlap){
            i--;
            continue;
        }
        
        plat[i].setterPosPlatform(x, y);
    }
    
    while(!quit){
        //Get the inital frame rate
        Uint32 frameStart = SDL_GetTicks();
        
        while(SDL_PollEvent(&e) != 0){
            //Check if request delete window
            if(e.type == SDL_QUIT){
                quit = true;
            }
            //Receive event from keyboard
            player.handleEvent(e);
        }
        
        
        //move the player according to event
        player.move(WINDOW_WIDTH);
        
        //render all to the window
        SDL_RenderClear(renderer);
        
        backgroundTexture.render(renderer, NULL, NULL);
        
        player.render(renderer);
        
        for(int i = 0; i < 15; i++){
            plat[i].render(renderer);
        }
        
        SDL_RenderPresent(renderer);
        
        //player falling
        player.gravityPull();
        
        //check Collision between player and platform
        
        for(int i = 0; i < 15; i++){
            //Minus the difference between the real size texture vs sprite display
            //Sprite nhan vat va Sprite platform deu
            if(checkCollision(player.getCollider(), plat[i].getCollider()) && player.getVelY() > 0){
                score++;
                player.jump();
            }
        }
        //Create a infinite map
        if(player.getY() < height){
            for(int i = 0; i < 15; i++){
                player.setterY(height);
                plat[i].moving(velP);
                if(plat[i].PPosY > WINDOW_HEIGHT){
                    plat[i].setterPosPlatform(rand() % 480, 0);
                }
            }
        }
        
        //Get the frame currently loading
        Uint32 frameTime = SDL_GetTicks() - frameStart;

        /*If the current frame is less that the desired frame, delay to get a
         consistent frame
         */
        if (frameTime < FRAME_TIME) {
            SDL_Delay(FRAME_TIME - frameTime);
        }
    }
    
    playerLeftTexture.free();
    backgroundTexture.free();
    platformTexture.free();
    playerRightTexture.free();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
