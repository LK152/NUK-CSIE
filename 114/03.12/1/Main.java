import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int input_1,input_2;    
        input_1=scanner.nextInt();        
        input_2=scanner.nextInt();      
        int ans = input_1 + input_2;  
        while (scanner.hasNext()) {                    
            int input_now;        
            input_now=scanner.nextInt();            
            if (input_now != ans) {
                System.out.println("WRONG!");
                continue;
            } else {
                System.out.println("RIGHT!");
                break;
            }
        }
        scanner.close();
    }
} 