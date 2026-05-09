class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        int l =0;
        int maxx=0;
        unordered_map<char,int> map;
        for(int r=0;r<n;r++){
            if(map.find(s[r])!=map.end()&&map[s[r]]>=l){
                l=map[s[r]]+1;
            }
            map[s[r]]=r;
            maxx=max(maxx,r-l+1);
        }
        return maxx;
    }
};
