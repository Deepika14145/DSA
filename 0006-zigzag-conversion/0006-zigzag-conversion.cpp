class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        int n = s.size();
        int cycle = 2 * numRows - 2;
        int cols = (n / cycle + 1) * (numRows - 1);

        vector<vector<char>> grid(numRows, vector<char>(cols, ' '));

        int row = 0, col = 0;
        int i = 0;

        while (i < n) {
            // Going down
            while (row < numRows && i < n) {
                grid[row++][col] = s[i++];
            }

            row = numRows - 2;
            col++;

            // Going up diagonally
            while (row > 0 && i < n) {
                grid[row--][col++] = s[i++];
            }
        }

        string ans;

        // Read row by row
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != ' ')
                    ans += grid[r][c];
            }
        }

        return ans;
    }
};