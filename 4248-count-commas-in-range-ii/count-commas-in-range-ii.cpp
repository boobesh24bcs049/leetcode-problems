class Solution {
public:
    long long countCommas(long long n) {
        long long count_commas=0;
        for(long long i=1000;i<=n;i*=1000)
        {
            count_commas+=n-i+1;
            if(i>n/1000) break;
        }
        return count_commas;
    }
};