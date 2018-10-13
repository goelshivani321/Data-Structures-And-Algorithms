#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree() : BinarySearchTree() {}

AvlTree::~AvlTree() {}

int AvlTree::height(const BinaryNode *ptr) const
{
    /***** Complete this function. *****/
return 0;
}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    /***** Complete this function. *****/

    // Recompute the node's height.
   // ptr->height = ...

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
    /***** Complete this function. *****/
    return nullptr;
}

//BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
//{
//    /***** Complete this function. *****/
//}

BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3) {
    return nullptr;
}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
    return nullptr;
}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
    return nullptr;
}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}