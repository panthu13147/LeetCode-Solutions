class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;   
        for(int i=0;i<s.size();i++)
        {

           
            if(stack.empty())
            {
                stack.push(s[i]);
            }
            else if (stack.top()==')' || stack.top()==']' || stack.top()=='}')
            {
                return false;
            }
            else if (stack.top()=='(' && s[i]==')')
            {
                stack.pop();
            }
            else if (stack.top()=='[' && s[i]==']')
            {
                stack.pop();
            }
            else if (stack.top()=='{' && s[i]=='}')
            {
                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }
            
        }


     return stack.empty();   
    }
};