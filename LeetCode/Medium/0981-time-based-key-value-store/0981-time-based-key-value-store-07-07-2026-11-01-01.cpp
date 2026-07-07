class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }
        
        auto& list = store[key];   // & avoids copying the whole vector
        int left = 0, right = list.size() - 1;
        int bestIdx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid].first <= timestamp) {
                bestIdx = mid;      // valid candidate — remember its INDEX
                left = mid + 1;     // look further right for an even better one
            } else {
                right = mid - 1;
            }
        }
        
        return bestIdx == -1 ? "" : list[bestIdx].second;
    }
};