#include "cripto.h"

cripto::cripto(int clave1){
    setclave(clave1,0);
}
cripto::cripto(int clave1, int b1){
    setclave(clave1,b1);
}
bool cripto::validarclave(int clave1){
  if(clave1>=1)
    return true;
  else return false;
}
bool cripto::validarmensaje(string mensaje){
  if(mensaje.length()<1)
    return false;
  else return true;
}
void cripto::setclave(int clave1,int b1=0){
  if(validarclave(clave1)){
     this->a=clave1;
     this->b=b1;
  }
}
int cripto::getclave(){
  return this->a;
}

string cripto::codifica(string mensaje){
    string temp=mensaje;
    for(unsigned int i=0;i<mensaje.length();i++){
        temp[i]=alfabeto[(a+b)%alfabeto.length()];
    }
    return temp;
}

string cripto::codifica2(string mensaje){
    string temp=mensaje;
    int t;
    for(unsigned int i=0;i<mensaje.length();i++){
        t=alfabeto.find(mensaje[i]);
        temp[i]=alfabeto[(a*t+b)%alfabeto.length()];
    }
    return temp;
}

string cripto::decodifica(string mensaje){
    string temp=mensaje;
    for(unsigned int i=0;i<mensaje.length();i++){
        temp[i]-=a%alfabeto.length();
    }
    return temp;
}

void cripto::gcd(int a, int b,int &d,int &sx,int& ty){
    int r,s,t,r1,r2,s1,s2,t1,t2,q;
    r1=a;r2=b;
    s1=1;s2=0;
    t1=0;t2=1;
    while(r2>0){
        q=r1/r2;//inicializamos el valor de q

        r=r1-q*r2;//iniciamos r como el valor "a" -el cociente por "b"
        r1=r2;r2=r;//actualizamos posiciones r1 ahora es b ,r2 ahora es el modulo a y b

        s=s1-q*s2;//hallamos el modulo de s1 y s2
        s1=s2;s2=s;//actualizamos su posicion

        t=t1-q*t2;//hallamos el modulo de t1 y t2
        t1=t2;t2=t;//actualizamos su posicion
    }
    sx=s1;//retornamos X
    ty=t1;//retornamos Y
    d=r1;

}

int cripto::inverso(int a,int b){
    int invert,x,y,d;
    gcd(a,b,d,x,y);
    if(d>1)
        return 0;
    else{
        if(x<0)
            invert=b+x;
        else invert=x;
    }
    return invert;
}

string cripto::decodifica2(string mensaje){
    int inv_a;
    string temp=mensaje;
    int t;
    for(unsigned int i=0;i<mensaje.length();i++){
        t=alfabeto.find(mensaje[i]);
        inv_a=inverso(alfabeto.length(),t);
        temp[i]=alfabeto[((a-b)*inv_a)%alfabeto.length()];
    }
    return temp;

}
////////////////////////////////////////////////////
#ifndef CRIPTO_H
#define CRIPTO_H

#include <stdio.h>
#include <math.h>
#include <cctype>
#include <string>

using namespace std;

class cripto{
  private:
    int a;
    int b;
  public:
    string alfabeto="abcdefghijklmnopqrstuvwxyz ";
    cripto(int clave1);
    cripto(int clave1,int b1);
    bool validarclave(int clave1);
    bool validarmensaje(string mensaje);
    string codifica(string mensaje);
    string codifica2(string mensaje);
    string decodifica(string mensaje);
    string decodifica2(string mensaje);
    int inverso(int n,int a);
    void gcd(int a1, int m, int &d, int &sx, int &ty);
    void setclave(int clave1, int b);
    int getclave();
};



#endif // CRIPTO_H


#include "cripto.h"
#include <iostream>
using namespace std;

int main(){

  cripto *emisor=new cripto(3,2);
  string mensaje="hola como va todo";
  cout<<mensaje<<endl;
  string mensajecifrado=emisor->codifica2(mensaje);
  cout<<mensajecifrado<<endl;
  cripto *receptor=new cripto(3,2);
  string mensajeplano=receptor->decodifica2(mensajecifrado);
  cout<<mensajeplano<<endl;
  return 0;

//lztfuentespzARROBAgmail.com asunto: EDIII-labP1
}
