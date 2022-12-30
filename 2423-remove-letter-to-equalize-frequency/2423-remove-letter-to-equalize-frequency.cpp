class Solution {
public:
   bool isEqual(string str, int i)
{
	str.erase(i,1);  //erasing i'th element 
	unordered_map<char, int> m; 
	
	//store frequency of character
	for (int i = 0; i < str.size(); i++)  m[str[i]]++;
	
	//if the occurence are different we return 0
	for (int i = 1; i < str.size(); i++)
		if (m[str[i]] != m[str[i-1]])  return 0;

	return 1;
}
bool equalFrequency(string word) {
	for (int i = 0; i < word.size(); i++)
		if (isEqual(word, i)) return true;		
	return false;
}
};