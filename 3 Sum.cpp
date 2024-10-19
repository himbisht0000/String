class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> vector_set;
        vector<vector<int>> output;
        vector<int> temp;
        int sum = 0;
        int array_size = nums.size();
        int left , right;
        /*sort nums to make binary search faster*/
        sort(nums.begin(), nums.end());

        /*Take one number and find other number using two pointer approach*/
        for(int i = 0 ; i < nums.size(); i++)
        {   
            temp.push_back(nums[i]);
            left = i + 1;
            right = array_size - 1;
            while(left < right)
            {
                sum = nums[i] + nums[left] + nums[right] ;
                if(sum == 0)
                {
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    vector_set.insert(temp);
                    temp.pop_back();
                    temp.pop_back();
                    left++;
                    right--;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            temp.pop_back();
            sum = 0;
        }

        for(auto it = vector_set.begin(); it!=vector_set.end();it++)
        {
            output.push_back(*it);
        }

        return output;
    }
};
