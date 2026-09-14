class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int ,int> counts;
        for(int num:nums) counts[num]++;

        int sum=0;
        for(const auto& pair: counts) if(pair.second==1) sum+=pair.first;
        return sum;
    }
};