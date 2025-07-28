#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
 bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums){
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);

        }
        return false;
    }
};

int main(){
    Solution sol;
    int n;
    vector<int> nums = {1,2,3,3}; //dynamic array xdefined
    if (sol.hasDuplicate(nums)){
        cout<< "Duplicate found";
    }
    else{
        cout<<" No Duplicates";
    }
    return 0;
    
};