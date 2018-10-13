#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool someDifferent(string str);
string shuffle(string a, string b);
string digits(string str);
int altSum(vector<int> v);
int altSumHelper(vector<int> v, int a);
vector<string> digitGroups(string str);
void digitsHelper(string str1, string str2, vector<string> &v);

int main() {

    cout<<"Check!!!!!! : ";
    /*
     * Code for testing someDifferent
     */
//    bool answer=false;
//    answer=someDifferent("aa");
//    cout<<answer;

    /*
     * Code for testing shuffle
     */
//    string c="";
//
//    c=shuffle("fred","wilma");
//    cout<<c;

    /*
     * Code for digits
     */
//    string c="a123";
//    bool yes = isdigit(c[0]);
//    cout<<yes;

    /*
     * Code for altSumHelper
     */
//    vector <int> v1={1,2,3,4,5};
//    int val=0;
//    val=altSum(v1);
//    cout<<val;

    /*
     * Code for digit groups
     */
    vector<string> vect;
    string c="I like 7 and 13";
   vect =digitGroups(c);
    for (std::vector<string>::const_iterator i = vect.begin(); i != vect.end(); ++i)
        std::cout << *i << ' ';


    return 0;
}

void digitsHelper(string str1, string str2, vector<string> &v)
{
    if(str1=="" && str2=="")
    {
        return;
    }
    if(str1=="" && str2!="")
    {
        v.push_back(str2);
        return;
    }
    else if ( isdigit(str1[0]) && str2!="")
    {
        str2+=str1.substr(0,1);
        digitsHelper(str1.substr(1),str2,v);
        return;
    }
    else if (isdigit(str1[0]) && str2=="")
    {
        str2=(str1.substr(0,1));
        digitsHelper(str1.substr(1),str2,v);
        return;
    }
    else if(!isdigit(str1[0]) && str2!="")
    {
        v.push_back(str2);
        str2="";
        digitsHelper(str1.substr(1),str2,v);
        return;
    }
    else if(!isdigit(str1[0]) && str2=="")
    {
        digitsHelper(str1.substr(1),str2,v);
        return;
    }


}

/**
   Given a string, return a vector of all substrings consisting of
   digits contained in it. For example, if str is "I like 7 and 13",
   return a vector containing "7" and "13".
   Use a recursive helper method. Do not use loops.
   A digit is a character between '0' and '9' inclusive.

*/
vector<string> digitGroups(string str)
{
    vector<string> result;
    digitsHelper(str, "", result);
    return result;
}

int altSumHelper(vector<int> v, int a)
{

    if(v.empty())
    {
        return 0;
    }
    vector <int> v1=v;
    if(a==0)
    {
        v.erase(v.begin());
        return v1.at(0) +  altSumHelper(v,1);
    }
    if(a==1)
    {
        v.erase(v.begin());
        return altSumHelper(v,0) - v1.at(0);
    }
}

/**
   Given a vector of integers, return the alternating sum
   v[0] - v[1] + v[2] - v[3] + ...
   If the vector is empty, the alternating sum is zero.
   Use a recursive helper method. Do not use loops.

*/
int altSum(vector<int> v)
{
    return altSumHelper(v, 0);
}

/**
   Given a string, return a string of all digits contained in it.
   Use recursion. Do not use loops.
   A digit is a character between '0' and '9' inclusive.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
string digits(string str)
{
    if(str=="")
    {
        return "";
    }
    if (isdigit(str[0]))
    {
        return str.substr(0,1) + digits(str.substr(1));
    }
    else
    {
        return digits(str.substr(1));
    }

}

/**
   Shuffle two strings by alternating characters from them. If one string
   runs out before the other, just pick from the longer one.
   For example, shuffle("Fred", "Wilma") is "FWrieldma".
   Use recursion. Do not use loops.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
string shuffle(string a, string b)
{
    string c="";
    if(a=="" && b=="")
    {
        return "";
    }
   else  if (a=="")
    {
        return b;
    }
    else if (b=="")
    {
        return a;
    }
    else
    {
        return a.substr(0,1)+b.substr(0,1)+shuffle(a.substr(1),b.substr(1)) ;

    }
}

/**
   Return true if the given string contains at least two
   different characters. Use recursion. Do not use loops.
   Hint: If str[0] is not the same as str[1], you have
   your answer. Otherwise, look at str.substr(1) (the substring of str
   from position 1 to the end).
*/
bool someDifferent(string str)
{
    if(str.length()<=1)
        return false;
    if((str[0]!=str[1]) )
        return true;
    else
    {
        str=str.substr(1);
        return  someDifferent(str);
    }

}


