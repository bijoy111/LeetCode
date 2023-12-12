class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        long int ans=0;
        while(i<j)
        {
            long int tmp=min(height[i],height[j])*(j-i);
            if(ans<tmp||ans==0)
            {
                ans=tmp;
            }
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};