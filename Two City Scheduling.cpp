class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,pair<int,int>>> p;
        for(int i=0;i<costs.size();i++)
        {
            int diff=abs(costs[i][0]-costs[i][1]);
            p.push_back({diff,{costs[i][0],costs[i][1]}}); 
        }
        sort(p.begin(),p.end());
        long int ans=0;
        int g1=0,g2=0;
        int n=p.size()/2;
        for(int i=(p.size()-1);i>=0;i--)
        {   
            if(((p[i].second.first<p[i].second.second) && (g1<n)) || (g2>=n))
            {
                ans+=p[i].second.first;
                g1++;
            }
            else
            {
                ans+=p[i].second.second;
                g2++;
            }
        }
        return ans;
    }
};