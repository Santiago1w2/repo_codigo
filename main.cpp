#include <iostream>

using namespace std;

int main() {
    int n = 80;
    long long suma_fi = 0;
    long long f1 = 1;
    long long f2 = 2;
    for (int i = 3; i <= n;i++) {

        if (i == 3 ) {
            suma_fi=0;
        }
        else {
            suma_fi = (f1 + f2);//2,3
        }
        cout << "f(" << i << ") = " << "f(" << i-1 << ") + " << "f(" << i-2<< ") = " << f1<< " + " << f2<< " = " << suma_fi << endl;

        f1 = f2;//f1=1,
        f2 = suma_fi;//f2=2;
    }

    return 0;
}


