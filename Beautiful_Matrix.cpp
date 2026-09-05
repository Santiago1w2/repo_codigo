#include <iostream>
#include <vector>
//Solaicon optiima susando int contador = std::abs(pos_i - 3) + std::abs(pos_j - 3);

int main() {
    std::vector<std::vector<int>> matriz (5,std::vector<int>(5,0));
    int pos_i = 0, pos_j = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            std::cin >> matriz[i][j];
            if (matriz[i][j]==1) {
                pos_i = (i+1);
                pos_j = (j+1);
            }

        }
    }
    int c_i = 3 , c_j = 3 ;
    int contador = 0;
    if (pos_i < c_i && pos_j > c_j  ) {
        contador+=(c_i-pos_i);
        contador+=(pos_j-c_j);
    } else if (pos_i > c_i && pos_j < c_j ) {
        contador+=(pos_i-c_i);
        contador+=(c_j-pos_j);
    } else if (pos_i==c_i && pos_j>c_j ) {
        contador+=(pos_j-c_j);
    } else if (pos_i==c_i && pos_j<c_j) {
        contador+=(c_j-pos_j);
    } else if (pos_j==c_j && pos_i>c_i ) {
        contador+=(pos_i-c_i);
    } else if (pos_j==c_j && pos_i<c_i) {
        contador+=(c_i-pos_i);
    } else if (pos_i > c_i && pos_j >c_j ) {
        contador+=(pos_i-c_i);
        contador+=(pos_j-c_j);
    } else if (pos_i < c_i && pos_j <c_j ) {
        contador+=(c_i-pos_i);
        contador+=(c_j-pos_j);
    }
    std::cout << contador << std::endl;



    return 0;
}
