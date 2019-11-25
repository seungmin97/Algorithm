#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end());

    while (1) {

        if (routes[0][1] < routes[1][0]) {
            answer++;
        }
        else if(routes[0][1] <= routes[1][1]){
            routes[1][1] = routes[0][1];
        }

        if (routes.size() == 2) {
            answer++;
            return answer;
        }
        else {
            routes.erase(routes.begin() + 0);
        }
    }

}

int main(){

    vector<vector<int>> routes = {{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}};

    cout << solution(routes);

    return 0;
}