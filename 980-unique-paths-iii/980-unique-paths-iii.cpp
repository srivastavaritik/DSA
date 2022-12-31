class Solution {
public:
int uniquePathsIII(vector<vector<int>>& grid) {
    vector<vector<int>> originalGrid = grid;
    int numSquares = 0;
    int startI = -1;
    int startJ = -1;
    int endI = -1;
    int endJ = -1;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != -1) {
                numSquares++;
            }
            if (grid[i][j] == 1) {
                startI = i;
                startJ = j;
            } else if (grid[i][j] == 2) {
                endI = i;
                endJ = j;
            }
        }
    }

    int numVisited = 1;
    int numPaths = 0;
    dfs(grid, originalGrid, startI, startJ, endI, endJ, numSquares, numVisited, numPaths);
    return numPaths;
}



private:
void dfs(vector<vector<int>>& grid, vector<vector<int>>& originalGrid, int i, int j, int endI, int endJ, int numSquares, int numVisited, int& numPaths) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] == -2) {
        return;
    }

    if (i == endI && j == endJ && numVisited == numSquares) {
        numPaths++;
        return;
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    grid[i][j] = -2;
    for (int d = 0; d < 4; d++) {
        int newI = i + directions[d][0];
        int newJ = j + directions[d][1];
        dfs(grid, originalGrid, newI, newJ, endI, endJ, numSquares, numVisited + 1, numPaths);
    }
    grid[i][j] = originalGrid[i][j];
}
};
