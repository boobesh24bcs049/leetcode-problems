class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close=nums[0]+nums[1]+nums[2];
        int cost=INT_MAX;
        int n=nums.size();
        if(n==3) return nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
            for(int j=i+1;j<n-1;j++)
                for(int k=j+1;k<n;k++)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if((sum-target<0?-(sum-target):sum-target)<cost)
                    {
                        cost=(sum-target<0?-(sum-target):sum-target);
                        close=sum;
                    }
                }
                return close;
    }
};