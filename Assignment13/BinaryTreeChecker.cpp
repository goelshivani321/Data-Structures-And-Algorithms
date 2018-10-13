#include <iostream>
#include "BinaryTreeChecker.h"

using namespace std;

BinaryTreeChecker::BinaryTreeChecker(BinarySearchTree& tree)
        : tree(tree)
{
    cache.clear();
}

BinaryTreeChecker::~BinaryTreeChecker() {}

void BinaryTreeChecker::clear()
{
    cache.clear();
}

void BinaryTreeChecker::add(const int data)
{
    cache.insert(data);
}

void BinaryTreeChecker::remove(const int data)
{
    cache.erase(data);
}

int BinaryTreeChecker::check(const bool dump)
{
    data.clear();
    walk(tree.get_root());

    return compare(dump);
}

void BinaryTreeChecker::walk(BinaryNode *node)
{
    if (node == nullptr) return;

    walk(node->left);
    data.insert(node->data);
    walk(node->right);
}

int BinaryTreeChecker::compare(const bool dump) const
{
    typename set<int>::iterator itCache;
    typename set<int>::iterator itData;

    itCache = cache.begin();
    itData  = data.begin();

    if (dump) cout << endl;

    while (itCache != cache.end())
    {
        if (itData == data.end()) return INSUFFICIENT_DATA;
        if (dump) cout << *itData << ":" << *itCache << " ";
        if (*itCache != *itData) return DATA_MISMATCH;

        itCache++;
        itData++;
    }

    if (dump) cout << endl;
    if (itData != data.end()) return REMAINING_DATA;

    return NO_ERROR;
}