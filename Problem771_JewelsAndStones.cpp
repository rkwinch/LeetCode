/*You're given strings J representing the types of stones 
that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  You want 
to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters 
in J and S are letters. Letters are case sensitive, so "a" 
is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0

Note: S and J will consist of letters and have length at most 50.
      The characters in J are distinct.*/

// Make a map of all possible jewels.  Go through stones.
// If stone is in map, it is also a jewel so keep track of that.
int numJewelsInStones(string J, string S) {
        
	int count = 0;
	std::map<char, int*> uniqueJewelMap;
	
	for (auto jewel : J)
	{
		uniqueJewelMap[jewel] = 0;
	}
	
	for (auto stone : S)
	{
		auto itr = uniqueJewelMap.find(stone);
		if (itr != uniqueJewelMap.end())
		{
			++count;
		}
	}
	
	return count;
    }
