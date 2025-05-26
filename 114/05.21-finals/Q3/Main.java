import java.util.Scanner;

class MyThread extends Thread {
    private int N;

    public MyThread(int n) {
        N = n;
    }

    public void run() {
        int sum = 0;
        while (N != 0) {
            sum += N--;
        }
        System.out.print(sum);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int n = scnr.nextInt();
        for (int i = 1;i<=n;i++) {
            int x = scnr.nextInt();
            int y = scnr.nextInt();
            int z = scnr.nextInt();

            MyThread Thread1 = new MyThread(x);
            MyThread Thread2 = new MyThread(y);
            MyThread Thread3 = new MyThread(z);

            try {
                System.out.println("Round " + i + ":");
                Thread1.start();
                Thread1.join();
                System.out.print(" ");
                Thread2.start();
                Thread2.join();
                System.out.print(" ");
                Thread3.start();
                Thread3.join();
                System.out.print("\n");
                if (i != n) System.out.println();

            } catch (Exception err) {
                System.out.println(err);
            }
        }
        
        scnr.close();
    }
}