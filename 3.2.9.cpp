#include <iostream>
#include <bitset>

using namespace std;

unsigned long convert(string bin){
	return bitset<32>(bin).to_ulong();
}

int main(){
  cout << "enter a binary" << endl;
  string bin;
  
  cin >> bin;
  
  cout << convert(bin) << endl;
}
