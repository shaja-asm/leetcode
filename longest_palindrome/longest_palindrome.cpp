#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
       if (s.size()==0) return "";
       int n = s.size();

       string t = "#";
       for (char c:s) {
           t += c;
           t += '#';
       }
       int m = t.size();
       vector<int> p(m,0);
       int center = 0, right = 0;
       int maxCenter = 0, maxLen=0;
       
       for (int i=0; i<m; i++) {
           if (i<right) p[i] = min(right-i, p[2*center-i]);
           while (i-p[i]-1>=0 && i+p[i]+1<m && t[i-p[i]-1]==t[i+p[i]+1]) p[i]++;

           if (i+p[i]>right) {
               center = i;
               right = i+p[i];
           }

           if (p[i]>maxLen) {
               maxLen = p[i];
               maxCenter = center;
           }
        }

        int start = (maxCenter-maxLen)/2;
        return s.substr(start,maxLen);
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("babad") << endl;

    cout << solution.longestPalindrome("abcdcab") << endl;

    cout << solution.longestPalindrome("abaadcd") << endl;
    
    cout << solution.longestPalindrome("ac") << endl;
    return 0;
}