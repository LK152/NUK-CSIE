import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        String ans = scnr.nextLine();

        while (true) {
            String input = scnr.nextLine();
            int a = 0, b = 0;
            int[] secretFreq = new int[10];
            int[] guessFreq = new int[10];
            for (int i = 0; i < 4; i++) {
                if (ans.charAt(i) == input.charAt(i))
                    a++;
                else {
                    secretFreq[ans.charAt(i) - '0']++;
                    guessFreq[input.charAt(i) - '0']++;
                }
            }

            for (int i = 0; i < 10; i++) {
                b += Math.min(secretFreq[i], guessFreq[i]);
            }

            System.out.println(a + "A " + b + "B");
            if (a == 4)
                break;
        }
        scnr.close();
    }
}
