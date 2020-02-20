//
// Created by 이승민 on 2020-02-20.
//

#include<iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;

    int T;
    cin>>T;

    vector<int> answer(T);

    for(test_case = 1; test_case <= T; ++test_case)
    {
        stack <int> s;
        int K;
        cin >> K;
        for (int i = 0; i < K; ++i) {
            int temp;
            cin >> temp;
            if(temp == 0 && s.size() != 0){
                s.pop();
            }
            else{
                s.push(temp);
            }
        }

        while(s.size() != 0){
            answer[test_case - 1] += s.top();
            s.pop();
        }
    }

    for (int i = 0; i < T; i++) {
        cout << "#" << i + 1 << " " << answer[i] << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}