https://leetcode.com/problems/subsets/

vector<vector<int>> subsets(vector<int>& v) {
        int size = pow(2, v.size());
        vector<vector<int>> result(size);
        int next = 0;

        for (int i = 0; i < size; ++i)
        {
            int bits = i;
                      
            while (bits)
            {
                int bit = __builtin_ctz(bits);
                result[next].push_back(v[bit]);
                bits &= (bits - 1);
            }

            ++next;            
        }

        return result; 
        }
