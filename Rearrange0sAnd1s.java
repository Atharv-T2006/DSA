class Solution{
    void segregate0and1(int[] arr) {
        // code here
        int i=0, j = arr.length-1;
        while(i<j){
            while(i<j&&arr[i]==0) i++;
            while(i<j&&arr[j]==1) j--;
            
            if(i<j){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
                
            }
        }
        
    }
}
