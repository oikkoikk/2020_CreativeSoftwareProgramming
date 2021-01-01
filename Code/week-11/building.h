#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <vector>
#include <set>

#include "college.h"
#include "user.h"
#include "utility.h"

class Building
{
public:
    Building(const std::string &name, size_t id, College &college, size_t size)
        : name(name), id(id), college(college), rooms(size)
    {
    }

    std::string getName() const
    {
        return name;
    }

    size_t getId() const
    {
        return id;
    }

    College &getCollege() const
    {
        return college;
    }

    bool isEmployExist()
    {
        bool flag = false;

        for (auto room : rooms)
        {
            if (!room.empty())
            {
                for (auto user : room)
                {
                    if (dynamic_cast<Employee *>(user))
                    //to confirm that user is Employee!
                    {
                        flag = true;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
        }
        return flag;
    }

    bool isProfExist(std::set<User *> &room)
    {
        if (!room.empty())
        {
            for (auto user : room)
            {
                if (dynamic_cast<Professor *>(user))
                //to confirm that user is Professor!
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isProfFull()
    {
        bool flag = false;
        size_t cnt = 0;

        for (auto room : rooms)
        {
            if (!room.empty())
            {
                for (auto user : room)
                {
                    if (dynamic_cast<Professor *>(user))
                    //to confirm that user is Professor!
                    {
                        cnt++;
                    }
                }
                if (cnt >= rooms.size())
                {
                    flag = true;
                    break;
                }
            }
        }

        return flag;
    }

    bool enter(User *user)
    {
        if (dynamic_cast<Employee *>(user))
        //if user is Employee
        {
            if (isEmployExist())
            {
                return false;
            }
            else
            {
                std::vector<std::set<User *>>::iterator room = util::select_randomly<std::vector<std::set<User *>>::iterator>(rooms.begin(), rooms.end());
                //random iterator between(begin, end-1)
                std::cout << std::distance(rooms.begin(), room) + 1 << std::endl;
                //print room number(start with 1)
                (*room).insert(user);
                return true;
            }
        }
        else if (dynamic_cast<Professor *>(user))
        //if user is Professor
        {
            bool flag = false;

            if (isProfFull())
            {
                return false;
            }

            while (!flag)
            {
                std::vector<std::set<User *>>::iterator room = util::select_randomly<std::vector<std::set<User *>>::iterator>(rooms.begin(), rooms.end());
                //random iterator between(begin, end-1)
                if (!isProfExist(*room))
                {
                    flag = true;
                    std::cout << std::distance(rooms.begin(), room) + 1 << std::endl;
                    //print room number(start with 1)
                    (*room).insert(user);
                    return true;
                }
            }
        }
        else if (dynamic_cast<Student *>(user))
        {
            std::vector<std::set<User *>>::iterator room = util::select_randomly<std::vector<std::set<User *>>::iterator>(rooms.begin(), rooms.end());
            //random iterator between(begin, end-1)
            Student *stud = dynamic_cast<Student *>(user);

            if (stud->getCollege().getCollegeName() == this->getCollege().getCollegeName())
            {
                std::cout << std::distance(rooms.begin(), room) + 1 << std::endl;
                //print room number(start with 1)
                (*room).insert(user);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool exit(User *user)
    {
        for (auto &room : rooms)
        //& for revision!
        {
            if (!room.empty())
            {
                for (auto pos = room.begin(); pos != room.end(); pos++)
                {
                    if ((*pos)->getId() == user->getId())
                    {
                        room.erase(pos);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool findUser(size_t userID) const
    {
        for (auto room : rooms)
        {
            for (auto user : room)
            {
                if (user->getId() == userID)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool clean()
    {
        for (auto &room : rooms)
        //& for revision!
        {
            if (!room.empty())
            {
                for (auto pos = room.begin(); pos != room.end();)
                {
                    if (dynamic_cast<Employee *>(*pos))
                    {
                        pos++;
                        continue;
                    }
                    pos = room.erase(pos);
                }
            }
        }
        return true;
    }

    bool attendance(size_t id)
    {
        bool isProfInRoom = false;
        int roomIdx = -1;

        for (size_t room = 0; room < rooms.size(); room++)
        {
            for (auto pos = rooms[room].begin(); pos != rooms[room].end(); pos++)
            {
                if ((*pos)->getId() == id)
                {
                    roomIdx = room;
                    isProfInRoom = true;
                    goto A;
                }
            }
        }
    A:
        if ((roomIdx >= 0 && isProfInRoom == true && rooms[roomIdx].size() == 1) || (!isProfInRoom))
        {
            return false;
        }
        else
        {
            for (auto student : rooms[roomIdx])
            {
                if (dynamic_cast<Professor *>(student) || dynamic_cast<Employee *>(student))
                {
                    continue;
                }
                std::cout << student->getId() << std::endl;
                return true;
            }
        }
    }

    size_t total() const
    {
        size_t cnt = 0;

        for (auto room : rooms)
        {
            cnt += room.size();
        }

        return cnt;
    }

    void all() const
    {
        for (auto room : rooms)
        {
            for (auto user : room)
            {
                std::cout << user->getName() << std::endl;
            }
        }
    }

private:
    std::string name;
    size_t id;
    College &college;

    std::vector<std::set<User *>> rooms;
};

#endif
