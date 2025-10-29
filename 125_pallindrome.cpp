//Leetcode 125. Valid palindrome
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string new_str = "";

        for(int i = 0; i < s.size();i++){
            if (isalnum(s[i])){
                new_str.push_back(tolower(s[i]));
            }
        }

        string rev_str = new_str;
        reverse(rev_str.begin(), rev_str.end());

        if (new_str == rev_str){
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution sol;
    string s = "tab a cat";

    bool result = sol.isPalindrome(s);
    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}
