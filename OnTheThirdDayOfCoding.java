/*
*   Problem: On The Third Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53344
* */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class OnTheThirdDayOfCoding {
    private static final String fileName = "hyperskill-dataset-119008234.txt";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(fileName));

        String bestPassword = "";
        double bestScore = 0;

        while (sc.hasNextLine()) {
            String password = sc.nextLine();
            if (password.isEmpty())
                continue;

            double score = calculateScore(password);
            if (score > bestScore) {
                bestScore = score;
                bestPassword = password;
            }
        }
        
        System.out.println(bestPassword);
        sc.close();
    }

    private static double calculateScore(String password) {
        double score = password.length();

        if (!password.matches(".*[a-z].*"))
            score *= 0.75;
        if (!password.matches(".*[A-Z].*"))
            score *= 0.75;
        if (!password.matches(".*[0-9].*"))
            score *= 0.75;
        if (!password.matches(".*[!@#$%^&*].*"))
            score *= 0.75;

        Map<Character, Integer> freq = new HashMap<>();
        for (char ch : password.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        Map.Entry<Character, Integer> mostRepeated = Collections.max(freq.entrySet(), Map.Entry.comparingByValue());
        if (mostRepeated.getValue() >= (int)Math.round((password.length() * 0.30)))
            score -= mostRepeated.getValue();

        return score;
    }
}
