import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        while (scnr.hasNextLine()) {
            long s, d, current = 0;
            s = scnr.nextLong();
            d = scnr.nextLong();
            while (current < d) {
                current += s;
                s++;
            }
            System.out.println(s-1);
        }
        
        scnr.close();
    }
}