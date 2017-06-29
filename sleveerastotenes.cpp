#include <ctime>
#include <iostream>
#define ll unsigned long long
unsigned t0, t1;

using namespace std;
ll n=1000000000;
bool * isPrime = new bool [n/2]();

void sleve(){

    for (ll i=0; i < n/2; ++i)//inicializacion de la mitad del vector en 1
        isPrime [i] = true;


    for (ll i = 5, t = 2; i < n; i += t, t = 6 - t) {//inicio en 5 , salto de 2 o 4 ,recorrido total ,saltamos de t en t

        if (isPrime [i / 3]) {//si es primo
            for (ll j = i * i, v = t; j < n; j += v * i, v = 6 - v)//saltamos en i^2 ,v vale 2 o 4 ,recorrido total,aumento de 2 o 4por las posicion actual 
                isPrime [j / 3] = false;//cribo el resultado
        }
    }
}
void print(){
    for(ll i = 5, t = 2; i < n; i += t, t = 6 - t) 
        if (isPrime [i / 3]) 
            cout<<i<<'\n';
}

int main()
{
    cout<< 2 << "\n";
    cout<< 3 << "\n";
    t0=clock();
    sleve();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution Time: " << time << endl;
    print();
    return 0;
}
