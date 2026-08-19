class Solution {

   void dfs(vector<vector<int>>&result,vector<int>&candidates,int index,vector<int>&current_subset,int target)
    {
        if(target==0)
        {
            result.push_back(current_subset);
            return;
        }
        if(target<0 || index==candidates.size())
        {
            return;
        }
        current_subset.push_back(candidates[index]);
        dfs(result,candidates,index+1,current_subset,target-candidates[index]);
        current_subset.pop_back();
        while(index + 1 <candidates.size() && candidates[index]==candidates[index+1])
        {
            index++;
        }
        dfs(result,candidates,index+1,current_subset,target);

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_subset;
        sort(candidates.begin(),candidates.end());
        int index=0;

        dfs( result,candidates,index,current_subset,target);
        return result;
    }
};