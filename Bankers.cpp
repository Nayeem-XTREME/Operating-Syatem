#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, r, temp = 0, it;
	vector <int> seq;
	cout << "Enter no. of processes: " << endl;
	cin >> n;
	cout << "Enter no. of resources: " << endl;
	cin >> r;
	int process[n], allocation[n][r], max[n][r], need[n][r], available[r], resources[r];
	
	cout << "Enter total resources:" << endl;
	for (int i = 0; i < r; i++) {
		printf("Resource %d: ", i+1);
		cin >> resources[i];
	}
	
	cout << endl << "Enter Allocation matrix: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			cin >> allocation[i][j];
		}
	}
	
	cout << endl << "Enter Max matrix: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			cin >> max[i][j];
		}
	}
	
	//calculating need matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	
	//calculating available
	for (int j = 0; j < r; j++) {
		for (int i = 0; i < n; i++) {
			temp += allocation[i][j];
		}
		available[j] = resources[j] - temp;
		temp = 0;
	}
	
	cout << endl << "Need" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			cout << need[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "Available" << endl;
	for (int i = 0; i < r; i++) {	
		cout << available[i] << " ";
	}

//	cout << endl;
	bool flag = true, safe = false;
	
	for (int i = 0; i < n; i++) {
		
//		printf("\ni = %d\n", i);
		it = 0;
		
		for (int j = 0; j < r; j++) {
//			printf("Need[%d][%d] = %d, Available[%d] = %d\n", i, j, need[i][j], j, available[j]);
			if (need[i][j] == -99 || need[i][j] > available[j]) {
//				printf("\tNeed[%d][%d] = %d, Available[%d] = %d\nNot possible to allocate!\n", i, j, need[i][j], j, available[j]);
				flag = false;
				break;
			}
		}
		cout << endl;
		
		if (flag == true) {
			seq.push_back(i);
			for (int j = 0; j < r; j++) {
				available[j] += allocation[i][j];
				printf("Available[%d] = %d\n", j, available[j]);
				need[i][j] = -99;
			}
			it++;
		}
		
		flag = true;
		
		if (seq.size() == n) {
			safe = true;
			break;
		}
		if (i == 4 && it == 0) {
			break;
		}	
		if (i == 4) {
			i = -1;
		}	
	}
	
	cout << "\nSequence: " << endl;
	for (int i = 0; i < seq.size(); i++) {
		cout << seq[i] << " ";
	}
	
	flag = true;
	for (int i = 0; i < r; i++) {
		if (available[i] != resources[i]) {
			flag = false;
			break;
		}
	}
	
	if (flag == true) {
		printf("\nAll processes are in Safe State!\n");
	}
	else {
		printf("\nDeadlock arise!");
	}
	
	return 0;
}
