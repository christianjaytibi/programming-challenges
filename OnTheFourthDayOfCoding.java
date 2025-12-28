/*
*   Problem: On The Fourth Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53345
* */

package twelvedaysofcoding;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class OnTheFourthDayOfCoding {
    private static final String fileName = "out/production/LearnJava/twelvedaysofcoding/hyperskill-dataset-119026486.txt";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(fileName));

        boolean[] state = new boolean[4];

        int contentions = 0;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.isEmpty())
                continue;

            String[] log = line.split(",");
            String action = log[1];
            int fork = Integer.parseInt(log[2]) - 1;

            if (action.equals("pick")
                && state[fork])
                contentions++;
            else
                state[fork] = !state[fork];
        }
        sc.close();

        System.out.println(contentions);
    }
}
