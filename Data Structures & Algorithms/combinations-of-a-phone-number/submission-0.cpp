class Solution {
public:
    void dfs(string digits,vector<string> &ans,string cans,int curr,int n,unordered_map<char,vector<char>>map){
        if(curr==n){
            ans.push_back(cans);
            return;
        }
        for(char c: map[digits[curr]]){
            cans.push_back(c);
            int d=curr+1;
            dfs(digits,ans,cans,d,n,map);
            cans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,vector<char>>map;
        map['2']={'a','b','c'};
        map['3']={'d','e','f'};
        map['4']={'g','h','i'};
        map['5']={'j','k','l'};
        map['6']={'m','n','o'};
        map['7']={'p','q','r','s'};
        map['8']={'t','u','v'};
        map['9']={'w','x','y','z'};
        vector<string> ans;
        string cans;
        int n = digits.size();
        int curr=0;
        dfs(digits,ans,cans,curr,n,map);
        return ans;
    }
};
