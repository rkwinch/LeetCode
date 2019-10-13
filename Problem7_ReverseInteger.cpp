/*
   Given a 32-bit signed integer, reverse digits of an integer.

   Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */


// reverse integer, keeping track if the int is negative or not.  Also, if reversing
// the integer causes it to overflow in either direction, just return 0 per instructions
#include <string>
#include <limits>
#include <stdio.h>

int numOfDigits(int num);

int reverse(int num) {
  int num2 = 0;
  std::string str2 = "";
  std::string str = std::to_string(num);
  const int MAX_INT = std::numeric_limits<int>::max();
  const int MIN_INT = std::numeric_limits<int>::min();

  if (str[0] == '-')
  {
    str2 += '-';
    for (int i = str.size() - 1; i > 0; --i)
    {
      str2 += str[i];
    }

    // checking for overflowing with a negative 
    if (str2.size() == numOfDigits(MIN_INT) && num < 0)
    {
      std::string minInt = std::to_string(MIN_INT);
      for (int i = 1; i < minInt.size() - 1; ++i)
      {
        if (str2[i] < minInt[i])
        {
          break;
        }
        if (str2[i] > minInt[i])
        {
          return 0;
        }
      }
    }
  }
  else
  {
    for (int i = str.size() - 1; i >= 0; --i)
    {
      str2 += str[i];
    }
    // checking if overflowing with a positive
    if (str2.size() == numOfDigits(MAX_INT))
    {
      std::string maxInt = std::to_string(MAX_INT);
      for (int i = 0; i < maxInt.size(); ++i)
      {
        if (str2[i] < maxInt[i]) break;

        if (str2[i] > maxInt[i]) return 0;
      }
    }
  }

  num2 = stoi(str2);
  return num2;
}
int numOfDigits(int num)
{
  bool isNegative = false;
  int counter = 0;

  // if the number is 0, only has one digit
  if(num == 0) return 1;

  // if negative, chop a digit off in case it is int_min.  it will have at least 1 digit.
  // then make the number positive and chop off #s until reaching 0, keeping track of 
  // the number of digits chopped off
  if(num < 0)
  {
    num /= 10;
    counter++;
    num *= -1;
  }

  // keep track of digits chopped off. this still helps count a number originally negative
  // since the first chop was counted and it was then made positive.
  while(num > 0)
  {
    num /= 10;
    counter++;
  }

  return counter;
