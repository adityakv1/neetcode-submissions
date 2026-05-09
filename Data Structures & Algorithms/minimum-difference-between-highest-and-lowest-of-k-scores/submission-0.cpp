class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minn=INT_MAX;
        int n =nums.size();

        for(int i =0;i<=n-k;i++){
            int diff=nums[i+k-1]-nums[i];
            
            minn=min(minn,diff);
        }
        return minn;
    }
};