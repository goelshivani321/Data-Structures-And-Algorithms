#include <iostream>
#include <cstring>

using namespace std;

void repeat(const char* str, int n, char result[], int sz);

int main()
{
    char results[28];
    char* r2 = results;
    char* r1 = results + 10;
    char* r4 = results + 21;
    char* r3 = results + 22;
    char* r5 = results + 26;
    strcpy(r5, "x");
    cout<<"=============================\n";
    repeat("Hello", 2, r1, 11);
    //cout<<result<<endl;
    repeat("Goodbye", 3, r2, 10);
   // cout<<results<<endl;
    repeat("Goodbye", 3, r3, 4);
    //cout<<results<<endl;
    repeat("HI", 10, r4, 1);
   // cout<<results<<endl;
    cout<<"=============================\n";
    cout << r1 << endl;
    cout << "Expected: HelloHello" << endl;
    cout << r2 << endl;
    cout << "Expected: GoodbyeGo" << endl;
    cout << r3 << endl;
    cout << "Expected: Goo" << endl;
    cout << "\"" << r4 << "\"" << endl;
    cout << "Expected: \"\"" << endl;
    cout << "\"" << r5 << "\"" << endl;
    cout << "Expected: \"x\"" << endl;

    return 0;
}

/*
  Repeats a string n times and places it into a buffer, filling
  it up as much as possible, and providing a terminating 0.
  Use strncpy.
  @param str a string
  @param n an integer
  @param result a character array to hold the result
  @param sz the size of result
*/

void repeat(const char* str, int n, char result[], int sz)
{
    int len= 0;
    int sz2=sz-1;
    char *resultbegin=result;
    const char* str2=str;
    while(*str2!='\0')
    {
        len++;
        str2++;
    }


        while(n>0 && sz2>0)
        {

            strncpy(result,str,sz2);
            result+=len;
            sz2-=len;
            n--;

        }
        result[sz-1]='\0';
    if(sz==1)
    {
        result[sz]='\0';
    }

}