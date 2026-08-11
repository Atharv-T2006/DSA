class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n=nums.size();
        int prefix_sum=nums[0];
        
       for(int i = 1; i < n; i++) { 
            if(nums[i]==nums[i-1]+1)
            {
                prefix_sum+=nums[i];
            } 
            else break;
              }

        unordered_set<int> s(nums.begin(),nums.end());

        while(s.count(prefix_sum))
        {
            prefix_sum++;
        }
        
        return prefix_sum;
    }
};