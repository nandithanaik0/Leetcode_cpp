//Brute Force Method
#include <iostream>
#include <vector>

using namespace std;
class Solution {

public:
bool hasDuplicate(vector<int> &nums){
        int n = nums.size();
        for (int i=0; i < n; i++){
            for (int j= i+1;j<n;j++){
                if (nums[i]==nums[j]){
                    return true;
    
                }
            }
        }
        return false;
}
};

int main(){
    Solution sol;
    int n;
    vector<int> nums = {1,2,3,4}; //dynamic array xdefined
    if (sol.hasDuplicate(nums)){
        cout<< "Duplicate found";
    }
    else{
        cout<<" No Duplicates";
    }
    return 0;
    
};
