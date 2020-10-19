// https://leetcode.com/problems/print-zero-even-odd/

class ZeroEvenOdd {
    private int n;
    private final int n2;
    private int a = 1;

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.n2 = n*2;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        synchronized(this) {
            while (a < n2) {
                if (a % 2 == 1) {
                    printNumber.accept(0);
                    a++;
                    notifyAll();
                } else {
                    wait();
                }
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        synchronized(this) {
            while (a <= n2) {
                if (a % 4 == 0) {
                    printNumber.accept(a/2);
                    a++;
                    notifyAll();
                } else {
                    wait();
                }
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        synchronized(this) {
            while (a <= n2) {
                if (a % 4 == 2) {
                    printNumber.accept(a/2);
                    a++;
                    notifyAll();
                } else {
                    wait();
                }
            }
        }
    }

}