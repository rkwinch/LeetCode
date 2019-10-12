/*
   Given an array of integers, return indices of the two 
   numbers such that they add up to a specific target.
   You may assume that each input would have exactly one 
   solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */


// runs in n^2, but fast enough for submission.  look at later
// basically, brute force the combinations.  pretty naive approach
vector<int> twoSum(vector<int>& nums, int target) {
  int index1 = 0;
  int index2 = index1 + 1;
  std::vector<int> vec;

  for (int i = 0; i < nums.size() - 1; ++i)
  {
    for (int j = 0 + index1; j < nums.size() - 1; ++j)
    {
      if ((nums[index1] + nums[index2]) == target)
      {
        vec.push_back(index1);
        vec.push_back(index2);
        return vec;
      }
      ++index2;
    }
    ++index1;
    index2 = index1 + 1; // reset index 2
  }
  return vec;
}
