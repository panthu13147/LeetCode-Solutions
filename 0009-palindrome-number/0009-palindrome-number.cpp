class Solution {
public:
    bool isPalindrome(int x) {
        double reversed=0;
        int orignal = x;
        if(x<0)
        {
            return false;
        }
        while(x!=0)
        {
            int digit = x%10;
            reversed = reversed*10 + digit;
            x = x/10;
        }
        if(reversed != orignal)
        {
            return false;
        }
        return true;
    }
};