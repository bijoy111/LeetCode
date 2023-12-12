class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long int ans=0;
        long int tmp=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                ans=nums[i],tmp=nums[i];
                continue;
            }
            if((tmp+nums[i])>nums[i])
            {
                tmp+=nums[i];
            }
            else
            {
                tmp=nums[i];
            }
            if(ans<tmp)
            {
                ans=tmp;
            }

        }
        return ans;
    }
};