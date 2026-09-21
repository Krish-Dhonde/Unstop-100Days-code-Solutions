#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> labels(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> labels[i];
    }
    
    unordered_map<int, int> freq;
    for(int e : labels)
    {
        freq[e]++;
    }

    int max = 0;
    int freqElem = labels[0];

    for(auto const& e : freq)
    {
        if(e.second >= max )
        {
            max = e.second;
            freqElem = e.first;
        }
    }

    cout<< freqElem;
    return 0;
}