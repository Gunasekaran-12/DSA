#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int start) {

        // Base case
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Try every possible candidate
        for (int i = start; i < candidates.size(); i++) {

            // Since array is sorted
            // no need to check further
            if (candidates[i] > target)
                break;

            // Skip duplicate numbers at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i + 1 means each element can be used only once
            backtrack(candidates, target - candidates[i], i + 1);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target
    ) {

        // Sort for duplicate handling
        // and early stopping
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    int target = 8;

    vector<vector<int>> result =
        obj.combinationSum2(candidates, target);

    cout << "Combinations:" << endl;

    for (vector<int> combination : result) {

        cout << "[ ";

        for (int x : combination) {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}