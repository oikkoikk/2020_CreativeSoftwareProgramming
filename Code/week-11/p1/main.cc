#include <iostream>
#include <string>
#include "number.h"

int main()
{
    std::string command;

    std::cin >> command;

    while (command != "quit")
    {
        if (command == "number")
        {
            Number *number = new Number();
            int num;
            std::cin >> num;

            number->setNumber(num);
            std::cout << "getNumber(): " << number->getNumber() << std::endl;
            delete number;
        }
        else if (command == "square")
        {
            Square *square = new Square();
            int num;
            std::cin >> num;

            square->setNumber(num);
            std::cout << "getNumber(): " << square->getNumber() << std::endl;
            std::cout << "getSquare(): " << square->getSquare() << std::endl;
            delete square;
        }
        else if (command == "cube")
        {
            Cube *cube = new Cube();
            int num;
            std::cin >> num;

            cube->setNumber(num);
            std::cout << "getNumber(): " << cube->getNumber() << std::endl;
            std::cout << "getSquare(): " << cube->getSquare() << std::endl;
            std::cout << "getCube(): " << cube->getCube() << std::endl;
            delete cube;
        }
        std::cin >> command;
    }

    return 0;
}