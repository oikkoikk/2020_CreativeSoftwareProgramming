#include <iostream>
#include <string>
#include <vector>
#include "shape.h"

int main()
{
    size_t x, y, w, h, r;
    std::string command;

    std::cin >> w >> h;
    Canvas canvas{h, w};

    std::cin >> command;
    while (command != "exit")
    {
        if (command == "add")
        {
            std::string addShape;
            std::cin >> addShape;
            if (addShape == "point")
            {
                std::cin >> x >> y;
                std::cout << canvas.add(new Point({x, y})) << std::endl;
            }
            else if (addShape == "rectangle")
            {
                std::cin >> x >> y >> w >> h;
                std::cout << canvas.add(new Rectangle({x, y}, {w, h})) << std::endl;
            }
            else if (addShape == "circle")
            {
                std::cin >> x >> y >> r;
                std::cout << canvas.add(new Circle({x, y}, r)) << std::endl;
            }
            else if (addShape == "triangle")
            {
                std::cin >> x >> y >> w >> h;
                std::cout << canvas.add(new Triangle({x, y}, {w, h})) << std::endl;
            }
        }
        else if (command == "draw")
        {
            canvas.draw();
        }
        else if (command == "set")
        {
            std::string subComm;
            size_t idNum;

            std::cin >> idNum;
            std::cin >> subComm;
            if (subComm == "fill")
            {
                std::string isOk;

                std::cin >> isOk;
                if (isOk == "true")
                {
                    canvas.at_fillable(idNum)->set_fill(true);
                }
                else
                {
                    canvas.at_fillable(idNum)->set_fill(false);
                }
            }
            else if (subComm == "visible")
            {
                std::string isOk;

                std::cin >> isOk;
                if (isOk == "true")
                {
                    canvas.at_drawable(idNum)->set_visible(true);
                }
                else
                {
                    canvas.at_drawable(idNum)->set_visible(false);
                }
            }
            else if (subComm == "size")
            {
                if (canvas.at_fillable(idNum)->get_size().first == canvas.at_fillable(idNum)->get_size().second)
                {
                    float newRad;
                    std::cin >> newRad;
                    canvas.at_fillable(idNum)->set_size({newRad, newRad});
                }
                else
                {
                    Point_ newSize;
                    std::cin >> newSize.first;
                    std::cin >> newSize.second;

                    canvas.at_fillable(idNum)->set_size(newSize);
                }
            }

            else if (subComm == "offset")
            {
                Point_ newOffset;
                std::cin >> newOffset.first;
                std::cin >> newOffset.second;

                canvas.at_drawable(idNum)->set_offset(newOffset);
            }
        }
        else if (command == "clear")
        {
            canvas.clear();
        }
        else if (command == "exit")
        {
            continue;
        }
        std::cin >> command;
    }

    return 0;
}