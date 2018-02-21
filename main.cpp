//
//  main.cpp
//  hw4
//
//  Created by Ethan Chee on 2/3/18.
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#include "Shape.h"
#include "Square.h"
#include "Diamond.h"
#include "Collection.h"
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<Shape> sp1 = std::make_shared<Square>(1, 2, 2); // top left at (1,2), size 2x2
    std::shared_ptr<Shape> sp2 = std::make_shared<Diamond>(5, 8, 3); // centre at (5,8), size 3
    std::shared_ptr<Shape> sp3 = std::make_shared<Square>(-1, -1, 4); // top left at (-1,-1), size 4
    Collection c(0, 10, 0, 10); // x from 0 to 10, y 0 to 10, inclusive
    
    // add the shapes
    c.addShape(sp1);
    c.addShape(sp2);
    c.addShape(sp3);
    
    // display the shapes
    c.display();
    std::cout << std::endl;
    // check total number of stars on display
    std::cout << "Total visible stars: " << c.totalStars() << std::endl;
    
    // add another square
    c.addShape(std::make_shared<Square>(5, 5, 1)); // top left at (5,5), size 1x1
    // change all shapes to have size 2 including the newly added square
    c.setSize(2);
    // move sp3 right 2 and down by 4
    sp3->moveBy(2, 4);
    // move all shapes left 1
    c.moveBy(-1, 0);
    
    // display the shapes
    c.display();
    std::cout << std::endl;
    // check total number of stars on display
    std::cout << "Total visible stars: " << c.totalStars() << std::endl;
    
    std::cin.get();
    
    return 0;
}
