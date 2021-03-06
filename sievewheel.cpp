#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#define ll long long
unsigned t0, t1;

using namespace std;

#define MAX_NUM 3000000//limite para los primos
// creamos un array de MAX_NUM inicializados en 0
ll primos[MAX_NUM];


void erasto(){
    for (ll p = 2; p < MAX_NUM; p++) // recorrido del array
    {
        if (primos[p] == 0) // si no es multiplo de algun otro primo
            primos[p] = 1; // marco como primo

        // marco todos los multiplos de primos seleccionados sobre los no primos
        ll c = 2;//inicializamos c en el primer primo
        ll mul = p * c;//todos los multiplos de c utilizados se almacenan en mul
        while (mul < MAX_NUM)//mientras que sea menor que el tamaño de mi array
        {
            primos[mul] = -1;//marco como no primo a los multiplos
            c++;//aumento el contador
            mul = p * c;//actualizo el valor para todos los multiplos
        }
    }
}

void print()
{
    ll c = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (primos[i] == 1)//si es primo
        {
            c++;          //actualizo el valor del contador
            cout << c << "primo  : " << i << endl;//imprimo los primos
        }
    }
}

int main()
{
    t0=clock();
    erasto();
    print();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}
