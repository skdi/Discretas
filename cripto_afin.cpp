#include "cripto.h"

cripto::cripto(int clave1){
    setclave(clave1,0);
}
cripto::cripto(int clave1, int b1){
    setclave(clave1,b1);
}
bool cripto::validarclave(int clave){
  if(a>=1)
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
    int t;
    for(unsigned int i=0;i<mensaje.length();i++){
        t=alfabeto.find(mensaje[i]);
        temp[i]=alfabeto[(a*t)%alfabeto.length()];
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

////////////////////////////////////////////////////////////////////////////
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
    int gcd(int a1,int m);
    void setclave(int clave1, int b);
    int getclave();
};



#endif // CRIPTO_H
////////////////////////////////////////////////////
#include "cripto.h"
#include <iostream>
using namespace std;

int main(){

  cripto *emisor=new cripto(3,2);
  string mensaje="hola como va todo";
  cout<<mensaje<<endl;
  string mensajecifrado=emisor->codifica2(mensaje);
  cout<<mensajecifrado<<endl;
  /*cripto *receptor=new cripto(3);
  string mensajeplano=receptor->decodifica(mensajecifrado);
  cout<<mensajeplano<<endl;*/
  return 0;

//lztfuentespzARROBAgmail.com asunto: EDIII-labP1
}
