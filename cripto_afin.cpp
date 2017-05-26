#include "cripto.h"
#include <iostream>

using namespace std;

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
    int t;
    for(unsigned int i=0;i<mensaje.length();i++){
        t=alfabeto.find(mensaje[i]);
        temp[i]=alfabeto[(t+b)%alfabeto.length()];
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


string cripto::decodifica2(string mensaje){
    int inv_a=0;
    string temp=mensaje;
    int t=0,t1=0;
    for(unsigned int i=0;i<alfabeto.length();i++){
        t=(a*i)%alfabeto.length();
        if(t==1)
            inv_a=i;
    }
    for(unsigned int i=0;i<mensaje.length();i++){
        t1=alfabeto.find(mensaje[i]);
        temp[i]=alfabeto[(inv_a*(t1-b))%alfabeto.length()];
    }
    return temp;


}

/////////////////////////////////////////////////////////////////////////////////
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
    void setclave(int clave1, int b);
    int getclave();
};



#endif // CRIPTO_H
///////////////////////////////////////////////////////////////////////////////////////
#include "cripto.h"
#include <iostream>
using namespace std;

int main(){

  cripto *emisor=new cripto(2,1);
  string mensaje="hola como va todo";
  cout<<mensaje<<endl;
  string mensajecifrado=emisor->codifica2(mensaje);
  cout<<mensajecifrado<<endl;
  string mensajeplano=emisor->decodifica2(mensajecifrado);
  cout<<mensajeplano<<endl;
  return 0;

//lztfuentespzARROBAgmail.com asunto: EDIII-labP1
}
