//
//  Core.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 20/04/2023.
//

#include "Core.hpp"


bool checkCollision( SDL_Rect a, SDL_Rect b ){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topB, topA;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    topA = a.y;
    leftA = a.x;
    rightA = a.x + a.w;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    
    //If rect A is above rectB
    if((rightA > leftB) && (leftA < rightB) && (topB < bottomA) && (bottomA < bottomB)){
        return true;
    }
     //If none of the sides from A are outside B
     return false;
}


