class Solution {
public:

    // Check whether s[start...end] is a palindrome
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(int start, string& s,
                   vector<string>& current,
                   vector<vector<string>>& result) {

        // Entire string has been partitioned
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start; end < s.size(); end++) {

            // Only choose the substring if it is a palindrome
            if (isPalindrome(s, start, end)) {

                // Choose
                current.push_back(s.substr(start, end - start + 1));

                // Explore
                backtrack(end + 1, s, current, result);

                // Undo choice
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> current;

        backtrack(0, s, current, result);

        return result;
    }
};