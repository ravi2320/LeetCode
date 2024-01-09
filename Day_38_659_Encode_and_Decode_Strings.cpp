/*
659 · Encode and Decode Strings
Algorithms
Medium
Accepted Rate
65%

Description
Solution53
Notes
Discuss99+
Leaderboard
Record

Description
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode

Only $39.9 for the "Twitter Comment System Project Practice" within a limited time of 7 days!

WeChat Notes Twitter for more information（WeChat ID jiuzhangfeifei）


Example
Example1

Input: ["lint","code","love","you"]
Output: ["lint","code","love","you"]
Explanation:
One possible encode method is: "lint:;code:;love:;you"
Example2

Input: ["we", "say", ":", "yes"]
Output: ["we", "say", ":", "yes"]
Explanation:
One possible encode method is: "we:;say:;:::;yes"
Tags
Company
Google
*/

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  /*
   * @param strs: a list of strings
   * @return: encodes a list of strings to a single string.
   */
  string encode (vector < string > &strs)
  {
    // write your code here
    string encodeString = "";
    for (string str:strs)
      {
	encodeString += to_string (str.length ()) + "#" + str;
      }
    return encodeString;
  }

  /*
   * @param str: A string
   * @return: decodes a single string to a list of strings
   */
      vector<string> decode(string &str) {
        int length = str.length(), i = 2, prevIndex = 2;
        vector<string> decodeString;
        
        // Adjusted the loop condition
        while (i <= length) {
            if (str[i] == '#') {
                // Adjusted the substring extraction
                decodeString.push_back(str.substr(prevIndex, i - prevIndex - 1));
                prevIndex = i + 1;
            }
            i++;
        }
        decodeString.push_back(str.substr(prevIndex, i - prevIndex));
        return decodeString;
    }
};

int
main ()
{
  Solution s;
  vector < string > encodeString = { "lint", "code", "love", "you" };
for (string str:encodeString)
    cout << str << endl;
  string encodeStr = s.encode (encodeString);
  cout << encodeStr << endl;
  vector < string > decodeString = s.decode (encodeStr);
for (string str:decodeString)
    cout << str << endl;
  return 0;
}
