//
//  platformMoving.hpp
//  FirstProject
//
//  Created by Nguyen Tien Dat on 29/04/2023.
//

#ifndef platformMoving_hpp
#define platformMoving_hpp

#include "Platform.hpp"

class MovingPlatform : public Platform{
    
    int PVelX = 1;
    
    
public:
    void moving(int SCREEN_WIDTH);
    
};

#endif /* platformMoving_hpp */
