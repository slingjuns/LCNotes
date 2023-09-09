// Date: September 9, 2023
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>(); // stores index
        int[] res = new int[nums.length+1-k];
        for(int i = 0; i < nums.length; ++i) {
            while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();
            if(!dq.isEmpty() && dq.peekFirst() <= i-k) dq.pollFirst();
            dq.offerLast(i);
            if(i+1-k >= 0) res[i+1-k] = nums[dq.peekFirst()];
        }
        return res;
    }
}
