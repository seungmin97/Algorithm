//
// Created by 이승민 on 2020-02-20.
//

#include<iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    vector<int> result(T);

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;
        cin >> N >> M;
        vector<int>v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int left = 0;
        int right = v.size() - 1;

        while(left < right){

            if(v[right] >= M){
                right--;
                continue;
            }

            int weight = v[left] + v[right];

            if(weight > M){
                right--;
            }
            else if(weight == M){
                result[test_case - 1] = M;
                break;
            }
            else{
                result[test_case - 1] = max(result[test_case - 1], weight);
                left++;
            }
        }
    }

    for (int i = 0; i < T; ++i) {
        if(result[i] == 0){
            cout << "#" << i + 1 << " " << -1 << endl;
            continue;
        }
        cout << "#" << i + 1 << " " << result[i] << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}