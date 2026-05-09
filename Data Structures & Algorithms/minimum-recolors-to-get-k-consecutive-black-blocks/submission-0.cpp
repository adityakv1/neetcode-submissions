class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n =blocks.size();
        int b=0;
        int m =INT_MIN;
        for(int i =0;i<k;i++){
            if(blocks[i]=='B'){
                b++;
            }
        }
        m=max(b,m);
        for(int i =k;i<n;i++){
            if(blocks[i-k]=='B'){
                b--;
            }
            if(blocks[i]=='B'){
                b++;
            }
            m=max(b,m);
        }
        return k-m;
    }
};