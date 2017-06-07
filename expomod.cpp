#include <iostream>
#include <stdio.h>
using namespace std;



int expomodular(int base,int exp,int mod){
    int result=1,expmod;

    if(exp%2!=0)
        result=base;
    exp=exp/2;

    while(exp>0){
        expmod=exp%2;
        base=(base*base)%mod;
        if(expmod!=0)
            result=(base*result)%mod;
        exp/=2;}
    return result;
}



int main() {


    cout<<"expm : "<<expomodular(7,644,645)<<endl;

    return 0;
}
