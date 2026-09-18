#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);

    for(int i = 0; i < arr.size(); ++i)
    {
        cin >> arr[i];
    }
    
    int index = 0;
    for(int j = 0; j < arr.size(); ++j)
    {
        if(arr[j] != 0)
        {
            swap(arr[j], arr[index]);
            index++;
        }
    }

    for(int k = 0; k < n; ++k)
    {
        cout<< arr[k] << " ";
    }

    return 0;
}