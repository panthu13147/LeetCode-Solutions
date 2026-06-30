class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> st;
    vector<pair<int,int>> cars;
    for(int i=0;i<position.size();i++)
    {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
    return a.first > b.first; // Descending by position
    }
    );

    for(const auto &[ p,s] :cars)
    {
        double time =(double)(target-p)/s ;
        if(st.empty() || time>st.top() )
        {
            st.push(time);
        }
        else
        {}

    }
    return st.size();
       
    }
};