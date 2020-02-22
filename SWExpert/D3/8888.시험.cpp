//
// Created by 이승민 on 2020-02-21.
//

#include<iostream>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    cin>>test_case;
    int answer1[test_case];
    int answer2[test_case];
    for(int h = 0; h < test_case; ++h)
    {
        int N, T, P;
        cin >> N >> T >> P;

        int arr[T][N];
        for (int i = 0; i < T; ++i) {
            memset(arr[i], 0, sizeof(int) * N);
        }

        int count[T];
        memset(count, 0, sizeof(int) * T);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < T; ++j) {
                int temp;
                cin >> temp;
                if(temp == 1){
                    arr[j][count[j]] = i;
                    count[j]++;
                }
            }
        }

        int result[N];
        memset(result, 0, sizeof(int) * N);
        for (int i = 0; i < T; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                result[arr[i][j]] += (N - count[i]);
            }
        }

        int rank = 1;
        for (int i = 0; i < N; ++i) {
            if(result[i] > result[P - 1]){
                rank++;
            }
            else if((result[i] == result[P - 1]) && (i < (P - 1))){
                rank++;
            }
        }

        answer1[h] = result[P - 1];
        answer2[h] = rank;
    }

    for (int i = 0; i < test_case; ++i) {
        cout << "#" << i + 1 << " " << answer1[i] << " " << answer2[i] << endl;
    }

    return 0;
}