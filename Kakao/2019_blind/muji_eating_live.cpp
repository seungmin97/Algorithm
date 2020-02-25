//
// Created by 이승민 on 2020-02-24.
//
/*
 * #include <string>
#include <vector>
#include <string.h>

using namespace std;

int solution(vector<int> food_times, long long k) {

    long long count = 0;

    int check = 1;
    while(1){
        vector <int> temp;
        for (int i = 0; i < food_times.size(); ++i) {
            if(food_times[i] >= check){
                //food_times[i]--;
                temp.push_back(i);
            }
        }

        check++;
        if(temp.size() == 0){
            return -1;
        }

        if(temp.size() == 1){
            if(count + food_times[temp[0]] - check >= k){
                return temp[0] + 1;
            }
        }
        else if(temp.size() == 2){
            if(food_times[temp[0]] + count - check >= k){
                if((k - count) % 2 == 0){
                    return temp[0] + 1;
                }
                else{
                    return temp[1] + 1;
                }
            }
        }


        long long index = k - count;
        count += temp.size();
        if(count > k){
            return (temp[index % temp.size()] + 1);
        }
    }
}
 */
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {

    long long count = 0;

    /*int check = 0;
    while(1){
        vector <int> temp;
        for (int i = 0; i < food_times.size(); ++i) {
            if(food_times[i] >= check + 1){
                temp.push_back(i);
            }
        }

        if(temp.size() == 0){
            return -1;
        }

        if((food_times[temp[0]] - check) + count >= k){
            return temp[(k - count) % temp.size()] + 1;
        }
        else if(count + (food_times[temp[0]] - check) * temp.size() <= k){
            count += (food_times[temp[0]] - check) * temp.size();
            check += food_times[temp[0]] - check;
        }
        else{
            check++;

            long long left = count;
            count += temp.size();

            if((left <= k) && (k < count)){
                return temp[k - left] + 1;
            }
        }
    }*/

    vector<int> check;
    vector<pair<int,int>> v;
    for (int i = 0; i < food_times.size(); ++i) {
        v.push_back(make_pair(food_times[i], i));
        check.push_back(i);
    }

    sort(v.begin(), v.end());

    int index = 0;
    int num = v[0].first;
    long long sum = 0;
    while(1){

        int size = food_times.size() - index;
        if(size == 0){
            return -1;
        }
        long long temp = num * size;
        sum += temp;
        if(sum < k){
            //다음줄 검사하기 전
            vector<int>::iterator it;
            it = find(check.begin(), check.end(), v[0].second);
            check.erase(it);

            //다음줄 검사
            //sum += temp;
            num = v[1].first - v[0].first;
            v.erase(v.begin());

            index++;
            continue;

        }
        else if(sum == k){
            if(v[1].first - v[0].first == 0){
                return -1;
            }
            else{
                vector<int>::iterator it;
                it = find(check.begin(), check.end(), v[0].second);
                check.erase(it);
                return check[0] + 1;
            }
        }
        else if(sum > k){

            if(sum - temp - k > 0){
                return check[(sum - temp - k) % check.size()] + 1;
            }
            else{
                return check[(check.size() - sum + k) % check.size()] + 1;
            }
        }
        else{
            return -1;
        }
    }

}

int main(){

    cout << solution({2,3,4}, 8) << endl; //3
    cout << solution({5,1,5}, 6) << endl; //3
    cout << solution({5,1,5}, 7) << endl; //1
    cout << solution({5,1,5}, 9) << endl; //1
    cout << solution({5,1,5}, 10) << endl; //3
    cout << solution({5,1,5}, 11) << endl; //-1
    cout << solution({5,5,5}, 13) << endl; //2
    cout << solution({5,5,5}, 14) << endl; //3
    cout << solution({5,5,5}, 12) << endl; //1
    cout << solution({5,5,5}, 15) << endl; //-1
    cout << solution({5,5,5}, 17) << endl; //-1

    cout << endl << endl;
    //cout << solution({5,2,3,4,1}, 15) << endl;
    //23451234134141
    for (int i = 1; i < 20; ++i) {
        cout << solution({5,2,3,4,1}, i) << endl;
    }


    return 0;
}