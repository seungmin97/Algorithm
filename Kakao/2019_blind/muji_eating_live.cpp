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

using namespace std;

int solution(vector<int> food_times, long long k) {

    long long count = 0;

    int check = 0;
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
    }
}

int main(){

    /*cout << solution({2,3,4}, 8) << endl; //3
    cout << solution({5,1,5}, 6) << endl; //3
    cout << solution({5,1,5}, 7) << endl; //1
    cout << solution({5,1,5}, 9) << endl; //1
    cout << solution({5,1,5}, 10) << endl; //3
    cout << solution({5,1,5}, 11) << endl; //-1
    cout << solution({5,5,5}, 13) << endl; //2
    cout << solution({5,5,5}, 14) << endl; //3
    cout << solution({5,5,5}, 15) << endl; //-1
    cout << solution({5,5,5}, 17) << endl; //-1*/

    cout << solution({5,2,3,4,1}, 15) << endl;
    /*for (int i = 1; i < 20; ++i) {
        cout << solution({5,2,3,4,1}, i) - 1 << endl;
    }

*/
    return 0;
}