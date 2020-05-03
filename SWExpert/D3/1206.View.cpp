//
// Created by 이승민 on 2020-05-04.
//

#include<iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //cin>>T;
    T = 10;
    int result[10] = {0};

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;

        int num;
        cin >> num;

        int *temp = new int[num];

        for (int i = 0; i < num; ++i) {
            cin >> temp[i];
        }

        for (int i = 0; i < num; ++i) {
            int max_;

            if(i == 1){
                max_ = max(temp[i + 1], temp[i + 2]);
            }
            else if(i == 2){
                max_ = max({temp[i - 1], temp[i + 1], temp[i + 2]});
            }
            else if(i == num - 1){
                max_ = max({temp[i - 1], temp[i - 2], temp[i + 1]});
            }
            else if(i == num - 2){
                max_ = max(temp[i - 1], temp[i - 2]);
            }
            else{
                max_ = max({temp[i - 1], temp[i - 2], temp[i + 1], temp[i + 2]});
            }

            if(temp[i] > max_){
                answer += (temp[i] - max_);
            }
        }
        result[test_case-1] = answer;

    }

    for (int i = 0; i < 10; ++i) {
        cout << "#" << i + 1 << " " << result[i] << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}