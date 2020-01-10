//
// Created by 이승민 on 2020-01-10.
//

#include <iostream>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack <char> st;
    if(s[0] == ')'){
        return false;
    }
    st.push(s[0]);

    for (int i = 1; i < s.length(); ++i) {
        if(s[i] == '('){
            st.push('(');
        }
        else{
            if(st.size() == 0){
                return false;
            }
            if(st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    if(st.size() == 0){
        return true;
    }
    else{
        return false;
    }

}

int main(){

    cout << solution("()()")<<endl;
    cout << solution("(())()") << endl;
    cout << solution(")()(") << endl;
    cout << solution("(()(");

    return 0;
}