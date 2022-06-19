class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        
        sort(products.begin(),products.end());
        auto it=products.begin();
        string str="";
        for(auto s:searchWord){
            str+=s;
            vector<string> v1;
            it=lower_bound(products.begin(),products.end(),str);
            for(int i=0;i<3 and it+i!=products.end();i++){
                string s1=*(it+i);
                if(s1.find(str))
                    break;
                v1.push_back(s1);
            }
            res.push_back(v1);
        }
        return res;
    }
};