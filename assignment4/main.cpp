//Shivani Mangal
#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 10;
const int PLACES         = 2000000;        // desired decimal places 5000
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Complete this file. *****/
/*
 * Function to print the result in a file
 */
void print();
duration<double> elapsed;

int main (void)
    {
        /*
         * Starting clock
         */

        auto start = std::chrono::high_resolution_clock::now();
        /*
         * Decalaring mpf_t variables
         */
        mpf_t a,b,c,d;
        mpf_t part1,part2,part3,part4,part5,part6,part7,part8,part9,part10,part11,part12,part13;
        mpf_t a0,y0,ypow,base,ynew,ynum,ydem,root2,anew;
        mpz_t four,two,one,eye;

        /*
         * Initialising variables
         */

        mpf_init (a);
        mpf_init (b);
        mpf_init (c);
        mpf_init (d);
        mpf_init2(root2,PLACES+1);
        mpf_init2(a0,PLACES+1);
        mpf_init2(y0,PLACES+1);
        mpf_init2(ypow,PLACES+1);
        mpf_init2(ynew,PLACES+1);
        mpf_init2(anew,PLACES + 1);
        mpf_init2(ynum,PLACES+1);
        mpf_init2(ydem,PLACES+1);
        mpf_init2(part1,PLACES+1);
        mpf_init2(part2,PLACES+1);
        mpf_init2(part3,PLACES+1);
        mpf_init2(part4,PLACES+1);
        mpf_init2(part5,PLACES+1);
        mpf_init2(part6,PLACES+1);
        mpf_init2(part7,PLACES+1);
        mpf_init2(part8,PLACES+1);
        mpf_init2(part9,PLACES+1);
        mpf_init2(part10,PLACES+1);
        mpf_init2(part11,PLACES+1);
        mpf_init2(part12,PLACES+1);
        mpf_init2(part13,PLACES+1);

        mpz_init2(four,PLACES+1);
        mpz_init2(two,PLACES+1);

        /*
         * The borweign formula
         */

        // Setting up variables a,b,c,d for values 1,2,4,6

        mpf_set_str (a, "1", BASE);
        mpf_set_str (b, "2", BASE);
        mpf_set_str (c, "4", BASE);
        mpf_set_str (d, "6", BASE);

        mpz_set_str(four,"4",BASE);
        mpz_set_str(two,"2",BASE);
        mpz_set_str(one,"1",BASE);

        //storing value of sqrt 2 in root2
        mpf_sqrt(root2,b);

        // storing value of a0
        mpf_mul(part1,c,root2);
        mpf_sub(a0,d,part1);

        // storing values of y0
        mpf_sub(y0,root2,a);

        //working on main iterations
        for(double i=1;i<=MAX_ITERATIONS;i++)
        {
            // storing value of y
            //char* val=i;

            mpz_init(eye);

            mpz_set_d(eye,i);

            mpz_mul(eye,eye,two);
            mpz_add(eye,one,eye);

            mpf_pow_ui(ypow,y0,mpz_get_ui(four));
            mpf_sub(part2,a,ypow);

            mpf_sqrt(part3,part2);

            mpf_sqrt(part3,part3);

            mpf_sub(ynum,a,part3);


            mpf_add(ydem,a,part3);

            mpf_div(ynew,ynum,ydem);

            //set value of ynew to y0
            mpf_set(y0,ynew);

            //set value for a

            //working on value of a
            //1+yi : part4
            mpf_add(part4,a,ynew);
            //(1+yi)^4:part5
            mpf_pow_ui(part5,part4,mpz_get_ui(four));
            //a(i-1) * (1+yi)^4 : part6
            mpf_mul(part6,a0,part5);

            //2^2i+3: part7
            mpf_pow_ui(part7,b,mpz_get_ui(eye));


            //ynew^2:part8
            mpf_pow_ui(part8,ynew,mpz_get_ui(two));

            //1+ynew+ynew^2 :part9
            mpf_add(part9,part4,part8);

            //y(1+y+y2) : part10
            mpf_mul(part10,ynew,part9);

            //2^2i+3*y*(1+y+y2) : part11
            mpf_mul(part11,part10,part7);

            //a (1+y)4-22i+1y(1+y+y2): anew
            mpf_sub(anew,part6,part11);

            //set value of a0 to anew
            mpf_set(a0,anew);

        }

        mpf_div(anew,a,anew);

        /*
         * stopping clock
         */
        auto finish = chrono::high_resolution_clock::now();
        elapsed = finish - start;

        mpz_t elapsedtime;
        mpz_set_d(elapsedtime,elapsed.count());


        /*
         * Printing data in a file
         */

        FILE *pFile;

        pFile = fopen("test.txt", "w");

        gmp_fprintf(pFile, "%.*Ff", 1000000, anew);


        fclose(pFile);

        //clear all mpf_t variables
        mpf_clear (a);
        mpf_clear (b);
        mpf_clear (c);
        mpf_clear (d);
        mpf_clear(root2);
        mpf_clear(a0);
        mpf_clear(y0);
        mpf_clear(ypow);
        mpf_clear(ynew);
        mpf_clear(anew);
        mpf_clear(ynum);
        mpf_clear(ydem);
        mpf_clear(part1);
        mpf_clear(part2);
        mpf_clear(part3);
        mpf_clear(part4);
        mpf_clear(part5);
        mpf_clear(part6);
        mpf_clear(part7);
        mpf_clear(part8);
        mpf_clear(part9);
        mpf_clear(part10);
        mpf_clear(part11);
        mpf_clear(part12);
        mpf_clear(part13);

        print();


        return 0;


    }
//function to print values
void print()
{
    string line;
    int i=0;
    char digit;
    ifstream infile("test.txt");

    ofstream pifile;
    pifile.open("Bigpi.txt");

    pifile<<"pi to 1000000 places:\n\n";

        digit=infile.get();
        pifile<<digit;
        digit=infile.get();
        pifile<<digit;
        for(i=0;i<1000001;i++)
        {
            if (i % 10 == 0 && i != 0)
            {
                pifile << " ";
            }
            if (i % 100 == 0 && i != 0)
            {
                pifile << "\r  ";
            }
            if (i % 500 == 0 && i != 0)
            {
                pifile << "\n\n";
                pifile << "  ";
            }

            if (i < 1000000)
            {
                digit = infile.get();
                pifile << digit;
            }

        }

    infile.close();

    pifile<<"Elapsed time:\t"<<elapsed.count()<<" seconds";
    pifile.close();
}



