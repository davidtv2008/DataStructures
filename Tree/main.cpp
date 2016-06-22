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

    //create our root key
    myTree.insertValue(100);
    for(int i = 0; i < 20; i++)
    {
        myTree.insertValue(rand()%100);
    }

    myTree.printIncreasingOrder();
    cout<<"Tree size: "<<myTree.getSize()<<endl<<endl;

    int input;
    while(input != 0)
    {
        cout<<"Please enter key to delete: ";
        cin>>input;
        myTree.deleteValue(input);

        myTree.printIncreasingOrder();
        cout<<"Tree size: "<<myTree.getSize()<<endl<<endl;

    }

    return 0;
}
