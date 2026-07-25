class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;

        while(j<nums.size())
        {
            if(0 != nums[j])
            {
                nums[i]=nums[j];
                i++;
            }
            j++;
        }

        while(i<nums.size())
        {
            nums[i]=0;
            i++;
        }

    
    }
};