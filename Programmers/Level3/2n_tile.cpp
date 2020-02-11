//
// Created by 이승민 on 2020-02-10.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int solution(int n) {
    int answer = 1;
    vector<int> v(n+1);

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;

    if(n < 3){
        return v[n];
    }

    int count = 1;

    while(count <= (int)(n/2)){
        int temp1 = n - 2 * count;
        int temp2 = count;
        answer += (factorial(temp1+temp2) / (factorial(temp1) * factorial(temp2)));
        count++;
    }

    return answer;
}

int main(){

    /*cout << solution(3) << endl;
    cout << solution(4) << endl;
    cout << solution(5) << endl;
    cout << solution(6) << endl;
    cout << solution(28) << endl;*/

    for (int i = 0; i < 100; ++i) {
        cout << factorial(i) << endl;
    }

    return 0;
}