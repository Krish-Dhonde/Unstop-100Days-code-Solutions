#include <iostream>
#include <vector>
using namespace std;

int highestAltitude(int n, const vector<int>& arr) {
    int highest = 0;
    int altitude = 0;
    for(int i = 0; i < n; ++i)
    {
        altitude += arr[i];
        if(highest <= altitude)
        {
            highest = altitude;
        }
    }

    return highest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int result = highestAltitude(n, arr);
    cout << result << endl;

    return 0;
}