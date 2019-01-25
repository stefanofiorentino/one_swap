#include <iostream>
#include <fstream>
#include <vector>
#include <iosfwd>
#include <algorithm>

inline int naive_solution(std::vector<int> &int_vec)
{
    auto sorted_int_vec{int_vec};
    std::sort(std::begin(sorted_int_vec), std::end(sorted_int_vec));
    int changes = 0;
    for (auto it = 0u; it < int_vec.size(); ++it)
    {
        if (sorted_int_vec.at(it) != int_vec.at(it))
        {
            ++changes;
        }
    }
    if (0 == changes)
    {
        return 0;
    }
    else if (2 == changes)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

inline int n2_solution(std::vector<int> &int_vec)
{
    if (std::is_sorted(std::begin(int_vec), std::end(int_vec)))
    {
        return 0;
    }
    for (auto i = 0u; i < int_vec.size(); ++i)
    {
        for (auto j = i + 1; j < int_vec.size(); ++j)
        {
            std::swap(int_vec.at(i), int_vec.at(j));
            if (std::is_sorted(std::begin(int_vec), std::end(int_vec)))
            {
                std::swap(int_vec.at(j), int_vec.at(i));
                return 1;
            }
            std::swap(int_vec.at(j), int_vec.at(i));
        }
    }
    return -1;
}

inline int nlogn_solution(std::vector<int> &int_vec)
{
    if (std::is_sorted(std::begin(int_vec), std::end(int_vec)))
    {
        return 0;
    }
    for (auto i = 0u; i < int_vec.size(); ++i)
    {
        for (auto j = int_vec.size() - 1; j > i; --j)
        {
            std::swap(int_vec.at(i), int_vec.at(j));
            if (std::is_sorted(std::begin(int_vec), std::end(int_vec)))
            {
                std::swap(int_vec.at(j), int_vec.at(i));
                return 1;
            }
            std::swap(int_vec.at(j), int_vec.at(i));
        }
    }
    return -1;
}

inline void solution(std::istream &in, std::ostream &out)
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
//    out << naive_solution(int_vec) << "\n";
//    out << n2_solution(int_vec) << "\n";
    out << nlogn_solution(int_vec) << "\n";
}


int main()
{
//    std::ifstream in("../input.txt");
//    std::cin.rdbuf(in.rdbuf());
//
//    solution(std::cin, std::cout);

    std::ifstream in1("../input.at.scale.txt");
    std::cin.rdbuf(in1.rdbuf());

    solution(std::cin, std::cout);

    return 0;
}