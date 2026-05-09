class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n =heights.size();
        int l=0,r=n-1;
        int maxx=INT_MIN;
        while(l<=r){
            int v=min(heights[l],heights[r])*(r-l);
            maxx=max(maxx,v);
            if(heights[l]<heights[r]){
                l++;
            }
            else if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return maxx;
    }
};
