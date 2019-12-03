//
// Created by 이승민 on 2019-12-03.
//

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int **map = new int*[n];

    for (int i = 0; i < n; ++i) {
        map[i] = new int[m];
        memset(map[i], 0 ,sizeof(int) * (m));
    }

    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]-1][puddles[i][0]-1]=-1;
    }

    map[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)
                continue;
            if(map[i][j]==-1){
                map[i][j]=0;
                continue;
            }
            if(i > 0 && j > 0){
                map[i][j]=(map[i-1][j]+map[i][j-1])%1000000007;
            }
            else if(i < 1){
                map[i][j] = map[i][j-1];
            }
            else{
                map[i][j] = map[i-1][j];
            }
        }
    }

    answer = map[n-1][m-1];

    return answer;
}
int main(){

    cout << solution(4,3,{{2,2}});

    return 0;
}