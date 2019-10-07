//
// Created by 이승민 on 2019-10-04.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){

    int alphabet[27];
    memset(alphabet, 0, 27 * sizeof(int));

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        int temp = str[i];
        if(temp >= 65 && temp <= 90){
            alphabet[temp - 65] += 1;
        }
        else{
            alphabet[temp - 97] += 1;
        }
    }
    int max = 0;
    int index = 0;
    int check = 0;
    for (int i = 0; i < 27; ++i) {
        if(max < alphabet[i]){
            check = 0;
            max = alphabet[i];
            index = i;

        }
        else if(max == alphabet[i]){
            check += 1;
        }
    }

    if(check == 0){
        cout << (char)(index + 65);
    }
    else{
        cout << '?';
    }

    return 0;
}
