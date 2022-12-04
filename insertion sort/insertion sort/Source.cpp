#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <iostream>

using namespace std;
void insertionsort(vector<int>& a) {

	for (int p = 1; p < a.size();p++) {
		int tmp = a[p];
		int j;
		int x = 0;
		cout << "after p=" << p << "  ";
		for (j = p;j > 0 && tmp < a[j - 1];j--,x++) 

			a[j] = a[j - 1];
			a[j] = tmp;
			


			for (int i = 0;i < a.size();i++) {
				cout << (a[i]) << " ";
			}
			cout << "  " <<  x<< "  ";
			cout << endl;

		}
	}

int main() {
	// 6306021411028
	// 63 06 02 14 11 02 8 = 63 6 2 14 11 8
	vector<int>mynum = { 63,6,2,14,11,8};
	cout << "original = ";
	for (int i = 0;i < mynum.size();i++) {
		cout << (mynum[i]) << " ";

	}
	cout << "P.moved";
	cout <<endl << endl;
	  insertionsort(mynum);
	
}
