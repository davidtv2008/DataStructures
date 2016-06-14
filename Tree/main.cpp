#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<string> myTree;
    myTree.insertValue("aaaar");
    myTree.insertValue("aaaaq");
    myTree.insertValue("aaaap");


    cout << "\nBack in main!" << endl;
    return 0;
}
