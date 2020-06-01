#include <iostream>
#include <bitset>

using namespace std;

unsigned long convert(string bin){
	return bitset<32>(bin).to_ulong();
}

int main(){
  cout << "enter a binary" << endl;
  int bin;
  
  cin >> n;
  
  cout << convert(bin) << endl;
}
