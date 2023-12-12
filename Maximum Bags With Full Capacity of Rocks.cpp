class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++)
        {
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        long ans=0;
        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i]<=additionalRocks)
            {
                additionalRocks-=capacity[i];
                capacity[i]=0;;
                ans++;
            }
        }
        return ans;
    }
};