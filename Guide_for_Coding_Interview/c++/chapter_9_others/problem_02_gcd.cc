#include <iostream>
using namespace std;

int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}

int main(int argc, char* argv[]) {
    cout<<gcd(18, 27)<<endl;
    return 0;
}
