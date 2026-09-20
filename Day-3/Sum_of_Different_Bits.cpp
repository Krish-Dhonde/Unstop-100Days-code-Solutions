#include <bits/stdc++.h>
using namespace std;

#define MAX 200002

long long int compareBits(string a, string b) {
    int n = a.length();
    int m = b.length();

    // prefix[i] = number of '1's in b[0 ... i-1]
    vector<int> prefix(m + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        prefix[i + 1] = prefix[i];

        if (b[i] == '1')
        {
            prefix[i + 1]++;
        }
    }

    long long answer = 0;

    // Number of substrings of b having length n
    int windows = m - n + 1;

    for (int i = 0; i < n; ++i)
    {
        // a[i] is compared with:
        // b[i] ... b[i + windows - 1]

        int left = i;
        int right = i + windows - 1;

        // Number of 1s in b[left ... right]
        int ones = prefix[right + 1] - prefix[left];

        if (a[i] == '0')
        {
            // 0 differs from 1
            answer += ones;
        }
        else
        {
            // 1 differs from 0
            int zeros = windows - ones;
            answer += zeros;
        }
    }

    return answer;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << compareBits(a, b);
    return 0;
}