#include <iostream>
#include "../include/array.h"
#include "../include/trapezoid.h"
#include "../include/rhombus.h"
#include "../include/pentagon.h"

int main() {
    std::cout << "Тестируем Array с фигурами..." << std::endl;
    
    Array array(5);
    
    Trapezoid* trap = new Trapezoid();
    std::cout << "Введите 4 точки трапеции: ";
    std::cin >> *trap;
    array.addFigure(trap);

    Rhombus* rhombus = new Rhombus();
    std::cout << "Введите 4 точки ромба: ";
    std::cin >> *rhombus;
    array.addFigure(rhombus);

    Pentagon* pentagon = new Pentagon();
    std::cout << "Введите 5 точек пятиугольника: ";
    std::cin >> *pentagon;
    array.addFigure(pentagon);
    
    std::cout << "\nВсе фигуры:" << std::endl;
    array.printAll();

    std::cout << "\nОбщая площадь: " << array.areaOfAllFigures() << std::endl;
    
    std::cout << "\nУдаляем фигуру по индексу 1..." << std::endl;
    array.deleteFigure(1);

    std::cout << "\nОставшиеся фигуры:" << std::endl;
    array.printAll();

    std::cout << "Общая площадь после удаления: " << array.areaOfAllFigures() << std::endl;

    return 0;
}
