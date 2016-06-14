#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<int> myTree;
    myTree.insertValue(7);
    myTree.insertValue(1);
    myTree.insertValue(9);

    myTree.printIncreasingOrder();
    myTree.printDecreasingOrder();

    cout << "\nBack in main!" << endl;
    return 0;
}
