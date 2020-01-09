//
// Created by 이승민 on 2020-01-09.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    int max_num = arr[arr.size() - 1];

    int num = 1;
    while(1){
        int temp = num * max_num;
        int count = 0;
        for (int i = 0; i < arr.size()-1; ++i) {
            if(temp % arr[i] == 0){
                count++;
            }
            else{
                break;
            }
        }

        if(count == (arr.size() - 1)){
            return temp;
        }
        num++;
    }

}

int main(){

    cout << solution({2,6,8,14}) << endl;
    cout << solution({1,2,3}) << endl;

    return 0;
}