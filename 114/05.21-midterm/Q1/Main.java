import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int n = scnr.nextInt();
        for (int i = 1;i<=n;i++) {
            int input[] = new int[3], max = 0, min = 0, mid = 0;
            for (int j = 0;j<3;j++) {
                input[j] = scnr.nextInt();
                if (input[j] > max) max = input[j];
                if (input[j] < min || j == 0) min = input[j];
            }
            for (int j = 0;j<3;j++) if (input[j] != max && input[j] != min) mid = j;

            System.out.println("Case " + i + ": " + input[mid]);
        }
        
        scnr.close();
    }
}