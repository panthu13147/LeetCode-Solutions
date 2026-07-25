class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // Tracks the position for the next non-zero element
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                // Seedha swap mar de! Zeroes automatically piche push hote jayenge.
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};