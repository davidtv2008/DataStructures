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

    myTree.insertValue(50);
    myTree.insertValue(30);
    myTree.insertValue(70);
    myTree.insertValue(10);
    myTree.insertValue(40);
    myTree.insertValue(60);
    myTree.insertValue(80);
    myTree.insertValue(5);
    myTree.insertValue(15);
    myTree.insertValue(35);
    myTree.insertValue(45);
    myTree.insertValue(55);
    myTree.insertValue(65);
    myTree.insertValue(75);
    myTree.insertValue(85);

    myTree.printIncreasingOrder();
    cout<<"Tree size: "<<myTree.getSize()<<endl<<endl;

    myTree.deleteValue(30);
    //cout<<"Tree size: "<<myTree.getSize()<<endl;
    //myTree.printIncreasingOrder();
    cout<<endl;

    cout << "\nBack in main!" << endl;
    return 0;
}
