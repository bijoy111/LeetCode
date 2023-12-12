class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string tmp;
        unordered_map <string,vector<string>>mp;
        for(string it:strs)
        {
            tmp=it;
            sort(it.begin(),it.end());
            mp[it].push_back(tmp);
        }
        vector<vector<string>> res;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};