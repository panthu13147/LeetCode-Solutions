class Solution {
public:

    bool dfs(int r, int c, int index, vector<vector<char>>& board, const string& word) {

        // Word completely matched
        if (index == word.size()) {
            return true;
        }

        // Invalid cell or character doesn't match
        if (r < 0 || c < 0 ||
            r >= board.size() ||
            c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions
        bool found = dfs(r + 1, c, index + 1, board, word) ||
                     dfs(r - 1, c, index + 1, board, word) ||
                     dfs(r, c + 1, index + 1, board, word) ||
                     dfs(r, c - 1, index + 1, board, word);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                if (board[r][c] == word[0]) {
                    if (dfs(r, c, 0, board, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};