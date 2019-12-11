//
// Created by 이승민 on 2019-12-09.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int check(vector<int> money, int index){

    int result = 0;
    vector<int> temp;
    temp.push_back(index);
    result = money[index];
    vector<int> sum;
    sum.push_back(money[index]);

    while(1) {
        int size = temp.size();
        for (int i = 0; i < size; ++i) {
            for (int j = temp[i] + 2; j < temp[i] + 4; ++j) {
                if (j >= money.size() - 3) {
                    result = max(result, sum[i] + money[j]);
                    break;
                } else if (j == money.size() - 4) {
                    result = max(result, sum[i] + money[j] + money[j + 2]);
                    break;
                } else {
                    temp.push_back(j);
                    sum.push_back(sum[i] + money[j]);
                    result = max(result, sum[i] + money[j]);
                }
            }
        }
        temp.erase(temp.begin(), temp.begin() + size);
        sum.erase(sum.begin(), sum.begin() + size);

        if (temp.size() == 0){
            return result;
        }
    }

}

int solution(vector<int> money) {
    int answer = 0;

    answer = check(money,0);
    answer = max(answer, check(money,1));

    return answer;
}

int main(){

    cout << solution({1,2,3,1});

    return 0;
}
