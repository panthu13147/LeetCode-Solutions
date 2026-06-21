class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {

        unordered_set<char> substring;
        int count=0,result=0,left=0;
        for(int i=0;i<s.size();i++)
        {
            if(substring.find(s[i])==substring.end())
            {
                substring.insert(s[i]);
                
            }
            else
            {
                while(substring.find(s[i])!=substring.end())
                {
                    substring.erase(s[left]);
                    left++;
                }
                substring.insert(s[i]);
                
                

            }
            result=std::max((int)substring.size(),result);
        }
        return result;

        
        
    }
};