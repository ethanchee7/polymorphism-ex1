//
//  Shape.h
//  hw4
//
//  Created by Ethan Chee on 2/3/18.
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#ifndef Shape_h
#define Shape_h

#include <utility>
#include <vector>

/**
 * This class serves as a abstract class representing a shape
 */
class Shape
{
public:
    
    /**
     * Constructor for our Shape object, initializing our shapeCenter to xPos,yPos, and shapeCenter to size
     * @param xPos X position that our shape will have it's "center" at
     * @param yPos Y position that our shape will have it's "center" at
     * @param size Size that our shape will be
     */
    Shape (int xPos, int yPos, int size);
    
    
    /**
     * Pure virtual function represeting how a shape add's it's coordinates to the shapeCoordinate vector (will be overridden)
     */
    virtual void setStars() = 0;
    
    
    /**
     * Move our Shape object by a distance x and distance y
     * @param distX How much we want to move our shape by on the X axis
     * @param distY How much we want to move our shape by on the Y axis
     */
    void moveBy (int distX, int distY);
    
    
    /**
     * Set our Shape object to a certain size
     * @param newSize The size we want to set our Shape object to
     */
    void setSize(int newSize);
    
    
    /**
     * Gives us the value for our std::pair corresponding to our shape's center
     * @return Member variable that is our shape's center (std::pair)
     */
    std::pair<int,int> getCenter() const;
    
    
    /**
     * Gives us the value for our int corresponding to our shape's size
     * @return Member variable that is our shape's size
     */
    int getSize() const;
    
    
    /**
     * Give us the value for our vector storing all of a shape's coordinates (std::pair)
     * @return Member variable of vectors that store std::pairs representing a shape's coordinates
     */
    std::vector<std::pair<int, int>> getCoordinates() const;
    
    
    /**
     * Adds a std::pair into our vector shapeCoordinates (that represents all of a shape's coordinates)
     * @param point The std::pair we want to push back into our shapeCoordinates vector
     */
    void addPoint(const std::pair<int,int>& point);
    
    
    /**
     * Clear all the coordinates stored in a shapeCoordinates vector
     */
    void clearStars();
    
    /**
     * The virtual destructor for our Shape base class
     */
    virtual ~Shape() = default;
    
private:
    // Pair representing a shape's "center"
    std::pair<int,int> shapeCenter;
    // Integer representing the a shape's size
    int shapeSize;
    // Vector storing all the pairs that represent a shape's coordinates
    std::vector<std::pair<int,int>> shapeCoordinates;
    
};

#endif /* Shape_h */

