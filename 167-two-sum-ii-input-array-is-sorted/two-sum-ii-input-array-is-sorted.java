class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l=0;
        int n= numbers.length;
        int r=n-1;
        int Total_sum=0;

        while(l<r)
        {
            Total_sum=numbers[l]+numbers[r];

            if(Total_sum == target)
            {
                return new int[] {l+1,r+1};
            }
            else if(Total_sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }

        }
        return new int[] {-1,-1};
    }
}