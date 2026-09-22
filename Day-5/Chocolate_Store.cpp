#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void processQueries(int q, const vector<vector<string>>& queries) {
    unordered_map<string, int> stock;

    for (int i = 0; i < q; ++i)
    {
        int queryType = stoi(queries[i][0]);
        string chocolate = queries[i][1];
        int quantity = stoi(queries[i][2]);

        if (queryType == 1)
        {
            stock[chocolate] += quantity;
        }
        else if (queryType == 2)
        {
            int available = stock[chocolate];

            int sold = min(available, quantity);

            cout << sold <<'\n';

            stock[chocolate] -= sold;
        }
    }
}

int main() {
    int q;
    cin >> q;
    vector<vector<string>> queries(q, vector<string>(3));
    
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    
    processQueries(q, queries);

    return 0;
}