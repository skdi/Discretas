#include <iostream>
#define ll long long

using namespace std;
/*  expo modular */
ll modulo(ll base, ll exponent, ll mod){
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
//p-1 = 2¨k*m...53->k=2,m=13
//s=2¨k *m
bool miller(ll p,int iteration){
    if (p < 2)//si p es menor de 2 no es primo
        return false;
    if (p != 2 && p % 2==0)//si es par no es primo
        return false;
    ll s = p - 1;//guardamos el valor de p-1 de tal forma que sea par
    while (s % 2 == 0)//lo reducimos a su minimo tamaño par
        s /= 2;
    //hallamos b(0)=a¨m(mod p) , si es 1 o -1 entonce es primo, en caso contrario hallar b(1)=b(0)¨m(modp),si b1=1 noes primo , si b1=-1 es primo
    for (int i = 0; i < iteration; i++){//iteracion = precision de la prueba
        //elegimos a 1<a<p-1
        ll a = rand() % (p - 1) + 1, temp = s;//guardamos el valor de S y calculamos a como un random
        ll mod = modulo(a, temp, p);//limitado por el tamaño del primo,hallamos el modulo de a, S y el n primo
        while (temp != p - 1 && mod != 1 && mod != p - 1)//si el temporal es diferente de p-1 ,el modulo no es 1
        {//y el modulo es diferente de p-1
            mod = mulmod(mod, mod, p);//hallamos el modulo de mod y p
            temp *= 2;//aumentamos por 2 el valor de S
        }
        if (mod != p - 1 && temp % 2 == 0)//luego del ciclo comprobamos que
            return false;//S es par y mod no es p-1 , con esto concluimos que no es primo
    }
    return true;//en caso de que no se cumpla la anterior conidicinal decimos que probablemente
}//sea un numero primo
int main(){

    cout <<miller(3264011,10)<< endl;
    return 0;
}
