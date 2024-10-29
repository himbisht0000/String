class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> A(boxes.size()), B(boxes.size());
        fill(A.begin(), A.end(),0);
        fill(B.begin(), B.end(),0);
        
        int ones = 0;
        
        if(boxes[0]=='1')
        ones++;
        
        //traverse from right to left
        for(int i = 1; i < boxes.size() ;i++)
        {
            A[i] = A[i-1] + ones;
            if(boxes[i] == '1')
            ones++;

        }

        ones = 0;
        if(boxes[boxes.size() - 1]=='1')
        ones++;
        //traverse from left to right 
        for(int i = boxes.size() - 2; i >=0 ;i--)
        {
            B[i] = B[i+1] + ones;
            if(boxes[i] == '1')
            ones++;
        }
        
        // now add A AND B

        for(int i = 0; i < A.size(); i++)
        {
            A[i] += B[i];
        }

        return A;

    }
};
