class Solution {
    // Helper function (saare containers pass by reference '&' hone chahiye)
    void dfs(vector<bool>& visited, vector<int>& current_perm, vector<int>& nums, vector<vector<int>>& result) {
        
        // Base Case: Saare numbers pick ho gaye
        if (current_perm.size() == nums.size()) {
            result.push_back(current_perm);
            return;
        }

        // Loop array ke end tak chalega (bina -1 ke)
        for (int i = 0; i < nums.size(); i++) {
            
            // Agar number pehle se used hai, toh skip karo
            if (visited[i] == true) {
                continue;
            }

            // TAKE IT
            visited[i] = true;
            current_perm.push_back(nums[i]);
            
            // DFS call agle step ke liye
            dfs(visited, current_perm, nums, result);
            
            // BACKTRACK (Undo)
            current_perm.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Saare variables main function mein banao
        vector<vector<int>> result;
        vector<int> current_perm;
        
        // Visited array ko nums ki size jitna banao, aur sabko 'false' set karo
        vector<bool> visited(nums.size(), false);

        // DFS start karo
        dfs(visited, current_perm, nums, result);

        return result;
    }
};