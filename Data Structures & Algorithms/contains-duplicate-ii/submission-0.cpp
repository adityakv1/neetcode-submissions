class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n =nums.size();
        for(int i = 0; i < n && i <= k; i++){
            if(map.find(nums[i])!=map.end()){
                return true;
            }
            map[nums[i]]++;
        }
        for(int i =k+1;i<n;i++){
            map[nums[i-k-1]]--;
            if(map[nums[i-k-1]]==0){
                map.erase(nums[i-k-1]);
            }
            int num=nums[i];
            if(map.find(num)!=map.end()){
                return true;
            }
            map[num]++;
        }
        return false;
    }
};