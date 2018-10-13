#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const char* nthrep(const char* str, int n);

int main()
{
   const char* p = "occurrence";
   const char* r = nthrep(p, 1);
   cout << r - p << endl;
   cout << "Expected: 1" << endl;
   r = nthrep(p, 2);
   cout << r - p << endl;
   cout << "Expected: 4" << endl;
   r = nthrep(p, 3);
   cout << boolalpha << (r == NULL) << endl;
   cout << "Expected: true" << endl;
   p = "abbaccccaddabbra";
   r = nthrep(p, 2);
   cout << r - p << endl;
   cout << "Expected: 4" << endl;
   r = nthrep(p, 3);
   cout << r - p << endl;
   cout << "Expected: 9" << endl;
}

/*
  Return a pointer to the nth occurrence of a repeated character
  in the given string. For example, if str is "occurrence" and n is 2,
  return a pointer to the first r.
*/
const char* nthrep(const char* str, int n)
{
    int repeat = 1;
    const char* it = str;
    const char* y;
    y=str +1;
    while(*y!='\0')
    {

        if(*y==*it)
        {
            n=n-1;
            if(n==0)
            {
                return it;
            }
            while(repeat && *y!='\0')
            {
                ++y;
                if(*it!=*y)
                {
                    it=y;
                    y=y+1;
                    repeat=0;
                }
            }
            repeat=1;
        }
        else
        {
            ++it;
            ++y;
        }
    }
    return NULL;
}