#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int maxSum = 0;
    for(int i = 0; i < n; i += 2)
    {
        maxSum += arr[i];
    }

    cout << maxSum;
    return 0;
}