class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string,vector<string>> ans;
        for(string s:strs)
        {
            string key=s;
            std::sort(key.begin(),key.end());
            ans[key].push_back(s);


        }
        vector<vector<string>> result;
         for(auto& pair:ans)
         {
            result.push_back(pair.second);
         }
        return result;
    }  
};