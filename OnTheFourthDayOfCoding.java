/*
*   Problem: On The Fourth Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53345
* */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class OnTheFourthDayOfCoding {
    private static final String fileName = "hyperskill-dataset-119026486.txt";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(fileName));

        Map<String, Boolean> state = new HashMap<>();
        for (int i = 0; i < 4; i++) {
            state.put(String.format("Fork_%d", i + 1), false);
        }

        int contentions = 0;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.isEmpty())
                continue;

            String[] log = line.split(",");
            String action = log[1];
            int fork = Integer.parseInt(log[2]);
            String forkId = String.format("Fork_%d", fork);

            if (action.equals("pick")
                && state.get(forkId))
                contentions++;
            else
                state.put(forkId, !state.get(forkId));
        }
        sc.close();

        System.out.println(contentions);
    }
}
