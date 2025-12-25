#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_index = 0;
        int right_index = nums.size()-1;

        while (left_index <= right_index){
            int mid_index = left_index + ((right_index - left_index)/2);
            if (nums[mid_index] < target){
                left_index = mid_index + 1;
            } else if (nums[mid_index] > target){
                right_index = mid_index - 1;
            }else{
                return mid_index;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    int result = sol.search(nums, target);

    cout << "Index of target " << target << ": " << result << endl;

    return 0;
}