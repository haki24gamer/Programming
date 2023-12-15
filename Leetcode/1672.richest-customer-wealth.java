/*
 * @lc app=leetcode id=1672 lang=java
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
    public int maximumWealth(int[][] accounts) {
        int currentMaxWealth=0;
        int i=0;
        for (int[] wealthOfAcc : accounts) {
            wealthOfAcc[i]=0;
            i++;
        }
        return 0;
    }
    public static void main(String[] args) {
        int[][] array2D = {2,3,4},{5,6,7};
        for (int i = 0; i < array2D.length; i++) {
                System.out.print(i);
        }
    }
}

// @lc code=end

