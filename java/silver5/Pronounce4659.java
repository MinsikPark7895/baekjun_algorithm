package silver5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Pronounce4659 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = br.readLine();
            if (s.equals("end")) {
                break;
            }

            char[] arr = s.toCharArray();

            boolean containsVowels = false; 
            boolean threeTimesInARow = false; 
            int vowelsInARowCount = 0; 
            int consonantsInARowCount = 0; 
            boolean doubleInARowCheck = false;

            for (int i = 0; i < arr.length; i++) {
                if (vowelCheck(arr[i])) { 
                    containsVowels = true;
                    vowelsInARowCount++;
                    consonantsInARowCount = 0;
                } else { 
                    consonantsInARowCount++;
                    vowelsInARowCount = 0;
                }
                if (vowelsInARowCount >= 3 || consonantsInARowCount >= 3) {
                    threeTimesInARow = true;
                    break;
                }

                
                if (i >= 1) {
                    if (arr[i - 1] == arr[i]) {
                        if (arr[i] == 'e') {
                            continue;
                        } else if (arr[i] == 'o') {
                            continue;
                        }
                        doubleInARowCheck = true;
                        break;
                    }
                }
            }

            StringBuilder sb = new StringBuilder();
            sb.append("<");
            for (int j = 0; j < arr.length; j++) {
                sb.append(arr[j]);
            }
            sb.append("> is ");
            if (!containsVowels || threeTimesInARow || doubleInARowCheck) {
                sb.append("not ");
            }
            sb.append("acceptable.");

            System.out.println(sb);
        }
    }

    static boolean vowelCheck(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
}