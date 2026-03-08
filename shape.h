#pragma once
#include <iostream>

class Shape
{
protected:
    unsigned int x;
    unsigned int y;

public:
    Shape(unsigned int x = 0, unsigned int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    Shape(const Shape& source)
    {
        this->x = source.x;
        this->y = source.y;
    }

    virtual Shape* clone() = 0;

    virtual void Draw() = 0;
};
