#include "map.h"
#include "set.h"

int main()
{
    max::set<int> set;
    set.insert(5);
    set.insert(2);
    set.insert(9);
    set.insert(1);
    set.insert(7);

    max::set<int>::iterator it = set.begin();
    while(it != set.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}