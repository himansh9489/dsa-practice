#include <bits/stdc++.h>
using namespace std;

void generatePermutationsHelper(int index, int N, string &current, vector<string> &result) {
   string s1 = "11";
   if (index == N) {
      if (current.find("11") == string::npos)
         result.push_back(current); // Add the current permutation to the result
      return;
   }

   // Generate permutations by setting the current character to '0' or '1'
   current[index] = '0';
   generatePermutationsHelper(index + 1, N, current, result);

   current[index] = '1';
   generatePermutationsHelper(index + 1, N, current, result);
}

vector<string> generatePermutations(int N) {
   vector<string> result;
   string current(N, '0'); // Initialize a string of length N with all '0' characters
   generatePermutationsHelper(0, N, current, result);
   return result;

   unordered_map<int, string> mp;
}

int main() {
   int N = 3; // Example value of N
   vector<string> permutations = generatePermutations(N);

   // Print all permutations
   for (const auto &perm : permutations) {
      // if (perm.find("11") == string::npos)
      cout << perm << endl;
   }
   return 0;
}