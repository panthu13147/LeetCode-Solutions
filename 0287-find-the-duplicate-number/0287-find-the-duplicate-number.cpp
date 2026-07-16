class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        
        // Phase 1: Find the intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Phase 2: Find the entrance to the cycle
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};