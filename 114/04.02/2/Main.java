class Pizza {
    private String size;
    private int cheese;
    private int pepperoni;
    private int ham;

    public Pizza(String size, int cheese, int pepperoni, int ham) {
        set_pizza_size(size);
        set_cheese_num(cheese);
        set_pepperoni_num(pepperoni);
        set_ham_num(ham);
    }

    public String get_pizza_size() {
        return size;
    }

    public int get_cheese_num() {
        return cheese;
    }

    public int get_pepperoni_num() {
        return pepperoni;
    }

    public int get_ham_num() {
        return ham;
    }

    public void set_pizza_size(String s) {
        size = s;
    }

    public void set_cheese_num(int n) {
        cheese = n;
    }

    public void set_pepperoni_num(int n) {
        pepperoni = n;
    }

    public void set_ham_num(int n) {
        ham = n;
    }

    public double pizza_cost() {
        double cost = (cheese + pepperoni + ham) * 2;
        ;

        switch (size) {
            case "small":
                cost += 10;
                break;
            case "medium":
                cost += 12;
                break;
            case "large":
                cost += 14;
                break;
        }

        return cost;
    }

    public String get_description() {
        String descript = "pizza\n"
                + "size:" + size
                + "\ncheese:" + cheese
                + "\npepperoni:" + pepperoni
                + "\nham:" + ham
                + "\ncost:$" + pizza_cost() + "\n";

        return descript;
    }
}

public class Main {
    public static void main(String[] args) {
        Pizza pizza = new Pizza("medium", 1, 4, 5);
        System.out.println(pizza.get_description());
    }
}
