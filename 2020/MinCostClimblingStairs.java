// https://leetcode.com/problems/min-cost-climbing-stairs/

public class MinCostClimblingStairs {

    public static int minCostClimbingStairs(int[] cost) {
        int i1 = 0, i2 = 0, tmp;
        //int[] best = new int[10];
        //best[0] =  0;
        //best[1] =  0;
        int n = cost.length;
        for (int i = 2; i < n; i++) {
            //best[i] = Math.min(best[i-2] + cost[i-2], best[i-1] + cost[i-1]);
            tmp = i1;
            i1 = Math.min(i1 + cost[i-1], i2 + cost[i-2]);
            i2 = tmp;
            System.out.println("For i=" + i + " " + i1 + ", " + i2 + ", " + tmp);
            //System.out.println("For i=" + i + ", " + best[i]);
        }
        return Math.min(i1 + cost[n-1], i2 + cost[n-2]);
        //return Math.min(best[n-2] + cost[n-2], best[n-1] + cost[n-1]);
    }


    public static void main(String[] args) {
        final int[] cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        System.out.println(minCostClimbingStairs(cost));
    }

}
