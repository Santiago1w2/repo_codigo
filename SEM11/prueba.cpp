#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k_nesimo(vector<int> dato, int k){
    sort(dato.begin(), dato.end());
    return dato[k-1];
}
int main(){
    vector<vector<int>> v ={{2,3},{4,3},{6,6}};
    vector<int> temp = {5,4,3,2};
    cout << v[4].size();
    return 0;
}