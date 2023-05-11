//
//  platformMoving.cpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 29/04/2023.
//

#include "platformMoving.hpp"

void MovingPlatform::moving(int SCREEN_WIDTH){
    PPosX += PVelX;
    
    if(PPosX + PCollider.w >= SCREEN_WIDTH){
        PPosX -= PVelX;
    }
}
