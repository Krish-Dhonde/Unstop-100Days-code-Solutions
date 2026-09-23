#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int main()
{
    int q;
    cin >> q;

    unordered_map<int, long long> frequency;

    for(int i = 0; i < q; ++i)
    {
        long long count;
        int number;

        cin >> count >> number;

        frequency[number] += count;
    }

    if(frequency.size() <= 1)
    {
        cout << 0;
        return 0;
    }

    auto it = frequency.begin();

    int minNumber = it->first;
    long long minFrequency = it->second;

    int maxNumber = it->first;
    long long maxFrequency = it->second;

    ++it;

    for(; it != frequency.end(); ++it)
    {
        int number = it->first;
        long long currentFrequency = it->second;

        // Find lowest frequency
        if(currentFrequency < minFrequency)
        {
            minFrequency = currentFrequency;
            minNumber = number;
        }
        else if(currentFrequency == minFrequency)
        {
            if(number < minNumber)
            {
                minNumber = number;
            }
        }

        // Find highest frequency
        if(currentFrequency > maxFrequency)
        {
            maxFrequency = currentFrequency;
            maxNumber = number;
        }
        else if(currentFrequency == maxFrequency)
        {
            if(number > maxNumber)
            {
                maxNumber = number;
            }
        }
    }

    cout << abs(maxNumber - minNumber);

    return 0;
}