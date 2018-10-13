#include <iostream>
#include <list>
#include <vector>
#include <string>


using namespace std;

template<typename I> void swap(I begin, I end);

template<typename C> void print(const C& c)
{
   cout << "{ ";
   for (auto p = c.begin(); p != c.end(); p++) cout << *p << " ";
   cout << "}" << endl;
}

template<typename E> void print(const E* a, int n)
{
   cout << "{ ";
   for (auto i = 0; i != n; i++) cout << a[i] << " ";
   cout << "}" << endl;
}


int main()
{
   int a[] = { 1, 2, 3, 4, 5, 6 };
   swap(a, a + 6);
   print(a, 6);
   cout << "Expected: { 2 1 4 3 6 5 }" << endl;
   vector<string> words = { "Mary", "had", "a", "little", "lamb" };
   swap(words.begin(), words.end());
   print(words);
   cout << "Expected: { had Mary little a lamb }" << endl;
   list<double> numbers = { 1, 0.5, 0.25, 0.125 };
   swap(numbers.begin(), numbers.end());
   print(numbers);
   cout << "Expected: { 0.5 1 0.125 0.25 }" << endl;
   string name = "Wilma";
   swap(name.begin(), name.end());
   cout << name << endl;
   cout << "Expected: iWmla" << endl;

   return 0;
}

/*
  You are given two STL iterators begin and end.

  Complete this template function that swaps neighboring elements
  of the range given by [begin, end). As always, you can assume that
  end is reachable from begin.

  If the length of the range is odd, the last element is unchanged.
*/

template<typename I> void swap(I begin, I end)
{
    while (begin!=end){
        auto temp1 = begin;
        auto temp2 = ++begin;
        if (temp2 == end) break;
        auto temp3 = *temp1;
        *temp1 = *temp2;
       *temp2 = temp3;
        begin++;
       }
}