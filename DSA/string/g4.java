/*Find all the patterns of “1(0+)1” in a given string | SET 2(Regular Expression Approach)
Difficulty Level : Easy
Last Updated : 30 May, 2018
In Set 1, we have discussed general approach for counting the patterns of the form 1(0+)1 where (0+) represents any non-empty consecutive sequence of 0’s.In this post, we will discuss regular expression approach to count the same.

Examples:

Input : 1101001
Output : 2

Input : 100001abc101
Output : 2*/
//Java program to count the patterns
// of the form 1(0+)1 using Regex

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG
{
	static int patternCount(String str)
	{
		// regular expression for the pattern
		String regex = "10+1";
		
		// compiling regex
		Pattern p = Pattern.compile(regex);
				
		// Matcher object
		Matcher m = p.matcher(str);
		
		// counter
		int counter = 0;
				
		// whenever match found
		// increment counter
		while(m.find())
		{
			// As last character of current match
			// is always one, starting match from that index
			m.region(m.end()-1, str.length());
			
			counter++;
		}
				
		return counter;
	}
	
	// Driver Method
	public static void main (String[] args)
	{
		String str = "1001ab010abc01001";
		System.out.println(patternCount(str));
	}
}
