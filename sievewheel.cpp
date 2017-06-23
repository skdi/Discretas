#include <iostream>
#include <math.h>
#include <stdlib.h>
#define ll long long

using namespace std;

#define MAX_NUM 500000//limite para los primos
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
    erasto();
    print();
    return 0;
}
