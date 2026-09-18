#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

int user_logic(vector<string> &ops) {
  int sum = 0;
  stack<int> s;

  for (int i = 0; i < ops.size(); ++i) {
    string item = ops[i];
    if (ops[i] == "+") {
      int first = s.top();
      s.pop();

      int second = s.top();

      s.push(first);

      int newScore = first + second;

      s.push(newScore);
      sum += newScore;
    } else if (ops[i] == "D") {
      int newScore = s.top() * 2;

      s.push(newScore);
      sum += newScore;
    } else if (ops[i] == "C") {
      int removedScore = s.top();

      s.pop();
      sum -= removedScore;
    } else {
      int score =
          stoi(ops[i]); // to convert string or char into an integer value.

      s.push(score);
      sum += score;
    }
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<string> ops(n);

  for (int i = 0; i < n; ++i) {
    cin >> ops[i];
  }

  int result = user_logic(ops);
  cout << result << endl;

  return 0;
}