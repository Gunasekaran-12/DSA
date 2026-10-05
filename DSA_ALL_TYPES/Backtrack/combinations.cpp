#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int start, int n, int k) {

        // Base case
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Try all possible numbers
        for (int i = start; i <= n; i++) {

            // Choose
            current.push_back(i);

            // Explore
            backtrack(i + 1, n, k);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        backtrack(1, n, k);

        return ans;
    }
};

int main() {

    Solution obj;

    int n = 4;
    int k = 2;

    vector<vector<int>> result = obj.combine(n, k);

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