#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
void print(vector<int>p) {
    for(int&n:p) cout << n << " ";
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
    for(vector<int>p:paths) {
vector<int> x(paths[minID].begin()+s,paths[minID].begin()+s+l);
       vector<int>y={2,3};

        
        
        
        if(!includes(p.begin(),p.end(),paths[minID].begin()+s,paths[minID].begin()+s+l)) {
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
    vector<vector<int>> paths ={
        {0,1,2,3,4},
        {5,6,7},
        {8,9,100,3}
    };
int ans=    s.longestCommonSubpath(5,paths);
cout << ans;
vector<int> temp={100,3};
cout << includes(paths[2].begin(),paths[2].end(),temp.begin(),temp.end());
s.print(paths[2]);
s.print(temp);
}