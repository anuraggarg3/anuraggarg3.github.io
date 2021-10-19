//question link: https://leetcode.com/problems/height-checker/
//consider this question under hacktober tag

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int total_indices=0;
        vector<int> expected;
        
        for(int i=0; i<heights.size(); i++){
            expected.push_back(heights[i]);
        }
        sort(expected.begin(), expected.end());
        
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != expected[i]){
                total_indices++;
            }
        }
        return total_indices;
    }
};




/*
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.

*/
