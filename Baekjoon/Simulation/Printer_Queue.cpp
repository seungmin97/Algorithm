//
// Created by 이승민 on 2019-09-24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define Max 100

using namespace std;

bool cmp(const int &a, const int &b){
    return a > b;
}

int check(int N, int M){

    vector <pair <int, int>> v;
    vector <int> find_max;
    int count;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        v.push_back(make_pair(i, temp));
        find_max.push_back(temp);
    }

    sort(find_max.begin(),find_max.end(), cmp);

    int index = 0;
    int max = find_max[index];
    count = 0;
    while(1){

            int check = 0;

            if(v[0].second < max){
                check = 1;
            }

            if(check == 1){
                v.push_back(make_pair(v[0].first, v[0].second));
                v.erase(v.begin() + 0);
            }
            else if((v[0].first) == M){
                count++;
                return count;
            }
            else{
                count++;
                v.erase(v.begin() + 0);

                max = find_max[++index];
            }
        }
}

int main(){

    int test_case;
    cin >> test_case;

    int N, M;

    int result[Max];
    memset(result, 0, sizeof(result));

    for (int i = 0; i < test_case; ++i) {
        cin >> N >> M;

        result[i] = check(N, M);
    }
    for (int i = 0; i < test_case; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
