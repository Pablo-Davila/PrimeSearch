
/// Begin date: ??/??/2017
/// Last modification: 03/08/2018
///
/// Personal project: PrimeSearch.
/// Description: This program aims to search for prime numbers in a reasonably optimised way.
///
/// Pablo Davila Herrero

#include <stdio.h>
#include <math.h>


long fPrimes = 1;        // Amount of found primes
long prime[100000];      // Found primes storage


void search(int pos) {

    for (long long num=prime[fPrimes]; fPrimes<pos; num+=2) {
		// We must check the divisibility of each 'num' value whith the already-found primes.
		// In case it is divisible by none of them we will have found a new prime.

		int primeTF = 1;
		for(long i=0; i<fPrimes && primeTF!=0 && prime[i]<=sqrt(num); i++) {

			primeTF = num%prime[i];
		}

		if(primeTF != 0) {
			prime[fPrimes] = num;
			fPrimes++;
		}
    }
}

int main() {

    printf("\n\t PrimeSearch by Pablo Davila Herrero\n\n");
    printf(" * Enter the position of the target prime number."
    		"\n * The position must be an integer between 1 and 100000."
    		"\n * The time required for this will increase along with the prime position."
    		"\n * Enter -1 to exit."
    		"\n\nPosition: ");

	prime[0] = 2;
	prime[1] = 3;

    while(1) {

    	// Input
    	long pos;
    	scanf("%ld", &pos);

    	// Cases
        if(pos == -1) break;
        if(pos < 1) printf("Incorrect input. Please enter an integer between 1 and 100000.\n\n");
        else if(pos > fPrimes) search(pos);

        // Output
        printf("The %ldth prime number is %ld\n\n", pos, prime[pos-1]);
        printf("Position: ");
    }

    return 0;
}

