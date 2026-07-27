class Solution {
    public int maxProduct(int[] nums) {

    int maxsum =0;
    int currsum =0;
        for(int i=0;i<nums.length-1;i++){
            for(int j=i+1;j<nums.length;j++){

            currsum= (nums[i]-1)*(nums[j]-1);
            maxsum = Math.max(currsum,maxsum);
            }
        }
        return maxsum;
    }
}