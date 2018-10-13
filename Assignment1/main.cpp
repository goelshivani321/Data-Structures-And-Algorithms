#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    /***** Complete this program. *****/
    //declaring variables
    double pi15, pi16, pi18, pi22, pi31, pi;
    double pi31_part1,pi31_part2,pi31_part3;
    float current_odd_number,current_square,sum;
    pi = 4*atan(1);
    /*
    cout<<4*arctan(1)<<endl;
    cout << "pi   = " <<setprecision(16)<<4*atan(1) << " = 4*arctan(1)" << endl;

    cout << endl;
    cout << "Ramanujan's pi formulas:" << endl;

    pi15= 12*(log((2+sqrt(5))*(3+sqrt(13))/sqrt(2)))/sqrt(130);
    cout<<"pi15 = "<<setprecision(16)<<pi15<<endl;

    pi16= 24*(log(sqrt((10+11*sqrt(2))/4)+sqrt((10+7*sqrt(2))/4)))/sqrt(142);
    cout<<"pi16 = "<<setprecision(16)<<pi16<<endl;

    pi18=12*log((2*sqrt(2)+sqrt(10))*(3+sqrt(10)))/sqrt(190);
    cout<<"pi18 = "<<setprecision(16)<<pi18<<endl;

    pi22=12*log((3+sqrt(5))*(2+sqrt(2))*(5+2*sqrt(10)+sqrt(61+20*sqrt(10)))/4)/sqrt(310);
    cout<<"pi22 = "<<setprecision(16)<<pi22<<endl;

    pi31_part1=(5+sqrt(29))/sqrt(2);
    pi31_part2=(5*sqrt(29)+11*sqrt(6));
    pi31_part3=sqrt((9+3*sqrt(6))/4)+sqrt((5+3*sqrt(6))/4);

    pi31= 4*log(pow(pi31_part1,3.0)*pi31_part2*pow(pi31_part3,6.0))/sqrt(522);
    cout<<"pi31 = "<<setprecision(16)<<pi31<<endl;

    cout<<endl;
*/
    cout << "Euler's infinite sum for pi*pi/6 = " <<setprecision(8)<< pi*pi/6 << endl;

    current_odd_number=1;
    sum=0;
    current_square=0;
    int num_iteration=0;
    while((1/current_square)>pow(10,-8)) {

            current_square += current_odd_number;
            sum += (1 / current_square);



        current_odd_number += 2;
        num_iteration++;
        cout<<fixed<<setprecision(16)<<1/current_square<<endl;
    }

    cout<<fixed<<setprecision(16)<<pow(10,-8)<<endl;


    cout << "                      Converged to " <<setprecision(8)<< sum
         << " after " << num_iteration << " iterations" << endl;

    cout<<endl;

    float euler_pi= sqrt(sum*6);

    cout << "Euler's estimate for pi = " <<setprecision(8)<< euler_pi<< endl;
    cout << "                  error = " << (pi-euler_pi) << endl;
}