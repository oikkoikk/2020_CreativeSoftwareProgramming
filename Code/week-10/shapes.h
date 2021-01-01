class Shape
{
public:
    double width, height;

    Shape(double width, double height)
        : width(width), height(height)
    {
    }

    virtual double getArea() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : Shape(width, height) {}

    virtual double getArea()
    {
        return width * height;
    }
};
class Triangle : public Shape
{
public:
    Triangle(double width, double height) : Shape(width, height) {}

    virtual double getArea()
    {
        return width * height * 0.5;
    }
};
class Circle : public Shape
{
public:
    Circle(double width, double height) : Shape(width, height) {}

    virtual double getArea()
    {
        return 3.14 * width * height;
    }
};
