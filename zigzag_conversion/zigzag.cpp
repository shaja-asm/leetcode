#include <string>
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1 || numRows==s.size()) return s;

        vector<string> rows(min(numRows, int(s.size())));                   // Create a vector of strings for rows
        int curRow = 0;
        bool goingDown = false;

        // Traverse the string and build rows
        for (char c:s) {
            rows[curRow] += c;

            if (curRow==0 || curRow==numRows-1) goingDown = !goingDown;     // Change direction at the top and bottom rows

            curRow += goingDown ? 1 : -1;                                   // Move to the next row based on direction
        }
        string result;

        for (string row:rows) result += row;

        return result;
        
    }
};


int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    cout << solution.convert("PAYPALISHIRING", 4) << endl;
    cout << solution.convert("A", 1) << endl;
    return 0;
}