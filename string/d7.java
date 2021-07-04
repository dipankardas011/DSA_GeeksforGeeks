/*URLify a given string (Replace spaces is %20)
Write a method to replace all the spaces in a string with ‘%20’. You may assume that the string has sufficient space at the end to hold the additional characters and that you are given the “true” length of the string.
Examples: 

Input: "Mr John Smith", 13
Output: Mr%20John%20Smith

Input: "Mr John Smith   ", 13
Output: Mr%20John%20Smith*/
package string;
class d7{
    public static void main(String[] args) {
        String str="Mr John Smith   ";
        str=str.trim();
        str=str.replace(" ", "%20");
        System.out.println(str);
    }
}