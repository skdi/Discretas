#include <conio.h>
#include <iostream.h>
 
int main(int argc, char* argv[])
{       int a, b, x, z, y=1, i=2;
            cout<<"ingrese primer numero: \n";
            cin>>a;
            cout<<"ingrese segundo numero: \n";
            cin>>b;
            if (a<b){x=a; z=b;} else {x=b; z=a;}
 
            do {
            if (x%i==0 && z%i==0){
            y=y*i;
            x=x/i; z=z/i;
            i=2;
            }
            else i++;
 
            }while(i<=x);
 
              cout<<"el MCD es "<<y<<"\n";
 
 getch(); getch();
 return 0;
}
