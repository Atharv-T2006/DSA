#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a; // negatives
        vector<int> b; // positives
        int i = 0, j = 0;

        // Split into negatives and positives
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                b.push_back(nums[i]);
            } else {
                a.push_back(nums[i]);
            }
        }

        // Square values
        for (int i = 0; i < a.size(); i++) {
            a[i] = a[i] * a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            b[i] = b[i] * b[i];
        }

        // Reverse negatives (since they were decreasing originally)
        reverse(a.begin(), a.end());

        // Merge two sorted lists
        vector<int> result;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                result.push_back(a[i++]);
            } else {
                result.push_back(b[j++]);
            }
        }
        while (i < a.size()) result.push_back(a[i++]);
        while (j < b.size()) result.push_back(b[j++]);

        return result;
    }
};
