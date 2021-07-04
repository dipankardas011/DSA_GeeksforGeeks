package string;

/*Most frequent word in an array of strings
Difficulty Level : Hard
Last Updated : 15 Jun, 2021
Given an array of words find the most occurring word in it
Examples: 
 

Input : arr[] = {"geeks", "for", "geeks", "a", 
                "portal", "to", "learn", "can",
                "be", "computer", "science", 
                 "zoom", "yup", "fire", "in", 
                 "be", "data", "geeks"}
Output : Geeks 
"geeks" is the most frequent word as it 
occurs 3 times

using hash */
// Java implementation
import java.util.*;

class d3 {

    // Function returns word with highest frequency
    static String findWord(String[] arr) {

        // Create HashMap to store word and it's frequency
        HashMap<String, Integer> hs = new HashMap<String, Integer>();

        // Iterate through array of words
        for (int i = 0; i < arr.length; i++) {
            // If word already exist in HashMap then increase it's count by 1
            if (hs.containsKey(arr[i])) {
                hs.put(arr[i], hs.get(arr[i]) + 1);
            }
            // Otherwise add word to HashMap
            else {
                hs.put(arr[i], 1);
            }
        }

        // Create set to iterate over HashMap
        Set<Map.Entry<String, Integer>> set = hs.entrySet();
        String key = "";
        int value = 0;

        for (Map.Entry<String, Integer> me : set) {
            // Check for word having highest frequency
            if (me.getValue() > value) {
                value = me.getValue();
                key = me.getKey();
            }
        }

        // Return word having highest frequency
        return key;
    }

    // Driver code
    public static void main(String[] args) {
        String arr[] = { "geeks", "for", "geeks", "a", "portal", "to", "learn", "can", "be", "computer", "science",
                "zoom", "yup", "fire", "in", "be", "data", "geeks" };
        String sol = findWord(arr);

        // Print word having highest frequency
        System.out.println(sol);
    }
}
