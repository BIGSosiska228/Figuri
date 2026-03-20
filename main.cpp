#include <iostream>
#include <vector>
#include <memory>
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

void demonstratePrototype(const Shape& original) {
    std::cout << "\n--- Демонстрация прототипа ---" << std::endl;
    std::cout << "Оригинал: ";
    original.Draw();
    
    std::unique_ptr<Shape> clone(original.clone());
    std::cout << "Клон: ";
    clone->Draw();
    
    clone->setSize(clone->getSize() * 2);
    std::cout << "Клон после увеличения: ";
    clone->Draw();
}

void demonstratePolymorphism(std::vector<Shape*>& shapes) {
    std::cout << "\n--- Полиморфная работа с фигурами ---" << std::endl;
    
    for (const auto& shape : shapes) {
        shape->Draw();
    }
    
    std::cout << "\nИзменяем размеры фигур:" << std::endl;
    for (auto& shape : shapes) {
        shape->setSize(50);
        shape->Draw();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    Rectangle rect(10, 20, 30, 40);
    Circle circle(50, 60, 25);
    Line line(70, 80, 90, 100);
    
    std::cout << "=== Демонстрация паттерна Прототип ===" << std::endl;
    demonstratePrototype(rect);
    demonstratePrototype(circle);
    demonstratePrototype(line);
    
    std::vector<Shape*> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circle);
    shapes.push_back(&line);
    
    demonstratePolymorphism(shapes);
    
    std::cout << "\n=== Специфические тесты для Line ===" << std::endl;
    Line line2(0, 0, 30, 40);
    std::cout << "Линия: ";
    line2.Draw();
    std::cout << "Длина линии: " << line2.getLength() << std::endl;
    
    line2.setEndPoint(60, 80);
    std::cout << "После изменения конечной точки: ";
    line2.Draw();
    std::cout << "Новая длина: " << line2.getLength() << std::endl;
    
    line2.setSize(100);
    std::cout << "После setSize(100): ";
    line2.Draw();
    std::cout << "Длина: " << line2.getLength() << std::endl;
    
    return 0;
}
