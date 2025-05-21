import java.util.Scanner;

class Caaa {
    public int num1;
    public int num2;
}

class Cbbb extends Caaa {
    public void set_num(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

    public void show() {
        System.out.println("num1=" + num1 + ", " + "num2=" + num2);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        Cbbb bb = new Cbbb();
        int n1 = scnr.nextInt(), n2 = scnr.nextInt();
        bb.set_num(n1, n2);
        bb.show();
        
        scnr.close();
    }
}