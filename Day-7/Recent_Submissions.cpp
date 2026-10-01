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

    int l = 0;
    int max_size = 0;
    for(int i = 0; i < n; ++i)
    {
        while(arr[i] - arr[l] >= 5000)
        {
            l++;
        }
        int current_size = i - l + 1;
        max_size = max(max_size, current_size);
    }
    
    cout << max_size;
    return 0;
}