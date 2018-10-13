//IGNORESPACE false
/**
   This program reads in the name of a file from stdin.
   Then it opens the file and reads all lines of the file.
   Each line has the form 

   label abbreviation value

   The label and abbreviation are nonempty strings without spaces. 
   The value is a floating-point number. 

   Print out the label and abbreviation with the smallest and 
   largest value, in a left-justified, field of width 50, 
   followed by the value in a right-justified field of width 10, with
   three digits after the decimal point. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    float val=0.0;
    string label,abvr;

    string input_file="/Users/shivanigoel/CLionProjects/Week3prog5/number.txt";

    ifstream in(input_file);

    float max_val,min_val;
    string max_abvr,max_label,min_abvr,min_label;
    in>>label>>abvr>>val;
    max_val=val;
    min_val=val;
    max_abvr=abvr;
    min_abvr=abvr;
    max_label=label;
    min_label=label;
    while(in>>label>>abvr>>val)
    {

        if(val>max_val)
        {
            max_val=val;
            max_abvr=abvr;
            max_label=label;
        }
        if(val<min_val)
        {
            min_val=val;
            min_abvr=abvr;
            min_label=label;
        }
    }
/*
    cout<<left<<min_label<<" "<<setw(50)<<left<<min_abvr<<" "<<
        right<<setw(10)<<fixed<<setprecision(2)<<right<<min_val<<endl;

    cout<<left<<max_label<<" "<<setw(50)<<left<<max_abvr<<" "<<
        right<<setw(10)<<fixed<<setprecision(2)<<max_val<<endl;
*/

    cout<<left<<setw(50)<<min_label+" "+min_abvr<<cout.fill(' ');
    //cout<<"*****";
    cout<<right<<setw(10)<<fixed<<setprecision(2)<<min_val;
    cout<<endl;

    cout<<left<<setw(50)<<max_label+" "+max_abvr;
    //cout<<"*****";
    cout<<right<<setw(10)<<fixed<<setprecision(2)<<max_val;


    in.close();

    return 0;
}