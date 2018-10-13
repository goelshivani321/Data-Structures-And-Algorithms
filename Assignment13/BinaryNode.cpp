#include "BinaryNode.h"

BinaryNode::BinaryNode(const int data)
        : data(data), height(0), left(nullptr), right(nullptr)
{
}

BinaryNode::BinaryNode(const int data, BinaryNode *left, BinaryNode *right)
        : data(data), height(0), left(left), right(right)
{
}

BinaryNode::~BinaryNode()
{
}
