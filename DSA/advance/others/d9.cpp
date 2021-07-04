/*How to design a tiny URL or URL shortener?
Difficulty Level : Medium
Last Updated : 19 Mar, 2020
How to design a system that takes big URLs like “https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and converts them into a short 6 character URL. It is given that URLs are stored in the database and every URL has an associated integer id.

One important thing to note is, the long URL should also be uniquely identifiable from the short URL. So we need a Bijective Function

We strongly recommend that you click here and practice it, before moving on to the solution.

One Simple Solution could be Hashing. Use a hash function to convert long string to short string. In hashing, that may be collisions (2 long URLs map to same short URL) and we need a unique short URL for every long URL so that we can access long URL back.

A Better Solution is to use the integer id stored in the database and convert the integer to a character string that is at most 6 characters long. This problem can basically seen as a base conversion problem where we have a 10 digit input number and we want to convert it into a 6 character long string.

Below is one important observation about possible characters in URL.



A URL character can be one of the following
1) A lower case alphabet [‘a’ to ‘z’], total 26 characters
2) An upper case alphabet [‘A’ to ‘Z’], total 26 characters
3) A digit [‘0’ to ‘9’], total 10 characters

There are total 26 + 26 + 10 = 62 possible characters.

So the task is to convert a decimal number to base 62 number.

To get the original long URL, we need to get URL id in the database. The id can be obtained using base 62 to decimal conversion.*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string idTOShortURL(long int n)
{
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string shorturl;

    while (n)
    {
        shorturl.push_back(map[n % 62]);
        n /= 62;
    }
    reverse(shorturl.begin(), shorturl.end());

    return shorturl;
}
/**
 * @return integer ID back
 * @param short url
*/
long int shortURLtoID(string shortURL)
{
    long int id = 0;
    // a simple base convertion logic
    for (int i = 0; i < shortURL.length(); i++)
    {
        if ('a' <= shortURL[i] && shortURL[i] <= 'z')
            id = id * 62 + shortURL[i] - 'a';
        if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
            id = id * 62 + shortURL[i] - 'A' + 26;
        if ('0' <= shortURL[i] && shortURL[i] <= '9')
            id = id * 62 + shortURL[i] - '0' + 52;
    }
    return id;
}

int main(void)
{
    int n=12345;
    string shorturl=idTOShortURL(n);
    cout<<"generated short url = "<<shorturl<<endl;
    cout<<"id from url = "<<shortURLtoID(shorturl)<<endl;
    return 0;
}