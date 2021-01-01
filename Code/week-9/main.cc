#include <iostream>
#include "animal.h"

using namespace std;

int main()
{
    Cucumber cu1(5);
    Apple app1(5);
    Blueberry blu1(5);
    Lion li1(10);
    Rabbit ra1(10);
    Human hu1(10);

    //Check : Food Point
    cout << "Cucumber Point : " << cu1.point << endl;
    cout << "Apple Point : " << app1.point << endl;
    cout << "Blueberry Point : " << blu1.point << endl;
    cout << endl;

    //Check : Animal Point
    cout << "Lion Point : " << li1.point << endl;
    cout << "Rabbit Point : " << ra1.point << endl;
    cout << "Human Point : " << hu1.point << endl;
    cout << endl;

    //Check : Animal eat
    li1.eat(cu1);
    ra1.eat(app1);
    hu1.eat(blu1);
    cout << "Lion Point : " << li1.point << endl;
    cout << "Rabbit Point : " << ra1.point << endl;
    cout << "Human Point : " << hu1.point << endl;
    cout << endl;

    //Check : Animal pop
    cout << "Popped Food Point : " << li1.pop().point << endl;
    cout << "Popped Food Point : " << ra1.pop().point << endl;
    cout << "Popped Food Point : " << hu1.pop().point << endl;
    //if stomach is empty
    cout << "Popped Food Point : " << li1.pop().point << endl;
    cout << "Popped Food Point : " << ra1.pop().point << endl;
    cout << "Popped Food Point : " << hu1.pop().point << endl;
    cout << endl;

    //Check : Animal fight
    Human hu2(0);
    li1.fight(hu2);
    cout << "Lion Point : " << li1.point << ' ' << "hu2 Point : " << hu2.point << endl;
    Human hu3(100);
    li1.fight(hu3);
    cout << "Lion Point : " << li1.point << ' ' << "hu3 Point : " << hu3.point << endl;
    hu2.point = 0;
    hu3.point = 100;
    ra1.fight(hu2);
    cout << "Rabbit Point : " << ra1.point << ' ' << "hu2 Point : " << hu2.point << endl;
    ra1.fight(hu3);
    cout << "Rabbit Point : " << ra1.point << ' ' << "hu3 Point : " << hu3.point << endl;
    hu2.point = 0;
    hu3.point = 100;
    hu1.eat(app1);
    hu1.eat(blu1);
    cout << "Human Point : " << hu1.point << endl;
    hu1.fight(hu3);
    cout << "Human Point : " << hu1.point << ' ' << "hu3 Point : " << hu3.point << endl;
    hu1.fight(hu3);
    cout << "Human Point : " << hu1.point << ' ' << "hu3 Point : " << hu3.point << endl;
    hu1.fight(hu3);
    cout << "Human Point : " << hu1.point << ' ' << "hu3 Point : " << hu3.point << endl;
    cout << endl;

    //Check : Lion shout
    li1.eat(cu1);
    li1.eat(app1);
    li1.eat(blu1);
    cout << "Lion stomach size : " << li1.stomach.size() << " Lion Point : " << li1.point << endl;
    li1.shout();
    cout << "Lion stomach size : " << li1.stomach.size() << " Lion Point : " << li1.point << endl;
    cout << endl;

    //Check : Rabbit run
    ra1.eat(cu1);
    ra1.eat(app1);
    ra1.eat(blu1);
    cout << "Rabbit stomach size : " << ra1.stomach.size() << " Rabbit Point : " << ra1.point << endl;
    ra1.run();
    cout << "Rabbit stomach size : " << ra1.stomach.size() << " Rabbit Point : " << ra1.point << endl;
    cout << endl;

    //Check : Human sleep
    hu1.eat(cu1);
    hu1.eat(app1);
    hu1.eat(blu1);
    cout << "Human stomach size : " << hu1.stomach.size() << " Human Point : " << hu1.point << endl;
    hu1.sleep();
    cout << "Human stomach size : " << hu1.stomach.size() << " Human Point : " << hu1.point << endl;
    hu1.eat(blu1);
    cout << "Human stomach size : " << hu1.stomach.size() << " Human Point : " << hu1.point << endl;
    cout << endl;

}