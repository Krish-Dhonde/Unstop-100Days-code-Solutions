#include <iostream>
#include <vector>
using namespace std;

void find_flower_indices(int n, int t, std::vector<int>& arr, int result[2]) {
    int l = 0;
    int r = n - 1;

    while(l < r)
    {
        int sum = arr[l] + arr[r];

        if(sum == t)
        {
            result[0] = l;
            result[1] = r;
            break;
        }
        else if(sum < t)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
}

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int result[2];
    find_flower_indices(n, t, arr, result);
    std::cout << result[0] << " " << result[1];
    return 0;
}