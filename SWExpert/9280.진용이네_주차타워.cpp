//
// Created by 이승민 on 2020-01-08.
//

#include<iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    vector<int> result;

    for(int test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;
        int n, m;
        cin >> n >> m;
        int *price = new int[n];
        int *car = new int[m];
        for (int i = 0; i < n; ++i) {
            cin >> price[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> car[i];
        }

        int *location = new int[n];
        memset(location, 0, sizeof(int) * n);
        vector<int> wait;

        for (int i = 0; i < 2*m; ++i) {
            int temp;
            cin >> temp;
            //차가 진입하는 경우
            int index = -1;
            if(temp > 0){
                for (int j = 0; j < n; ++j) {
                    if(location[j] == 0){
                        index = j;
                        break;
                    }
                }
                //주차할 자리가 있는 경우
                if(index != -1){
                    location[index] = temp;
                    answer += price[index] * car[temp-1];
                }
                //주차할 자리가 없는 경우
                else{
                    wait.push_back(temp);
                }

            }
            //차가 나가는 경우
            else{
                for (int j = 0; j < n; ++j) {
                    if(location[j] == (temp * -1)){
                        index = j;
                        location[j] = 0;
                    }
                }
                if(wait.size()!=0){
                    location[index] = wait[0];
                    answer += price[index] * car[wait[0] - 1];
                    wait.erase(wait.begin() + 0);
                }

            }
        }
        result.push_back(answer);
    }

    for (int i = 0; i < T; ++i) {
        cout << "#" << i + 1 << " " << result[i] << endl;
    }
    return 0;
}