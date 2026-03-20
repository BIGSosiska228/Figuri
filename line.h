#pragma once
#include "Shape.h"
#include <iostream>
#include <cmath>
#include <utility>

class Line : public Shape {
private:
    unsigned int x2;
    unsigned int y2;

public:
    Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) 
        : Shape(x1, y1), x2(x2), y2(y2) {}
    
    Line(const Line& source) 
        : Shape(source), x2(source.x2), y2(source.y2) {}
    
    Shape* clone() const override {
        return new Line(*this);
    }
    
    void Draw() const override {
        std::cout << "Line from (" << x << "," << y 
                  << ") to (" << x2 << "," << y2 << ")" << std::endl;
    }
    
    void setSize(unsigned int size) override {
        double dx = static_cast<double>(x2) - x;
        double dy = static_cast<double>(y2) - y;
        double currentLength = std::sqrt(dx*dx + dy*dy);
        
        if (currentLength > 0) {
            double ratio = static_cast<double>(size) / currentLength;
            x2 = x + static_cast<unsigned int>(dx * ratio);
            y2 = y + static_cast<unsigned int>(dy * ratio);
        }
    }
    
    unsigned int getSize() const override {
        return static_cast<unsigned int>(getLength());
    }
    
    void setEndPoint(unsigned int x, unsigned int y) {
        x2 = x;
        y2 = y;
    }
    
    std::pair<unsigned int, unsigned int> getEndPoint() const {
        return {x2, y2};
    }
    
    double getLength() const {
        double dx = static_cast<double>(x2) - x;
        double dy = static_cast<double>(y2) - y;
        return std::sqrt(dx*dx + dy*dy);
    }
};
