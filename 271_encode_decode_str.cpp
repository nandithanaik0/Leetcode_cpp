//Leetcode 271. Encode and Decode Strings
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> str_sizes;

    string encode(vector<string>& strs) {
        string combined = "";
        for (int i = 0; i<strs.size(); i++){
            str_sizes.push_back(strs[i].size());
        }

        // for (int i=0; i<str_sizes.size(); i++){
        //     cout << str_sizes[i];
        // }

        for(int i=0;i<strs.size(); i++){
            combined += strs[i];
        }

        return combined;
    }

    vector<string> decode(string s) {
        int j = 0;
        int check = 0;
        vector<string> output;

        for(int i = 0; i < str_sizes.size();i++){

            string dummy = "";
            check += str_sizes[i];

            for(j; j<check; j++){
                dummy += s[j];
            }

            output.push_back(dummy);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"hello", "world", "!!"};

    string encoded = sol.encode(strs);
    cout << "Encoded string: " << encoded << endl;

    vector<string> decoded = sol.decode(encoded);

    cout << "Decoded strings:" << endl;
    for (int i = 0; i < decoded.size(); i++) {
        cout << decoded[i] << endl;
    }

    return 0;
}
