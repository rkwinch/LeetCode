/*
   Given a string s, find the longest palindromic 
   substring in s. You may assume that the maximum 
   length of s is 1000.

   Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb
 */

// idea behind this algorithm is to go left to right in the string and try to fan out on either
// side to check if it's a palindrome.  If not, just continue going to the right and repeating.
// Special cases were handled if the middle of the palindrome was even, if the palindrome was 
// just one character long or two characters long
#include <string>
#include <iostream>

using namespace std;
string longestPalindrome(string s);

int main(int argc, char **argv) {
  std::cout << longestPalindrome(argv[1]) << std::endl;
}

string longestPalindrome(string s) {
  bool isPalin = true;
  int indexL = 0;
  int indexR = 0;
  int indexL2 = -1;
  int indexR2 = -1;
  std::string sub2 = "";
  std::string longestSub = "";
  std::string sub = "";
  bool isEvenMiddle = false;

  for (int i = 0; i < s.length(); ++i)
  { // start from index i and fan out on either side
    indexL = i - 1;
    indexR = i + 1;
    indexR2 = 0;
    indexL2 = 0;
    sub = "";

    // handles if first 2 values are the same and s is longer than 2 characters
    if ((indexL < 0) && (indexR < s.length()) && (s[i] == s[indexR]))
    {
      sub += s[i];
      sub += s[indexR];

      if (sub.length() > longestSub.length()) longestSub = sub; // update longest palindrome currently

      sub = ""; // reset 
      continue;
    }
    // don't have to worry about conflict with if statement above since it continues 
    // and won't be entered again (either happens 0 or 1 times)
    if (indexL < 0 || indexR > s.length() - 1) // handles if i is on either end of the string
    {
      sub += s[i];

      // since sub will only be one char long, this will only be the longest palindrome
      // in the case of a single character input
      if (sub.length() > longestSub.length()) longestSub = sub; // update longest palindrome

      sub = ""; // reset
      continue;
    }
    // given string was only length 2 and both characters were the same. can return here
    if ((s.length() == 2) && (s[0] == s[1]))
    {
      sub += s[0];
      sub += s[1];
      return sub;
    }

    // disallow non-palindromes, but allow case 
    // like "cbbd" where the first b starts the palindrome to go through
    if ((s[indexL] != s[indexR])  && (s[i] != s[indexR]))
    {
      continue;
    }

    // handles if center of palindrome is even
    if ((s[indexR] == s[i]) && (indexR + 1 < s.length()))
    {
      isEvenMiddle = true;
      indexR2 = indexR + 1;
      indexL2 = indexL;
    }

    if(isEvenMiddle)
    {
      while ((indexL2 >= 0) && (indexR2 <= s.length() - 1))
      {
        if (s[indexL2] != s[indexR2]) break;
        --indexL2;
        ++indexR2;
      }

      for (int j = indexL2 + 1; j <= indexR2 - 1; ++j)
      {
        sub2 += s[j];
      }

      isEvenMiddle = false;
    }

    while ((indexL >= 0) && (indexR <= s.length() - 1))
    {
      if (s[indexL] != s[indexR]) break; // going out further is not a palindrome

      --indexL;
      ++indexR;
    }
    // copy over substring
    for (int j = indexL + 1; j <= indexR - 1; ++j)
    {
      sub += s[j];
    }

    // handles if change from prev accepted palindrome but cannot fan out
    // and is a length of at least 2, such as "abb"
    if (indexL + 1 == indexR - 1) sub += s[i];

    if (sub.length() >= sub2.length())
    {
      if (sub.length() > longestSub.length()) longestSub = sub;
    }
    else
    {
      if (sub2.length() > longestSub.length()) longestSub = sub2;
    }

    sub = "";
    sub2 = "";
  }

  return longestSub;
}
