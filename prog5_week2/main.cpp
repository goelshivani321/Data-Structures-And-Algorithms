#include <cstdlib>
#include <iostream>


using namespace std;

double rand_double();
double inside_quarter_circle(double radius_1, int tries_1);

int main() {


    srand(42);

    cout << inside_quarter_circle(1, 1000) << endl;
    cout << inside_quarter_circle(20, 1000) << endl;
    // Approximating pi
    cout << 4 * inside_quarter_circle(1, 10000000) << endl;
    return 0;
}

double inside_quarter_circle(double radius, int tries)
{
    //generate coordinates
    double x=0,y=0,dist_sq=0,hits=0,miss=0,return_value=0;
    int tries_bkp=tries;
    while(tries>0)
    {
        x= radius*rand_double();
        y= radius*rand_double();
        dist_sq = ((x*x)+(y*y));
       // cout<<x<<"\t"<<y<<"\t"<<dist_sq<<"\t";
        if(dist_sq<=(radius*radius))
        {
            hits++;
            //cout<<"hits"<<endl;
        }
        else
        {
            miss++;
            //cout<<"miss"<<endl;
        }
        tries--;
    }
   // cout<<"ratio---------"<<hits/miss<<endl;
    return_value=hits/tries_bkp;
    return return_value;

}

/*
  Returns a random number between 0 and 1.
*/
double rand_double()
{
    return rand() * 1.0 / RAND_MAX;
}

