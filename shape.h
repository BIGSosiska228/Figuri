#pragma once

class Shape {
protected:
    unsigned int x;
    unsigned int y;

public:
    Shape(unsigned int x, unsigned int y) : x(x), y(y) {}
    Shape(const Shape& source) : x(source.x), y(source.y) {}
    virtual ~Shape() = default;
    
    virtual Shape* clone() const = 0;
    virtual void Draw() const = 0;
    virtual void setSize(unsigned int size) = 0;
    virtual unsigned int getSize() const = 0;
    
    unsigned int getX() const { return x; }
    unsigned int getY() const { return y; }
    void setPosition(unsigned int newX, unsigned int newY) { x = newX; y = newY; }
};
