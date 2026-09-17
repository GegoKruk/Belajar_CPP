#include <iostream>
using namespace std;

//Program Typo 

int main () {
	
	string kalimat;
	char temp;
	int first = 0;
	
	cout << "Masukan 2 Kata: "; getline(cin, kalimat); 
	
	for (int i = 0; i < kalimat.length(); i++) {
		
		if (kalimat[i] == ' ') {
			temp = kalimat[first];
			kalimat[first] = kalimat[i+1];
			kalimat[i+1] = temp;
		}
	}
	
	cout << endl << kalimat;
}
