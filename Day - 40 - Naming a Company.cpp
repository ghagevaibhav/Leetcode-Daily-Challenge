class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>>mp;

        for(auto& it:ideas){
            mp[it[0]].insert(it.substr(1));
        }

        long long ans = 0;

        for(auto& it1:mp){
            int c=0;
            for(auto& it2:mp){
                if(it1.first==it2.first)continue;
                long long int common=0;
                for(auto& x:it1.second){
                    if(it2.second.find(x)!=it2.second.end()){
                        common+=1;
                    }
                }

                c+=((it1.second.size()-common)*(it2.second.size()-common));
            }
            ans+=c;
        }

        return ans ;
    }
};



