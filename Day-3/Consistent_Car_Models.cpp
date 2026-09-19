#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countConsistentCars(const string& components, int n, const vector<string>& models) {
    vector<string> consistent;

    for(int i = 0; i < n; ++i)
    {
        bool is_consistent = true;

        for(char c : models[i])
        {
            if(components.find(c) == std::string::npos)
            {
                is_consistent = false;
                break;
            }
        }

        if(is_consistent)
        {
            consistent.push_back(models[i]);
        }
    }

    return consistent.size();  
}

int main() {
    string components;
    int n;
    vector<string> models;

    getline(cin, components);
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string model;
        cin >> model;
        models.push_back(model);
    }

    int result = countConsistentCars(components, n, models);
    cout << result << endl;

    return 0;
}