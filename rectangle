#pragma once
#include "Shape.h"

class Line : public Shape
{
private:
    unsigned int width;

public:
    Line(unsigned int x, unsigned int y, unsigned int w)
        : Shape(x, y)
    {
        width = w;
    }

    Line(const Line& source) : Shape(source)
    {
        width = source.width;
    }

    Shape* clone() override
    {
        return new Line(*this);
    }

    void Draw() override
    {
        std::cout << "Line "
            << x << " "
            << y << " "
            << width << std::endl;
    }
};
