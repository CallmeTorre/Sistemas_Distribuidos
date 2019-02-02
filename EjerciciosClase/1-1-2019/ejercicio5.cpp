#include <iostream>
using namespace std;
int main()
{
const int ARRAY_LENGTH = 5;
int myNums[ARRAY_LENGTH] = {0};
int n=2;
cout << "Lista " << ARRAY_LENGTH << " enteros." << endl;
for (int counter = 0; counter < ARRAY_LENGTH; ++counter)
{
cout << "enteros " << counter << ": ";
cin >> myNums[counter];
n+(++n);
}
cout << "contenidos " << endl;
cout << n << endl;
for (int counter = 0; counter < ARRAY_LENGTH; ++counter)
cout << "elementos " << counter << " = " << myNums[counter] << endl;
return 0;
}