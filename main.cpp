#include <iostream>
#include "Tree.h"
#include <ctime>

int main( )
{
    int n = 0;
    Tree Tr('a', 'z', 8);
    srand(time(nullptr));
    Tr.MakeTree();
    if (Tr.exist()) {
        Tr.OutTree();
        std::cout << '\n' << "Breadth-first traversal: ";
        n = Tr.BFS();
        std::cout << '\n';
        std::cout << "Nodes visited = " << n;
    }
    else
        std::cout << "The tree is empty!";

    std::cout << '\n';
    std::cout << "Leaves in tree " << Tr.CountLeaves();

    std::cin.get();

}

