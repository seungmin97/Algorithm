//
// Created by 이승민 on 2020-02-10.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    if(n < 3){
        return v.at(n);
    }

    for (int i = 3; i <= n; ++i) {
        v.push_back((v[i-1] + v[i-2]) % 1000000007);
    }

    answer = v.at(n);

    return answer;
}

int main(){

    /*cout << solution(3) << endl;
    cout << solution(4) << endl;
    cout << solution(5) << endl;
    cout << solution(6) << endl;
    cout << solution(28) << endl;*/

    for (int i = 0; i < 300; ++i) {
        cout << solution(i) << endl;
    }


    return 0;
}