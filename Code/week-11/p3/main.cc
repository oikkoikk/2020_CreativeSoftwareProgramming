#include <iostream>
#include <vector>

class B
{
public:
    virtual ~B() {}
};

class C : public B
{
public:
    void test_C() { std::cout << "C::test_C()" << std::endl; }
};

class D : public B
{
public:
    void test_D() { std::cout << "D::test_D()" << std::endl; }
};

int main()
{
    std::vector<B *> arr;
    char command;
    std::cin >> command;

    while (command != '0')
    {

        if (command == 'B')
        {
            arr.push_back(new B());
        }
        if (command == 'C')
        {
            arr.push_back(new C());
        }
        if (command == 'D')
        {
            arr.push_back(new D());
        }

        std::cin >> command;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        C *cObj = dynamic_cast<C *>(arr[i]);
        D *dObj = dynamic_cast<D *>(arr[i]);
        if (cObj)
        {
            cObj->test_C();
        }
        if (dObj)
        {
            dObj->test_D();
        }

        delete arr[i];
    }

    return 0;
}
