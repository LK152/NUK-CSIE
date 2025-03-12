import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int max = 0, input;
        Scanner scnr = new Scanner(System.in);
        while (true) {
            input = scnr.nextInt();
            if (input == -1) {
                System.out.print("MAX:");
                System.out.println(max);
                break;
            }

            if (input > max) max = input;
        }
        scnr.close();
    }
}
