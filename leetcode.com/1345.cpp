#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dist[50001];
    unordered_map<int, vector<int>> mp;
    int minJumps(vector<int>& arr) {
      for(int i = 0;i < arr.size();++i){
	if(mp.find(arr[i]) == mp.end())
	  mp[arr[i]] = vector<int>();
	mp[arr[i]].push_back(i);
	dist[i] = -1;
      }
      dist[0] = 0;
      deque<int> bfs;
      bfs.push_back(0);

      while(!bfs.empty()){
	int cur = bfs.front();
	bfs.pop_front();
	if(cur == arr.size() - 1)
	  return dist[cur];

	int d = dist[cur] + 1;
	vector<int> &v = mp[arr[cur]];
	v.push_back(cur - 1);
	v.push_back(cur + 1);
	for(auto i: mp[arr[cur]]){
	  if(i >= 0 && i < arr.size() && dist[i] < 0){
	    dist[i] = d;     
	    bfs.push_back(i);              
	  }
	}
	v.clear();
      }
      return dist[arr.size() - 1];
    }
};

void solve() {
  Solution s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
