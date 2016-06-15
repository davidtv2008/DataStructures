#include <iostream>
#include "Tree.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    //for random number
    srand(static_cast<unsigned int>(time(0)));

    Tree<int> myTree;

    myTree.insertValue(10);
    myTree.insertValue(9);
    myTree.insertValue(3);

    myTree.printIncreasingOrder();
    //myTree.printDecreasingOrder();

    cout<<"The tree contains: "<<myTree.getSize()<<" unique items"<<endl;

    myTree.deleteValue(3);

    cout << "\nBack in main!" << endl;
    return 0;
}
