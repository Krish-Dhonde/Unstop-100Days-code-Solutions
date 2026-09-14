#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool isB = false;
        bool isR = false;
        bool possible = true;

        for(char c : s)
        {
            if(c == 'B')
            {
                isB = true;
            }
            else if(c == 'R')
            {
                isR = true;
            }
            else
            {
                if(isB != isR)
                {
                    possible = false;
                    break;
                }
                
                isB = false;
                isR = false;
            }
        }

        if(isB != isR)
        {
            possible = false;
        }

        cout<< (possible ? "YES" : "NO") << '\n';
    }
       
    return 0;
}