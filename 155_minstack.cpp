#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:

    stack<int> stack_min;
    stack<int> history;
    
    MinStack() {

    }
    
    void push(int val) {
        stack_min.push(val);
        if(history.empty()){
            history.push(val);
        }
        else{
            if(val<history.top()){
                history.push(val);
            }
            else{
                history.push(history.top());
            }
        }
    }
    
    void pop() {
       stack_min.pop(); 
       history.pop();
    }
    
    int top() {
        return stack_min.top();
    }
    
    int getMin() {
       return history.top();   
    }
};


int main() {
    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Top: " << s.top() << endl;        // 2
    cout << "Min: " << s.getMin() << endl;     // 2

    s.pop();  // remove 2

    cout << "Top after pop: " << s.top() << endl;    // 7
    cout << "Min after pop: " << s.getMin() << endl; // 3

    return 0;
}