class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return (nums[0]-nums[0])<=k ? nums[0]-nums[0]: -1; 
        for(int j=0;j<n;j++)
        {
            int max=nums[0];
            for(int s=1;s<=j;s++) if(nums[s]>max) max=nums[s];
            int min=nums[j];
            for(int i=j+1;i<n;i++) if(nums[i]<min) min=nums[i];
            if((max-min)<=k) return j;
        }
        return -1;
    }
};