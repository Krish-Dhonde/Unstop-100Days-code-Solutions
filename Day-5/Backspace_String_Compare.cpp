#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool userLogic(string bob, string alice) {
    stack<char> bob_stack;
    stack<char> alice_stack;

    int size_bob = bob.size();
    int size_alice = alice.size();

    // For Bob.
    for(int i = 0; i < size_bob; ++i)
    {
        if(bob[i] == '#')
        {
            if(!bob_stack.empty())
            {
                bob_stack.pop();
            }
        }
        else
        {
            bob_stack.push(bob[i]);
        }
    }

    // For Alice.
    for(int i = 0; i < size_alice; ++i)
    {
        if(alice[i] == '#')
        {
            if(!alice_stack.empty())
            {
                alice_stack.pop();
            }
        }
        else
        {
            alice_stack.push(alice[i]);
        }
    }

   return bob_stack == alice_stack;
}

int main() {
    string bob, alice;
    getline(cin, bob);
    getline(cin, alice);
    bool result = userLogic(bob, alice);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}