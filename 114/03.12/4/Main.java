import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String ac = "RGB";
        Scanner scnr = new Scanner(System.in);
        String input = scnr.nextLine();
        boolean flg = false, f = true;
        int idx = 1;
        for (int i = 0; i < 5; i++) {
            if (ac.contains(String.valueOf(input.charAt(i)))) {
                f = false;
                break;
            }
        }
        if (!f) {
            for (int i = 0; i < 4; i++) {
                if (input.charAt(idx) == input.charAt(i)) {
                    System.out.println("INVALID");
                    flg = true;
                    break;
                } else
                    idx++;
            }
        }

        if (f) {
            System.out.println("INVALID");
            flg = true;
        }

        if (!flg) {
            System.out.println("VALID:" + input);
        }

        scnr.close();
    }
}
