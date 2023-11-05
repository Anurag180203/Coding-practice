// class Node{
//     public:
//         bool isWord=false;
//         Node*children[26];
//         bool containsKey(char ch)
//         {
//             return children[ch-'a']!=NULL;
//         }
//         void putKey(char ch)
//         {
//             children[ch-'a'] = new Node();
//         }
//         Node* get(char ch)
//         {
//             return children[ch-'a'];
//         }
//         void setEnd(){
//             isWord=true;
//         }
//         bool isEnd(){
//             return isWord;
//         }
// };

// class Trie{
//     public:
//         Node*root;
//         Trie(){
//             root = new Node();
//         }
//         void insert(string s)
//         {
//             Node* x = root;
//             for(int i=0;i<s.size();i++)
//             {
//                 if(!(x->containsKey(s[i])))
//                 {
//                     x->putKey(s[i]);
//                 }
//                 x = x->get(s[i]);
//             }
//             x->setEnd();
//         }
//         vector<string> suggest(string s)
//         {
//             vector<string>ans;
//             Node *x = root;
//             for(auto i:s)
//             {
//                 if(!(x->containsKey(i)))
//                 return ans;
//                 x = x->get(i);
//             }
//             findWords(x,ans,s);
//             return ans;
//         }
//         void findWords(Node*x,vector<string>&ans,string temp){
//             if(ans.size()==3)
//                 return;
//             if(x->isEnd())
//                 ans.push_back(temp);
//             for(int i=0;i<26;i++) {
//                 if(x->containsKey(char('a'+i))) {
//                     findWords(x->get(char('a'+i)),ans,temp+char('a'+i));
//                 }
//             }
//         }
// };

// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         Trie x;
//         for(auto i:products)
//         x.insert(i);
//         vector<vector<string>>ans;
//         for(int i=1;i<=searchWord.size();i++)
//         {
//             ans.push_back(x.suggest(searchWord.substr(0,i)));
//         }
//         return ans;
//     }
// };
class Solution {
public:
//If the strings are sorted we can binary search to get the first word that has the same prefix, we can then just check the next 2 words to see if they have the same prefix or not.
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>res;
        string temp="";
        int low=0,high=0;
        for(int i=0;i<searchWord.length();i++){
            temp+=searchWord[i];
            low=lower_bound(products.begin()+high,products.end(),temp)-products.begin();
            res.push_back({});
            for(int j=low;(j<(low+3) && j<products.size()) && (!products[j].compare(0,temp.size(),temp));j++){
                res.back().push_back(products[j]);
            }
            high=low;
        }
        return res;
        
    }
};