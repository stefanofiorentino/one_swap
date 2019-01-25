#include <iostream>
#include <fstream>
#include <vector>
#include <iosfwd>


void solution(std::istream &in, std::ostream &out)
{
    int numel = -1;
    std::cin >> numel;
    std::vector<int> int_vec;
    int int_temp;
    for (auto it = 0; it < numel; ++it)
    {
        std::cin >> int_temp;
        int_vec.emplace_back(int_temp);
    }
    return;
}


int main()
{
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());

    solution(std::cin, std::cout);
    return 0;
}