#include <iostream>

int *array;
size_t cap = 0;
size_t maxPos = -1;

void initialize(int cap_)
{
    array = new int[cap_];
    cap = cap_;
}

void release()
{
    delete[] array;
}
void push_back(int element)
{
    if (maxPos >= 0)
    {
        int *tempArr = new int[maxPos + 1];
        for (int i = 0; i < maxPos + 1; i++)
        {
            tempArr[i] = array[i];
        }
        release();
        initialize(maxPos + 2);
        for (int i = 0; i < cap - 1; i++)
        {
            array[i] = tempArr[i];
        }
        array[cap - 1] = element;
        maxPos++;
        delete[] tempArr;
    }
    else
    {
        initialize(1);
        array[0] = element;
    }
}
int pop_back()
{
    int popped;
    if (maxPos >= 0)
    {
        int *tempArr = new int[maxPos];
        for (int i = 0; i < maxPos; i++)
        {
            tempArr[i] = array[i];
        }
        popped = array[maxPos];
        release();
        initialize(maxPos);
        for (int i = 0; i < cap; i++)
        {
            array[i] = tempArr[i];
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
int len()
{
    return maxPos+1;
}
int main()
{
    return 0;
}