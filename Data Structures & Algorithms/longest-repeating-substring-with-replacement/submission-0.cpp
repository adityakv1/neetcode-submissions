class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0;
        int maxxfreq = 0;
        int maxx = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r] - 'A']++;
            
            // Track the most frequent character in current window
            maxxfreq = max(maxxfreq, freq[s[r] - 'A']);

            // If replacements needed > k, shrink window
            while ((r - l + 1) - maxxfreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            // Update answer
            maxx = max(maxx, r - l + 1);
        }

        return maxx;
    }
};