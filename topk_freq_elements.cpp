#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<pair<int,int>> arr;
        vector<int> output;

        for(int i = 0; i< nums.size(); i++){
            if (count.find(nums[i])!= count.end()) {
                count[nums[i]] = count[nums[i]] + 1;
            } else {
                count[nums[i]] = 1;
            }
        }

        for (const auto& pair : count) {
            arr.push_back({pair.second, pair.first});
        }
        sort(arr.rbegin(), arr.rend());

        for (int i = 0; i < k; i++){
            output.push_back(arr[i].second);
        }

        return output;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
