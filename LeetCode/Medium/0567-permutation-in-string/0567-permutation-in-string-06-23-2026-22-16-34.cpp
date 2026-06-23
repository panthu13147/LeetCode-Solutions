class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_size=s1.size();
        unordered_map<char,int> map1,map2;
        int left=0;
        for(int i=0;i<window_size;i++)
        {
            map1[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++)
        {
           
            if(i+1-left<=window_size)
            {
                map2[s2[i]]++;
            }
            else
            {
                map2[s2[i]]++;
                map2[s2[left]]--;
                if(map2[s2[left]]==0)
                {
                    map2.erase(s2[left]);
                }
                left++;
                
            }
            if(map1==map2)
            {
                return true;
            }
        }
        return false;

        
    }
};