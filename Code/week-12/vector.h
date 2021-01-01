//vector.h
#include <iostream>

template <typename T>
class Vector
{
public:
    class iterator
    {
    public:
        iterator() : pointer(nullptr) {}
        iterator(T *newPointer) : pointer(newPointer) {}
        ~iterator() { pointer = nullptr; }

        T &operator*() const
        {
            return *pointer;
        }

        T &operator[](int idx) const
        {
            return *(pointer + idx);
        }

        T *operator->() const
        {
            return pointer;
        }

        iterator operator+(int num) const
        {
            iterator temp((pointer + num));
            return temp;
        }

        iterator operator-(int num) const
        {
            iterator temp((pointer - num));
            return temp;
        }

        iterator &operator++()
        {
            ++pointer;
            return *this;
        }

        iterator &operator--()
        {
            --pointer;
            return *this;
        }

        iterator operator++(int i)
        {
            iterator temp = *this;
            ++pointer;

            return temp;
        }

        iterator operator--(int i)
        {
            iterator temp = *this;
            --pointer;

            return temp;
        }

        iterator &operator+=(int i)
        {
            pointer += i;
            return *this;
        }

        iterator &operator-=(int i)
        {
            pointer -= i;
            return *this;
        }

        bool operator==(const iterator &another)
        {
            return (pointer == another.getPointer() ? true : false);
        }

        bool operator!=(const iterator &another)
        {
            return (pointer != another.getPointer() ? true : false);
        }

        bool operator<(const iterator &another)
        {
            return pointer < another.getPointer();
        }

        bool operator>(const iterator &another)
        {
            return pointer > another.getPointer();
        }

        bool operator>=(const iterator &another)
        {
            return pointer >= another.getPointer();
        }

        bool operator<=(const iterator &another)
        {
            return pointer <= another.getPointer();
        }

        T *getPointer() const
        {
            return pointer;
        }

    protected:
        T *pointer;
    };

    class const_iterator
    {
    public:
        const_iterator() : cpointer(nullptr) {}
        const_iterator(const T *newPointer) : cpointer(newPointer) {}
        ~const_iterator() { cpointer = nullptr; }

        const T &operator*() const
        {
            return *cpointer;
        }

        const T &operator[](int idx) const
        {
            return *(cpointer + idx);
        }

        const T *operator->() const
        {
            return cpointer;
        }

        const_iterator operator+(int num) const
        {
            const_iterator temp((cpointer + num));
            return temp;
        }

        const_iterator operator-(int num) const
        {
            const_iterator temp((cpointer - num));
            return temp;
        }

        const_iterator &operator++()
        {
            ++cpointer;
            return *this;
        }

        const_iterator &operator--()
        {
            --cpointer;
            return *this;
        }

        const_iterator operator++(int i)
        {
            const_iterator temp = *this;
            ++cpointer;

            return temp;
        }

        const_iterator operator--(int i)
        {
            const_iterator temp = *this;
            --cpointer;

            return temp;
        }

        const_iterator &operator+=(int i)
        {
            cpointer += i;
            return *this;
        }

        const_iterator &operator-=(int i)
        {
            cpointer -= i;
            return *this;
        }

        bool operator==(const const_iterator &another)
        {
            return (cpointer == another.getCpointer() ? true : false);
        }

        bool operator!=(const const_iterator &another)
        {
            return (cpointer != another.getCpointer() ? true : false);
        }

        bool operator<(const const_iterator &another)
        {
            return cpointer < another.getCpointer();
        }

        bool operator>(const const_iterator &another)
        {
            return cpointer > another.getCpointer();
        }

        bool operator>=(const const_iterator &another)
        {
            return cpointer >= another.getCpointer();
        }

        bool operator<=(const const_iterator &another)
        {
            return cpointer <= another.getCpointer();
        }

        const T *getCpointer() const
        {
            return cpointer;
        }

    private:
        const T *cpointer;
    };

    class reverse_iterator
    {
    public:
        reverse_iterator() : pointer(nullptr) {}
        reverse_iterator(T *newPointer) : pointer(newPointer) {}
        ~reverse_iterator()
        {
            pointer = nullptr;
        }

        T &operator*() const
        {
            return *pointer;
        }

        T &operator[](int pos) const
        {
            return *(pointer - pos);
        }

        T *operator->() const
        {
            return pointer;
        }

        reverse_iterator operator+(int num) const
        {
            reverse_iterator temp((pointer - num));
            return temp;
        }

        reverse_iterator operator-(int num) const
        {
            reverse_iterator temp((pointer + num));
            return temp;
        }

