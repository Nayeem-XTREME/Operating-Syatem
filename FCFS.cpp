#include <iostream>
using namespace std;

int main()
{
	
	printf("FCFS\n\n");
	
	int n, wait = 0, turnarround = 0, grantt = 0;
	cout << "Enter the no. of process: " << endl;
	cin >> n;
	int process[n][3];
	
	cout << endl << "Enter the burst times of the processes: " << endl;
	for (int i = 0; i < n; i++) {
		printf("Process [%d] = ", i+1);
		cin >> process[i][0];
	}
	
	for (int i = 0; i < n; i++) {
		
		if (i != 0) {
			wait += process[i-1][0];
			process[i][1] = wait;
		}
		else {
			process[i][1] = 0;
		}
		
		turnarround += process[i][0];
		process[i][2] = turnarround;
	}
	
	grantt = turnarround;
	cout << endl << endl;
	wait = turnarround = 0;
	
	printf("Process\t\tBurst Time\tWaiting time\tTurnarround Time\n");
	
	for (int i = 0; i < n; i++) {
		printf("Process [%d] : \t\t%d\t\t%d\t\t%d\n", i, process[i][0], process[i][1], process[i][2]);
		wait += process[i][1];
		turnarround += process[i][2];
	}
	
	printf("\nAverage waiting time: %f\n", (float)wait/n);
	printf("Average Turnarround time: %f\n", (float)turnarround/n);
	
	
	cout << endl << "Gantt Chart: " << endl;
	for (int i = 0; i < grantt; i++) {
		printf("_");
	}
	cout << endl;
	for (int i = 1, j = 0; i <= grantt; i++) {
		if (i == process[j][2]) {
			printf("|");
			j++;
		}
		else
			printf("%d", j+1);	
	}
	cout << endl;
	for (int i = 0; i < grantt; i++) {
		printf("'");
	}
	cout << endl;
	for (int i = 1, j = 0; i <= grantt; i++) {
		if (i == process[j][2]) {
			printf("%d", process[j][2]);
			j++;
		}
		else
			printf(" ");
	}
	
	return 0;
}
