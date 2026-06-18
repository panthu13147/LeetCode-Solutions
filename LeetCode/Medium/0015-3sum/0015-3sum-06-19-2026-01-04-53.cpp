class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int a,b,c;
        std::sort(nums.begin(),nums.end());
        for (a=0;a<nums.size();a++)
        {
            if(a>0 && nums[a]==nums[a-1])
            {
                continue;
            }
            b=a+1,c=nums.size()-1;
            while(b<c)
            {
                if(nums[b]+nums[c]==-nums[a])
                {
                    results.push_back({nums[a], nums[b], nums[c]});
                    b++;
                    c--;
                    while(b<c && nums[b]==nums[b-1])
                    {
                        b++;
                    }
                    while(b<c && nums[c]==nums[c+1])
                    {
                        c--;
                    }

                }
                else if (nums[b]+nums[c]>-nums[a])
                {
                    c--;
                }
                else
                {
                    b++;
                }

            }
        }
        

        
        return results;
        
    }
};