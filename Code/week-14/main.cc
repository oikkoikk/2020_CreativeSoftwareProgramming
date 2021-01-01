#include <iostream>

#include "screen.hpp"
#include "utility.hpp"

int main()
{
    size_t height, width;
    std::cin >> height >> width;

    Screen screen{height, width};
    screen.draw(std::cout);

    char c = 0;
    bool flag = true;
    while (flag)
    {
        std::cin >> c;
        switch (c)
        {
        case Key::UP:
            screen.goUp();
            break;
        case Key::DOWN:
            screen.goDown();
            break;
        case Key::LEFT:
            screen.goLeft();
            break;
        case Key::RIGHT:
            screen.goRight();
            break;
        default:
            flag = false;
            break;
        }
        //다른 버튼 누르면
        if (!flag)
        {
            break;
        }
        screen.create();
        screen.draw(std::cout);
        //더 이상 움직일 수 없는 상황이라면
        if (screen.is_full() && screen.is_Stuck())
        {
            break;
        }
    }
    std::cout << screen.score();
    return 0;
}
