import java.util.Scanner;

class FibManager {
    private int[] fib = new int[46];
    private int[][] fibSprial = new int[7][7];
    private int m = 0;
    public FibManager(int n, int M) {
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2;i<=n;i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        int cnt = 0;
        for (int i = 0;i<M;i++) {
            for (int j = 0;j<M;j++) {
                fibSprial[i][j] = fib[++cnt];
            }
        }
        m = M;
    }
    public void getFibAt(int n) {
        System.out.println(fib[n]);
    };
    public void printTDArray() {
        for (int i = 0;i<m;i++) {
            for (int j = 0;j<m;j++) {
                System.out.print(fibSprial[i][j]);
                if (j + 1 != m) System.out.print(" ");
            }
            System.out.println();
        }
    };
    public void getSpiralSum() {
        if (m%2 == 1) {
            for (int u = 0;u<=m/2;u++) {
                if (u != 0) System.out.print(" ");
                int n = 0;
                if (u == m/2) {
                    System.out.println(fibSprial[m/2][m/2]);
                } else {
                    for (int i = u;i<m-u;i++) {
                        n += fibSprial[i][u];
                        n += fibSprial[i][m-1-u];
                    }
                    for (int i = u+1;i<m-u-1;i++) {
                        n += fibSprial[u][i];
                        n += fibSprial[m-1-u][i];
                    }
                    System.out.print(n);
                }
            }
        } else {
            for (int u = 0;u<m/2;u++) {
                if (u != 0) System.out.print(" ");
                int n = 0;
                if (u+1 == m/2) {
                    for (int i = u;i<m-u;i++) {
                        n += fibSprial[i][u];
                        n += fibSprial[i][m-1-u];
                    }
                    System.out.println(n);
                } else {
                    for (int i = u;i<m-u;i++) {
                        n += fibSprial[i][u];
                        n += fibSprial[i][m-1-u];
                    }
                    for (int i = u+1;i<m-u-1;i++) {
                        n += fibSprial[u][i];
                        n += fibSprial[m-1-u][i];
                    }
                    System.out.print(n);
                }
            }
        }
    };
}

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int n, m, d;
        n = scnr.nextInt();
        m = scnr.nextInt();
        d = scnr.nextInt();
        FibManager f = new FibManager(n, m);
        f.getFibAt(d);
        f.printTDArray();
        f.getSpiralSum();

        scnr.close();
    }
}