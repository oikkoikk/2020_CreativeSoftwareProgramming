#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::queue<std::string> nameList;

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        std::string name;
        std::vector<std::string> temp;
        std::priority_queue<std::string, std::vector<std::string>,std::greater<std::string>> tempQ;

        std::cin >> M;
        for (int j = 0; j < M; j++)
        {
            std::cin >> name;
            
            tempQ.push(name);
        }
        int Qtimes = tempQ.size();
        for (int j = 0; j < Qtimes; j++)
        {
            nameList.push(tempQ.top());
            tempQ.pop();
        }
    }

    int times = nameList.size();

    for (int i = 0; i < times; i++)
    {
        std::cout << nameList.front() << std::endl;
        nameList.pop();
    }
    
}