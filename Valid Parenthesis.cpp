class Solution {
public:
    bool checkValidString(string s) {
        int left_count = 0 , right_count = 0;
        int string_len = s.length();

        /*
        we perform two traversal
        1.left to right
        2.right to left 
        ------------------------------------------
        we check if we are able to balance right paranthesis when traversing left to right
        and vice verse for second traversal
        check non-zero condition inside the loop only
        */
        for(int i = 0 ; i < string_len ; i++)
        {
            if(s[i] == '(' || s[i] == '*')
            {
                left_count++;
            }
            else
            {
                left_count--;
            }
            if(left_count < 0)
            return false;
        }
        
        

        for(int i = string_len-1 ; i >= 0 ; i--)
        {
            if(s[i] == ')' || s[i] == '*')
            {
                right_count++;
            }
            else
            {
                right_count--;
            }
            if(right_count < 0)
            return false;
        }
      
        return true;

    }
};
