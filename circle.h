#pragma once
#include "Shape.h"

class Circle : public Shape
{
private:
    unsigned int radius;

public:
    Circle(unsigned int x, unsigned int y, unsigned int r)
        : Shape(x, y)
    {
        radius = r;
    }

    Circle(const Circle& source) : Shape(source)
    {
        radius = source.radius;
    }

    Shape* clone() override
    {
        return new Circle(*this);
    }

    void Draw() override
    {
        std::cout << "Circle "
            << x << " "
            << y << " "
            << radius << std::endl;
    }
};
