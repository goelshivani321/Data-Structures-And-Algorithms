/**
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Coordinate.h"
#include "Node.h"
#include "SortedLinkedList.h"

using namespace std;

const string BOUNDARY_FILE_NAME = "/Users/shivanigoel/CLionProjects/Assignment7_USMAPS/boundary-data copy.csv";
const string CITY_FILE_NAME     = "/Users/shivanigoel/CLionProjects/Assignment7_USMAPS/city-data copy.csv";

/**
 * Read and process the boundary data, then print the boundary map.
 * @param input the input stream.
 * @param list the sorted linked list of boundary data.
 */
void do_boundary(ifstream& input, SortedLinkedList& list);

/**
 * Read and process the city data, then print the map with cities.
 * @param input the input stream.
 * @param list the merged sorted linked of boundary and city data.
 */
void do_cities(ifstream& input, SortedLinkedList& list);

/**
 * The main. Read the boundary data and city data files.
 * Print a map of the U.S. boundary. Print a map of the U.S. with cities.
 */
int main()
{
    ifstream input;         // input stream
    SortedLinkedList list;  // sorted linked list of Node objects

    // Open the boundary data file.
    input.open(BOUNDARY_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << BOUNDARY_FILE_NAME << endl;
        return -1;
    }

    // Process the U.S. boundary.
    do_boundary(input, list);
    input.close();

    cout << endl;

    // Open the city data file.
    input.open(CITY_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << CITY_FILE_NAME << endl;
        return -1;
    }

    // Process the U.S. cities.
    do_cities(input, list);
    input.close();

    cout << endl << "Done!" << endl;
    return 0;
}

void do_boundary(ifstream& input, SortedLinkedList& list)
{
    Coordinate coordinate;

    // Loop to input each boundary coordinate
    // and insert it into the sorted linked list.
    while (!input.eof())
    {
        input >> coordinate;
        list.insert(new Node(coordinate));
    }

    // Print the boundary map.
    cout << "=============" << endl;
    cout << "U.S. boundary" << endl;
    cout << "=============" << endl << endl;
    cout << list << endl;
}

void do_cities(ifstream& input, SortedLinkedList& list)
{
    City city;

    // Loop to input each city and insert it into the sorted linked list.
    // The city nodes will be merged with the boundary coordinate nodes.
    while (!input.eof())
    {
        input >> city;
        list.insert(new Node(city));
    }

    // Print the city map.
    cout << "===========" << endl;
    cout << "U.S. Cities" << endl;
    cout << "===========" << endl << endl;
    cout << list << endl;
}