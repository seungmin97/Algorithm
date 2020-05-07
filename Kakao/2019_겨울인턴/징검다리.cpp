//
// Created by 이승민 on 2020-05-07.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int mid = 1;

    while(1){

        for (int i = 0; i < stones.size(); ++i) {
            if(mid > stones[i]){
                if(mid <= stones[i+1] && (i < stones.size())){
                    i+=1;
                }
                else if(mid > stones[i+2] && (i < stones.size()- 1)){
                    return answer;
                }
                else{
                    i += 2;
                }
            }
        }

        mid++;
        answer++;
    }
}

int main(){

    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) << endl;
}