#include <iostream>
using namespace std;

class hashtable {
public:
    int hash(const string& key, int tablesize) {
        int hashval = 0;
        for (int i = 0;i < key.length();i++)
            hashval += key[i];
        return hashval % tablesize;
    }

};
int main()
{
    hashtable a;
   
    cout<<a.hash("AA", 7);
 
    return 0;
}
