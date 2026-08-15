class Solution {

    void dfs(int index, vector<int>& subset, vector<int>& nums, vector<vector<int>>& result)
    {
        if(index==nums.size())
        {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(index + 1, subset, nums, result);
        subset.pop_back();
        dfs(index + 1, subset, nums, result);




    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int index=0;
        vector<vector<int>> result;
        vector<int> subset;
        dfs(index,subset,nums,result);


        return result;
    }
};