#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty()||s.empty()){
            return ans;
        }
        int wordlen=words[0].size();
        int n=s.size();
        int totalwords=words.size();
        if(n<wordlen*totalwords){
            return ans;
        }
        unordered_map<string,int> wordcnt;
        for(string i:words){
            wordcnt[i]++;
        }
        for(int offset=0;offset<wordlen;offset++){
            int l=offset;
            int cnt=0;
            unordered_map<string,int> windowcnt;
            for(int r=offset;r+wordlen<=n;r+=wordlen){
                string word=s.substr(r,wordlen);
                if(wordcnt.find(word)==wordcnt.end()){
                    windowcnt.clear();
                    cnt=0;
                    l=r+wordlen;
                    continue;
                }
                windowcnt[word]++;
                cnt++;
                while(windowcnt[word]>wordcnt[word]){
                    string leftword=s.substr(l,wordlen);
                    windowcnt[leftword]--;
                    cnt--;
                    l+=wordlen;
                }
                if(cnt==totalwords){
                    ans.push_back(l);
                    string leftword=s.substr(l,wordlen);
                    windowcnt[leftword]--;
                    cnt--;
                    l+=wordlen;
                }
            }
        }
return ans;
    }
};
int main(){
    Solution obj;
 string s;
 cin>>s;
 int n;
 cin>>n;
 vector<string> words(n);
 for(int i=0;i<n;i++){
    cin>>words[i];
 }
 vector<int> ans=obj.findSubstring(s,words);
 for(auto i:ans){
    cout<<i<<" ";
 }
 return 0;
}