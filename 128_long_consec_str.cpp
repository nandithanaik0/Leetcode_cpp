#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        sort(nums.begin(), nums.end());

        int output = 0;
        int count = 1;

        for (int i = 0; i < nums.size() - 1; i++){
            int j = i + 1;
            if (nums[j] == nums[i]+1){
                count++;
            }
            else if(nums[j] == nums[i]) continue;
            else{
                if(count > output){
                    output = count;
                }
                count = 1;
            }
        }
        if(count > output){
            output = count;
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = s.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << ans << endl;
    return 0;
}
