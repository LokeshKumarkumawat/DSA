//Aditya Verma

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod/s,char to_rod/D, char aux_rod/H)//Source,Destination,Helper
{
	if (n == 0)
	{
		return;
	}
	towerOfHanoi(n - 1, from_rod/s, aux_rod/H, to_rod/D);
	cout << "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod/D << endl;
	towerOfHanoi(n - 1, aux_rod/H, to_rod/D, from_rod);
}


int main()
{
	int n = 1; // Number of disks
	towerOfHanoi(n, 'A', 'C', 'B'); 
	return 0;
}

