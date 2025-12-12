#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack_num; 

        for(int i=0;i<tokens.size();i++){
            if (tokens[i]!= "+" && tokens[i]!= "-" && tokens[i]!=
            "*" && tokens[i]!= "/"){
                stack_num.push(stoi(tokens[i])); 
            }
            else{
                if (tokens[i] == "+"){
                    int b = stack_num.top();
                    stack_num.pop();
                    int a = stack_num.top();
                    stack_num.pop();
                    int c = a + b;
                    stack_num.push(c);
                }
                else if (tokens[i] == "-"){
                    int b = stack_num.top();
                    stack_num.pop();
                    int a = stack_num.top();
                    stack_num.pop();
                    int c = a - b;
                    stack_num.push(c);
                }
                else if (tokens[i] == "*"){
                    int b = stack_num.top();
                    stack_num.pop();
                    int a = stack_num.top();
                    stack_num.pop();
                    int c = a*b;
                    stack_num.push(c);
                }
                else if (tokens[i] == "/"){
                    int b = stack_num.top();
                    stack_num.pop();
                    int a = stack_num.top();
                    stack_num.pop();
                    int c = a/b;
                    stack_num.push(c);
                }
            }
        
        }
        return stack_num.top();
        
    }
};

int main() {
    Solution sol;

    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = sol.evalRPN(tokens);

    cout << result << endl;  // Expected output: 9

    return 0;
}