#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int, int>> A;
        vector<pair<int, int>> B;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1) {
                    A.push_back({i, j});
                }

                if (img2[i][j] == 1) {
                    B.push_back({i, j});
                }
            }
        }

        map<pair<int, int>, int> mp;

        int ans = 0;

        for (auto p1 : A) {
            for (auto p2 : B) {

                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                mp[{dr, dc}]++;

                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> img1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    };

    vector<vector<int>> img2 = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}
    };

    Solution obj;

    cout << obj.largestOverlap(img1, img2) << endl;

    return 0;
}