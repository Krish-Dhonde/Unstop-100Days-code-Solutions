#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    if(!(std::cin >> n)) return 0;

    std::vector<string> arr(n);
    std::unordered_map<string, int> freq;

    for(int i = 0; i < n; ++i)
    {
        std::cin>> arr[i];
        freq[arr[i]]++;
    }

    int k;
    std::cin >> k;

    int unique = 0;
    for(int i = 0; i < n; ++i)
    {
        if(freq[arr[i]] == 1)
            unique++;

            if(unique == k)
            {
                std::cout<< arr[i]<<'\n';
                return 0;
            }
    }

    std::cout<< -1<< '\n';
    return 0;
}