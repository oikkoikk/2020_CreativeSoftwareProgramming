#include <utility>
#include <vector>
#include <functional>
#include <iostream>
#include <cmath>

using Point_ = std::pair<float, float>;
class Drawable
{
public:
    Drawable(Point_ offset = {0, 0}, bool visible = true)
        : offset(offset), visible(visible)
    {
    }

    virtual std::vector<Point_> draw() = 0;
    void set_offset(const Point_ &offset)
    {
        this->offset = offset;
    }
    const Point_ &get_offset() const
    {
        return offset;
    }

    void set_visible(bool visible = true)
    {
        this->visible = visible;
    }
    bool get_visible() const
    {
        return visible;
    }

private:
    bool visible;
    Point_ offset;
};

class Fillable
{
public:
    Fillable(Point_ size, bool fill = true)
        : size(size), fill(fill)
    {
    }

    void set_fill(bool fill = true)
    {
        this->fill = fill;
    }
    bool get_fill() const
    {
        return fill;
    }

    void set_size(const Point_ &size)
    {
        this->size = size;
    }
    const Point_ &get_size() const
    {
        return size;
    }

private:
    bool fill;
    Point_ size;
};

class Point : public Drawable
{
public:
    Point(Point_ offset = {0, 0}, bool visible = true)
        : Drawable(offset, visible)
    {
    }

    virtual std::vector<Point_> draw()
    {
        return {get_offset()};
    }
};

class Rectangle : public Drawable, public Fillable
{
public:
    Rectangle(Point_ offset, Point_ size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable(size, fill)
    {
    }

    virtual std::vector<Point_> draw()
    {
        std::vector<Point_> dots;
        float x = std::round(get_offset().first);
        float y = std::round(get_offset().second);
        float wid = std::round(get_size().first);
        float heig = std::round(get_size().second);

        for (int row = y; row < y + heig; row++)
        {
            for (int col = x; col < x + wid; col++)
            {
                if (!get_fill())
                {
                    if ((x < col && col < x + wid - 1) && (y < row && row < y + heig - 1))
                        continue;
                    dots.push_back({col, row});
                }
                else
                {
                    dots.push_back({col, row});
                }
                        }
        }

        return dots;
    }
};

class Circle : public Drawable, public Fillable
{
public:
    Circle(Point_ offset, size_t size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable({size, size}, fill)
    {
    }

    virtual std::vector<Point_> draw()
    {
        std::vector<Point_> dots;
        float x = get_offset().first;
        float y = get_offset().second;
        float rad = get_size().first;

        for (float row = y - rad; row <= y + rad; row += 1.0)
        {
            for (float col = x - rad; col <= x + rad; col += 0.1)
            {
                if (!get_fill())
                {
                    if ((col - x) * (col - x) + (row - y) * (row - y) <= rad * rad)
                    {
                        dots.push_back({std::round(col), std::round(row)});
                        dots.push_back({std::round(col + (x - col) * 2), std::round(row)});
                        break;
                    }
                }
                else
                {
                    if ((col - x) * (col - x) + (row - y) * (row - y) <= rad * rad)
                    {
                        dots.push_back({std::round(col), std::round(row)});
                    }
                }
            }
        }

        return dots;
    }
};

class Triangle : public Drawable, public Fillable
{
public:
    Triangle(Point_ offset, Point_ size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable(size, fill)
    {
    }

    virtual std::vector<Point_> draw()
    {
        std::vector<Point_> dots;
        float x = get_offset().first;
        float y = get_offset().second;
        float wid = get_size().first;
        float heig = get_size().second;
        float lftDwn = x - wid / 2;
        float rgtDwn = x + wid / 2;
        float upperRow = y - heig;
        float lowerRow = y;
        float tan = (wid / 2) / heig;

        for (int row = std::round(upperRow); row <= std::round(lowerRow); row++)
        {
            int lftEdge = std::round(lftDwn + (wid / 2) - ((row - std::round(upperRow)) * tan));
            int rgtEdge = std::round(rgtDwn - (wid / 2) + ((row - std::round(upperRow)) * tan));

            if (row == std::round(lowerRow))
            {
                for (int col = std::round(lftDwn); col <= std::round(rgtDwn); col++)
                {
                    dots.push_back(Point_{col, row});
                }
                continue;
            }
            if (!get_fill())
            {
                for (int col = lftEdge; col <= rgtEdge; col++)
                {
                    if (col == lftEdge || col == rgtEdge)
                    {
                        dots.push_back(Point_{col, row});
                    }
                }
            }
            else
            {
                for (int col = lftEdge; col <= rgtEdge; col++)
                {
                    dots.push_back(Point_{col, row});
                }
            }
        }
        return dots;
    }
};

class Canvas
{
public:
    Canvas(size_t row, size_t col, char ch = '*')
        : row(row), col(col), ch(ch), matrix(row, std::vector<bool>(col, false))
    {
    }
    ~Canvas()
    {
        for (std::vector<Drawable *>::iterator it = drawable_components.begin(); it != drawable_components.end(); it++)
        {
            delete (*it);
            it = drawable_components.erase(it);
        }
        for (std::vector<Fillable *>::iterator it = fillable_components.begin(); it != fillable_components.end(); it++)
        {
            delete (*it);
            it = fillable_components.erase(it);
        }
        clear();
    }

    void resize(size_t row, size_t col)
    {
        row = row;
        col = col;
    }

    size_t add(Point *drawable)
    {
        drawable_components.push_back(drawable);
        fillable_components.push_back(nullptr);

        return drawable_components.size() - 1;
    }

    template <typename T>
    size_t add(T fillable)
    {
        drawable_components.push_back(fillable);
        fillable_components.push_back(fillable);

        return drawable_components.size() - 1;
    }

    void draw()
    {
        char **canvas = new char *[row + 1];
        for (int i = 0; i <= row; i++)
        {
            canvas[i] = new char[col + 1];
        }

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                canvas[i][j] = '.';
            }
        }

        for (auto nowDrawable : drawable_components)
        {
            if (nowDrawable->get_visible())
            {
                for (auto dots : nowDrawable->draw())
                {
                    if ((1 <= dots.first && dots.first <= col) && (1 <= dots.second && dots.second <= row))
                    {
                        canvas[(int)dots.second][(int)dots.first] = ch;
                    }
                }
            }
        }

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                std::cout << canvas[i][j];
            }
            std::cout << std::endl;
        }

        for (int i = 0; i <= row; i++)
        {
            delete[] canvas[i];
        }
        delete[] canvas;
    }

    void drawable_apply(const std::function<void(Drawable *)> &f)
    {
        for (auto component : drawable_components)
        {
            f(component);
        }
    }
    void fillable_apply(const std::function<void(Fillable *)> &f)
    {
        for (auto component : fillable_components)
        {
            f(component);
        }
    }

    void clear()
    {
        drawable_components.clear();
        fillable_components.clear();
    }

    void set_ch(char ch)
    {
        ch = ch;
    }
    char get_ch() const
    {
        return ch;
    }

    Drawable *at_drawable(size_t index)
    {
        return drawable_components[index];
    }
    Fillable *at_fillable(size_t index)
    {
        return fillable_components[index];
    }

private:
    size_t row, col;
    char ch;
    std::vector<Drawable *> drawable_components;
    std::vector<Fillable *> fillable_components;

    std::vector<std::vector<bool>> matrix;
};
