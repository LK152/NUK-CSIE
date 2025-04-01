class Fraction {
    private int numerator, denominator;
    public void set_numerator(int n) {
        numerator = n;
    }

    public void set_denominator(int n) {
        denominator = n;
    }

    public void displays_fraction() {
        System.out.println(numerator + "/" + denominator);
    }

    public void displays_equals(Fraction fraction) {
        if (fraction.denominator * numerator == denominator * fraction.numerator) System.out.println("YES");
        else System.out.println("NO");
    }
}

public class Main {
    public static void main(String[] args) {
        // Scanner scn = new Scanner(System.in);
        // int a = scn.nextInt();
        // int b = scn.nextInt();
        // int c = scn.nextInt();
        // int d = scn.nextInt();
        // Fraction frac = new Fraction();
        // frac.set_numerator(a);
        // frac.set_denominator(b);
        // frac.displays_fraction();
        // Fraction f = new Fraction();
        // f.set_numerator(c);
        // f.set_denominator(d);
        // frac.displays_equals(f);

        // scn.close();
    }
}