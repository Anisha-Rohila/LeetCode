class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        int maxFreq = 0;
        for (int x : freq) {
            if (x > maxFreq) {
                maxFreq = x;
            }
        }
        int maxCount = 0;
        for (int x : freq) {
            if (x == maxFreq) {
                maxCount++;
            }
        }
        int answer = (maxFreq - 1) * (n + 1) + maxCount;
        return max(answer, (int)tasks.size());
    }
};