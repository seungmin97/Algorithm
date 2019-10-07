//
// Created by 이승민 on 2019-10-04.
//

#include <iostream>
#include <string>

using namespace std;

int main(){

    string str;
    getline(cin, str);

   int num = 1;

   if(str[0] == ' ' && str.length() == 1){
       cout << 0;
       return 0;
   }

    for (int i = 1; i < str.length() - 1; ++i) {
        if(str[i] == ' '){
            num += 1;
        }
    }

    cout << num;
    return 0;
}