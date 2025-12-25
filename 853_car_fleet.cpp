#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector < pair<int,int>> pair_pos;

        for  (int i = 0; i < position.size(); i++){
            pair_pos.push_back({position[i],speed[i]});
        }
        sort(pair_pos.rbegin(),pair_pos.rend());

        vector<double> stack;

        for(auto& p : pair_pos){
            stack.push_back((double)(target - p.first)/p.second);

            if (stack.size()>=2 && stack.back() <= stack[stack.size() - 2]){
                stack.pop_back();
            }
        }
        return stack.size();
        
    }
};


int main() {
    Solution sol;

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed    = {2, 4, 1, 1, 3};

    int result = sol.carFleet(target, position, speed);

    cout << "Number of car fleets: " << result << endl;

    return 0;
}
