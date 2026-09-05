#include <iostream>
#include <vector>


int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> A(n);
    bool hard = false;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
        if (A[i] > 0) {
            hard = true;
        }
    }
    if (hard) {
        std::cout << "HARD" << std::endl;
    } else {
        std::cout << "EASY" << std::endl;
    }
    return 0;
}
