#include <iostream>
using namespace std;

int digitsInCommon(int x, int y);
//int* find_digits(int num);
//int compare_digits(int arr[],int arr2[]);
int main() {

    int a,b,commonDigit;
    a=7770777;
    b=70087;

    commonDigit=digitsInCommon(a,b);
    cout<<"Common Digits : "<<commonDigit<<endl;

    return 0;
}
/*
int digitsInCommon(int m, int n)
{
    int arr[10]={0},same_digits=0;
    while(m>0)
    {
        int digit = m%10;
        m=m/10;
        arr[digit]=1;
    }
    while(n>0)
    {
        int digit = n%10;
        n=n/10;
        if(arr[digit]==1)
        {
            same_digits+=1;
            arr[digit]=0;
        }
    }
    return same_digits;

}*/

int digitsInCommon(int m,int n)
{
    int common=0;

    for(int i = 0;i<10;i++)
    {
       // cout<<"Checking for "<<i<<endl;
        int new_m=m;
        int new_n=n;
        bool match_found=0;
        while(new_m>0)
        {
            int digit_m = new_m%10;
            new_m=new_m/10;
//            cout<<"Inside first while\t";
            if(i==digit_m && !match_found)
            {
                while(new_n>0)
                {
//                    cout<<"Inside second while\t";
                    int digit_n = new_n%10;
                    new_n=new_n/10;
                    if(i==digit_n)
                    {
                        common++;
                        match_found=1;
//                        cout<<"The common digit is "<<i<<endl;
                        break;
                    }
                }
            }


        }
    }
    return common;
}
