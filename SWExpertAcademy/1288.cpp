//
// Created by 이승민 on 2019-09-03.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream in;
    in.open("1288_input.txt");

    int temp;
    while(in.is_open()){
        in >> temp;
        cout << temp;
    }


    return 0;
}