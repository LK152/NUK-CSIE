import java.util.Scanner;

class Student {
    private String Name;
    private int ID;

    public Student(String N, int id) {
        Name = N;
        ID = id;
    }

    public void printStu() {
        System.out.printf("%s %d\n", Name, ID);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int n = scnr.nextInt();
        int id, o;
        Student q[] = new Student[n];
        for (int i = 0;i<n;i++) {
            String stuName = scnr.next();
            id = scnr.nextInt();
            Student Stu = new Student(stuName, id);
            q[i] = Stu;
        }
        while (scnr.hasNext()) {
            String cmd = scnr.next();
            int cnt = 0;
            for (int i = 0;i<n;i++) {
                if (q[i] == null) cnt++;
            }
            if (cnt == n) return;

            switch (cmd) {
                case "P":
                    for (int i = 0;i<n;i++) {
                        if (q[i] != null) q[i].printStu();
                    }
                    break;

                case "T":
                    o = 0;
                    while (q[o] == null) o++;
                    q[o].printStu();
                    break;
                
                case "R":
                    o = 0;
                    while (q[o] == null) o++;
                    q[o] = null;
                    break;
            }
        }

        scnr.close();
    }
}