class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> substring;
        int left=0,right;
        int window_length=0;
        int maxf=0;
        int count=0;
        int result=0;
        for(int right=0;right<s.size();right++)
        {           
 
            substring[s[right]]++;
            count=substring[s[right]];
            
            maxf=std::max(maxf,count);
            if(right-left+1-maxf<=k)
            {
                result=std::max(result,right-left+1);

            }
           else
            {
                substring[s[left]]--;
                left++;
            }
             

           

        
        }




        return result;
    }
};