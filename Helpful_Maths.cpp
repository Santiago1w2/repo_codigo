#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string x = "";
    std::cin>> x;
    std::vector<int> d;
    for (int i = 0; i < x.size(); i++) {
        if (x[i]!='+') {
            d.push_back(x[i]-'0');
        }
    }
    std::sort(d.begin(), d.end());
    std::string res = "";
    for (int i = 0; i < d.size(); i++) {
        char s =d[i]+'0';
        res+=s;
        if (i != d.size() - 1) {
            res+= "+";
        }
    }
    std::cout << res;
    return 0;
}