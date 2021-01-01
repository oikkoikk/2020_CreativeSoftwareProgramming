// animal-main.cc
#include <iostream>
#include <vector>
#include <string>
#include "animal.h"

int main()
{
    char command;
    std::string name;
    int age;
    int numStripes;
    std::string favoriteToy;
    std::vector<Animal *> animals;

    std::cin >> command;

    while (command != '0')
    {
        if (command == 'z')
        {
            std::cin >> name >> age >> numStripes;
            animals.push_back(new Zebra(name, age, numStripes));
        }
        else if (command == 'c')
        {
            std::cin >> name >> age >> favoriteToy;
            animals.push_back(new Cat(name, age, favoriteToy));
        }

        std::cin >> command;
    }

    for (auto pos : animals)
    {
        pos->printInfo();
        delete pos;
    }
}
