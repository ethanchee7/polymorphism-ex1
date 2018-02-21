//
//  Graphics.cpp
//  hw4
//
//  Created by Ethan Chee on 2/3/18.
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Collection.h"
#include "Shape.h"
#include "Square.h"
#include "Diamond.h"


/**
 * Constructor of a Collection object, will collect our different shapes
 * @param lowX Lowest x value that can be called on our grid
 * @param highX Highest x value that can be called on our grid
 * @param lowY Lowest y value that can be called on our grid
 * @param highY Highest y value that can be called on our grid
 */
Collection::Collection(int lowX, int highX, int lowY, int highY): xBoundLow(std::move(lowX)), xBoundHigh (std::move(highX)), yBoundLow(std::move(lowY)), yBoundHigh (std::move(highY)) {}

/**
 * Adds a shape to our collection class
 * @param s Shared pointer to a shape that we will add to our collection of shapes
 */
void Collection::addShape(const std::shared_ptr<Shape>& s)
{
    // Push back shape object into our vector of shapes
    shapeCollection.push_back(s);
}

/**
 * Displays our grid as well as any shapes that are on it with the '*' character
 */
void Collection::display() const
{
    // Create pair we want to test in checkStar() function
    std::pair<int, int> test;
    // Go through the entire x values
    for (int j = xBoundLow; j <= xBoundHigh; ++j)
    {
        // Go through all y values for each ex value
        for (int i = yBoundLow; i <= yBoundHigh; ++i)
        {
            // Make a pair from our current x and y value
            test = std::make_pair(i,j);
            // If checkStar returns true (there is a coordinate that matches with our test pair)
            if (checkStar(test))
            {
                // Print out a star on our grid
                std::cout << "*";
            }
            // Otherwise we just print out a dash
            else
            {
                // Print out a dash on our grid
                std::cout << "-";
            }
        }
        // Create a new line after each row of our grid
        std::cout << std::endl;
    }
    
    // Print out a line that shows what type of shapes we have in our grid
    std::cout << "shapes are: ";
    // For loop that ranges through all of our shape objects in shapeCollection
    for (const auto& shapePointer: shapeCollection)
    {
        // Try and cast our shapePointer to a square shared_ptr
        std::shared_ptr<Square> square = std::dynamic_pointer_cast<Square>(shapePointer);
        // If we haven't reached the end of our shapeCollection vector
        if (shapeCollection.back() != shapePointer)
        {
            // If the dynamic cast to a Square shared_ptr casted successfully
            if (square)
            {
                // Print out that we have a square, with a comma
                std::cout << "square, ";
            }
            // If our dynamic cast to a Square shared_ptr failed
            else
            {
                // Print out that we have a diamond with a comma
                std::cout << "diamond, ";
            }
        }
        // Otherwise, we've reached the end of our shapeCollection vector
        else
        {
            // If the dynamic cast to a Square shared_ptr casted successfully
            if (square)
            {
                // Print out that we have a square without a comma
                std::cout << "square ";
            }
            // If our dynamic cast to a Square shared_ptr failed
            else
            {
                // Print out that we have a diamond without a comma
                std::cout << "diamond ";
            }
        }
    }
    
}

/**
 * Lets us know how many total stars we have in our grid
 * @return Returns the number of stars in our grid
 */
size_t Collection::totalStars() const
{
    // Create a counter for our total number of stars
    size_t starCounter = 0;
    // Create a pair that we will use to cycle through our entire grid
    std::pair<int,int> starChecker;
    // For loop going through each of the rows in our grid
    for (int i = xBoundLow; i <= xBoundHigh; ++i)
    {
        // For loop going through each of the columns in our grid
        for (int j = yBoundLow; j <= yBoundHigh; ++j)
        {
            // Assign our starChecker to a pair with (i,j)
            starChecker = std::make_pair(i,j);
            // If our starChecker pair returns true
            if (checkStar(starChecker))
            {
                //Increase starCounter by 1
                ++starCounter;
            }
        }
    }
    // Return our starCounter after going through our entire grid
    return starCounter;
}

