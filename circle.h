#pragma once
#include "Shape.h"
#include <iostream>

class Circle : public Shape {
private:
    unsigned int radius;

public:
    Circle(unsigned int x, unsigned int y, unsigned int r) 
        : Shape(x, y), radius(r) {}
    
    Circle(const Circle& source) 
        : Shape(source), radius(source.radius) {}
    
    Shape* clone() const override {
        return new Circle(*this);
    }
    
    void Draw() const override {
        std::cout << "Circle at (" << x << "," << y 
                  << ") radius " << radius << std::endl;
    }
    
    void setSize(unsigned int size) override {
        radius = size;
    }
    
    unsigned int getSize() const override {
        return radius;
    }
    
    unsigned int getRadius() const { return radius; }
};
