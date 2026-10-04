#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtrack(vector<int>& nums, int index) {

    // Every path is a valid subset
    ans.push_back(path);

    for (int i = index; i < nums.size(); i++) {

        // Choose
        path.push_back(nums[i]);

        // Move to next element
        backtrack(nums, i + 1);

        // Backtrack
        path.pop_back();
    }
}

int main() {

    vector<int> nums = {1, 2, 3};

    backtrack(nums, 0);

    cout << "All subsets:\n";

    for (vector<int> subset : ans) {

        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}