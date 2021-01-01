#include <iostream>

struct student_t
{
    int id;
    std::string name;
    std::string phone;
};

int main()
{
    int N, M;
    struct student_t students[101];

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        int input_id;
        std::string input_name;
        std::string input_phone;

        std::cin >> input_id;
        std::cin >> input_name;
        std::cin >> input_phone;
        students[i + 1] = {input_id, input_name, input_phone};
    }

    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        int searching_id;
        int flag = 0;

        std::cin >> searching_id;
        for (int j = 1; j <= N; j++)
        {
            if (students[j].id == searching_id)
            {
                flag = j;
            }
        }
        if (flag)
        {
            std::cout << students[flag].name << ',' << students[flag].phone << '\n';
        }
        else
        {
            std::cout << "Unknown" << '\n';
        }
        flag = 0;
    }

    return 0;
}