//
// Created by 이승민 on 2019-10-04.
//

#include <iostream>
#include <string>

using namespace std;

string str;
string bomb;

int main(){
    cin >> str;
    cin >> bomb;

    while(1){
        int index = str.find(bomb);
        if(index == -1){
            if(str.length() == 0){
                cout << "FRULA";
                return 0;
            }
            else{
                cout << str;
                return 0;
            }
        }
        else{
            str.erase(index, bomb.length());
        }
    }

}