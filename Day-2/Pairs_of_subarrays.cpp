#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int calculate_pairs(int n, vector<int>& arr) {
    int pairs = 0;
    unordered_map<int, int> freq;

    for(int split = 0; split <= n - 1; ++split)
    {
        int current_sum = 0;
        for(int i = split; i >= 0; --i)
        {
            current_sum += arr[i];
            freq[current_sum]++;
        }

        int next_sum = 0;
        for(int j = split + 1; j < n; ++j)
        {
            next_sum += arr[j];

            if(freq.find(next_sum) != freq.end())
            {
                pairs += freq[next_sum];
            }
        }
    }
    return pairs;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = calculate_pairs(n, arr);
    cout << result << endl;
    return 0;
}