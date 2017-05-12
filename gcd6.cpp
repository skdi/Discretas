#include <iostream>
using namespace std;

int gcd(int a,int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cout << gcd(24, 18) << endl; // Output: 6
    cout << gcd(54, 36) << endl; // Output: 18
    cout << gcd(120, 428860) << endl; // Output: 20
    cout << gcd(324, 8460592) << endl; // Output: 4
    return 0;
}
