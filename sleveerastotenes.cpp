#include <iostream>
#define ll long long

using namespace std;
void sleve(ll n){

    bool * isPrime = new bool [n/2]();

    for (ll i=0; i < n/2; ++i)
        isPrime [i] = true;

    cout<< 2 << "\n";
    cout<< 3 << "\n";

    for (ll i = 5, t = 2; i < n; i += t, t = 6 - t) {

        if (isPrime [i / 3]) {

            cout<< i << "\n";

            for (ll j = i * i, v = t; j < n; j += v * i, v = 6 - v)
                isPrime [j / 3] = false;
        }
    }
}

int main()
{
    sleve(5024);
    cout << "Hello World!" << endl;
    return 0;
}
