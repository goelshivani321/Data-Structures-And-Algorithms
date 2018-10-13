#include <iostream>
#include <string>
#include <map>
#include "Thing.h" 
using namespace std;
int main()
{
    Thing t;

    t.insert("one", 1);
    t.insert("two", 2);
    map<string, int> tdata = t.get_data();
    map<string, int>::iterator it;

     cout << "Map dump:" << endl;

    for (it = tdata.begin(); it != tdata.end(); it++)
     {
       cout << it->first << ":" << it->second << endl;
        }
    cout << endl << "Map searches:" << endl; 
    cout << "  Searching for \"one\":";
    it = t.search("one");
    if (it != tdata.end()) cout << it->second << endl;
    else cout << "***" << endl; 
    cout << "  Searching for \"two\":";
     it = t.search("two");
     if (it != tdata.end()) cout << it->second << endl;
     else cout << "***" << endl; 
     cout << "  Searching for \"three\":";
     it = t.search("three");
   if (it != tdata.end()) cout << it->second << endl;
     else cout << "***" << endl;

   return 0;
}
