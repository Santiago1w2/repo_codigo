#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    if (n%2==0 && n!=2) {
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
    }
    return 0;
}
