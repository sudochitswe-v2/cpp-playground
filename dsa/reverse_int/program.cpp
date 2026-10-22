#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check for overflow/underflow before multiplying by 10
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    Solution sol;

    // Test cases
    int testCases[] = {123, -123, 120, 0, 1534236469, -2147483648};
    for (int x : testCases) {
        cout << "Input: " << x << " -> Reversed: " << sol.reverse(x) << endl;
    }

    return 0;
}
