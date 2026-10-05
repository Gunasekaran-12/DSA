#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int k, int n, int sum, int start) {

        // Base case
        if (current.size() == k) {

            if (sum == n) {
                ans.push_back(current);
            }

            return;
        }

        // Numbers are only from 1 to 9
        for (int i = start; i < 10; i++) {

            // Choose
            current.push_back(i);

            // Explore
            backtrack(k, n, sum + i, i + 1);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        backtrack(k, n, 0, 1);

        return ans;
    }
};

int main() {

    Solution obj;

    int k = 3;
    int n = 7;

    vector<vector<int>> result =
        obj.combinationSum3(k, n);

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