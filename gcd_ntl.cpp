#include <iostream>
#include <stdio.h>
#include <NTL/ZZ.h>

NTL_CLIENT

using namespace std;
using namespace NTL;


ZZ mcd(ZZ m, ZZ n)
{
    ZZ r,q;
    //if(m<n)
       // swap(m,n);

    while(r!=0)
    {
        q=m/n;
        r=m-q*n;//funcion para el "modulo" m,n
        m=n;//reasigno las variablescout << c << "\n";
        n=r;
    }
    return m;/*m es el ultimo resto no nulo*/
}



int main()
{
    int a,b;
    ZZ c;
    cout<<"ingrese a , b"<<endl;
    cin>>a;
    cin>>b;
    c=mcd(ZZ(a),ZZ(b));
    printf("%ZZ",&c);




    return 0;
}
