class Solution {
public:
   bool isValid(string s) {
    stack<char> st;
    unordered_map<char,char> pair = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for(char c : s) {
        if(pair.count(c) == 0)       // opening bracket
            st.push(c);
        else {                        // closing bracket
            if(st.empty() || st.top() != pair[c])
                return false;
            st.pop();
        }
    }
    return st.empty();

        
    }
};