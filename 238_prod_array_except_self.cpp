#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod_output;

        for (int i = 0; i < nums.size(); i++) {
            int prod = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    prod *= nums[j];
                }
            }
            prod_output.push_back(prod);
        }
        return prod_output;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
