//
//  Diamond.h
//  hw4
//
//  Created by Ethan Chee on 2/3/18.
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#ifndef Diamond_h
#define Diamond_h

/**
 * This class is dervied from the Shape class, it represents a diamond
 */
class Diamond : public Shape
{
    
public:
    
    /**
     * Constructor for our Diamond object, that derives from the Shape class (and constructs it)
     * @param xPos X position that our shape will have it's "center" at
     * @param yPos Y position that our shape will have it's "center" at
     * @param size Size that our shape will be
     */
    Diamond (int xPos, int yPos, int size);
    
    /**
     * Adds all of a Diamond object's coordinates(std::pair) to our shapeCoordinates vector
     */
    void setStars() override;
    
};

#endif /* Diamond_h */
