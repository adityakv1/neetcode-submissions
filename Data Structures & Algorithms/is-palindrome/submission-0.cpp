class Solution {
    public:
        bool isPalindrome(string s) {
                int i =0;
                        int n =s.length();
                                
                                        string word;
                                                while(i<n){
                                                            if(isalnum(s[i])){
                                                                            word+=tolower(s[i]);
                                                                                        }
                                                                                                    i++;
                                                                                                            }
                                                                                                                    int m =word.length();
                                                                                                                            int l=0,r=m-1;
                                                                                                                                    while(l<=r){
                                                                                                                                                if(word[l]!=word[r]){
                                                                                                                                                                return false;
                                                                                                                                                                            }
                                                                                                                                                                                        l++;
                                                                                                                                                                                                    r--;
                                                                                                                                                                                                            }
                                                                                                                                                                                                                    return true;
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                        };