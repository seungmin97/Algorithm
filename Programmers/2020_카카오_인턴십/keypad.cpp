//
// Created by 이승민 on 2020-07-20.
//

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

struct position{
    int x;
    int y;
};

string solution(vector<int> numbers, string hand) {
    string answer = "";

    position left, right;
    left.x = 3;
    left.y = 0;
    right.x = 3;
    right.y = 2;

    for (int i = 0; i < numbers.size(); ++i) {
        int temp = 0;

        if(numbers[i] == 0){
            temp = 3;
        }
        else{
            temp = numbers[i] / 3;
        }

        if(numbers[i] % 3 == 1){
            answer += "L";
            left.x = temp;
            left.y = 0;
        }
        else if(numbers[i] % 3 == 0 && numbers[i] != 0){
            answer += "R";
            right.x = temp - 1;
            right.y = 2;
        }
        else{
            int left_ = abs(left.x - temp) + abs(left.y - 1);
            int right_ = abs(right.x - temp) + abs(right.y - 1);

            if(left_ > right_){
                answer += "R";
                right.x = temp;
                right.y = 1;
            }
            else if(left_ < right_){
                answer += "L";
                left.x = temp;
                left.y = 1;
            }
            else{
                if(hand == "right"){
                    answer += "R";
                    right.x = temp;
                    right.y = 1;
                }
                else{
                    answer += "L";
                    left.x = temp;
                    left.y = 1;
                }
            }

        }
    }

    return answer;
}

int main(){
    cout << "LRLLLRLLRRL" << endl;
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;

    cout << "LRLLRRLLLRR" << endl;
    cout << solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left") << endl;

    cout << "LLRLLRLLRL" << endl;
    cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right") << endl;

    return 0;
}
