/*
   You are given two non-empty linked lists representing 
   two non-negative integers. The digits are stored in 
   reverse order and each of their nodes contain a 
   single digit. Add the two numbers and return it as a linked list.

   You may assume the two numbers do not contain any 
   leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


std::string addStrings(std::string str1, std::string str2)
{
  int nLocalSum = 0;
  std::string strLocalSum = "";
  std::string sum = "";
  std::string carry = "0";
  int counter = 0;

  // make the strings the same length with prepended 0s
  while (str1.length() > str2.length())
  {
    str2 = "0" + str2;
  }

  while (str1.length() < str2.length())
  {
    str1 = "0" + str1;
  }

  while (counter < str1.length())
  { // add from the back to the front, keeping in mind the carry
    nLocalSum = str1[str1.length() - 1 - counter] - '0' + str2[str2.length() - 1 - counter] - '0'  + stoi(carry);
    strLocalSum = std::to_string(nLocalSum);

    if (nLocalSum > 9)
    {
      carry = "1";
      strLocalSum = std::to_string(nLocalSum % 10);
    }
    else
    {
      carry = "0";
      strLocalSum = std::to_string(nLocalSum);
    }

    sum = strLocalSum + sum; // keep adding new values to the left
    std::cout << "strLocalSum:  " << strLocalSum << "  sum:  " << sum << "  carry:  " << carry << std::endl;
    strLocalSum = ""; // clearing localSum
    ++counter;
  }
  // add last carry (if present) to the front
  if (carry == "1")
  {
    sum = carry + sum;
  }

  std::cout << "sum = " << sum << std::endl;
  return sum;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  std::string str1 = "";
  std::string str2 = "";
  int num1 = 0;
  int num2 = 0;
  ListNode* l5 = l1;
  bool zero = true;
  ListNode* l3 = new ListNode(0);

  str1 = std::to_string(l1->val) + str1; // get first value of l1
  // making string of ListNode* l1
  while (l5->next != NULL)
  {
    str1 = std::to_string(l5->next->val) + str1; 
    l5 = l5->next;
  }

  l5 = l2;
  str2 = std::to_string(l2->val) + str2; // get first value of l2
  // making string of ListNode* l2
  while (l5->next != NULL)
  {
    str2 = std::to_string(l5->next->val) + str2;
    l5 = l5->next;
  }

  str1 = addStrings(str1, str2); // add the strings character by character as ints
                                 // keeping in mind that they are reversed

  // checking if the sum was zero.  If so, just return it (l3 is 0)
  for (int i = 0; i < str1.length(); ++i)
  {
    if (str1[i] != '0')
    {
      zero = false;
      break;
    }
  }

  if (zero) return l3; 
  else l3->val = str1[str1.length() - 1] - '0'; // getting int value of sum in reverse of reverse order

  ListNode* l6 = l3; // make another listnode and point it to current one

  while (num1 < str1.length() - 1) // num1 starts at 0.  So just go through all values.
    // don't to to end since do -2 below since already have one value
  { // already have first value, so that's why it's -2
    ListNode* l4 = new ListNode(str1[str1.length() - num1 - 2] - '0'); 
    l6->next = l4; // set next one to the one you just made
    l6 = l6->next; // continue to next
    ++num1;
  }

  return l3;  
}
