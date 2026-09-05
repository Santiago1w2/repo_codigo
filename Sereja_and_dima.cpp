#include <iostream>

int main() {
    int n = 0;
    std::cin>>n;
int cartas[n];
    int left = 0;
    int right = n-1;
    for (int i = 0; i < n; i++) {
        std::cin>>cartas[i];
    }
    int s= 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (i%2==0) {
            if (cartas[left] > cartas[right]) {
                s = s + cartas[left];
                left++;
            } else {
                s = s + cartas[right];
                right--;
            }
        } else {
            if (cartas[left] > cartas[right]) {
                d = d + cartas[left];
                left++;
            } else {
                d = d + cartas[right];
                right--;
            }
        }

    }
    std::cout << s << " " << d << std::endl;

    return 0;
}
