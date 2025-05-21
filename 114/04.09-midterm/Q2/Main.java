import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int m, n;
        String c;
        m = scnr.nextInt();
        n = scnr.nextInt();
        int arr[][][] = new int[m][n][3];

        for (int i = 0;i<m;i++) {
            for (int j = 0;j<n;j++) {
                arr[i][j][0] = scnr.nextInt();
                arr[i][j][1] = scnr.nextInt();
                arr[i][j][2] = scnr.nextInt();
            }
        }
        for (int k = 0;k<=10;k++) {
            c = scnr.nextLine();
            for (int i = 0;i<m;i++) {
                for (int j = 0;j<n;j++) {
                    for (int u = 0;u<3;u++) {
                        if (arr[i][j][u] < 0) arr[i][j][u] = 0;
                        if (arr[i][j][u] > 255) arr[i][j][u] = 255;
                    }
                }
            }

            switch (c) {
                case "P":
                    for (int i = 0;i<m;i++) {
                        for (int j = 0;j<n;j++) {
                            System.out.printf("(%s,%s,%s,)", arr[i][j][0], arr[i][j][1], arr[i][j][2]);
                        }
                        System.out.println();
                    }
                    System.out.println("-");
                    break;
                
                case "R":
                    for (int i = 0;i<m;i++) {
                        for (int j = 0;j<n;j++) {
                            arr[i][j][0] += 30;
                        }
                    }
                    break;

                case "G":
                    for (int i = 0;i<m;i++) {
                        for (int j = 0;j<n;j++) {
                            arr[i][j][1] -= 30;
                        }
                    }
                    break;

                case "E":
                    scnr.close();
                    return;
            }
        }
        scnr.close();
    }
}