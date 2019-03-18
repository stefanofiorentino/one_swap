#include <iostream>
#include <fstream>
#include <vector>
#include <iosfwd>
#include <algorithm>
#include <iterator>


void solution();

int main()
{
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    solution();
    std::cout << std::endl;

    std::ifstream in1("../input.at.scale.txt");
    std::cin.rdbuf(in1.rdbuf());
    solution();
    std::cout << std::endl;

    return 0;
}

void solution()
{
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    copy_n(std::istream_iterator<int>(std::cin), N, begin(a));

    auto it = is_sorted_until(begin(a), end(a));
    if (it == end(a) || a.size() == 1)
    {
        std::cout << 0;
    }
    else
    {
        auto lb = *prev(it);
        auto targetRev = find_if(rbegin(a), make_reverse_iterator(it), [=](auto i){
            return i < lb;
        });
        auto target = prev(targetRev.base());
        iter_swap(prev(it), target);
        std::cout << (is_sorted(it, end(a)) ? 1 : -1);
    }
}