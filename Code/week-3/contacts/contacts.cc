#include "contacts.h"

bool contacts_t::add(student_t student)
{
    // TODO:
    // create student with given information and add to students
    // return true if add success else false
    // Students with duplicate IDs must not exist.
    long long pos = -1;
    long long flag = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (student.id == students[i].id)
        {
            flag = i;
            break;
        }
        if (students[i].id == -1)
        {
            pos = i;
            break;
        }
    }

    if (flag >= 0)
    {
        return false;
    }
    else if (pos >= 0)
    {
        students[pos].id = student.id;
        students[pos].mail = student.mail;
        students[pos].name = student.name;
        students[pos].phone = student.phone;
    }

    return true;
}

bool contacts_t::add(int id, std::string name)
{
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.

    long long pos = -1;
    long long flag = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (id == students[i].id)
        {
            flag = i;
            break;
        }
        if (students[i].id == -1)
        {
            pos = i;
            break;
        }
    }

    if (flag >= 0)
    {
        return false;
    }
    else if (pos >= 0)
    {
        students[pos].id = id;
        students[pos].mail = "";
        students[pos].name = name;
        students[pos].phone = "";
    }

    return true;
}

bool contacts_t::add(int id, std::string name, std::string phone)
{
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.
    long long pos = -1;
    long long flag = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (id == students[i].id)
        {
            flag = i;
            break;
        }
        if (students[i].id == -1)
        {
            pos = i;
            break;
        }
    }

    if (flag >= 0)
    {
        return false;
    }
    else if (pos >= 0)
    {
        students[pos].id = id;
        students[pos].mail = "";
        students[pos].name = name;
        students[pos].phone = phone;
    }

    return true;
}

bool contacts_t::add(int id, std::string name, std::string phone, std::string mail)
{
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.
    long long pos = -1;
    long long flag = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (id == students[i].id)
        {
            flag = i;
            break;
        }
        if (students[i].id == -1)
        {
            pos = i;
            break;
        }
    }

    if (flag >= 0)
    {
        return false;
    }
    else if (pos >= 0)
    {
        students[pos].id = id;
        students[pos].mail = mail;
        students[pos].name = name;
        students[pos].phone = phone;
    }

    return true;
}

bool contacts_t::remove(int id)
{
    // TODO:
    // remove student which match given id
    // return true after remove If can't find a student return false
    long long pos = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (students[i].id == id)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return false;
    else if (pos >= 0)
    {
        students[pos].id = -1;
        students[pos].mail = "";
        students[pos].name = "";
        students[pos].phone = "";
    }
    return true;
}

bool contacts_t::update(int id, std::string name, std::string phone, std::string mail)
{
    // TODO:
    // Finds the student with the given ID and
    // updates the information to the given values.
    // return true after update else false
    long long pos = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (students[i].id == id)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return false;
    else if (pos >= 0)
    {
        students[pos].mail = mail;
        students[pos].name = name;
        students[pos].phone = phone;
    }
    return true;
}

student_t contacts_t::find(int id)
{
    // TODO:
    // return student which match given id
    // else, return {};
    long long pos = -1;
    for (size_t i = 0; i < m_size; i++)
    {
        if (students[i].id == id)
        {
            pos = i;
            break;
        }
    }
    if (pos >= 0)
        return students[pos];
    else
    {
        return {};
    }
}

size_t contacts_t::size()
{
    // TODO:
    // return number of students in contacts
    size_t pos = 0;
    for (size_t i = 0; i < m_size; i++)
    {
        if (students[i].id != -1)
        {
            pos++;
        }
    }
    return pos;
}