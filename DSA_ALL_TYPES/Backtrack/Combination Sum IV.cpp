#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> dp;

    int backtrack(vector<int>& nums, int target) {

        // Base case
        if (target == 0)
            return 1;

        // Already calculated
        if (dp[target] != -1)
            return dp[target];

        int count = 0;

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Since nums is sorted
            if (nums[i] > target)
                break;

            count += backtrack(
                nums,
                target - nums[i]
            );
        }

        // Store answer
        return dp[target] = count;
    }

    int combinationSum4(
        vector<int>& nums,
        int target
    ) {

        // Sort the array
        sort(nums.begin(), nums.end());

        // Initialize DP
        dp.assign(target + 1, -1);

        return backtrack(nums, target);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 3};

    int target = 4;

    int result = obj.combinationSum4(nums, target);

    cout << "Number of combinations: "
         << result << endl;

    return 0;
}