// animal.h
#include <string>
#include <iostream>

class Animal
{
public:
    std::string name;
    int age;

    Animal(std::string name, int age) : name(name), age(age) {}

    virtual void printInfo() = 0;
};

class Zebra : public Animal
{
public:
    int numStripes;

    Zebra(std::string name, int age, int numStripes) : Animal(name, age), numStripes(numStripes) {}

    virtual void printInfo()
    {
        std::cout << "Zebra" << ' ' << this->name << ' ' << this->age << ' ' << this->numStripes << std::endl;
    }
};

class Cat : public Animal
{
public:
    std::string favoriteToy;

    Cat(std::string name, int age, std::string favoriteToy) : Animal(name, age), favoriteToy(favoriteToy) {}
    virtual void printInfo()
    {
        std::cout << "Cat" << ' ' << this->name << ' ' << this->age << ' ' << this->favoriteToy << std::endl;
    }
};
