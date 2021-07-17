/*Strong Password Suggester Program
Difficulty Level : Medium
Last Updated : 05 Apr, 2021
Given a password entered by the user, check its strength and suggest some password if it is not strong.
Criteria for strong password is as follows : 
A password is strong if it has : 
1. At least 8 characters 
2. At least one special char 
3. At least one number 
4. At least one upper and one lower case char. 
Examples : 
 

Input : keshav123
Output : Suggested Password
k(eshav12G3
keshav1@A23
kesh!Aav123
ke(shav12V3
keGshav1$23
kesXhav@123
keAshav12$3
kesKhav@123
kes$hav12N3
$kesRhav123

Input :rakesh@1995kumar
Output : Your Password is Strong */
#include <iostream>
#include <string>
 
// adding more characters to suggest strong password
std::string add_more_char(std::string str, int need)
{
    int pos = 0;
 
    // all 26 letters
    std::string low_case = "abcdefghijklmnopqrstuvwxyz";
 
    for (int i = 0; i < need; i++) {
        pos = rand() % str.length();
        str.insert(pos, 1, low_case[rand() % 26]);
    }
    return str;
}
 
// make powerfull std::string
std::string suggester(int l, int u, int d, int s, std::string str)
{
 
    // all digits
    std::string num = "0123456789";
 
    // all lower case, uppercase and special characters
    std::string low_case = "abcdefghijklmnopqrstuvwxyz";
    std::string up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string spl_char = "@#$_()!";
 
    // position at which place a character
    int pos = 0;
 
    // if there is no lowercase char in input std::string, add it
    if (l == 0) {
        // generate random integer under std::string length
        pos = rand() % str.length();
 
        // generate random integer under 26 for indexing of a to z
        str.insert(pos, 1, low_case[rand() % 26]);
    }
 
    // if there is no upper case char in input std::string, add it
    if (u == 0) {
        pos = rand() % str.length();
        str.insert(pos, 1, up_case[rand() % 26]);
    }
 
    // if there is no digit in input std::string, add it
    if (d == 0) {
        pos = rand() % str.length();
        str.insert(pos, 1, num[rand() % 10]);
    }
 
    // if there is no special character in input std::string, add it
    if (s == 0) {
        pos = rand() % str.length();
        str.insert(pos, 1, spl_char[rand() % 7]);
    }
 
    return str;
}
 
/* make_password function :This function is used to check
strongness and if input std::string is not strong, it will suggest*/
void generate_password(int n, std::string p)
{
    // flag for lower case, upper case, special
    // characters and need of more characters
    int l = 0, u = 0, d = 0, s = 0, need = 0;
 
    // password suggestions.
    std::string suggest;
 
    for (int i = 0; i < n; i++) {
        // password suggestions.
        if (p[i] >= 97 && p[i] <= 122)
            l = 1;
        else if (p[i] >= 65 && p[i] <= 90)
            u = 1;
        else if (p[i] >= 48 && p[i] <= 57)
            d = 1;
        else
            s = 1;
    }
 
    // Check if input std::string is strong that
    // means all flag are active.
    if ((l + u + d + s) == 4) {
        std::cout << "Your Password is 💪" << std::endl;
        return;
    }
    else
        std::cout << "Suggested password" << std::endl;
 
    /*suggest 10 strong std::strings */
    for (int i = 0; i < 10; i++) {
        suggest = suggester(l, u, d, s, p);
        need = 8 - suggest.length();
        if (need > 0)
            suggest = add_more_char(suggest, need);
        std::cout << suggest << std::endl;
    }
}

int main(int argc, char const *argv[]) {
  
    std::string inputstring ;
    std::cout<<"enter the pasword for 🧾evaluate.. ";
    std::cin>>inputstring;
    srand(time(NULL));
 
    // srand function set Seed for rand().
    generate_password(inputstring.length(), inputstring);
    remove(argv[0]);
    return 0;
}