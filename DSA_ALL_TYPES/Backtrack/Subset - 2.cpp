#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtrack(vector<int>& nums, int index) {

    // Every path is a valid subset
    ans.push_back(path);

    for (int i = index; i < nums.size(); i++) {

        // Skip duplicate at the same level
        if (i > index && nums[i] == nums[i - 1]) {
            continue;
        }

        // Choose
        path.push_back(nums[i]);

        // Move to next element
        backtrack(nums, i + 1);

        // Backtrack
        path.pop_back();
    }
}

int main() {

    vector<int> nums = {1, 2, 2};

    // IMPORTANT: sort first
    sort(nums.begin(), nums.end());

    backtrack(nums, 0);

    cout << "All unique subsets:\n";

    for (vector<int> subset : ans) {

        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}