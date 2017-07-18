#include "cripto.h"

cripto::cripto(){
    //this->p=generador();//hallamos p
    //this->q=generador();//hallamos q
    this->N=this->p*this->q;//calculamos n=p*q
    this->fi=(this->p-1)*(this->q-1);//calculamos fi=p-1*q-1
    this->e=randomize()%fi;//generamos 1<e<fi
    this->d=inversa(this->e,this->fi);//generamos una clave privada
}

ZZ cripto::modulo(ZZ base, ZZ exponent,ZZ mod){
    ZZ x = 1;
    ZZ y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

ZZ cripto::mulmod(ZZ a, ZZ b,ZZ mod){
    ZZ x = 0,y = a % mod;
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
bool cripto::miller(ZZ p,int iteration){
    if (p < 2)//si p es menor de 2 no es primo
        return false;
    if (p != 2 && p % 2==0)//si es par no es primo
        return false;
    ZZ s = p - 1;//guardamos el valor de p-1 de tal forma que sea par
    while (s % 2 == 0)//lo reducimos a su minimo tamaño par
        s /= 2;
    //hallamos b(0)=a¨m(mod p) , si es 1 o -1 entonce es primo, en caso contrario hallar b(1)=b(0)¨m(modp),si b1=1 noes primo , si b1=-1 es primo
    for (int i = 0; i < iteration; i++){//iteracion = precision de la prueba
        //elegimos a 1<a<p-1
        ZZ a = rand() % (p - 1) + 1, temp = s;//guardamos el valor de S y calculamos a como un random
        ZZ mod = modulo(a, temp, p);//limitado por el tamaño del primo,hallamos el modulo de a, S y el n primo
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

ZZ cripto::randomize(){
    ZZ randnumber;
    int digits=time(0);
    for(int i=305; i>=1; i--)
    {
       ZZ power=pow(10,(i-1)/digits);

        if (power%2 != 0 && power != 1)     //elimina el "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power << digits;
    }
    randnumber=randnumber%446744073709551615;
    if(randnumber%2==0)
        randnumber--;
return randnumber;
}
ZZ cripto::generador(){
    ZZ random;
    random=randomize();
    while(!miller(random,2)){
        random-=2;
    }
    return random;

}
ZZ cripto::gcd(ZZ a,ZZ b){
    //gcd(a,alfabeto.length(),d,x,y);
    ZZ r,s,t,r1,r2,s1,s2,t1,t2,q;

    r1=a;r2=b;
    s1=1;s2=0;
    t1=0;t2=1;
     while(r2>0){
        //cout<<r<<"\t"<<s<<"\t"<<t<<"\t"<<r1<<"\t"<<r2<<"\t"<<s1<<"\t"<<s2<<"\t"<<t1<<"\t"<<t2<<"\t"<<q<<endl;
        ///////////////
        q=r1/r2;//inicializamos el valor de q
        ///////////////
        r=r1-q*r2;//iniciamos r como el valor "a" -el cociente por "b"
        r1=r2;r2=r;//actualizamos posiciones r1 ahora es b ,r2 ahora es el modulo a y b
        ///////////////
        s=s1-q*s2;//hallamos el modulo de s1 y s2
        s1=s2;s2=s;//actualizamos su posicion
        ///////////////
        t=t1-q*t2;//hallamos el modulo de t1 y t2
        t1=t2;t2=t;//actualizamos su posicion
   }

    return s1;//retornamos X
}
bool cripto::fermat(ZZ p,int iterations){
        if (p == 1)
        {
            return false;
        }
        for (int i = 0; i < iterations; i++)
        {
            ZZ a = rand() % (p - 1) + 1;
            if (modulo(a, p - 1, p) != 1)
            {
                return false;
            }
        }
        return true;
}

ZZ cripto::inversa(ZZ a,ZZ n){
    ZZ inv_a;
    inv_a=gcd(a,n);
    if(inv_a<0)
        inv_a+=N;
    return inv_a;
}

ZZ* cripto::segment(ZZ a){
    stringstream ss;
    ss << a;
    string mensaje = ss.str();
    string temp;
    ZZ *clave;
    //recorrido del string mensaje
    int j=0;
    while(mensaje[j]!='\0'){
        for(unsigned int i=0;i<this->segmento;i++)
            temp[i]=mensaje[i];//lo partimos en segmentos y lo almacenamos en temp
        clave[j]=stoi(temp);//convertimos el string a int lo almacenamos en clave en la posicion j
        j++;
}
    return clave;
}

ZZ cripto::encripta(ZZ m){
    ZZ *c ; ZZ *segmentos;int i=0;
    while(i<m/segmento){//recorrido para encriptar ,por segmentos
        segmentos=segment(m);//segmento mi clave
        c[i] = modulo(segmentos[i],this->e,this->N);//cada segmento lo encripto y lo almaceno
        i++;//aumento la posicion par el siguiente segmento
    }
    return desegmenta(c);//retorno el valor encriptado
}

bool cripto::set_all(ZZ p, ZZ q, ZZ N){
    this->p=p;
    this->q=q;
    this->N=N;

}
ZZ cripto::desegmenta(ZZ * c){
    string temp;
    for(unsigned int i=0;c[i]!=NULL;i++){
        temp[i]=c[i];
    }

}

ZZ cripto::desencripta(ZZ c){
    ZZ m;
    m=modulo(c,this->d,this->N);
    return m;
}

//////////////////////////////////////////////////////



#ifndef CRIPTO_H
#define CRIPTO_H
#include <string>
#include <sstream>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ZZ unsigned long long

class cripto{
private:
    ZZ p;
    ZZ q;
    ZZ d;
    ZZ fi;
    ZZ desencripta(ZZ c);
    ZZ encripta(ZZ m);
    bool set_all(ZZ p = 0,ZZ q = 0,ZZ N = 0);
public:
    int segmento;
    ZZ N;
    ZZ e;
    cripto();
    ZZ modulo(ZZ base,ZZ exponent,ZZ mod);
    ZZ mulmod(ZZ a,ZZ b,ZZ mod);
    bool miller(ZZ p,int interation);
    ZZ randomize();
    ZZ generador();    
    ZZ *segment(ZZ a);
    ZZ desegmenta(ZZ *c);    
    ZZ inversa(ZZ a,ZZ n);
    bool fermat(ZZ p,int iterations);
    ZZ gcd(ZZ a,ZZ b);
};

#endif // CRIPTO_H

////////////////////////////////////////
#include <cripto.h>
using namespace std;

int main()
{

    cripto *emisor=new cripto();
    ZZ este=emisor->randomize();
    cout<<este<<endl;
    cout<<emisor->fermat(este,2)<<endl;
    while(!emisor->fermat(este,2)){
        este-=2;
    }
    cout<<este<<endl;
    return 0;

}
