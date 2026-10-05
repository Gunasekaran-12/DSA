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

        for (int i = start; i < candidates.size(); i++) {

            // Since candidates is sorted,
            // no later element can be smaller
            if (candidates[i] > target)
                break;

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i means we can use the same element again
            backtrack(candidates,
                      target - candidates[i],
                      i);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};

    int target = 7;

    vector<vector<int>> result =
        obj.combinationSum(candidates, target);

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