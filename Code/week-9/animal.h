#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <vector>

#include "food.h"

class Animal
{
public:
    int point;
    std::vector<Food> stomach;

    Animal(int point) : point(point) {}

    virtual void eat(Food &food){};
    virtual Food pop(){};
    virtual void fight(Animal &animal){};
};

class Lion : public Animal
{
public:
    Lion(int point)
        : Animal(point * 3)
    {
    }

    void eat(Food &food)
    {
        stomach.push_back(food);
        this->point += food.point;
    }

    Food pop()
    {
        if (!stomach.empty())
        //stomach가 비어있으면 실행 안되도록!
        {
            int idx = 0;
            int minScore = stomach[0].point;
            for (int i = 1; i < stomach.size(); i++)
            {
                if (stomach[i].point < minScore)
                {
                    idx = i;
                    minScore = stomach[i].point;
                }
            }
            stomach[idx].point -= 10;
            Food food = stomach[idx];
            stomach.erase(stomach.begin() + idx);
            return food;
        }
        else
        {
            return Food(0);
        }
    }

    void fight(Animal &animal)
    {
        //상대가 이미 죽었는지 체크
        if (animal.point > 0)
        {
            if (animal.point >= (this->point / 2))
            {
                animal.point -= (this->point / 2);
            }
            else
            {
                animal.point = 0;
            }

            if (animal.point == 0)
            {
                this->point += 10;
            }
            else
            {
                this->point += 5;
            }
        }
    }

    void shout()
    {
        if ((!stomach.empty()) && this->point > 0)
        {
            if (this->point >= 5)
            {
                this->point -= 5;
            }
            else
            {
                this->point = 0;
            }
            int idx = 0;
            int maxScore = stomach[0].point;
            for (int i = 1; i < stomach.size(); i++)
            {
                if (stomach[i].point > maxScore)
                {
                    idx = i;
                    maxScore = stomach[i].point;
                }
            }
            stomach.erase(stomach.begin() + idx);
        }
    }
};

class Rabbit : public Animal
{
public:
    Rabbit(int point)
        : Animal(point * 2)
    {
    }
    void eat(Food &food)
    {
        stomach.push_back(food);
        this->point += food.point;
    }
    Food pop()
    {
        if (!stomach.empty())
        //stomach가 비어있으면 실행 안되도록!
        {
            int idx = 0;
            int maxScore = stomach[0].point;
            for (int i = 1; i < stomach.size(); i++)
            {
                if (stomach[i].point > maxScore)
                {
                    idx = i;
                    maxScore = stomach[i].point;
                }
            }
            stomach[idx].point -= 10;
            Food food = stomach[idx];
            stomach.erase(stomach.begin() + idx);
            return food;
        }
        else
        {
            return Food(0);
        }
    }
    void fight(Animal &animal)
    {
        //내 체력 & 상대 체력 체크
        if (this->point > 0 && animal.point > 0)
        {
            if (animal.point >= (this->point / 2))
            {
                animal.point -= (this->point / 2);
            }
            else
            {
                animal.point = 0;
            }
            if (this->point >= 5)
            {
                this->point -= 5;
            }
            else
            {
                this->point = 0;
            }
        }
    }
    void run()
    {
        if ((!stomach.empty()) && this->point > 0)
        {
            if (this->point >= 10)
            {
                this->point -= 10;
            }
            else
            {
                this->point = 0;
            }
            int idx = 0;
            int minScore = stomach[0].point;
            for (int i = 1; i < stomach.size(); i++)
            {
                if (stomach[i].point < minScore)
                {
                    idx = i;
                    minScore = stomach[i].point;
                }
            }
            stomach.erase(stomach.begin() + idx);
        }
    }
};

class Human : public Animal
{
private:
    bool isSlept = false;

public:
    Human(int point)
        : Animal(point)
    {
    }
    void eat(Food &food)
    {
        stomach.push_back(food);
        if (isSlept)
        {
            stomach.back().point *= 2;
            isSlept = false;
        }
        this->point += stomach.back().point;
    }
    Food pop()
    {
        if (!stomach.empty())
        //stomach가 비어있으면 실행 안되도록!
        {
            Food food = stomach.back();
            stomach.pop_back();
            return food;
        }
        else
        {
            return Food(0);
        }
    }
    void fight(Animal &animal)
    {
        //내 stomach & 상대 체력 체크
        if (animal.point > 0)
        {
            if (!stomach.empty())
            {
                if (animal.point >= (this->point / 2))
                {
                    animal.point -= (this->point / 2);
                }
                else
                {
                    animal.point = 0;
                }
                stomach.erase(stomach.begin());
            }
            else
            {
                if (animal.point >= (this->point / 2))
                {
                    animal.point -= (this->point / 2);
                }
                else
                {
                    animal.point = 0;
                }
                this->point = 0;
            }
        }
    }
    void sleep()
    {
        if (this->point >= stomach.size())
        {
            this->point -= stomach.size();
            isSlept = true;
        }
        else
        {
            this->point = 0;
            isSlept = true;
        }
    }
};

#endif
