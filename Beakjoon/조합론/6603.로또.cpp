//
// Created by 이승민 on 2020-10-21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){

    //입력처리
    vector<string> v;
    string str;
    while(1){
        getline(std::cin, str);
        if(str == "0"){
            break;
        }
        v.push_back(str);
    }


    vector<vector<int>> v_(v.size());

    for (int i = 0; i < v.size(); ++i) {

        stringstream ss(v[i]);
        int index = 0;
        int temp;

        while(ss >> temp){
            if(index == 0){
                index = 1;
            }
            else{
                v_[i].push_back(temp);
            }
        }


        vector<int> check(v_[i].size(), 0);
        for (int j = 0; j < 6; ++j) {
            check[j] = 1;
        }
        sort(v_[i].begin(), v_[i].end());
        sort(check.begin(), check.end());

        vector<vector<int>> result;
        do{
            vector<int> haha;
            for (int j = 0; j < check.size(); ++j) {
                if(check[j] == 1){
                    haha.push_back(v_[i][j]);
                }
            }

            result.push_back(haha);
        }while(next_permutation(check.begin(), check.end()));

        sort(result.begin(), result.end());
        for (int k = 0; k < result.size(); ++k) {
            for (int j = 0; j < 6; ++j) {
                cout << result[k][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}