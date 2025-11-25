#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for (int i = 0;i<nums.size(); i++) {

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = nums.size() - 1;

            while (j<k){
                if (nums[i] + nums[j] +  nums[k] > 0) {
                    k--;
                }
                else if (nums[i] + nums[j] +  nums[k] <0) {
                    j++;
                }
                else{
                   result.push_back({nums[i], nums[j], nums[k]}); 
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Triplets:\n";
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
