#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
struct Node
{
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

        int getSize();

    protected:

    private:
        Node<T>* root;
        Node<T>* previousNode;

        void addLeaf(T key, Node<T>* ptr);
        void deleteLeaf(T key, Node<T>* ptr);

        Node<T>* createLeaf(T s);
        int treeSize;

        void printIncOrder(Node<T>* ptr);
        void printDecOrder(Node<T>* ptr);
};

template <class T>
Tree<T>::Tree()
{
    root = NULL;
    treeSize = 0;
}

template <class T>
void Tree<T>::insertValue(T s)
{
    addLeaf(s,root);
}

template <class T>
void Tree<T>::deleteValue(T s)
{
    deleteLeaf(s,root);
}

template<class T>
void Tree<T>::deleteLeaf(T key,Node<T>* ptr)
{
    if(root != NULL)
    {
        if(key == ptr->key)
        {

        }
        else if(key != ptr->key)
        {
            if(key < ptr->key)
            {

            }
        }
    }
    else
    {
        cout<<"The tree is empty"<<endl;
    }
}

template <class T>
void Tree<T>::addLeaf(T key,Node<T>* ptr)
{
    if(root == NULL)
    {
        cout<<"root: "<<key<<endl;
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
        cout<<"The value you are trying to\nadd already exists."<<endl;
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
