
class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i = 0;
        vector<vector<string>> output;
        vector<pair<string,int>> data;

        for(int i = 0; i < strs.size() ; i++)
        {
            data.push_back(make_pair(strs[i] , i));
        }

        for(int i = 0; i < strs.size() ; i++)
        {
            sort( data[i].first.begin() , data[i].first.end() );
        }
        
        sort(data.begin() , data.end());

        for(int i = 0 ; i < data.size() ; i++)
        {
            cout<<data[i].first<<" ";
        }
        int left = 0 , right = 0;

        vector<string> temp;
        while(right < strs.size())
        {
            if(data[left].first == data[right].first)
            {
                temp.push_back(strs[data[right].second]);
                right++;
            }
            else
            {
                left = right;
                output.push_back(temp);
                temp.clear();
            }
        }

        if(temp.size() != 0)
        {
            output.push_back(temp);
        }


        return output;
    }
};
