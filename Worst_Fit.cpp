#include <iostream>
using namespace std;

int main()
{
	cout << "Worst Fit Algorithm\n" << endl;
	
	int n, p;
	cout << "Enter no. of Blocks:" << endl;
	cin >> n;
	int block[n][4];
	cout << "Enter size of Blocks:" << endl;
	for (int i = 0; i < n; i++) {
		printf("Block %d: ", i+1);
		cin >> block[i][0];
	}
	
	cout << "\nEnter no. of Processes:" << endl;
	cin >> p;
	int process[p];
	cout << "Enter size of Processes:" << endl;
	for (int i = 0; i < p; i++) {
		printf("Process %d: ", i+1);
		cin >> process[i];
	}

	for (int i = 0; i < p; i++) {
		int temp = -1;
		for (int j = 0; j < n; j++) {
			if (block[j][0] >= process[i] && block[j][2] != 1) {
				if (temp != -1 && block[j][0] > block[temp][0]) {
					temp = j;
				}
				else if (temp == -1) {
					temp = j;
				}
			}
			else if (block[j][2] != 1) {
				block[j][2] = 0;
			}
		}
		if (temp != -1) {
			block[temp][1] = block[temp][0] - process[i];
			block[temp][2] = 1;
			block[temp][3] = i;
		}
	}
	
	printf("\n\nBlock No.\t\tSize\t\tProcess No.\t\tSize\t\tFragmented\n");
	for (int i = 0; i < n; i++) {
		if (block[i][2] == 1) {
			printf("Block[%d]\t\t%d\t\t%d\t\t\t%d\t\t%d\n", i+1, block[i][0], block[i][3]+1, process[block[i][3]], block[i][1]);
		}
		else if (block[i][2] == 0) {
			printf("Block[%d]\t\t%d\t\tNot Allocated\n", i+1, block[i][0]);
		}
	}
	
	return 0;
}
