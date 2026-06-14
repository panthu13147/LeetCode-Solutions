class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<int> result;
        for(int i :nums)
        {
            count[i]++;

        }
        vector<std::pair<int,int>> vec(count.begin(),count.end());
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Use '>' for descending order
         }
    );
    for (auto& v: vec)
    {
        result.push_back(v.first);
    }
    std::vector<int> slice(result.begin() + 0, result.begin() + k);
    return slice;       
    }
};