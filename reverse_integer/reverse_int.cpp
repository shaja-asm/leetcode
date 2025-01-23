#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x!=0) {
            int pop = x%10;                                                         // pop the last digit
            x /= 10;
            if (result>(INT_MAX/10) || (result<(INT_MIN/10))) return 0;          // check for overflow and underflow
            result = result*10 + pop;
        }
        return result;
    }
};


int main() {
    //Problem Description,
    // Given a signed 32-bit integer x, return x with its digits reversed. 
    // If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Solution solution;
    cout << solution.reverse(1234456789) << endl;
    cout << solution.reverse(-123456789) << endl;
    cout << solution.reverse(1202360) << endl;
    return 0;
}


