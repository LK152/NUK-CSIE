import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int N = scnr.nextInt();
        for (int i = 0;i<N;i++) {
            int sides[] = new int[3];
            boolean flag = false;
            for (int j = 0;j<3;j++) {
                sides[j] = scnr.nextInt();
            }
            if (sides[0] == sides[1] && sides[0] == sides[2]) System.out.println("Yes");
            else {
                for (int j = 0;j<3;j++) {
                    if (sides[j] + sides[j+1 >= 3 ? j-2 : j+1] <= sides[j+2 >= 3 ? j-1 : j+2]) flag = true;
                }
                System.out.println(flag ? "No" : "Yes");
            }
        }
        
        scnr.close();
    }
}