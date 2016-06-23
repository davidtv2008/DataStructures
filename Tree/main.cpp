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
    int input, limit;

    while(input != 0)
    {
        cout<<"\n\nWELCOME TO BINARY TREE"<<endl;
        cout<<"Please select from the following options"<<endl;
        cout<<"1. Add Value"<<endl;
        cout<<"2. Delete Value"<<endl;
        cout<<"3. Search for value"<<endl;
        cout<<"4. Print in increasing order"<<endl;
        cout<<"5. Print in decreasing order"<<endl;
        cout<<"6. Randomly insert values"<<endl;
        cout<<"7. Size of Tree"<<endl;
        cout<<"0. EXIT"<<endl<<endl;
        cout<<"Please enter your selection: ";
        cin>>input;

        switch(input)
        {
            case 1:{ cout<<"insert: ";
                    cin>>input;
                    myTree.insertValue(input);
            }break;
            case 2:{ cout<<"delete: ";
                    cin>>input;
                    myTree.deleteValue(input);
            }break;
            case 3:{ cout<<"search: ";
                    cin>>input;
                    myTree.findValue(input);
            }break;
            case 4:{ myTree.printIncreasingOrder();
            }break;
            case 5:{ myTree.printDecreasingOrder();
            }break;
            case 6:{cout<<"How many values to enter?: ";
                cin>>input;
                cout<<"What is the max limit to randomize?: ";
                cin>>limit;
                for(int i = 0; i < input; i++)
                {
                    myTree.insertValue(rand()%limit);
                }
            }break;
            case 7:{ cout<<"Tree size: "<<myTree.getSize();
            }break;
            case 0:{
            cout<<"EXIT"<<endl;}
        }
    }
    return 0;
}
