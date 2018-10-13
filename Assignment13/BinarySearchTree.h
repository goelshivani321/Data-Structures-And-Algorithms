/**
 * An implementation of the binary search tree and its operations.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 *
 * Modified from Data Structures and Algorithm Analysis in C++, 4th ed.
 * by Mark Allen Weiss
 * Pearson, 2014
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include "BinaryNode.h"

using namespace std;

class BinarySearchTree
{
public:
    /**
     * Default constructor
     */
    BinarySearchTree();

    /**
     * Destructor
     */
    virtual ~BinarySearchTree();

    /**
     * Getter.
     * @return pointer to the root of the tree.
     */
    BinaryNode *get_root() const;

    /**
     * Public gettere.
     * @return the height of the tree.
     */
    int height() const;

    /**
     * Find the minimum data item in a subtree.
     * @return the minimum data item in the tree
     *         or nullptr if the tree is empty.
     * @throw an error message if an error occurred.
     */
    int find_min() const throw(string);

    /**
     * Find the maximum data item in a subtree.
     * @return pointer to the maximum data item in the tree
     *         or nullptr if the tree is empty.
     * @throw an error message if an error occurred.
     */
    int find_max() const throw(string);

    /**
     * Public method to empty a subtree.
     */
    void clear();

    /**
     * @return true if and only if the tree is empty.
     */
    bool is_empty() const;

    /**
     * Search for a data item in the tree.
     * @param data the data to search for.
     * @return true if and only if data is in the tree.
     */
    bool contains(const int data) const;

    /**
     * Insert a data item into a subtree
     * and set the new root of the subtree.
     * @param data the data to insert into the tree.
     */
    void insert(const int data);

    /**
     * Remove a data item from a subtree
     * and set the new root of the subtree.
     * Do nothing if the data item is not found.
     * @param data the data to remove.
     */
    void remove(const int data);

protected:
    /**
     * Compute the height of a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return the height.
     */
    virtual int height(const BinaryNode *ptr) const;

    /**
     * Insert a data item into a subtree
     * and set the new root of the subtree.
     * @param data the data to insert.
     * @param ptr pointer to the root node of the subtree.
     */
    virtual void insert(const int data, BinaryNode* &ptr);

    /**
     * Protected method to remove a data item from a subtree
     * and set the new root of the subtree.
     * Do nothing if the data item is not found.
     * @param data the data to remove.
     * @param ptr pointer to the root node of the subtree.
     */
    virtual void remove(const int data, BinaryNode* &ptr);

private:
    BinaryNode *root;

    /**
     * Find the minimum data item in a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return pointer to the node containing the smallest data item
     *         or nullptr if the subtree is empty.
     */
    BinaryNode *find_min(BinaryNode *ptr) const;

    /**
     * Find the maximum data item in a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return pointer to the node containing the largest data item
     *         or nullptr if the subtree is empty.
     */
    BinaryNode *find_max(BinaryNode *ptr) const;

    /**
     * Empty a subtree.
     * @param ptr pointer to the root node of the subtree.
     */
    void clear(BinaryNode* &ptr);

    /**
     * Search for a data item in a subtree.
     * @param data the data to search for.
     * @param ptr pointer to the root node of the subtree.
     * @return true if and only if data is in the tree.
     */
    bool contains(const int data, BinaryNode *ptr) const;
};


#endif // BINARY_TREE_CHECKER_H
