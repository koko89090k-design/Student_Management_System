#include <bits/stdc++.h>
#include "student.h"


using namespace std;

int main() {
  
  priority_queue<int, vector<int>, greater<int> > pq;

 int n;
 cin >> n;

  long long h=0;

 for(int i = 0 ; i<n ; ++i){
  int x;
  cin >> x;
  pq.push(x);
  h += x;
  
  if(h<0){
    h -= pq.top();
    pq.pop();
  }

 }
 
 cout << pq.size();

  return 0;
}