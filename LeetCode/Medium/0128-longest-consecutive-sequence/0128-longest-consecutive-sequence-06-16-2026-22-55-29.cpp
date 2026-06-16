class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> num1,ss;
       int longest=1,temp=1;
       if(nums.size()==0)
       {
        return 0;
       }
        for(int i :nums)
        {
            num1.insert(i);
        }
        for(int i:num1)
        {
            if(num1.find(i-1)==num1.end())
            { int k=i;
                
                while(num1.find(k+1)!=num1.end())
                {
                    temp++;
                    k++;
                }
                if(temp>longest)
                {
                    longest=temp;
                }
                
                    temp=1; 
            }
            else
            {
            continue;
            }

     
                
        }

        return longest;
    }
};