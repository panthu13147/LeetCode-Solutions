class Solution {
public:
    bool isPalindrome(string s) {
        int left,right;
        left=0;
        right=s.size()-1;
        while(left<right)
        {
            if (isalnum(s[left])==false)
            {
                left++;
            }
            if (isalnum(s[right])==false)
            {
                right--;
            }
            if(isalnum(s[left]) && isalnum(s[right]))
            {

            
            if(tolower(s[left])!=tolower(s[right]))
            {
                return false;
            }
            else{
                left++;
                right--;
            }
            }
        }
        return true;
        
    }
};