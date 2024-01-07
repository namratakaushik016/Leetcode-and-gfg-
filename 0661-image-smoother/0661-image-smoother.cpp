class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    const int m = img.size();
    const int n = img[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int ones = 0;
        int count = 0;
        for (int x = max(0, i - 1); x < min(m, i + 2); ++x)
          for (int y = max(0, j - 1); y < min(n, j + 2); ++y) {
            ones += img[x][y];
            ++count;
          }
        ans[i][j] = ones / count;
      }

    return ans;
    }
};