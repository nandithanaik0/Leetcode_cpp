#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() -  1;
        vector <int> output;

        while (i<j){
            if (numbers[i] + numbers[j] > target){
                j--;
            }
            else if (numbers[i] + numbers[j] < target){
                i++;
            }
            else{
                output.push_back(i+1);
                output.push_back(j+1);
                break;
            }
        }
        return output;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    // Call the twoSum function
    vector<int> result = sol.twoSum(numbers, target);

    // Print output
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
