class Solution {
    void dfs(int index,vector<int>&subset,vector<int>nums,vector<vector<int>>& result)
        {
            if(index==nums.size())
            {
                result.push_back(subset);
                return;
            }
            subset.push_back(nums[index]);
            dfs(index+1,subset,nums,result);
            subset.pop_back();
            while(index+1<nums.size() && nums[index]==nums[index+1])
            {
                index++;
            }
            dfs(index+1,subset,nums,result);
        
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int index=0;
        vector<int>subset;
        vector<vector<int>>result;

        sort(nums.begin(),nums.end());

       dfs(index,subset,nums,result);
        return result;
    }
};