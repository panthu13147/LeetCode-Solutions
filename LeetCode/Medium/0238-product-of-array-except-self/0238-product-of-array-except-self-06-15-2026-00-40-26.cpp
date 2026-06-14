class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int k,n;
        
        n=nums.size();
        int suffix=1,prefix=1;
        vector<int> left(n,1),right(n,1);
        vector<int> result(n);
        for(int k=0;k<n;k++)
        {
            left[k]=suffix;
             suffix*=nums[k];
        }
        for(int k=n-1;k>=0;k--)
        {
            right[k]=prefix;
            prefix*=nums[k];
        }
        for(int i=0;i<=n-1;i++)
        {
            result[i]=left[i]*right[i];
         
        }
        
        
        
     return result;   
    }
};
