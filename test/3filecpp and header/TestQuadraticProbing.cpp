#include <iostream>
#include "QuadraticProbing.h"
using namespace std;


int main( )
{
    HashTable<string> a;
    string name = "CHISANUPONG";
    cout << "name is = " << name<<endl;
    cout<<"hashTable = " <<  a.inserttext(name, 7) << endl;

    return 0;
}
