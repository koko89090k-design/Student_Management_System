#include <bits/stdc++.h>

using namespace std;

int main() {
int x , y;

cin >> x >> y;
try
{
if(y == 0)
  throw exception();  
  else
  cout << x / y;
}

catch(exception e)
{
  cout << e.what() << '\n';
  cout <<"please review your input"<< '\n';
}
cout << "the program continued" << '\n';
cout << x + y + 100 << '\n';
  
  return 0;
}