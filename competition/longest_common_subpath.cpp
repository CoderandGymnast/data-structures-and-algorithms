#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
void print(vector<int>p) {
    for(int&n:p) cout << n << " ";
    cout << endl;
}
    bool isSubset(vector<int>m,vector<int>s) {
       int subSize=s.size();
        bool status;
        for(int i=0;i<=m.size()-subSize;++i) {
            if(m[i]==s[0]) {
                status=true;
                for(int j=1;j<subSize;++j) {
                    if(m[i+j]!=s[j]) {
                        status=false;
                        break;
                    }
                }
                if(status) return true;
            }
        }
        return false;
    }
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int minID=-1,minNumCities=INT_MAX,size;
        for(int i=0;i<paths.size();i++){
size=paths[i].size();
            
if(size<minNumCities){
    minNumCities=size;
minID=i;
}   
}
  int status ; 
for(int l=minNumCities;l>=1;--l)        {
for(int s=0;s<=minNumCities-l;s++) {
    status=true;
vector<int>sub(paths[minID].begin()+s,paths[minID].begin()+s+l);
    for(vector<int>p:paths) {
        if(!isSubset(p,sub)) {
            status=false;
       break; 
        }
    }
    if(status) {
        return l;
    }
}
}

return 0; 
    }
};

int main() {
    Solution s;
    vector<vector<int>> paths ={{0,1,2,3,4},{2,3,4},{4,0,1,2,3}};
int ans=    s.longestCommonSubpath(5,paths);
cout << ans;
}