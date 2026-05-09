class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0;
        int maxx=0;
        int n =fruits.size();
        unordered_map<int,int> map;
        for(int right=0;right<n;right++){
            map[fruits[right]]++;
            while(map.size()>=3){
                map[fruits[left]]--;
                if(map[fruits[left]]<=0){
                    map.erase(fruits[left]);
                }
                left++;
            }
            maxx=max(maxx,right-left+1);
        }
        return maxx;
    }
};