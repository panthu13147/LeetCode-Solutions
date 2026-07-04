class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    std::sort(piles.begin(),piles.end());
    int left=1,right = piles.back();
    int mid;

    while(left<=right)
    {
        mid=left+(right-left)/2;
        long long hn=0;
        for(int i:piles)
        {
             hn+= (i+mid-1)/mid;
        }

        if(hn<=h)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        } 
    }
    return left;


    }
};