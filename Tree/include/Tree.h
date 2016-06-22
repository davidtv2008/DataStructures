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
        Node<T>* tptr;

        //add and delete nodes
        void addLeaf(T key, Node<T>* ptr);
        void deleteLeaf(T key, Node<T>* ptr);
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
    cout<<s<<" ";
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
            if(root->key == key && root->left == NULL && root->right == NULL)
            {
                treeSize--;
                delete root;
                root = NULL;
            }
            else if(root->key == key && root->right == NULL && root->left != NULL)
            {
                if(root->left->left == NULL && root->left->right == NULL)
                {
                    treeSize--;
                    root->key = root->left->key;
                    delete root->left;
                    root->left = NULL;
                }
                else if(root->left->left != NULL && root->left->right == NULL)
                {
                    treeSize--;
                    root->key = root->left->key;
                    root->left = root->left->left;
                }
                else
                {
                    treeSize--;
                    findLastPtr(ptr->left,'L');
                    root->key = lptr->key;
                    pptr->right = lptr->left;
                    delete lptr;
                    lptr = NULL;
                }
            }
            else if((root->key == key) && (root->left == NULL) && (root->right != NULL))
            {
                if(root->right->right == NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    delete root->right;
                    root->right = NULL;
                }
                else if(root->right->right != NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    root->right = root->right->right;
                }
                else
                {
                    treeSize--;
                    findLastPtr(ptr->right,'R');
                    root->key = lptr->key;
                    pptr->left = lptr->right;
                    delete lptr;
                    lptr = NULL;
                }
            }
            //if root key and root has 2 children
            else if(root->key == key && root->left != NULL && root->right != NULL)
            {
                if(root->right->right == NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    delete root->right;
                    root->right = NULL;
                }
                else if(root->right->right != NULL && root->right->left == NULL)
                {
                    treeSize--;
                    root->key = root->right->key;
                    root->right = root->right->right;
                }
                else
                {
                    treeSize--;
                    findLastPtr(ptr->right,'R');
                    root->key = lptr->key;
                    pptr->left = lptr->right;
                    delete lptr;
                    lptr = NULL;
                }
            }
            //if value to delete is less than current pointer value, "GO LEFT"
            else if(key < ptr->key)
            {
                pptr = ptr; // hold the previous pointer
                deleteLeaf(key, ptr->left); //recursion to examine each node
            }
            //else if value to delete is greater than current pointer value, "GO RIGHT"
            else if( key > ptr->key)
            {
                pptr = ptr; // hold the previous pointer
                deleteLeaf(key, ptr->right); //recursion to examine each node
            }
            //case number 1, parent has no children.
            else if(key == ptr->key && ptr->left == NULL && ptr->right == NULL)
            {
                cout<<pptr->right<<"|"<<pptr->left<<endl;
                treeSize--;
                cout<<"Previous Pointer: "<<pptr->key<<endl;
                cout<<"Deleting key: "<<ptr->key<<endl;

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
            //case 2, 1 child and 1 null pointer on left
            else if(key==ptr->key && ptr->left == NULL && ptr->right != NULL)
            {
                cout<<"examine left null and match on right"<<endl;
                treeSize--;
                cout<<"Previous Pointer: "<<pptr->key<<endl;
                cout<<"Deleting key: "<<ptr->key<<endl;

                delete ptr->left;//ok
                ptr->left = NULL;//ok
                pptr->left = ptr->right;
                delete ptr;
                ptr = NULL;
            }//case 2, 1 child and 1 null pointer on right
            else if(key==ptr->key && ptr->right == NULL && ptr->left != NULL)
            {
                cout<<"examine right null and match on left"<<endl;
                treeSize--;
                cout<<"Previous Pointer: "<<pptr->key<<endl;
                cout<<"Deleting key: "<<ptr->key<<endl;

                delete ptr->right;//ok
                ptr->right = NULL;//ok
                pptr->right = ptr->left;
                delete ptr;
                ptr = NULL;
            }
            else if(ptr->key == key && ptr->left != NULL && ptr->right != NULL)
            {
                treeSize--;
                if(key < root->key)
                {
                    findLastPtr(ptr->left,'L');
                    ptr->key = lptr->key;
                    pptr->right = lptr->left;
                    delete lptr;
                    lptr = NULL;
                }
                else if(key > root->key)
                {
                    findLastPtr(ptr->right,'R');
                    ptr->key = lptr->key;
                    pptr->left = lptr->right;
                    delete lptr;
                    lptr = NULL;
                }
            }
        }
        else
        {
            cout<<"Value is not in tree"<<endl;
        }
    }
    else //execute if tree is empty
    {
        cout<<"The tree is empty"<<endl;
    }
}

template<class T>
void Tree<T>::findLastPtr(Node<T>* ptr,char side)
{
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
    if(root == NULL)
    {
        root = createLeaf(key);
        treeSize++;
    }
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
        cout<<"value exists already"<<endl;
    }
}

template<class T>
Node<T>* Tree<T>::createLeaf(T key)
{
    Node<T>* n = new Node<T>;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

template <class T>
void Tree<T>::printIncreasingOrder()
{
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
   return treeSize;
}

template <class T>
Tree<T>::~Tree()
{

}

#endif // TREE_H
