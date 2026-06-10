class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n,i;
        std::set<int> myset;        
        n=nums.size();


        for(i=0;i<n;i++)
        {
            if(myset.find(nums[i])==myset.end())
            {
            myset.insert(nums[i]);
            }
            else{
            return true;
        }}
        return false;
    }
};