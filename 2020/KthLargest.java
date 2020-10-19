//https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Priority Queue

/**
 * Runtime: 586 ms, faster than 5.51% of Java online submissions for Kth Largest Element in a Stream.
 * Memory Usage: 42.6 MB, less than 16.32% of Java online submissions for Kth Largest Element in a Stream.
 */

class KthLargest {

    int[] arr;
    int[] posArr;
    int size = 0;
    final int k;
    int kth;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        arr = new int[k];
        posArr = new int[k];
        for (int i=0;i<nums.length;i++) {
            add(nums[i]);
        }
    }

    public int add(int val) {

        int position = size+1;

        kth = val; // kth position
        int toBeRemoved = -1;

        for (int i=0;i<size;i++) {
            if (arr[i] < val) {
                if (posArr[i] < position) {
                    position = posArr[i];
                }
                posArr[i]++;
            }

            if (posArr[i] == k) { // kth largest number, not current one.
                kth = arr[i];
            }
            if (posArr[i] == k+1) { // This will be replaced.
                toBeRemoved = i;
            }
            if (position == k) {
                kth = val;
            }
        }

        if (position <= k) {
            if (size < k) {
                arr[size] = val;
                posArr[size++] = position;
            } else {
                arr[toBeRemoved] = val;
                posArr[toBeRemoved] = position;
            }
        }

        // System.out.println("For val - " + val);
        // System.out.println(Arrays.toString(arr));
        // System.out.println(Arrays.toString(posArr));

        return kth;

    }

}


// Sorted Array
/**
 * Runtime: 89 ms, faster than 11.36% of Java online submissions for Kth Largest Element in a Stream.
 * Memory Usage: 42.8 MB, less than 16.32% of Java online submissions for Kth Largest Element in a Stream.
 */

class KthLargest {

    int[] arr;
    int size = 0;
    final int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        arr = new int[k];
        for (int i=0;i<nums.length;i++) {
            add(nums[i]);
        }
    }

    public int add(int val) {
        if (size == 0) {
            arr[0] = val;
            size++;
        } else {
            if (size < k) { // set at end and swap to position
                int i = size-1;
                arr[size++] = val;
                while (i >= 0 && arr[i] > val) {
                    arr[i+1] = arr[i];
                    arr[i--] = val;
                }
            } else { // set at 0 and swap to position
                if (arr[0] < val) {
                    arr[0] = val;
                    int i = 1;
                    while (size > 1 && i < size && arr[i] < val) {
                        arr[i-1] = arr[i];
                        arr[i++] = val;
                    }
                }
            }
        }
        return arr[0];
    }

}


