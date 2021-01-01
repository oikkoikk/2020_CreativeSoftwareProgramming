#include <iostream>
#include <vector>
#include <algorithm>

class Person
{
public:
    std::string name;
    int assets;

    Person(const std::string name, int assets)
        : name(name), assets(assets)
    {
    }
};

bool operator==(const Person &lhs, const Person &rhs)
{
    return &lhs == &rhs; //주솟값이 같으면 같은 객체라고 판단
}

class Vehicle
{
public:
    float max_speed, cur_speed;
    int max_passengers;
    std::vector<Person *> passengers;

    Vehicle(float max_speed, int max_passengers)
        : max_speed(max_speed), cur_speed(0), max_passengers(max_passengers)
    {
    }

    void start()
    {
        cur_speed = max_speed;
    }

    void stop()
    {
        cur_speed = 0.f;
    }

    int size() const
    {
        return passengers.size();
    }

    virtual void get_in(Person &person) {}
    virtual void get_off(Person &person) {}
};

class Car : public Vehicle
{
public:
    Person &owner;

    Car(float max_speed, int max_passengers, Person &owner)
        : Vehicle(max_speed, max_passengers), owner(owner)
    {
    }

    void get_in(Person &person)
    {
        bool isOwnerRide = false;

        for (auto passenger : passengers)
        {
            if (*passenger == owner)
            {
                isOwnerRide = true;
                break;
            }
        }
        if ((isOwnerRide || person == owner) && size() < max_passengers)
        {
            passengers.push_back(&person);
        }
    }

    void get_off(Person &person)
    {
        int idx = 0;
        for (; idx < size(); idx++)
        {
            if (*passengers[idx] == person)
            {
                break;
            }
        }

        if (*passengers[idx] == owner)
        {
            passengers.clear();
        }

        else if (idx != size())
        {
            passengers.erase(passengers.begin() + idx);
        }
    }
};

class Bus : public Vehicle
{
public:
    int charge;

    Bus(float max_speed, int max_passengers, int charge)
        : Vehicle(max_speed, max_passengers), charge(charge)
    {
    }

    void start()
    {
        cur_speed = (max_speed / 2.f);
    }

    void get_in(Person &person)
    {
        if (size() < max_passengers && person.assets >= charge)
        {
            person.assets -= charge;
            passengers.push_back(&person);
        }
    }

    void get_in(std::vector<Person *> people)
    {
        for (auto person : people)
        {
            get_in(*person);
        }
    }

    void get_off(Person &person)
    {
        int idx = 0;

        for (; idx < size(); idx++)
        {
            if (*passengers[idx] == person)
            {
                break;
            }
        }

        if (idx != size())
        {
            passengers.erase(passengers.begin() + idx);
        }
    }

    void get_off(std::vector<Person *> people)
    {
        for (auto person : people)
        {
            get_off(*person);
        }
    }
};

class Taxi : public Vehicle
{
public:
    int charge;

    Taxi(float max_speed, int max_passengers, int charge)
        : Vehicle(max_speed, max_passengers), charge(charge)
    {
    }
    //이미 승객이 타고 있으면, 추가로 탈 수 없음! 한번에 타야함
    void get_in(Person &person)
    {
        if (size() == 0 && size() < max_passengers && person.assets >= charge)
        {
            passengers.push_back(&person);
        }
    }
    void get_in(std::vector<Person *> people)
    {
        if (size == 0 && people.size() <= max_passengers)
        {
            bool isOk = true;
            for (auto person : people)
            {
                if (person->assets < charge)
                {
                    isOk = false;
                    break;
                }
            }

            if (isOk)
            {
                for (auto person : people)
                {
                    passengers.push_back(person);
                }
            }
        }
    }
    void get_off(Person &person)
    {
        int idx = 0;

        for (; idx < size(); idx++)
        {
            if (*passengers[idx] == person)
            {
                break;
            }
        }

        if (idx != size())
        {
            passengers[idx]->assets -= charge;
            passengers.erase(passengers.begin() + idx);
        }
    }
    void get_off(std::vector<Person *> people)
    {
        for (auto person : people)
        {
            get_off(*person);
        }
    }
};

int main()
{
    return 0;
}
