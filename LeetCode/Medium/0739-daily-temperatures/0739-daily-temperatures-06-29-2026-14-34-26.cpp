class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

    vector<int> result(temperatures.size(),0);
    std::stack<int> st;

    for(int i=0;i<temperatures.size();i++)
    {
        while(!st.empty() && temperatures[i]>temperatures[st.top()])
        {
            int prev_index = st.top();
            st.pop();
            result[prev_index]= i-prev_index;
        }
        st.push(i);
    }
    return result;

  }
};