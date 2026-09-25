#include <iostream>
#include <vector>

std::vector<int> modify_array(int n, std::vector<int> arr) {
    int maxHold = arr[0];
    for(int i = 0; i < n; ++i)
    {
        if(maxHold < arr[i])
        {
            maxHold = arr[i];
        }
        arr[i] += maxHold;
    }
    return arr;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> modified_arr = modify_array(n, arr);
    for(int i = 0; i < modified_arr.size(); i++) {
        std::cout << modified_arr[i] << " ";
    }
    return 0;
}