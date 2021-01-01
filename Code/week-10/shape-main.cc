#include <iostream>
#include <vector>
#include "shapes.h"

int main()
{
    char command;
    double width, height;
    std::vector<Shape*> arr;

    std::cin >> command;
    while(command != '0')
    {
        std::cin >> width >> height;

        if(command == 'r')
        {
            arr.push_back(new Rectangle(width,height));
        }
        else if(command == 't')
        {
            arr.push_back(new Triangle(width,height));
        }
        else if(command == 'c')
        {
            arr.push_back(new Circle(width,height));
        }
        std::cin >> command;
    }
    for(auto pos : arr)
    {
        std::cout << pos->getArea() << std::endl;
        delete pos;
    }
}
