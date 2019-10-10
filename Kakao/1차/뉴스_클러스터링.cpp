//
// Created by 이승민 on 2019-10-10.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string str1 = "FRANCE";
    string str2 = "french";

    transform(str1.begin(), str1.end(), str1.begin(),  (int(*)(int))toupper);


    return 0;
}