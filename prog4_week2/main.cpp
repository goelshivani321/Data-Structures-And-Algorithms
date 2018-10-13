#include <iostream>
#include <cstdlib>

using namespace std;
int die_toss();
int game1_wins(int s, int i, int m, int x);
int game2_wins(int l, int u, int y, int q, int k, int z);
int game1(int iter);
int game2(int itere);

int main() {

    srand(42);
    cout << game1(1000) << endl;
    /*cout << game2(1000) << endl;
    cout << game1(10000) << endl;
    cout << game2(10000) << endl;
    cout << game1(100000) << endl;
    cout << game2(100000) << endl;
    cout << game1(1000000) << endl;
    cout << game2(1000000) << endl;*/
    return 0;
}

int die_toss()
{
    return 1 + rand() % 6;
}

/*
  Return true if you got a pair of 5s and 6s.
*/
int game1_wins(int a, int b, int c, int d)
{
    int fives=0,sixs=0;

    if (a==5)fives++;
    if (b==5)fives++;
    if (c==5)fives++;
    if (d==5)fives++;

    if(a==6)sixs++;
    if(b==6)sixs++;
    if(c==6)sixs++;
    if(d==6)sixs++;

    if(fives==2 && sixs==2)
    {
       // cout<<"--------------------------------------"<<endl;
        return 1;
    }
    else return 0;
}

/*
  Return true if you got four 6s.
*/
int game2_wins(int a, int b, int c, int d, int e, int f)
{
    int sixs=0,not_sixs=0;
    if(a==6)sixs++;
    if(b==6)sixs++;
    if(c==6)sixs++;
    if(d==6)sixs++;
    if(e==6)sixs++;
    if(f==6)sixs++;
    if(e != 6) not_sixs++;
    if(f != 6) not_sixs++;
    if(a != 6) not_sixs++;
    if(b != 6) not_sixs++;
    if(c != 6) not_sixs++;
    if(d != 6) not_sixs++;

    if(sixs==4 && not_sixs==2) return 1;
    else return 0;

}

/*
  Play game 1 for the given number of iterations and return the
  number of wins.
*/
int game1(int iterations)
{
    int win=0,a,b,c,d;

    while(iterations>0)
    {
        a= die_toss();
        b= die_toss();
        c= die_toss();
        d= die_toss();
        cout<<"the values of a b c d are    "<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
        win+= game1_wins(a,b,c,d);
        iterations--;
    }
    return win;
}

/*
  Play game 2 for the given number of iterations and return the
  number of wins.
*/
int game2(int iterations)
{
    int win=0,a,b,c,d,e,f;
    while(iterations>0)
    {
        a= die_toss();
        b= die_toss();
        c= die_toss();
        d= die_toss();
        e= die_toss();
        f= die_toss();
        //cout<<"the values of a b c d are    "<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
        win+= game2_wins(a,b,c,d,e,f);
        iterations--;
    }
    return win;

}
