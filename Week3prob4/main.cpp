#include <iostream>

#include <string>
using namespace std;
string intertwine(string a, string b);

int main() {
    //std::cout << "Hello, World!" << std::endl;
    string a,b,c;
    a="123";
    b="marry";
    //cout<<a[0];
    c= intertwine(a,b);
    //cout<<c;
    return 0;
}

/**
   Return a string that mixes the characters in the string a
   with the characters in b reversed. For example,
   intertwine("Fred", "Mary") yields "FyrreadM".

   If one string is longer than the other, append the unused
   characters (in reverse order if the second string is longer).
   intertwine("Sue", "Peggy") yields "SyugegeP".
*/
string intertwine(string a, string b)
{   string c;
    int i=0,k=0;
    //find lengths of strings and adding 1 for null pointer
    int size_a=a.size();
    int size_b=b.size();

    if(size_a>size_b || size_a==size_b)
    {
        cout<<"a>b"<<endl;
        while(a[i]!='\0')
        {   cout<<"A Flag : "<<a[i]<<endl;
            if(a[i]!='\0') c.insert(k,1,a[i]);
            cout<<"entered here checking a :"<<c<<endl;
            if(size_b-1>=0)c.insert(++k,1,b[size_b-1]);
                //c[k++]=b[size_b-1];
            cout<<"entered here checking b new :"<<c<<endl;
            i++;
            k++;
            size_b--;
        }
    }

    else if(size_b>size_a)
    {
        while(a[i]!='\0')
        {
            if(a[i]!='\0') c.insert(k,1,a[i]);
            c.insert(++k,1,b[size_b-1]);
            i++;
            k++;
            size_b--;

        }
        while(size_b-1>=0)
        {
            c.insert(k,1,b[size_b-1]);
            k++;
            size_b--;
        }
    }
    cout<<c;
    return c;
}