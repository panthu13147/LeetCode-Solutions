class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int highest=0,lowest=prices[0];
        int max=0;
        int high,low;


        for (int i : prices)
        {
            low=i;
            high=i;
            if( low < lowest)
            {
                highest=i;
                lowest=i;
            }
            else if (high > highest)
            {
                highest=i;
            }
            max=std::max(max,highest-lowest);
            
        }
        return max;
        
    }
};