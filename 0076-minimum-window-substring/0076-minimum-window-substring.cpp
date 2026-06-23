class Solution {
public:
    bool valid(vector<int>& have, vector<int>& need) {
        for (int i = 0; i <256; i++) {
            if (have[i] < need[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>have(256, 0);
        vector<int>need(256, 0);
        for (char c : t)
            need[c]++;
        int low = 0,
         start = 0,
         res = INT_MAX;
        for (int high = 0; high < s.size(); high++) {
            have[s[high]]++;
            while (valid(have, need)) {
                int len = high - low + 1;
                if (len < res) {
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if (res == INT_MAX)
            return "";
        return s.substr(start, res);
    }
};