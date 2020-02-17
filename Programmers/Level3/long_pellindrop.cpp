//
// Created by 이승민 on 2020-02-16.
//

#include <iostream>
#include <string>
using namespace std;

int check(int index, string s, int length){

    int answer = 0;

    int count = 1;
    for (int i = index + 1; i <= length; ++i) {

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
        count++;
    }

    return answer;
}

int solution(string s)
{
    int answer=0;

    if(s.length() < 2){
        return s.length();
    }

    for (int i = 0; i < s.length(); ++i) {
        int length = s.length() - i;
        if(length % 2 == 0){
            length -= 2;
        }
        else{
            length += 1;
        }
        length /= 2;

        int result = check(i, s, length);
        if(result != 0){
            return result;
        }
    }

    return answer;
}

int main(){

    cout << solution("abcdcba") << endl;
    cout << solution("abacde") << endl;
    cout << solution("bababcde") << endl;
    cout << solution("abccba") << endl;
    cout << solution("a") << endl;
    cout << solution("") << endl;

    return 0;
}