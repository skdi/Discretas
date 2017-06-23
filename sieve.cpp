#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#define ll long long
#define MAX 100000000
#define LIM 10000

unsigned flag[MAX>>6]={0};//divido entre 64 el tamaño maximo y separo espacio para los n.
//inicializo en 0 el array
#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))/*funcion para ver si es compuesto,
    *vemos el numero entero de 32bits q contiene el valor de bits en n/2.
    *( & 31se asegura de que se trata de "en línea"). y nos da la posicion de bit
    *el & del medio es para combinar ambas"funciones"
    */

#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))/*
    vemos el numero entero de 32bits q contiene el valor de bits en n/2
    |= ->a = a | b,usado para  establecer el bit correspondiente(1 o 0)
    nuevamente guardamos el valor en la posicion del bit libre
    
    */
unsigned t0, t1;

using namespace std;

#define MAX_NUM 3000000//limite para los primos
// creamos un array de MAX_NUM inicializados en 0
ll primos[MAX_NUM];


void sieve() {
    unsigned i, j, k;//creo 3 variables solo positivas
    for(i=3; i<LIM; i+=2)//inicio desde 3 y avanzo de 2 en 2
        if(!ifc(i))//si no es un numero compuesto
            for(j=i*i, k=i<<1; j<LIM*LIM; j+=k)//j=numero al cuadrado,k es ix2,y avanzamos de ix2 en ix2
                cout<<j<<endl;//imprimimos
                isc(j);//marcamos la posicion
}

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
    //erasto();
   // print();
    sieve();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}
