class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        int b,a,result;
        for(string i: tokens)
        {
            if(i=="+" || i=="-" || i=="*" || i=="/")
            {
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
            
            if (i=="+"){
            result= a + b;
            }
            else if (i=="-"){
            result= a - b;
            }
            else if (i=="*"){
            result= a * b;
            }
            else if (i=="/"){
            result= a / b;
            }
            st.push(result);
            }
            else
            {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};