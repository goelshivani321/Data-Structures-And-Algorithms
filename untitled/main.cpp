#include <iostream>
#include <vector>
#include<chrono>
using namespace std;

double nnavg(int a[], int alen);
void swap3last(vector<int>& a);
int main() {
    /*
    int a[] = {1,2,3,4,5,-1,-3,4,-5,8};
    int alen= 10;
    double avg = nnavg(a,alen);
    cout<<avg;*/

//    vector<int> arr;
//    arr={1,2,3,4,5,6,7,8,9,10};
//    swap3last(arr);


    int* num = new int;
    *num = 10;
    cout << num << endl;
    delete num;
    *num = *num * 2;
    cout << num << endl;

    return 0;

}

/**
   Computes the average of all nonnegative elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all nonnegative elements in a, or 0 if there are none.
*/
double nnavg(int a[], int alen)
{   double avg,sum=0, num=0;

    for(int i =0; i<alen;i++)
    {
        if(a[i]>=0)
        {
            sum+=a[i];
            num++;
        }
    }

    if(num!=0) return (sum/num);

    return 0;
}


/**
   Swaps the third and last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 1, 6, 1, 5, 9, 1, 4}.
   If the array has length < 3, do nothing.
   @param a a vector of integers
*/
void swap3last(vector<int>& a)
{
    int third, last, num;
    if(a.size()>3)
    {
        num=a[2];
        a[2]=a.back();
        a.back()=num;

        cout<<a[2];
        cout<<a.back();

    }
}