/**
 * Move all the shapes a distance x and a distance y
 * @param distX How much we want to move all shapes by on the X axis
 * @param distY How much we want to move all shapes by on the Y axis
 */
void Collection::moveBy (int distX, int distY)
{
    // For loop ranging through each shape in our shapeCollection vector
    for (auto shape: shapeCollection)
    {
        // For each shape, we dereference pointer to Shape and call the moveBy function for a distance of X and Y
        shape->moveBy(distX, distY);
    }
}

/**
 * Set all shapes to a certain size
 * @param newSize The size we want to set all of our shapes in Collection to
 */
void Collection::setSize (int newSize)
{
    // For loop ranging through each shape in our shapeCollection vector
    for (auto shape: shapeCollection)
    {
        // For each shape, we dereference pointer to Shape and call the setSize function with newSize
        shape->setSize(newSize);
    }
}

/**
 * Check to see if a pair matches with a coordinate in any of shapes (therefore being a '*')
 * @param coordinate A pair that we want to check against all the pairs in each of our Shape objects
 * @return True if there is a pair matching with coordinate, otherwise returns false
 */
bool Collection::checkStar (const std::pair<int, int>& coordinate) const
{
    // For loop ranging through each shape in our shapeCollection vector
    for (auto shape : shapeCollection)
    {
        // For loop ranging through each vector of pairs (coordinates) for each Shape object
        for (auto shapecoord : shape->getCoordinates())
        {
            // If shapecoord matches with our coordinate we pass into the checkStar() function
            if (shapecoord == coordinate)
            {
                // Then there is a shape with a pair that matches coordinate, return true
                return true;
            }
        }
    }
    // Otherwise there is no match, return false
    return false;
}



/**
 * Constructor for our Shape object, initializing our shapeCenter to xPos,yPos, and shapeCenter to size
 * @param xPos X position that our shape will have it's "center" at
 * @param yPos Y position that our shape will have it's "center" at
 * @param size Size that our shape will be
 */
Shape::Shape (int xPos, int yPos, int size): shapeCenter(std::move(xPos),std::move(yPos)), shapeSize(std::move(size)) {}

/**
 * Move our Shape object by a distance x and distance y
 * @param distX How much we want to move our shape by on the X axis
 * @param distY How much we want to move our shape by on the Y axis
 */
void Shape::moveBy(int distX, int distY)
{
    // Update value of shapeCenter by adding distX to the first component and distY to the second component
    shapeCenter = std::make_pair(shapeCenter.first + distX, shapeCenter.second + distY);
    // Add coordinates (std::pairs) for this new shape to our shapeCoordinates vector
    setStars();
}

/**
 * Set our Shape object to a certain size
 * @param newSize The size we want to set our Shape object to
 */
void Shape::setSize(int newSize)
{
    // Update value of shapeSize to our newSize we passed in as an argument
    shapeSize = newSize;
    // Add coordinates (std::pairs) for this new shape to our shapeCoordinates vector
    setStars();
}

/**
 * Gives us the value for our std::pair corresponding to our shape's center
 * @return Member variable that is our shape's center (std::pair)
 */
std::pair<int,int> Shape::getCenter() const
{
    // Return the std::pair that is shapeCenter
    return shapeCenter;
}

/**
 * Gives us the value for our int corresponding to our shape's size
 * @return Member variable that is our shape's size
 */
int Shape::getSize() const
{
    // Return the int that is shapeSize
    return shapeSize;
}


/**
 * Give us the value for our vector storing all of a shape's coordinates (std::pair)
 * @return Member variable of vectors that store std::pairs representing a shape's coordinates
 */
std::vector<std::pair<int, int>> Shape::getCoordinates() const
{
    // Return the vector that is shapeCoordinates
    return shapeCoordinates;
}

