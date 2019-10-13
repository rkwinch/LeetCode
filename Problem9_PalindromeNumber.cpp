bool isPalindrome(int x) {
  std::string s = std::to_string(x);
  return std::equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
}
