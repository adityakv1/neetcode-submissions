class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left=0;
        int n =nums.size();
        int m=INT_MAX;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                m=min(m,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(m!=INT_MAX){
            return m;
        }
        return 0;
    }
};