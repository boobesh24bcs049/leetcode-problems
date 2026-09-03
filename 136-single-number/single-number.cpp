class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int a:nums) result^=a;
        return result;
    }
};