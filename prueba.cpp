#include <iostream>
#include <string>
#include <algorithm>


int main(){
    std::string str="";
    std::cin>>str;

    int a = int(str.find("#"));


    std::cout << a << std::endl;
    return 0;
}