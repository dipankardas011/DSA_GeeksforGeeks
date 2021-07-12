/* C++ Program for Bad Character Heuristic of Boyer Moore String Matching Algorithm */
#include <iostream>
#include <string>
#define NO_OF_CHARS 256

                                            // The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(std::string str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	                                        // Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	                                        // Fill the actual value of last occurrence of a character
	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;

}

                                            /* A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm */
void search( std::string txt, std::string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];
	                                        /* Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern */
	badCharHeuristic(pat, m, badchar);
    printf("~~ Debug ~~\n");
    for(int i=0;i<NO_OF_CHARS;i++)
        printf("\tindex %d : %d\n",i,badchar[i]);
    printf("~~ Debug ~~\n");
	int s = 0;                              // s is shift of the pattern with
				                            // respect to text
	while(s <= (n - m))
	{
		int j = m - 1;
		                                    /* Keep reducing index j of pattern while characters of pattern and text are matching at this shift s */
		while(j >= 0 && pat[j] == txt[s + j])
			j--;

		                                    /* If the pattern is present at current shift, then index j will become -1 after the above loop */
		if (j < 0)
		{
			std::cout << "pattern occurs at shift = " << s << std::endl;
			s += (s + m < n)? m-badchar[txt[s + m]] : 1;

                                            /* Shift the pattern so that the next character in text aligns with the last
                                            occurrence of it in pattern. The condition s+m < n is necessary for
                                            the case when pattern occurs at the end of text */

		}

		else
			s += std::max(1, j - badchar[txt[s + j]]);
			                                /* Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern. The max function is used to make sure that we get a positive shift. We may get a negative shift if the last occurrence of bad character in pattern is on the right side of the current character. */
	}
}

int main(int argc, char const *argv[])
{
	std::string txt= "ABAAABCD";
	std::string pat = "ABC";
	search(txt, pat);

    remove(argv[0]); 
    return 0;
}
