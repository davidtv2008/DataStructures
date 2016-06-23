#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
struct Node
{
    //tree structure with 1 key, and 2 pointers
    T key;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class Tree
{
    public:
        Tree();
        ~Tree();
        void insertValue(T s);
        void deleteValue(T s);
        void findValue(T s);
        void printIncreasingOrder();
        void printDecreasingOrder();

        //return number of elements in the tree
        int getSize();

    protected:

    private:
        //declare our root pointer
        Node<T>* root;
        Node<T>* lptr;
        Node<T>* pptr;
        Node<T>* lpptr;

        //add and delete nodes
        void addLeaf(T key, Node<T>* ptr);
        void deleteLeaf(T key, Node<T>* ptr);
        void findValuePrivate(T s, Node<T>* ptr);
        void findLastPtr(Node<T>* ptr,char side);

        //to create a new node
        Node<T>* createLeaf(T s);
        int treeSize; // hold the size of the tree, will ++ on added values, or -- on removed

        //to output order from smallest to greatest, and vice versa
        void printIncOrder(Node<T>* ptr);
        void printDecOrder(Node<T>* ptr);
};

template <class T>
Tree<T>::Tree()
{
    //tree is always empty(NULL) with 0 elements upon creation
    root = NULL;
    treeSize = 0;
}

template <class T>
void Tree<T>::insertValue(T s)
{
    //cout<<s<<" "<<endl;
    //pass parameter s so that the value gets added to the tree
    addLeaf(s,root);
}

template <class T>
void Tree<T>::deleteValue(T s)
{
    //pass parameter s so that the value is searched for and removed
    deleteLeaf(s,root);
}


template<class T>
void Tree<T>::deleteLeaf(T key,Node<T>* ptr)
{
    // check if the root contains a value
    if(root != NULL)
    {
        if(ptr != NULL)
        {
            //this is for case where root has no children
            if(root->key == key && root->left == NULL && root->right == NULL)
            {
                treeSize--;
                delete root;
                root = NULL;
            }
            //this if for case where root has left child only
            else if(root->key == key && root->right == NULL && root->left != NULL)
            {
                if(root->left->left == NULL && root->left->right == NULL)
                {
                    treeSize--;
                    root->key = root->left->key;
                    delete root->left;
                    root->left = NULL;
                    cout<<"New Root: "<<root->key<<endl;
                }
                else if(root->left->left != NULL && root->left->right == NULL)
                {
                    treeSize--;
                    root->key = root->left->key;
                    root->left = root->left->left;
                    cout<<"New Root: "<<root->key<<endl;
                }
                else
                {
                    treeSize--;
                    findLastPtr(ptr->left,'L');
                    root->key = lptr->key;
                    pptr->right = lptr->left;
                    delete lptr;
                    lptr = NULL;
                    cout<<"New Root: "<<root->key<<endl;
                }
            }
            //this is for case where root has right child only
            else if((root->key == key) && (root->left == NULL) && (root->right != NULL))
            {
                if(root->right->right == NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    delete root->right;
                    root->right = NULL;
                    cout<<"New Root: "<<root->key<<endl;
                }
                else if(root->right->right != NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    root->right = root->right->right;
                    cout<<"New Root: "<<root->key<<endl;
                }
                else
                {
                    treeSize--;
                    findLastPtr(ptr->right,'R');
                    root->key = lptr->key;
                    pptr->left = lptr->right;
                    delete lptr;
                    lptr = NULL;
                    cout<<"New Root: "<<root->key<<endl;
                }
            }
            //this is for case where root has 2 children
            else if(root->key == key && root->left != NULL && root->right != NULL)
            {
                if(root->right->right == NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    delete root->right;
                    root->right = NULL;
                    cout<<"New Root: "<<root->key<<endl;
                }
                else if(root->right->right != NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    root->right = root->right->right;
                    cout<<"New Root: "<<root->key<<endl;
                }
                else
                {
                    treeSize--;
                    findLastPtr(ptr->right,'R');
                    root->key = lptr->key;
                    pptr->left = lptr->right;
                    delete lptr;
                    lptr = NULL;
                    cout<<"New Root: "<<root->key<<endl;
                }
            }
            //this is for recursion to find the node that contains the value that is to be deleted
            else if(key < ptr->key)
            {
                pptr = ptr; // hold the previous pointer
                deleteLeaf(key, ptr->left); //recursion to examine each node
            }
            //this is for recursion to find the node that contains the value that is to be deleted
            else if( key > ptr->key)
            {
                pptr = ptr; // hold the previous pointer
                deleteLeaf(key, ptr->right); //recursion to examine each node
            }
            //case where value to delete is NOT in the root node and Node has no children
            else if(key == ptr->key && ptr->left == NULL && ptr->right == NULL)
            {
                treeSize--;
                if(key > root->key && pptr->right == ptr)
                {
                    pptr->right = NULL;
                }
                else if(key > root->key && pptr->left == ptr)
                {
                    pptr->left = NULL;
                }

                if(key < root->key && pptr->right == ptr)
                {
                    pptr->right = NULL;
                }
                else if(key < root->key && pptr->left == ptr)
                {
                    pptr->left = NULL;
                }
            }
            //case where value to delete is NOT in the root node and Node has 1 child and 1 null pointer on left
            else if(key==ptr->key && ptr->left == NULL && ptr->right != NULL)
            {
                treeSize--;
                if(key < root->key)
                {
                    if(pptr->right == ptr)
                    {
                        pptr->right = ptr->right;
                    }
                    else if(pptr->left == ptr)
                    {
                        pptr->left = ptr->right;
                    }
                }
                else if(key > root->key)
                {
                    if(pptr->left == ptr)
                    {
                        pptr->left = ptr->right;
                    }
                    else if(pptr->right == ptr)
                    {
                        pptr->right = ptr->right;
                    }
                }
                delete ptr;
                ptr = NULL;

            }
            //case where value to delete is NOT in the root node and Node has 1 child and 1 null pointer on right
            else if(key==ptr->key && ptr->right == NULL && ptr->left != NULL)
            {
                treeSize--;
                if(key < root->key)
                {
                    if(pptr->right == ptr)
                    {
                        pptr->right = ptr->left;
                    }
                    else if(pptr->left == ptr)
                    {
                        pptr->left = ptr->left;
                    }
                }
                else if(key > root->key)
                {
                    if(pptr->left == ptr)
                    {
                        pptr->left = ptr->left;
                    }
                    else if(pptr->right == ptr)
                    {
                        pptr->right = ptr->left;
                    }
                }
                delete ptr;
                ptr = NULL;
            }
            //case where value to delete is not in ROOT node, and Node has 2 children
            else if(ptr->key == key && ptr->left != NULL && ptr->right != NULL)
            {
                treeSize--;
                if(key < root->key)
                {
                    findLastPtr(ptr->left,'L');
                    ptr->key = lptr->key;
                    if(ptr->left->right != NULL)
                    {
                        ptr->left->right = lptr->left;
                    }
                    else
                    {
                        ptr->left = NULL;
                    }
                }
                else if(key > root->key)
                {
                    findLastPtr(ptr->right,'R');
                    ptr->key = lptr->key;
                    ptr->right->left = lptr->right;
                    delete lptr;
                    lptr = NULL;
                }
            }
        }
        //if after traversing the entire tree the value is not found, let user know value does not exist in tree
        else
        {
            cout<<"Value is not in tree"<<endl;
        }
    }
    //when tree is empty, no nodes, just a null root
    else
    {
        cout<<"The tree is empty"<<endl;
    }
}

template<class T>
void Tree<T>::findValue(T s)
{
   findValuePrivate(s,root);
}

template<class T>
void Tree<T>::findValuePrivate(T s, Node<T>* ptr)
{
    if(ptr != NULL)
    {
        if(s < ptr->key)
        {
            findValuePrivate(s,ptr->left);
        }
        else if(s > ptr->key)
        {
            findValuePrivate(s,ptr->right);
        }
        else if( s == ptr->key)
        {
            cout<<"FOUND!"<<endl;
        }
    }
    else
    {
        cout<<"NOT FOUND!"<<endl;
    }

}


template<class T>
void Tree<T>::findLastPtr(Node<T>* ptr,char side)
{
    //recursion until last node is found, either on left root branches or right root branches
    if(side == 'L')
    {
        if(ptr->right != NULL)
        {
            pptr = ptr;
            findLastPtr(ptr->right,side);
        }
        else
        {
            lptr = ptr;
        }
    }
    else if(side == 'R')
    {
        if(ptr->left != NULL)
        {
            pptr = ptr;
            findLastPtr(ptr->left,side);
        }
        else
        {
            lptr = ptr;
        }
    }
}

template <class T>
void Tree<T>::addLeaf(T key,Node<T>* ptr)
{
    //when root contains nothing, create a new node and insert value
    if(root == NULL)
    {
        root = createLeaf(key);
        treeSize++;
    }
    //when root already exists and the new value is less that root value, then add a new node on roots left branch
    else if(key < ptr->key)
    {
        if(ptr->left != NULL)
        {
           if(key != ptr->left->key)
            {
                addLeaf(key,ptr->left);
            }
        }
        else
        {
            ptr->left = createLeaf(key);
            treeSize++;
        }
    }
    //when root already exists and the new value is greater that root value, then add a new node on roots right branch
    else if(key > ptr->key)
    {
         if(ptr->right != NULL)
        {
            if(key != ptr->key)
            {
                addLeaf(key,ptr->right);
            }
        }
        else
        {
            ptr->right = createLeaf(key);
            treeSize++;
        }
    }
    else
    {
        //when the value that is being added is already existing in tree.
        //so cannot add it again to maintain uniqueness.
    }
}

template<class T>
Node<T>* Tree<T>::createLeaf(T key)
{
    //each time a new value is added that is not yet in the tree, we create a new node
    //that has left and right null children.
    Node<T>* n = new Node<T>;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

template <class T>
void Tree<T>::printIncreasingOrder()
{
    //access private print function
    printIncOrder(root);
    cout<<endl;
}

template <class T>
void Tree<T>::printIncOrder(Node<T>* ptr)
{
    if(root != NULL)
    {
        if(ptr->left != NULL)
        {
            printIncOrder(ptr->left);
        }
        cout<<ptr->key<<" ";
        if(ptr->right != NULL)
        {
            printIncOrder(ptr->right);
        }
    }
    else
    {
        cout<<"The tree is empty\n";
    }
}

template <class T>
void Tree<T>::printDecreasingOrder()
{
    printDecOrder(root);
    cout<<endl;
}

template <class T>
void Tree<T>::printDecOrder(Node<T>* ptr)
{
    if(root != NULL)
    {
        if(ptr->right != NULL)
        {
            printDecOrder(ptr->right);
        }
        cout << ptr->key << " ";
        if(ptr->left != NULL)
        {
            printDecOrder(ptr->left);
        }
    }
    else
    {
        cout<<"The tree is empty\n";
    }
}

template<class T>
int Tree<T>::getSize()
{
    //for accessing the current tree size
    return treeSize;
}

template <class T>
Tree<T>::~Tree()
{

}

#endif // TREE_H
