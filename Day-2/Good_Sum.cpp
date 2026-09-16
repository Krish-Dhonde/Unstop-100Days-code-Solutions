#include <iostream>
#include <vector>
using namespace std;

int good_sum(int N, vector<int>& A)
{
    int i = 0;

    while (i < A.size())
    {
        // Process only negative elements
        if (A[i] < 0)
        {
            int negative = A[i];
            int required = -negative;

            int sum = 0;
            int removeStart = i - 1;

            // Move backwards and find minimum elements
            // whose sum is >= required
            while (removeStart >= 0)
            {
                sum += A[removeStart];

                if (sum >= required)
                {
                    break;
                }

                removeStart--;
            }

            // If even all previous elements are not enough,
            // remove everything before the negative element.
            if (sum < required)
            {
                A.erase(A.begin(), A.begin() + i);

                // Negative element is now at index 0
                A[0] = required;

                i = 1;
            }
            else
            {
                // Remove the required consecutive elements
                A.erase(A.begin() + removeStart, A.begin() + i);

                // Negative element is now at removeStart
                A[removeStart] = required;

                // Continue from the element after it
                i = removeStart + 1;
            }
        }
        else
        {
            // Current element is not negative
            i++;
        }
    }

    // Calculate final sum
    int result = 0;

    for (int x : A)
    {
        result += x;
    }

    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    int result = good_sum(N, A);
    std::cout << result << std::endl;
    return 0;
}