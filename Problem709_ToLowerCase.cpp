/*
Implement function ToLowerCase() that has a 
string parameter str, and returns the same 
string in lowercase.

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"
 */

#include <string>

string toLowerCase(string str) {
  int count = 0;

  while (count < str.length())
  { // 90 is 'Z' and 65 is 'A' from ASCII table
    // so, if between 'Z' and 'A', then letter is cap.
    if ((str[count] < 91) && (str[count] > 64))
    { // 'a' is 97. 97 - 65 is 32.  So add offset 
      // to make capital characters become lower case chars
      str[count] = str[count] + 32;
    }
    ++count;
  }

  return str;
}
