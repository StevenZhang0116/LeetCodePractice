#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int d[5] = {0, 1, 0, -1, 0};
public:
	int dfs(vector<vector<int>> &grid, int i, int j) {
        int result = 0;
        int temp = grid[i][j];
        grid[i][j] = 0;

        for (int k = 0; k < 4; ++k) { 
            int x = i + d[k], y = j + d[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y <  grid[0].size() && grid[x][y] != 0) {
                result = max(result, dfs(grid, x, y));
            }
        }
        grid[i][j] = temp; 
        return result + grid[i][j];
    }

    int getMaximumGold(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};

int main(){
	Solution theSolution;
	vector<vector<int>> grid;

	cin >> grid;
	cout << theSolution.getMaximumGold(grid) << endl;
}



