class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<int> maxx(n,0);
        maxx[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxx[i]=max(maxx[i+1],prices[i]);
            cout<<maxx[i];
        }
        int res=0;
        for(int i =0;i<n;i++){
            int p=maxx[i]-prices[i];
            res=max(p,res);
        }
        return res;
    }
};
