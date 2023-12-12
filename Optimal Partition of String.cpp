class Solution {
public:
    int partitionString(string s) {
        int vec[26];
        long int ans=1;
        for(int i=0;i<26;i++)
        {
            vec[i]=0;
        }
        for(char c:s)
        {
            vec[c-97]++;
            if(vec[c-97]>1)
            {
                ans++;
                for(int i=0;i<26;i++)
                {
                    vec[i]=0;
                }
                vec[c-97]=1;
            }
        }
        return ans;
    }
};