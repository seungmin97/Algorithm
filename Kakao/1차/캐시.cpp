//
// Created by 이승민 on 2019-10-10.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define Size 5
using namespace std;

int main() {

    int cacheSize = 0;
    string cities[Size] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    for (int i = 0; i < Size; i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(),  (int(*)(int))toupper);
    }
    vector <string> v;

    if (cacheSize == 0) {
        cout << Size * 5;
        return 0;
    }

    vector <string>::iterator it;
    int result = 0;
    for (int i = 0; i < Size; i++)
    {
        it = find(v.begin(), v.end(), cities[i]);

        if (it == v.end()) {
            if (v.size() >= cacheSize) {
                result += 5;
                v.erase(v.begin() + cacheSize - 1);
                v.insert(v.begin(), cities[i]);
            }
            else {
                result += 5;
                v.insert(v.begin() + 0, cities[i]);

            }
        }
        else {
            result += 1;
            v.erase(v.begin() + cacheSize - 1);
            v.insert(v.begin(), cities[i]);
        }
    }
    cout << result;
    return 0;
}