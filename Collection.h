//
//  Collection.h
//  hw4
//
//  Created by Ethan Chee on 2/3/18.
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#ifndef Collection_h
#define Collection_h

#include <memory>
#include <vector>
#include "Shape.h"

/**
 * Class that represents a collection of Shape objects
 */
class Collection
{
    
public:
    
    /**
     * Constructor of a Collection object, will collect our different shapes
     * @param lowX Lowest x value that can be called on our grid
     * @param highX Highest x value that can be called on our grid
     * @param lowY Lowest y value that can be called on our grid
     * @param highY Highest y value that can be called on our grid
     */
    Collection(int lowX, int highX, int lowY, int highY);
    
    /**
     * Adds a shape to our collection class
     * @param s Shared pointer to a shape that we will add to our collection of shapes
     */
    void addShape(const std::shared_ptr<Shape>& s);
    
    /**
     * Displays our grid as well as any shapes that are on it with the '*' character
     */
    void display() const;
    
    
    /**
     * Lets us know how many total stars we have in our grid
     * @return Returns the number of stars in our grid
     */
    size_t totalStars() const;
    
    
    /**
     * Move all the shapes a distance x and a distance y
     * @param distX How much we want to move all shapes by on the X axis
     * @param distY How much we want to move all shapes by on the Y axis
     */
    void moveBy (int distX, int distY);
    
    /**
     * Change all the sizes for all of our shapes in our Collection object
     * @param newSize New size we want to set all shapes to
     */
    void setSize (int newSize);
    
    /**
     * Checks to see if there is a star at a given pair object
     * @param coordinate The coordinate we are checking to see if a star is present at
     */
    bool checkStar (const std::pair<int, int>& coordinate) const;
    
    
private:
    // Integer functions that represent our low and high x's and y's
    int xBoundLow, xBoundHigh, yBoundLow, yBoundHigh;
    // Vector storing our shape objects
    std::vector<std::shared_ptr<Shape>> shapeCollection;
    
    
    
};

#endif /* Collection_h */

