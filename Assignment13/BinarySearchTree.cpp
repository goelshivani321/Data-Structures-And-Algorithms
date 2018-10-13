#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() { clear(); }

BinaryNode *BinarySearchTree::get_root() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
    if(ptr==nullptr) return -1;
    else
        return 1 + max(height(ptr->left),height(ptr->right));
}

int BinarySearchTree::find_min() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_min(root)->data;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
    if(ptr != nullptr)
    { while (ptr->left != nullptr)
        {
            ptr = ptr->left;
        }
    }
    return ptr;
}

int BinarySearchTree::find_max() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_max(root)->data;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
    // Base case
    if (ptr == NULL)
        return 0;

    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    BinaryNode* res = ptr;
    BinaryNode* lres = find_max(ptr->left);
    BinaryNode* rres = find_max(ptr->right);
    if (lres->data > res->data)
        res->data = lres->data;
    if (rres->data > res->data)
        res->data = rres->data;
    return res;
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
    if( ptr == NULL )
        return;
    if( ptr->left != NULL )
        clear( ptr->left );
    if( ptr->right != NULL )
        clear( ptr->right );

    delete ptr;       /* free(t) if c */

    return;
}

bool BinarySearchTree::is_empty() const
{
    return (root== nullptr);
}

bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{

    while(ptr != NULL)
    {
        if(data > ptr->data) return contains(data,ptr->right);
        else if (data < ptr->data) return contains(data,ptr->left);
        else return 1;
    }

    return 0;
}

void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    /* If the tree is empty, return a new node */
    BinaryNode *newNode ;
    BinaryNode *currentNode;
    BinaryNode *trailnewNode ;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if(ptr==nullptr)
    {
        ptr=newNode;
    }
     else
    {
        currentNode = ptr;
        while(currentNode!=nullptr){
            trailnewNode=currentNode;
            if(currentNode->data == data)
            {
                return;
            }
            else if(currentNode->data > data)
            {
                currentNode = currentNode->left;
            } else
            {
                currentNode = currentNode->right;
            }

        }//end
        if(trailnewNode->data > data)
        {
            trailnewNode->left = newNode;
        }
        else
        {
            trailnewNode->right = newNode;
        }
    }

}

void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}

void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
    BinaryNode *currentNode;
    BinaryNode *trailNode;

    bool contains = false;

    if(ptr==nullptr) return;
    else{
        currentNode = ptr;
        trailNode = ptr;

        while(currentNode!=nullptr && !contains)
        {
            if (currentNode->data == data)
                contains = true;
            else
            {
                trailNode = currentNode;
                if (currentNode->data > data)
                    currentNode = currentNode->left;
                else
                    currentNode = currentNode->right;
            }
        }

        if(currentNode==nullptr) return;
        else if(contains)
        {
            if(currentNode==ptr)
            {
                remove(data,ptr);
            }
            else if (trailNode->data > data)
            {
                remove(data,trailNode->left);
            } else{
                remove(data,trailNode->right);
            }
        }
    }
}