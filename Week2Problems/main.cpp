#include <iostream>
using namespace std;
int min(int x,int d,int f,int g);
int max(int x,int d,int f,int g);
double middle(int x,int d,int f,int g);
int main() {

    int a,b,c,d;

    cin>>a;
    cout<<a<<endl;
    cin>>b;
    cout<<b<<endl;
    cin>>c;
    cout<<c<<endl;
    cin>>d;
    cout<<d<<endl;

    double output= middle(a,b,c,d);
    cout<<output;
    return 0;
}


int min(int a, int b, int c, int d)
{
    int result = a;
    if (b < result) result = b;
    if (c < result) result = c;
    if (d < result) result = d;
    return result;
}
int max(int a, int b, int c, int d)
{
    int result = a;
    if (b > result) result = b;
    if (c > result) result = c;
    if (d > result) result = d;
    return result;
}

double middle(int a, int b, int c, int d)
{
    int maxValue, minValue, sum=0;
    double average;
    maxValue= max(a,b,c,d);
    minValue= min(a,b,c,d);
cout<<"minvalue is"<<minValue<<endl;
    cout<<"maxValue is"<<maxValue<<endl;

    if(a!=maxValue && a!=minValue) sum+=a;
    cout<<"check sum:"<<sum<<endl;
    if(b!=maxValue && b!=minValue) sum+=b;
    cout<<"check sum:"<<sum<<endl;
    if(c!=maxValue && c!=minValue) sum+=c;
    cout<<"check sum:"<<sum<<endl;
    if(d!=maxValue && d!=minValue) sum+=d;
    cout<<"sum is="<<sum<<endl;
    average=static_cast<double>(sum)/2;

    return average;

}