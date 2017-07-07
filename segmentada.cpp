#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#define ll long long
unsigned t0, t1;
using namespace std;
#define MAX_NUM 10000000000//limite para los primos
std::vector<char> primos;
const int L1D_CACHE_SIZE = 32768;//memoria interna de la pc


void primo(ll limit,int segment_size = L1D_CACHE_SIZE)
{
    int sqrt1 = (int) sqrt((double) limit);//guardamos la raiz del tamaño maximo para trabajarlo por segmentos
    ll count = (limit < 2) ? 0 : 1;//inicializo un contador comprobando el tamño del limite
    ll s = 2;//variables de apoyo
    ll n = 3;

    // vector para marcar los primos por segmentos
    std::vector<char> sieve(segment_size);
    /**********************   erastotenes normal    *****************************/
    // se genera los primeros numeros primos menores que sqrt
    std::vector<char> is_prime(sqrt1 + 1, 1);
    for (int i = 2; i * i <= sqrt1; i++)//empezamos el ciclo y siempre que el valor
        if (is_prime[i])// actual al cuadrado sea menor que el nuevo limite
            for (int j = i * i; j <= sqrt1; j += i)//avanzamos de i en i
                is_prime[j] = 0;//marcamos la posicion como no primo

    std::vector<int> primes;//creo un vector de primos
    std::vector<int> next;//un vector de apoyo que sera el sig
    //para la parte segmentada empiezo en 0 hasta el limite total y avanzo en porciones de segmento
    for (ll low = 0; low <= limit; low += segment_size)
    {
        std::fill(sieve.begin(), sieve.end(), 1);//inicializo mi vector con 1

        //segmento actual = intervalo [low, high]
        ll high = std::min(low + segment_size - 1, limit);

        // guardo los primos pequenios necesarios para marcar sus multiplos
        for (; s * s <= high; s++)
        {
            if (is_prime[s])
            {
                primes.push_back((int) s);
                next.push_back((int)(s * s - low));
            }
        }
        // marco el sefmento actual
        for (std::size_t i = 1; i < primes.size(); i++)
        {
            int j = next[i];
            for (int k = primes[i] * 2; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }

        for (; n <= high; n += 2)
            if (sieve[n - low]) // n es primo
                count++;
    }

    std::cout << count << " primes found." << std::endl;
}


/*void print()
{
    ll c = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (sieve[i] == 1)//si es primo
        {
            c++;          //actualizo el valor del contador
            cout << c << "primo  : " << i << endl;//imprimo los primos
        }
    }
}*/

int main()
{
    t0=clock();
    primo((ll)MAX_NUM);
    //erasto();
   // print();
    //sieve();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}