        reverse_iterator &operator++()
        {
            --pointer;
            return *this;
        }

        reverse_iterator &operator--()
        {
            ++pointer;
            return *this;
        }

        reverse_iterator operator++(int i)
        {
            reverse_iterator temp = *this;
            --pointer;

            return temp;
        }

        reverse_iterator operator--(int i)
        {
            reverse_iterator temp = *this;
            ++pointer;

            return temp;
        }

        reverse_iterator &operator+=(int i)
        {
            pointer -= i;
            return *this;
        }

        reverse_iterator &operator-=(int i)
        {
            pointer += i;
            return *this;
        }

        bool operator==(const reverse_iterator &another)
        {
            return (pointer == another.getPointer() ? true : false);
        }

        bool operator!=(const reverse_iterator &another)
        {
            return (pointer != another.getPointer() ? true : false);
        }

        bool operator<(const reverse_iterator &another)
        {
            return pointer > another.getPointer();
        }

        bool operator>(const reverse_iterator &another)
        {
            return pointer < another.getPointer();
        }

        bool operator>=(const reverse_iterator &another)
        {
            return pointer <= another.getPointer();
        }

        bool operator<=(const reverse_iterator &another)
        {
            return pointer >= another.getPointer();
        }

        T *getPointer() const { return pointer; }

    private:
        T *pointer;
    };

    class const_reverse_iterator
    {
    public:
        const_reverse_iterator() : cpointer(nullptr) {}
        const_reverse_iterator(const T *newPointer) : cpointer(newPointer) {}
        ~const_reverse_iterator() { cpointer = nullptr; }

        const T &operator*() const
        {
            return *cpointer;
        }

        const T &operator[](int idx) const
        {
            return *(cpointer - idx);
        }

        const T *operator->() const
        {
            return cpointer;
        }
        const_reverse_iterator operator+(int num) const
        {
            const_reverse_iterator temp((cpointer - num));
            return temp;
        }

        const_reverse_iterator operator-(int num) const
        {
            const_reverse_iterator temp((cpointer + num));
            return temp;
        }

        const_reverse_iterator &operator++()
        {
            --cpointer;
            return *this;
        }

        const_reverse_iterator &operator--()
        {
            ++cpointer;
            return *this;
        }

        const_reverse_iterator operator++(int i)
        {
            const_reverse_iterator temp = *this;
            --cpointer;

            return temp;
        }

        const_reverse_iterator operator--(int i)
        {
            const_reverse_iterator temp = *this;
            ++cpointer;

            return temp;
        }

        const_reverse_iterator &operator+=(int i)
        {
            cpointer -= i;
            return cpointer;
        }

        const_reverse_iterator &operator-=(int i)
        {
            cpointer += i;
            return cpointer;
        }

        bool operator==(const const_reverse_iterator &another)
        {
            return (cpointer == another.getCpointer() ? true : false);
        }

        bool operator!=(const const_reverse_iterator &another)
        {
            return (cpointer != another.getCpointer() ? true : false);
        }

        bool operator<(const const_reverse_iterator &another)
        {
            return cpointer > another.getCpointer();
        }

        bool operator>(const const_reverse_iterator &another)
        {
            return cpointer < another.getCpointer();
        }

        bool operator>=(const const_reverse_iterator &another)
        {
            return cpointer <= another.getCpointer();
        }

        bool operator<=(const const_reverse_iterator &another)
        {
            return cpointer >= another.getCpointer();
        }

        const T *getCpointer() const
        {
            return cpointer;
        }

    private:
        const T *cpointer;
    };

    Vector() : elements(new T[vecCapacity]), vecSize(0), vecCapacity(1) {}
    Vector(Vector &rhs) : elements(new T[rhs.capacity()]), vecSize(rhs.size()), vecCapacity(rhs.capacity())
    {
        for (int i = 0; i < vecSize; i++)
        {
            elements[i] = rhs[i];
        }
    }
    Vector(const Vector &rhs) : elements(new T[rhs.capacity()]), vecSize(rhs.size()), vecCapacity(rhs.capacity())
    {
        for (int i = 0; i < vecSize; i++)
        {
            elements[i] = rhs[i];
        }
    }

    ~Vector()
    {
        delete[] elements;
    }

    int capacity() const
    {
        return vecCapacity;
    }

    int size() const
    {
        return vecSize;
    }

    bool empty() const
    {
        return (vecSize == 0 ? true : false);
    }

