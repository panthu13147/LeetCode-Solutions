class Solution {
private:
bool isvowel(char a)
{
    string vowels= "aeiouAEIOU" ;
    return vowels.find(a) != string::npos;
}
public:
    string reverseVowels(string s) {

        int left=0,right=s.size()-1;
        while(left<right)
        {
            if( isvowel(s[left]) && isvowel(s[right]))
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if( isvowel(s[left]) )
            {
                right--;
            }
            else
            {
                left++;
            }

            
        }

        return s;
    }
};