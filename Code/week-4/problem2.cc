#include <iostream>

template <typename T>
struct dynamic_array
{
    T *pointer = nullptr;
    size_t cap = 0;
    size_t maxPos = -1;

public:
    dynamic_array(size_t cap) : cap(cap)
    {
        this->pointer = new T[cap];
    }

    void push_front(const T &element)
    {
        if (maxPos >= 0)
        {
            T *temp = new T[maxPos + 1];
            for (int i = 0; i < maxPos + 1; i++)
            {
                temp[i] = this->pointer[i];
            }
            delete[] this->pointer;
            this->pointer = new T[maxPos + 2];
            this->pointer[0] = element;
            for (int i = 1; i < maxPos + 2; i++)
            {
                this->pointer[i] = temp[i - 1];
            }
            maxPos++;
            delete[] temp;
        }
        else
        {
            delete[] this->pointer;
            this->pointer = new T[1];
            this->pointer[0] = element;
            maxPos++;
        }
    }
    void push_back(const T &element)
    {
        if (maxPos >= 0)
        {
            T *temp = new T[maxPos + 1];
            for (int i = 0; i < maxPos + 1; i++)
            {
                temp[i] = this->pointer[i];
            }
            delete[] this->pointer;
            this->pointer = new T[maxPos + 2];
            for (int i = 0; i < maxPos + 1; i++)
            {
                this->pointer[i] = temp[i];
            }
            maxPos++;
            this->pointer[maxPos] = element;
            delete[] temp;
        }
        else
        {
            delete[] this->pointer;
            this->pointer = new T[1];
            this->pointer[0] = element;
            maxPos++;
        }
    }
    T pop_front()
    {
        if (maxPos >= 0)
        {
            T *tempArr = new T[maxPos];
            T popped;
            popped = this->pointer[0];
            for (int i = 1; i < maxPos+1; i++)
            {
                tempArr[i-1] = this->pointer[i];
            }
            delete[] this->pointer;
        this->pointer = new T[maxPos];
            for (int i = 0; i < maxPos; i++)
            {
                this->pointer[i] = tempArr[i];
            }
            maxPos--;
            delete[] tempArr;
            return popped;
        }
        else
        {
            return 0;
        }
    }
    T pop_back()
    {
       if (maxPos >= 0)
        {
            T *tempArr = new T[maxPos];
            T popped;
            popped = this->pointer[maxPos];
            for (int i = 0; i < maxPos; i++)
            {
                tempArr[i] = this->pointer[i];
            }
            delete[] this->pointer;
        this->pointer = new T[maxPos];
            for (int i = 0; i < maxPos; i++)
            {
                this->pointer[i] = tempArr[i];
            }
            maxPos--;
            delete[] tempArr;
            return popped;
        }
        else
        {
            return 0;
        }
    }
    ~dynamic_array()
    {
        delete[] this->pointer;
    }
};

int main()
{
    return 0;
}