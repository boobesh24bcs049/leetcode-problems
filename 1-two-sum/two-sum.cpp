class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> a;
        for(int i=0;i<nums.size();i++)
        {
            int n=target-nums[i];
            if(a.find(n)!=a.end())
            {
                return {a[n],i};
            }
             a[nums[i]]=i;
        }
        return {};
    }
};