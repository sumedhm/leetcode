//https://leetcode.com/problems/lemonade-change/

/**
 * Runtime: 1 ms, faster than 100% of Java online submissions for Lemonade Change.
 * Memory Usage: 40.1 MB, less than 5.04% of Java online submissions for Lemonade Change.
 */


class Lemonade {
    public boolean lemonadeChange(int[] bills) {
        int dollar5 = 0;
        int dollar10 = 0;

        for (int i = 0; i < bills.length; i++) {
            if (bills[i] == 5) {
                dollar5++;
            } else if (bills[i] == 10) {
                dollar10++;
                if (dollar5 > 0) {
                    dollar5--;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (dollar10 > 0 && dollar5 > 0) {
                    dollar10--; dollar5--;
                } else if (dollar5 >= 3) {
                    dollar5 -= 3;
                } else {
                    return false;
                }



            } else {
                System.exit(1);
            }
        }

        return true;

    }
}