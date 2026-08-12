class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int l=0;
        int max_len=0;

        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        

        while(freq[nums[i]]>k)
        {
            freq[nums[l]]--;
            l++;
        }

        max_len = max(max_len,i-l+1);
        }

        return max_len;
        
    }
};