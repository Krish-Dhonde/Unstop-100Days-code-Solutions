#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max_bottle_cost(int n, int x, const vector<int>& costs)
{
    vector<int> new_costs = costs;

    sort(new_costs.begin(), new_costs.end());

    long long prefixSum = 0;
    long long answer = 0;

    for(int i = 0; i < n; ++i)
    {
        prefixSum += new_costs[i];

        // Even on day 0, these shops cannot be bought within the budget.
        if(prefixSum > x)
        {
            break;
        }

        int numberOfShops = i + 1;

        // Maximum day on which we can buy from all these shops.
        long long maxDays = (x - prefixSum) / numberOfShops;

        // Days are counted from day 0.
        long long numberOfDays = maxDays + 1;

        // The newly added shop contributes one bottle on each of these days.
        answer += numberOfDays;
    }

    return answer;
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> costs[i];
    }
    long long result = max_bottle_cost(n, x, costs);
    std::cout << result << std::endl;
    return 0;
}