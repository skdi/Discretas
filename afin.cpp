#include <iostream>
using namespace std;


class Afin{
private:
    int a;
    int b;
    string abc="abcdefghijklmnopqrstuvwxyz";
    int m=abc.size();
public:
    Afin();
    Afin(string);
    int gcd(int a,int m){
        if(m==0){
            return a;
        }
        gcd(a,a%m);
    }
};


Afin::Afin(){
    cout<<"a:";
    cin>>a;
    cout<<"b:";
    cin>>b;
    string mensaje;
    cout<<"Ingrese Mensaje: ";
    cin>>mensaje;
    for(int i=0;i<mensaje.size();i++){
        int t=abc.find(mensaje[i]);
        if((a*t)+b<m){
            mensaje[i]=abc[a*t+b];
        }
        else{
            mensaje[i]=abc[(a*t+b)%m];
        }
    }
    for(int j=0;j<mensaje.size();j++){
        cout<<mensaje[j];
    }
}


int main(){
    Afin a;
    cout<<a.gcd(8,3);
    return 0;
}

