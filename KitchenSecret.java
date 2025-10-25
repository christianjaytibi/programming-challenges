/*
*   Problem: The Kitchen Secret
*   Problem Link: https://hyperskill.org/learn/daily/53138
* */

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class KitchenSecret {
    static final String filePath = "hyperskill-dataset-117344221.txt";
    static final char[][] keypad = new char[][] {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P'}
    };

    public static void main(String[] args) throws IOException {
        Path path  = Path.of(filePath);
        BufferedReader reader = Files.newBufferedReader(path);
        
        reader
            .lines()
            .map(str -> {
                String[] instructions = str.split(",");
                return solve(instructions);
            })
            .forEach(System.out::print);

        reader.close();
    }

    private static char solve(String[] instructions) {
        int row = 0;
        int col = 0;
        int lowerBound = 0;
        int upperBound = keypad.length - 1;

        for (String instruction : instructions) {
            if (instruction.equals("UP") && row == lowerBound)
                continue;
            else if (instruction.equals("DOWN") && row == upperBound)
                continue;
            else if (instruction.equals("LEFT") && col == lowerBound)
                continue;
            else if (instruction.equals("RIGHT") && col == upperBound)
                continue;

            switch (instruction) {
                case "UP" -> row--;
                case "DOWN" -> row++;
                case "LEFT" -> col--;
                case "RIGHT" -> col++;
            }
        }

        return keypad[row][col];
    }
}

