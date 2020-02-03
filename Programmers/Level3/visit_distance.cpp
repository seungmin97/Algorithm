//
// Created by 이승민 on 2020-02-03.
//

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int solution(string dirs) {
    int answer = 0;

    int arr1[11][10];
    int arr2[11][10];
    for (int i = 0; i < 11; i++) {
        memset(arr1[i], 0, sizeof(int) * 10);
        memset(arr2[i], 0, sizeof(int) * 10);
    }

    int x = 0, y = 0;
    int check = 0;
    for (int i = 0; i < dirs.length(); ++i) {
        if(dirs[i] == 'U' && y < 5){
            if(arr1[x][y + 2] == 0){
               answer++;
               arr1[x][y+2] = 1;
            }
            y++;
        }
        else if(dirs[i] == 'D' && y > -5){
            if(arr1[x][y+1] == 0){
                answer++;
                arr1[x][y+1] = 1;
            }
            y--;
        }
        else if(dirs[i] == 'L' && x > -5){
            if(arr2[x+1][y] == 0){
                answer++;
                arr2[x+1][y] = 1;
            }
            x--;
        }
        else if(dirs[i] == 'R' && x < 5){
            if(arr2[x+2][y] == 0){
                answer++;
                arr2[x+2][y] = 1;
            }
            x++;
        }
        else{
            continue;
        }

    }

    return answer;
}

int main(){

    cout << solution("LR") << endl;
    cout << solution("ULURRDLLU") << endl;
    cout << solution("LULLLLLLU") << endl;

    return 0;
}