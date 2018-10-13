#include <iostream>
#include <mpir.h>

using namespace std;


int main (void) {
    mpz_t a, b, c;
    mpz_init (a); mpz_init (b); mpz_init (c);

    mpz_set_str (a, "1024", 10);
    mpz_set_str (b, "768", 10);
    mpz_gcd (c, a, b);

    printf ("GCD of "); mpz_out_str (stdout, 10, a);
    printf (" and ");   mpz_out_str (stdout, 10, b);
    printf (" is ");    mpz_out_str (stdout, 10, c);
    putchar ('\n');

    return 0;
}
