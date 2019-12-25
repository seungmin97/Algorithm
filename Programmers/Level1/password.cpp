//
// Created by 이승민 on 2019-12-25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    char temp;
    int num;

    for (int i = 0; i < s.length(); ++i) {
        temp = s[i] + n;
      if((s[i] >= 65) && (s[i] <= 90)){
          num = (temp - 90) / 26;
          if(temp > 90){
              temp -= 26 * (num + 1);
          }
      }
      else if((s[i] >= 97) && (s[i] <= 122)){
          num = (temp - 122) / 26;
        if(temp > 122){
            temp -= 26 * (num + 1);
        }
      }
      else{
          temp = s[i];
      }
        answer += temp;
    }

    return answer;
}

int main(){

    cout << solution("AB",1) << endl;
    cout << solution("z", 6) << endl;
    cout << solution("a B z", 4) << endl;

    return 0;
}