class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {
        {-1, 0}, {0, -1}, {0, 1}, {1, 0}
    };

    bool isSafe(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1; // the cell itself
        for (auto& d : dir) {
            int newi = i + d[0];
            int newj = j + d[1];

            if (isSafe(newi, newj) && matrix[newi][newj] < matrix[i][j]) {
                ans = max(ans, 1 + dfs(newi, newj, matrix, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(i, j, matrix, dp));
            }
        }

        return result;
    }
};
