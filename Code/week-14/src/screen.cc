#include "screen.hpp"

const int INF = 987654321;

Screen::Screen(size_t height, size_t width)
    : height(height), width(width),
      blocks(height, std::vector<size_t>(width, 0))
{
    create();
}

/**
 * check block is full
 *
 * This function returns whether the block can no longer be created. 
 * If it can be created, it returns false if it is not.
 *
 * @return false if possible to create else true
 */
bool Screen::is_full()
{
    size_t count = 0;
    for (const auto &row : blocks)
    {
        for (const auto &val : row)
        {
            if (val)
            {
                count += 1;
            }
        }
    }

    return count == height * width;
}

/**
 * Create 2 block at random location
 *
 * This function creates 2 blocks at random locations. 
 * Internally, it calls Screen::create(row, col).
 *
 * @return false if failed else true
 */
bool Screen::create()
{
    if (is_full())
    {
        return false;
    }

    bool flag = false;
    size_t row, col;
    do
    {
        row = util::random(height * width);
        col = row / height;
        row %= height;

        flag = create(row, col);
    } while (!flag);
    return true;
}

/**
 * Create 2 block at the specificed location
 *
 * This function takes row and col and creates 2 blocks at that location. 
 * This function does not check if the block is empty.
 * Returns false when an invalid row or col value is entered.
 *
 * @param row, col
 * @return false if range_error else true with mark blocks[row][col] = 2
 */
bool Screen::create(size_t row, size_t col)
{
    if (row >= height || col >= width || blocks[row][col])
    {
        return false;
    }

    blocks[row][col] = 2;
    return true;
}

/**
 * draw current blocks
 *
 * This function prints the current block 
 * to the output stream given as an argument.
 *
 * @param target output stream
 */
void Screen::draw(std::ostream &out)
{
    for (const auto &row : blocks)
    {
        for (const auto &val : row)
        {
            out << val << ',';
        }
        out << std::endl;
    }
}

/**
 * check current blocks
 *
 * This function check whether user can move.
 * .
 *
 * @return if it's stuck, return true
 */
bool Screen::is_Stuck()
{
    //상하좌우에 같은 것이 있는지 확인
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //위쪽
            if ((0 < i && i < height) && (blocks[i][j] == blocks[i - 1][j]))
            {
                return false;
            }
            //아래쪽
            if((0<= i && i < height -1) && (blocks[i][j] == blocks[i+1][j]))
            {
                return false;
            }
            //오른쪽
            if((0<= j && j< width-1) && (blocks[i][j] == blocks[i][j+1]))
            {
                return false;
            }
            //왼쪽
            if((0<j && j< width) && (blocks[i][j] == blocks[i][j-1]))
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * push up the blocks
 *
 * INF : to mark a block(already visited)
 * 
 */
void Screen::goUp()
{
    for (int j = 0; j < width; j++)
    {
        for (int i = 1; i < height; i++)
        {
            for (int curr = i; curr > 0; curr--)
            {
                if (blocks[curr][j] == 0 || (blocks[curr][j] > INF))
                {
                    break;
                }
                if ((blocks[curr - 1][j]) && (blocks[curr - 1][j] != blocks[curr][j]))
                {
                    break;
                }

                if (blocks[curr - 1][j] == 0)
                {
                    blocks[curr - 1][j] = blocks[curr][j];
                }
                else if (blocks[curr][j] == blocks[curr - 1][j])
                {
                    blocks[curr - 1][j] *= 2;
                    blocks[curr - 1][j] += INF;
                }
                blocks[curr][j] = 0;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (blocks[i][j] >= INF)
            {
                blocks[i][j] -= INF;
            }
        }
    }
}

/**
 * push down the blocks
 *
 * INF : to mark a block(already visited)
 * 
 */
void Screen::goDown()
{
    for (int j = 0; j < width; j++)
    {
        for (int i = height - 2; i >= 0; i--)
        {
            for (int curr = i; curr <= height - 2; curr++)
            {
                if (blocks[curr][j] == 0 || (blocks[curr][j] > INF))
                {
                    break;
                }
                if ((blocks[curr + 1][j]) && (blocks[curr + 1][j] != blocks[curr][j]))
                {
                    break;
                }

                if (blocks[curr + 1][j] == 0)
                {
                    blocks[curr + 1][j] = blocks[curr][j];
                }
                else if (blocks[curr][j] == blocks[curr + 1][j])
                {
                    blocks[curr + 1][j] *= 2;
                    blocks[curr + 1][j] += INF;
                }
                blocks[curr][j] = 0;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (blocks[i][j] >= INF)
            {
                blocks[i][j] -= INF;
            }
        }
    }
}

/**
 * push left the blocks
 *
 * INF : to mark a block(already visited)
 * 
 */
void Screen::goLeft()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            for (int curr = j; curr > 0; curr--)
            {
                if (blocks[i][curr] == 0 || (blocks[i][curr] > INF))
                {
                    break;
                }
                if ((blocks[i][curr - 1]) && (blocks[i][curr - 1] != blocks[i][curr]))
                {
                    break;
                }

                if (blocks[i][curr - 1] == 0)
                {
                    blocks[i][curr - 1] = blocks[i][curr];
                }
                else if (blocks[i][curr] == blocks[i][curr - 1])
                {
                    blocks[i][curr - 1] *= 2;
                    blocks[i][curr - 1] += INF;
                }
                blocks[i][curr] = 0;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (blocks[i][j] >= INF)
            {
                blocks[i][j] -= INF;
            }
        }
    }
}
/**
 * push right the blocks
 *
 * INF : to mark a block(already visited)
 * 
 */
void Screen::goRight()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = width - 2; j >= 0; j--)
        {
            for (int curr = j; curr <= width - 2; curr++)
            {
                if (blocks[i][curr] == 0 || (blocks[i][curr] > INF))
                {
                    break;
                }
                if ((blocks[i][curr + 1]) && (blocks[i][curr + 1] != blocks[i][curr]))
                {
                    break;
                }

                if (blocks[i][curr + 1] == 0)
                {
                    blocks[i][curr + 1] = blocks[i][curr];
                }
                else if (blocks[i][curr] == blocks[i][curr + 1])
                {
                    blocks[i][curr + 1] *= 2;
                    blocks[i][curr + 1] += INF;
                }
                blocks[i][curr] = 0;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (blocks[i][j] >= INF)
            {
                blocks[i][j] -= INF;
            }
        }
    }
}

/**
 * return the total score
 *
 *
 * 
 */
size_t Screen::score()
{
    size_t sum = 0;

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (blocks[i][j])
            {
                sum += blocks[i][j];
            }
        }
    }

    return sum;
}