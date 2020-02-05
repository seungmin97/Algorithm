//
// Created by 이승민 on 2020-02-03.
//

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int solution(string dirs) {
    int answer = 0;

    //왼오
    int arr1[11][11];
    //위아래
    int arr2[11][11];

    for (int i = 0; i < 11; i++) {
        memset(arr1[i], 0, sizeof(int) * 11);
        memset(arr2[i], 0, sizeof(int) * 11);
    }

    int x = 5, y = 5;
    for (int i = 0; i < dirs.length(); ++i) {

        if(dirs[i] == 'U' && y < 10){
            if(arr2[x][y] == 0){
               answer++;
               arr2[x][y] = 1;
            }
            y++;
        }
        else if(dirs[i] == 'D' && y > 0){
            if(arr2[x][y-1] == 0){
                answer++;
                arr2[x][y-1] = 1;
            }
            y--;
        }
        else if(dirs[i] == 'L' && x > 0){
            if(arr1[x-1][y] == 0){
                answer++;
                arr1[x-1][y] = 1;
            }
            x--;
        }
        else if(dirs[i] == 'R' && x < 10){
            if(arr1[x][y] == 0){
                answer++;
                arr1[x][y] = 1;
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

    cout << solution("LR") << endl; //1
    cout << solution("ULURRDLLU") << endl; //7
    cout << solution("LULLLLLLU") << endl; //7
    cout <<  solution("LLLLRLRLRLL") << endl; //5
    cout << solution("UUUUDUDUDUUU") << endl; //5
    cout << solution("LURDLURDLURDLURDRULD") << endl; //7
    cout << solution("RRRRRRRRUUUUUUULU") << endl; //11


    return 0;
}