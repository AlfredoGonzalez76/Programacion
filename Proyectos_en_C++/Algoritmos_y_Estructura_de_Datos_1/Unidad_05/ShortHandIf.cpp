#include <iostream>
#include <string>
using namespace std;

int main() {
  int time = 19;
  double a = 10;
  string result = (time < 12) ? "Buen dia" : "Buenas tardes";
  cout << endl;
  cout << result;
  cout << a/time << endl;
  return 0;
}