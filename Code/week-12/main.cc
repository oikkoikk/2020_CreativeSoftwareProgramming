#include "vector.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Vector<int> arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);
    Vector<int>::iterator temp = arr.insert(arr.begin() + 2, 20);
    cout << *temp << endl;
    cout << arr << endl;
    temp = arr.erase(arr.begin() + 2);
    cout << *temp << endl;
    cout << arr << endl;

    Vector<int> arrCopy(arr);
    arrCopy.push_back(3);
    cout << "arrCopy : ";
    cout << arrCopy << endl;

    cout << arr[0] << endl;
    Vector<int>::iterator it = arr.begin();
    cout << *it << endl;
    cout << *(it + 3) << endl;
    cout << *(it++) << endl;
    cout << *it << endl;
    cout << *(++it) << endl;
    arr.assign(5, 3);
    cout << arr[0] << ' ' << arr[4] << endl;
    cout << arr << endl;
    cin >> arr;
    cout << arr << endl;
    //++가 전위
    //++(int)가 후위
}