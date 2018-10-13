#include <iostream>
#include<cmath>
#include <typeinfo>
using namespace std;

double decimal_time(int x,int y,int z,bool pm);
float rounding(float time);
int main() {

    double decimaltime= decimal_time(9,0,0,0);
    cout<<decimaltime;
    //cout<<cmath::round(12.2);
    return 0;
}

double decimal_time(int hours, int minutes, int seconds, bool pm)
{
    float newhour,newmin,newsec;
    if(hours>=24 || minutes>=60 || seconds>=60 ||hours<0||minutes<0||seconds<0) return -1;
    if(hours==0 && minutes==0 && seconds==0) return -1;

    if(pm==0)
    {
        float total_time= (hours*3600)
                          +(minutes*60)+seconds;
        cout<<"dec_time : "<<(total_time/86400)*100000<<endl;
        float dec_time=(total_time/86400)*10;
        //dec_time= (round(dec_time*10000))/10000;
        dec_time= rounding(dec_time);
        return dec_time;
    }
    else
    {
        hours+=12;
        float total_time= (hours*3600)
                          +(minutes*60)+seconds;
        cout<<"total_time : "<<total_time<<endl;
        cout<<"new_time : "<<(total_time/86400)*100000<<endl;
        float dec_time=(total_time/86400)*10;
        dec_time= rounding(dec_time);
        return dec_time;
    }
}

float rounding(float time)
{
    cout<<time<<endl;
    time=time*100000;
    int new_time = time;
    cout<<new_time<<endl;
    int units=new_time%10;
    new_time=new_time/10;
    if(units>=5) new_time+= 1;
    cout<<new_time<<endl;

    return new_time/10000.0;

}