#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <pair<int,int>> temp_stack;
        vector<int> output(temperatures.size(),0);

        for (int i = 0; i<temperatures.size(); i++){
            while(!temp_stack.empty() && temperatures[i] > temp_stack.top().first){
                auto pair = temp_stack.top();
                temp_stack.pop();

                output[pair.second] = i - pair.second;
            }
            temp_stack.push({temperatures[i],i});
        }
        return output;
    }
};

int main() {
    Solution sol;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = sol.dailyTemperatures(temperatures);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}