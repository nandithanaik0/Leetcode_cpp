//20_Valid Parentheses leetcode
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> stack;
        unordered_map <char, char> bracket_map;

        bracket_map = { {'}','{'}, {')','('}, {']','['}};

        for (char i:s){
            if(bracket_map.count(i)){
                if (!stack.empty() && stack.top() == bracket_map[i]){
                    stack.pop();
                }
                else {
                    return false;
                }
            }else {
                stack.push(i);
            }
        }
        return stack.empty();
    }
};


int main() {
    Solution sol;
    string s = "{[()]}";

    bool result = sol.isValid(s);
    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}