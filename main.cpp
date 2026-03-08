#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

int main()
{
    Shape* rect = new Rectangle(10, 20, 50, 40);
    Shape* copyRect = rect->clone();

    rect->Draw();
    copyRect->Draw();

    return 0;
}
