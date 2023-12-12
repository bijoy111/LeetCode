class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l=s.length();
        vector<char> ch;
        int j=0;
        for(int i=0; i<l; i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                ch.push_back(s[i]+32);
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                ch.push_back(s[i]);
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                ch.push_back(s[i]);
            }
        }
        for(int i=0,j=ch.size()-1;i<j;i++,j--)
        {
            if(ch[i]!=ch[j]) return false;
        }
    return true;

    }
};