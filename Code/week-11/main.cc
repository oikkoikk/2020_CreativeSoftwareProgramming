#include <iostream>
#include <vector>
#include <unordered_map>

#include "college.h"
#include "user.h"
#include "building.h"

int main()
{
    std::unordered_map<std::string, College *> colleges;
    std::unordered_map<size_t, Building *> buildings;
    std::unordered_map<size_t, User *> users;

    size_t N, B, U, C;

    std::cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        std::string temp;

        std::cin >> temp;
        auto ret = colleges.insert({temp, new College(temp)});
        if (!ret.second) //ret => {iterator, value or false}
        {
            std::cout << "Name duplicated error" << std::endl;
        }
    }

    std::cin >> B;
    for (size_t i = 0; i < B; i++)
    {
        std::string building_name, college_name;
        size_t building_id, number_of_rooms;

        std::cin >> building_name >> building_id >> college_name >> number_of_rooms;

        if (colleges.find(college_name) == colleges.end())
        {
            std::cout << "College not exist error" << std::endl;
            continue;
        }
        auto ret = buildings.insert({building_id, new Building(building_name, building_id, *colleges[college_name], number_of_rooms)});
        if (!ret.second) //ret => {iterator, value or false}
        {
            std::cout << "Id duplicated error" << std::endl;
        }
    }

    std::cin >> U;
    for (size_t i = 0; i < U; i++)
    {
        std::string user_type, user_name, college_name;
        size_t user_id;

        //구현 남음!!!!!!!!!!!!!!!!!!!!!!!!!!
        std::cin >> user_type >> user_name >> user_id >> college_name;
        if (colleges.find(college_name) == colleges.end())
        {
            std::cout << "College not exist error" << std::endl;
            continue;
        }

        if (user_type == "student")
        {
            auto ret = users.insert({user_id, new Student(user_name, user_id, *colleges[college_name])});
            if (!ret.second) //ret => {iterator, value or false}
            {
                std::cout << "Id duplicated error" << std::endl;
            }
        }
        else if (user_type == "professor")
        {
            auto ret = users.insert({user_id, new Professor(user_name, user_id, *colleges[college_name])});
            if (!ret.second) //ret => {iterator, value or false}
            {
                std::cout << "Id duplicated error" << std::endl;
            }
        }
        else if (user_type == "employee")
        {
            auto ret = users.insert({user_id, new Employee(user_name, user_id, *colleges[college_name])});
            if (!ret.second) //ret => {iterator, value or false}
            {
                std::cout << "Id duplicated error" << std::endl;
            }
        }
    }

    std::cin >> C;
    for (size_t i = 0; i < C; i++)
    {
        std::string command;

        std::cin >> command;
        if (command == "enter")
        {
            size_t user_ID, building_ID;

            std::cin >> user_ID >> building_ID;

            if (users.find(user_ID) == users.end() || buildings.find(building_ID) == buildings.end())
            {
                std::cout << "Not enter error" << std::endl;
            }
            else if (!buildings[building_ID]->enter(users[user_ID]))
            {
                //room number는 building.h의 enter함수에서 출력!
                std::cout << "Not enter error" << std::endl;
            }
        }

        else if (command == "exit")
        {
            size_t user_ID, building_ID;

            std::cin >> user_ID >> building_ID;

            buildings[building_ID]->exit(users[user_ID]);
        }

        else if (command == "total")
        {
            size_t building_ID;

            std::cin >> building_ID;

            std::cout << buildings[building_ID]->total() << std::endl;
        }

        else if (command == "clean")
        {
            size_t user_ID;
            bool isEmpInBuilding = false;

            std::cin >> user_ID;

            if (dynamic_cast<Employee *>(users[user_ID]))
            {
                for (auto &building : buildings)
                {
                    if (building.second->findUser(user_ID))
                    {
                        isEmpInBuilding = true;
                        building.second->clean();
                    }
                }
                if (!isEmpInBuilding)
                {
                    std::cout << "Nothing to clean error" << std::endl;
                }
            }
            else
            {
                std::cout << "Permission error" << std::endl;
            }
        }

        else if (command == "attendance")
        {
            size_t user_ID;
            bool isProfInRoom = false;
            bool flag = false;

            std::cin >> user_ID;

            if (dynamic_cast<Professor *>(users[user_ID]))
            {
                for (auto &building : buildings)
                {
                    if (building.second->findUser(user_ID))
                    {
                        isProfInRoom = true;
                        flag = building.second->attendance(user_ID);
                        if (!flag)
                        {
                            goto B;
                        }
                    }
                }
                if (!isProfInRoom)
                {
                B:
                    std::cout << "No students error" << std::endl;
                }
            }
            else
            {
                std::cout << "Permission error" << std::endl;
            }
        }

        else if (command == "where")
        {
            size_t user_ID;
            bool flag = false;

            std::cin >> user_ID;

            for (auto building : buildings)
            {
                if ((building.second->findUser(user_ID)))
                {
                    flag = true;
                    std::cout << building.second->getName() << std::endl;
                    break;
                }
            }
            if (!flag)
            {
                std::cout << 0 << std::endl;
            }
        }

        else if (command == "all")
        {
            size_t building_ID;

            std::cin >> building_ID;

            buildings[building_ID]->all();
        }
    }
    for (auto &college : colleges)
    {
        delete college.second;
    }
    for (auto &building : buildings)
    {
        delete building.second;
    }
    for (auto &user : users)
    {
        delete user.second;
    }

    return 0;
}
