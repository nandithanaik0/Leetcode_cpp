#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count_map;
        vector<pair<int,int>> arr;
        vector<int>output;

        for (int i=0;i<nums.size();i++){
            if (count_map.find(nums[i]) != count_map.end()) {
                count_map[nums[i]]++;
            }
            else {
                count_map[nums[i]] = 1;
            }
        }

        for (const auto& pair : count_map){
            arr.push_back({pair.second, pair.first});
        }
        
        sort(arr.rbegin(), arr.rend());

        for (int j=0;j<k;j++){
            output.push_back(arr[j].second);
        }

        return output;

    }


};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}