class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for(char T:t){
            map[T]++;
        }
        int have=0;
        int m=INT_MAX;
        int l=0;
        int need = map.size();
        int n =s.length();
        pair<int,int> ans;
        unordered_map<char,int> window;
        for(int r=0;r<n;r++){
            char c= s[r];
            window[c]++;
            if(map.find(c)!=map.end()&&map[c]==window[c]){
                have++;
            }
            while(have==need){
                if(r-l+1<m){
                    m=r-l+1;
                    ans={l,r};
                }
                window[s[l]]--;
                if(map.find(s[l])!= map.end()&&map[s[l]]>window[s[l]]){
                    have--;
                }
                l++;
            }
            
        }
        if(m==INT_MAX){
            return "";
        }
        return s.substr(ans.first, m);
    }
};
