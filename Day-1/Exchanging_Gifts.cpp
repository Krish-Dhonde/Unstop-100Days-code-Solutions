#include <iostream>
#include <vector>

void find_youngest_member(int n, int m, std::vector<std::pair<int, int>> &gifts) {
    std::vector<int> give(n+1, 0);
    std::vector<int> recieve(n+1, 0);

    for(int i = 0; i < m; ++i)
    {
        int giver = gifts[i].first;
        int reciever = gifts[i].second;

        give[giver]++;
        recieve[reciever]++;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(give[i] == 0 && recieve[i] == n - 1)
        {
            std::cout<<i<<'\n';
            return;
        }
    }

    std::cout<< -1<<'\n';
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> gifts(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> gifts[i].first >> gifts[i].second;
    }
    find_youngest_member(n, m, gifts);
    return 0;
}

