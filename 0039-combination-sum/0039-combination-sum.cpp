class Solution {
         vector<vector<int>> result;
        vector<int>current_subset;
        int index=0;

    void dfs(int index,vector<int>& current_subset,vector<int>& candidates,int current_target)
        {

            if(current_target==0)
            {
                result.push_back(current_subset);
                return ;
            }

            if(index==candidates.size())
            {
                return;
            }
            if(current_target<0)
            {
                return;
            }
            current_subset.push_back(candidates[index]);
            dfs(index,current_subset,candidates,current_target-candidates[index]);
            current_subset.pop_back();
            dfs(index+1,current_subset,candidates,current_target);

        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
   
        dfs(index,current_subset,candidates,target);
        return result;
        
    }
};