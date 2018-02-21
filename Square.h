//
//  Square.h
//  hw4
//
//  Created by Ethan Chee on 2/3/18.
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#ifndef Square_h
#define Square_h

/**
 * This class is dervied from the Shape class, it represents a square
 */
class Square : public Shape
{
    
public:
    
    /**
     * Constructor for our Square object, that derives from the Shape class (and constructs it)
     * @param xPos X position that our shape will have it's "center" at
     * @param yPos Y position that our shape will have it's "center" at
     * @param size Size that our shape will be
     */
    Square (int xPos, int yPos, int size);
    
    /**
     * Adds all of a Square object's coordinates(std::pair) to our shapeCoordinates vector
     */
    void setStars() override;
    
    
};

#endif /* Square_h */
