//
// Created by 이승민 on 2019-10-14.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int result = 0;
int m = 6, n =6;
//int m = 5, n = 4;
vector <string> change_board(int (*temp)[6], vector <string> v){

    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if(temp[i][j] == 1){
                result += 1;
                v[i].erase(v[i].begin() + j);
            }
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < v.size(); ++i) {
        int size = v[i].size();
        for (int j = 0; j < 6 - size; ++j) {
       // for (int j = 0; j < 4; ++j) {

            v[i].push_back('Z');
        }
    }

    cout << endl;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return v;
}

int main(){

    //int m = 4, n = 5;
    //vector <string> v = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    //vector <string> v = {"CAAC", "CAAC", "BAAB", "BBDD", "FFEE"};

    int m = 6, n = 6;
     //vector <string> v = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
     vector <string> v = {"TTTRRT", "MTRRRT", "MMRRFT", "TMRFAA", "TMACCN", "JFACCT"};

    while(1){
        int temp[6][6] = {0,};
        //int temp[5][4] = {0,};

        int count = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                char ch = v[i][j];
                if(ch != 'Z'){
                    if((v[i + 1][j + 1] == ch) && (v[i+1][j] == ch) && (v[i][j + 1] == ch)){
                        temp[i+1][j+1] = 1;
                        temp[i+1][j] = 1;
                        temp[i][j+1] = 1;
                        temp[i][j] = 1;
                        count += 1;
                    }
                }
            }
        }

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }

        if(count == 0){
            cout << result;
            return 0;
        }

        v = change_board(temp, v);

    }

}