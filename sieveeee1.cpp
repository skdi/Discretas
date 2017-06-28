#include <iostream>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
const unsigned long long int Limit = 10000000ULL;

//bitset<Limit+1> isPrime;
bitset<Limit>& isPrime = *(new bitset<Limit>());

void fillArray() {
    isPrime[2] = 1;
        for (unsigned long long int i = 1; i <= Limit; i += 2) {

                isPrime[i] = 1;
        }
}

void sieveOfEratosthenes() {
        unsigned long long int iLim = (unsigned long long int)sqrt(Limit);
        for (unsigned long long int i = 3; i <= iLim; i += 2) {
            if (!isPrime[i]) {
                for (unsigned long long int j = i * i; j <= Limit; j += i) {
                    isPrime[j] = 1;
                }

            }
        }
 }


void display() {

    unsigned long long int count = 0;
    for (unsigned long long int i = 2; i <= Limit; i++) {
        if (isPrime[i]) {
            count++;
        }

    }
    cout << endl;
    cout << "  Number of Prime upto " << Limit << " : " << count << endl;

}

int main() {

    clock_t start = clock();
    fillArray();
    sieveOfEratosthenes();
    clock_t end = clock();
    display();
    cout << "  Run time : " << ((double)end - start)/CLOCKS_PER_SEC << endl;
    cout << endl;
    return 0;

}
