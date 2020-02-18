//
// Created by 이승민 on 2020-02-16.
//

/*#include <iostream>
#include <string>
using namespace std;

int check(int index, string s){

    int left = index;
    int right = s.length() - 1;
    int result = 0;

    while((left) <= (right + 2)){
        int left_ = left;
        int right_ = right;
        int count = 0;
        while((left_ + count) <= (right_ + count)){
            if(s[left_ + count] == s[right_ - count]){
                count++;
            }
            else{
                break;
            }
        }
        result = max(result, count);
        right--;
    }

    return result;
}

int solution(string s)
{
    int answer=0;

    if(s.length() <= 2){
        return 1;
    }

    for (int i = 0; i < s.length() - 2; ++i) {
        answer = max(check(i, s), answer);
    }

    return answer;
}
*/

#include <iostream>
#include <string>
using namespace std;

/*int check(int index, string s, int length){

    int answer = 0;

    int count = length - index;
    for(int i = length + index; i >= index + 1; i--){

        //겹치는게 있는 경우
        int check = 0;
        for (int j = 0; j < count; ++j) {
            if(s[i - j - 1] != s[i + j + 1]){
                break;
            }
            else{
                check++;
            }
        }

        if(check == count){
            answer = max(answer, check * 2 + 1);
        }

        //겹치는게 앖는 경우
        check = 0;
        for (int j = 0; j <= count; ++j) {
            if(s[i - j] != s[i + j + 1]){
                break;
            }
            else{
                check++;
            }
        }

        if(check == (count + 1)){
            answer = max(answer, check * 2);
        }
        count--;
    }

    return answer;
}

int solution(string s)
{
    int answer=0;

    if(s.length() <= 2){
        return 1;
    }

    for (int i = 0; i < s.length(); ++i) {
        int length = s.length() - i;
        if(length % 2 == 0){
            length -= 2;
        }
        else{
            length -= 1;
        }
        length /= 2;

        int result = check(i, s, length);

        answer = max(answer, result);
    }

    return answer;
}
*/

int check(int index, string s){

    int result = 0;
    int length = s.length() - index;
    int check = 0;
    //1이면 홀수, 0이면 짝수
    if(length % 2 != 0){
        check = 1;
    }
    length /= 2;
    int count = 0;
    int check1 = 1;
    int check2 = 1;
    for (int j = length; j >= 1; --j) {
        count = 0;

        //겹치는지 확인
        if((check == 1) && (check1 == 1)){
            for (int i = 1; i <= length; ++i) {
                if(s[j - i + index] != s[j + i + index]){
                    break;
                }
                count++;
            }
        }
        if(count == j) {
            result = max(result, 2 * j + 1);
            check1 = 0;
        }

        if(j > 1 && check2 == 1){
            count = 0;
            //안겹치는지 확인
            for (int i = 1; i <= length; ++i) {
                if(s[j - i + index] != s[j + i - 1 + index]){
                    break;
                }
                count++;
            }

            if(count == j){
                result = max(result, 2 * j);
                check2 = 1;
            }

        }

        check = 1;
    }
    return result;
}

int solution(string s){

    int answer = 0;

    if(s.length() <= 2){
        return 1;
    }

    for (int i = 0; i < s.length() - 2; ++i) {
        answer = max(check(i, s), answer);
    }

    return answer;
}


int main(){

    cout << solution("abcdcba") << endl; //7
    cout << solution("abacde") << endl; //3
    cout << solution("bababcde") << endl; //5
    cout << solution("abccba") << endl; //6
    cout << solution("cbababcde") << endl; //7
    cout << solution("abcdc") << endl; //3
    cout << solution("a") << endl; //1
    cout << solution("") << endl; //1
    cout << solution("aaab") << endl;
    return 0;
}