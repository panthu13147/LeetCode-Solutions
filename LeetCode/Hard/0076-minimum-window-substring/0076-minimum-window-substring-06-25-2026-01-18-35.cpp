class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> map2,map1;
        int left=0;
        int count=0;
        string window;
        int minlen=INT_MAX,minstart=-1;
        for(int i=0;i<t.size();i++)
        {
            map2[t[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            map1[s[i]]++;
            if(map2.count(s[i]) && map1[s[i]]==map2[s[i]])
            {
                count++;
            }
   

            while(count==map2.size())
            {
                if(minlen>i-left+1)
                {
                    minlen=i-left+1;
                    minstart=left;
                }
            
        
            
            if(map2.find(s[left])==map2.end())
            {
                map1[s[left]]--;
            if(map1[s[left]]==0)
            {
                map1.erase(s[left]);
            }
                left++;
            }
            else if(map1[s[left]]>map2[s[left]])
            {
                map1[s[left]]--;
                left++;
            }
            else
            {
                map1[s[left]]--;
                count--;
                left++;
            }
            }
            }
            

        
        if (minstart==-1)
        {
            return "";
        }
        else
        {
        return s.substr(minstart,minlen);
        }

        
    }
};