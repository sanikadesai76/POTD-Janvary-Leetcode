/*
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
*/

//solution
class Solution {
public:
    bool isValid(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();

        vector<int> ans(m);
        vector<int> cumsum(n);
        int sum = 0;
        for(int i = 0 ; i < n ; i++ ){
            if(isValid(words[i][0]) && isValid(words[i].back())){
                sum++;
            }
            cumsum[i] = sum;
        }

        for(int i = 0; i < m ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            ans[i] = cumsum[r] - ((l>0)? cumsum[l-1]: 0);
        }
        return ans;
        
    }
};