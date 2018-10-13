/*
 * practice2.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Shivani
 */

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

int main()
{
    string min_label="Hydrogen",max_label="Oxygen",min_abvr="H",max_abvr="O";
    double min_val=2.02,max_val=122.43;
    cout<< "|leftedge" << "                    " << "right edge|"<< endl;
    // Total output has 40 chars in lenth, from left edge to write edge  [Tlenght]
    cout<< endl;

    std::cout << std::resetiosflags(std::ios::adjustfield);

    std::cout << std::setiosflags(std::ios::left);// prints to the left edge of the width  window (36) [windowA]
    std::cout << std::setw(50) << "Hydrogen" ;

    std::cout << std::setiosflags(std::ios::right);// prints to the right of edge of the width window (4) [windowB]
    std::cout << std::setw(10) << "1.00" << '\n';

    // just keep the sum of [windowA] + [windowB] = [Tlength]
    //     and replace these strings with your veriables

    cout<<left<<setw(50)<<min_label+" "+min_abvr;
    //cout<<"*****";
    cout<<right<<setw(10)<<fixed<<setprecision(2)<<min_val;
    cout<<endl;

    cout<<left<<setw(50)<<max_label+" "+max_abvr;
    //cout<<"*****";
    cout<<right<<setw(10)<<fixed<<setprecision(2)<<max_val;


    return 0;
}

