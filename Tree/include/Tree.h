#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>
#include <string>

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
        void addLeaf(T key, Node<T>* ptr);

        void printIncOrder();
        void PrintDecOrder();

        Node<T>* createLeaf(T s);
        T getValue(T s);

    protected:

    private:
        Node<T>* root;


};

template <class T>
Tree<T>::Tree()
{
    root = NULL;
}

template <class T>
void Tree<T>::insertValue(T s)
{
    addLeaf(s,root);
}
template <class T>
void Tree<T>::addLeaf(T key,Node<T>* ptr)
{
    if(root == NULL)
    {
        root = createLeaf(key);
    }
    else if(key < root->key)
    {
         if(ptr->left != NULL)
        {
           addLeaf(key,ptr->left);
        }
        else
        {
            ptr->left = createLeaf(key);
        }
    }
    else if(key > root->key)
    {
         if(ptr->right != NULL)
        {
            addLeaf(key,ptr->right);
        }
        else
        {
            ptr->right = createLeaf(key);
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
T Tree<T>::getValue(T n)
{

}

template <class T>
Tree<T>::~Tree()
{

}

#endif // TREE_H
