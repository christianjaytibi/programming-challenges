/*
*   Problem: The White Noise
*   Problem Link: https://hyperskill.org/learn/daily/53136
* */

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class WhiteNoise {
    public static void main(String[] args) throws IOException {
        String filePath = "hyperskill-dataset-117284932.txt";
        Scanner sc = new Scanner(new File(filePath)).useDelimiter(",|\\s+");

        int state = 0;
        while (sc.hasNextInt()) {
            int movement = sc.nextInt();
            state = Math.floorMod(state + movement, 360);
        }

        System.out.println(state);
    }
}
