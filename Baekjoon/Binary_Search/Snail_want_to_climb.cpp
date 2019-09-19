#include <iostream>
#include <algorithm>

using namespace std;
int main() {

    int A, B, V;
    cin >> A >> B >> V;

    long long left = 0;
    long long right = 1000000000;

    long long location;
    long long result = 1000000000;

    while(left <= right){

        long long mid = (left + right) / 2;

        location = (A * mid) - (B * (mid - 1));

        if((location >= V) && (location < (V + A))){

            //cout << location << endl;
            result = min(result, mid);
            right = mid - 1;
        }
        else if(location >= (V + A)){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << result;
    return 0;
}