/**
 * Adds a std::pair into our vector shapeCoordinates (that represents all of a shape's coordinates)
 * @param point The std::pair we want to push back into our shapeCoordinates vector
 */
void Shape::addPoint(const std::pair<int,int>& point)
{
    // Push back point into shapeCoordinates
    shapeCoordinates.push_back(point);
}

/**
 * Clear all the coordinates stored in a shapeCoordinates vector
 */
void Shape::clearStars()
{
    //Clear the contents of shapeCoordinates
    shapeCoordinates.clear();
}


/**
 * Constructor for our Square object, that derives from the Shape class (and constructs it)
 * @param xPos X position that our shape will have it's "center" at
 * @param yPos Y position that our shape will have it's "center" at
 * @param size Size that our shape will be
 */
Square::Square (int xPos, int yPos, int size): Shape(std::move(xPos), std::move(yPos), std::move(size))
{
    // When our Square object is constructed, we want to add all of it's std::pairs to our shapeCoordinates vector
    setStars();
}


/**
 * Adds all of a Square object's coordinates(std::pair) to our shapeCoordinates vector
 */
void Square::setStars()
{
    // Clear the vector that contains all the current Square coordinates
    clearStars();
    // For loop ranging us through the square's rows
    for (int i = getCenter().first; i < (getCenter().first + getSize()); ++i)
    {
        // For loop ranging us through the square's columns
        for (int j = getCenter().second; j < (getCenter().second + getSize()); ++j)
        {
            // Create a std::pair representing our current (i,j) in our Square
            std::pair<int,int> point(i,j);
            // Adds the point to our shapeCoordinates
            addPoint(point);
        }
        
    }
    
}

/**
 * Constructor for our Diamond object, that derives from the Shape class (and constructs it)
 * @param xPos X position that our shape will have it's "center" at
 * @param yPos Y position that our shape will have it's "center" at
 * @param size Size that our shape will be
 */
Diamond::Diamond (int xPos, int yPos, int size):Shape(std::move(xPos), std::move(yPos), std::move(size))
{
    // When our Diamond object is constructed, we want to add all of it's std::pairs to our shapeCoordinates vector
    setStars();
}

/**
 * Adds all of a Diamond object's coordinates(std::pair) to our shapeCoordinates vector
 */
void Diamond::setStars()
{
    // Clear the vector that contains all the current Diamond coordinates
    clearStars();
    // Create an integer variable that represents a diamond's width (widest length in a diamond)
    int diamondWidth = 2 * getSize() - 1;
    //For loop ranging us through the y-value that is the center of the diamond, building up until the top of the diamond
    for (int j = getCenter().second; j > getCenter().second - getSize(); --j)
    {
        // For loop ranging us through the x-value of each row in our diamond, starting leftmost and building to the right
        for (int i = getCenter().first - diamondWidth/2; i <= getCenter().first + diamondWidth/2; ++i)
        {
            // Create a pair representing our current (i,j) in our Diamond
            std::pair<int,int> point (i,j);
            // Add the point to our shapeCoordinates vector
            addPoint(point);
        }
        // Decrease the width by 2 (we lose two stars each row we go up)
        diamondWidth -= 2;
        
    }
    
    // Reset the diamondWidth to the original value
    diamondWidth = 2 * getSize() - 1;
    //For loop ranging us through the y-value that is the center of the diamond, building down until the bottom of the diamond
    for (int j = getCenter().second; j < getCenter().second + getSize(); ++j)
    {
        // For loop ranging us through the x-value of each row in our diamond, starting leftmost and building to the right
        for (int i = getCenter().first - diamondWidth/2; i <= getCenter().first + diamondWidth/2; ++i)
        {
            // Create a pair representing our current (i,j) in our Diamond
            std::pair<int,int> point (i,j);
            // Add the point to our shapeCoordinates vector
            addPoint(point);
        }
        // Decrease the width by 2 (we lose two stars each row we go up)
        diamondWidth -= 2;
        
    }
    
}













