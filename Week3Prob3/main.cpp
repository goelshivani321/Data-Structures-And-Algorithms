#include <iostream>
#include <vector>
using namespace std;

void precedingsum(double a[], int n);

void print(double v[], int size)
{
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        cout << v[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "}" << endl;
}

int main()
{
    double values[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    precedingsum(values, sizeof(values) / sizeof(values[0]));
    print(values, sizeof(values) / sizeof(values[0]));
    cout << "Expected: {3, 4, 8, 9, 14, 23, 25, 31}" << endl;

    double values2[] = { 1, -2, 3, -4, 5, -6 };
    precedingsum(values2, sizeof(values2) / sizeof(values2[0]));
    print(values2, sizeof(values2) / sizeof(values2[0]));
    cout << "Expected: {1, -1, 2, -2, 3, -3}" << endl;

    double values3[] = { 1, 2 };
    precedingsum(values3, sizeof(values3) / sizeof(values3[0]));
    print(values3, sizeof(values3) / sizeof(values3[0]));
    cout << "Expected: {1, 3}" << endl;

    double values4[] = { 1 };
    precedingsum(values4, sizeof(values4) / sizeof(values4[0]));
    print(values4, sizeof(values4) / sizeof(values4[0]));
    cout << "Expected: {1}" << endl;

    double values5[] = {};
    precedingsum(values5, sizeof(values5) / sizeof(values5[0]));
    print(values5, sizeof(values5) / sizeof(values5[0]));
    cout << "Expected: {}" << endl;

    return 0;
}

/**
   Replaces each element in an array with the sum of itself and the
   elements preceding it.

   For example { 1, 2, 3, 4 } turns into { 1, 3, 6, 10 }

   Do not declare any arrays or vectors.
   @param a an array
   @param n the length of the array
*/
void precedingsum(double a[], int n)
{
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i]+a[i-1];
    }
}