    void clear()
    {
        delete[] elements;

        vecCapacity = 1;
        elements = new T[vecCapacity];
        vecSize = 0;
    }

    iterator insert(const iterator &pos, const T &content)
    {
        if (vecCapacity == vecSize)
        {
            T *temp = new T[vecCapacity];
            for (int i = 0; i < vecSize; i++)
            {
                temp[i] = elements[i];
            }
            delete[] elements;
            vecCapacity *= 2;
            elements = new T[vecCapacity];
            for (int i = 0; i < vecSize; i++)
            {
                elements[i] = temp[i];
            }
            delete[] temp;
        }
        for (iterator it = this->end(); it != pos; it--)
        {
            *it = *(it - 1);
        }
        *pos = content;
        vecSize += 1;

        return pos;
    }

    iterator erase(const iterator &pos)
    {
        for (iterator it = pos; it != this->end(); it++)
        {
            *it = *(it + 1);
        }
        vecSize -= 1;

        return pos;
    }

    void push_back(const T &content)
    {
        if (vecCapacity > vecSize)
        {
            elements[vecSize] = content;
            vecSize += 1;
        }
        else
        {
            T *temp = new T[vecCapacity];
            for (int i = 0; i < vecSize; i++)
            {
                temp[i] = elements[i];
            }
            delete[] elements;
            vecCapacity *= 2;
            elements = new T[vecCapacity];
            for (int i = 0; i < vecSize; i++)
            {
                elements[i] = temp[i];
            }
            elements[vecSize] = content;
            vecSize += 1;
            delete[] temp;
        }
    }

    void pop_back()
    {
        if (vecSize > 0)
        {
            vecSize -= 1;
        }
    }

    void resize(int newSize, const T &content = 0)
    {
        if (newSize > vecSize) //현재 사이즈보다 크게 할 경우
        {
            T *temp = new T[vecCapacity];
            for (int i = 0; i < vecSize; i++)
            {
                temp[i] = elements[i];
            }
            delete[] elements;
            while (vecCapacity < newSize)
            {
                vecCapacity *= 2;
            }
            elements = new T[vecCapacity];
            for (int i = 0; i < vecSize; i++)
            {
                elements[i] = temp[i];
            }
            for (int i = vecSize; i < newSize; i++)
            {
                elements[i] = content; //남은 부분은 content로 채워준다!
            }
            vecSize = newSize;
            delete[] temp;
        }
        else
        {
            vecSize = newSize;
        }
    }

    T &operator[](int idx) const
    {
        if (0 <= idx && idx < vecSize)
        {
            return elements[idx];
        }
    }
    friend std::ostream &operator<<(std::ostream &out, Vector<T> &vector)
    {
        for (int i = 0; i < vector.size(); i++)
        {
            out << vector[i];
            if (i < vector.size() - 1)
            {
                out << ", ";
            }
        }

        return out;
    }

    friend std::istream &operator>>(std::istream &in, Vector<T> &vector)
    {
        T content;
        in >> content;
        vector.push_back(content);

        return in;
    }

    Vector<T> &operator=(const Vector<T> &originVec)
    {
        delete[] elements;

        vecSize = originVec.size();
        vecCapacity = originVec.capacity();
        elements = new T[vecCapacity];
        for (int i = 0; i < vecSize; i++)
        {
            elements[i] = originVec[i];
        }
        return *this;
    }

    void assign(int count, const T &content)
    {
        delete[] elements;

        vecCapacity = 1;
        elements = new T[vecCapacity];
        vecSize = 0;

        for (int i = 0; i < count; i++)
        {
            this->push_back(content);
        }
    }

    iterator begin() const
    {
        iterator temp(elements);
        return temp;
    }

    iterator end() const
    {
        iterator temp(&elements[vecSize]);
        return temp;
    }

    const_iterator cbegin() const
    {
        const_iterator temp(elements);
        return temp;
    }

    const_iterator cend() const
    {
        const_iterator temp(&elements[vecSize]);
        return temp;
    }

    reverse_iterator rbegin() const
    {
        reverse_iterator temp(&elements[vecSize - 1]);
        return temp;
    }

    reverse_iterator rend() const
    {
        reverse_iterator temp(elements - 1);
        return temp;
    }

    const_reverse_iterator crbegin() const
    {
        const_reverse_iterator temp(&elements[vecSize - 1]);
        return temp;
    }

    const_reverse_iterator crend() const
    {
        const_reverse_iterator temp(elements - 1);
        return temp;
    }

private:
    T *elements;
    int vecCapacity;
    int vecSize;
};