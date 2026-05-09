class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int total=0;
        int left=0;
        sort(nums.begin(),nums.end());
        int maxx=0;
        int n =nums.size();
        for(int right=0;right<n;right++){
            total+=nums[right];
            while(nums[right]*(right-left+1)>total+k){
                total-=nums[left];
                left++;
            }
            maxx=max(maxx,right-left+1);
        }
        return maxx;
    }
};