class Solution {
public:
    int longestPalindrome(string s) {
        int res[200];
        for(int i=0;i<200;i++)
            res[i]=0;
        for(char c:s)
        {
            res[static_cast<int>(c)]++;
        }
        int odd=0;
        int ans=0;
        for(int i=0;i<200;i++)
        {
            if(res[i]%2!=0)
                odd=1;
            ans+=(res[i]/2)*2;
        }
        if(odd==1)ans++;
        return ans;
    }
};