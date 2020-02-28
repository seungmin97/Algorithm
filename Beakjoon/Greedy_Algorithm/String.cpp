//
// Created by 이승민 on 2019-09-10.
//

#include <iostream>
#include <string>

using namespace std;

string a, b;

int check(int i){
    int count = 0;
    for (int j = 0; j < a.length(); ++j) {
        if(b[i + j] != a[j]){
            count += 1;
        }
    }
    return count;
}

int main(){

    cin >> a >> b;
    int length = b.length() - a.length(); // 1

    int temp = 0, min = a.length();

    for (int i = 0; i <= length; ++i) {
        temp = check(i);
            if(min > temp){
                min = temp;
            }
        }

        cout << min;


    return 0;
}