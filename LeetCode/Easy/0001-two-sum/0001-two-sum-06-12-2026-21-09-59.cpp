class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n,i;
        std::unordered_map<int, int> ans;
        n=nums.size();
        for (i=0;i<n;i++)
        {
            if(ans.find(nums[i])!=ans.end())
            {
                return {ans[nums[i]],i};
            }
            else
            {
                ans[target-nums[i]]=i;
            }

        }
        return {0};

    }
};