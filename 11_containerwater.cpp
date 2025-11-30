#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_area = 0;

        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            max_area = max(max_area, area);

            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution sol;
    int result = sol.maxArea(height);

    cout << "Maximum area: " << result << endl;

    return 0;
}
