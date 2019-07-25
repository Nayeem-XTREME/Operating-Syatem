#include <iostream>
using namespace std;

int main()
{	
	printf("SJF\n\n");
	
	int n, key1, key2, key3, key4, wait = 0, turnarround = 0, grantt = 0;
	cout << "Enter the no. of process: " << endl;
	cin >> n;
	int process[n][4];
	
	cout << endl << "Enter the burst times of the processes: " << endl;
	for (int i = 0; i < n; i++) {
		printf("Process [%d] = ", i+1);
		process[i][3] = i;
		cin >> process[i][0];
	}
	
	//sorting based on burst time
   	for (int i = 1; i < n; i++) {
       key1 = process[i][0];
       key2 = process[i][1];
       key3 = process[i][2];
       key4 = process[i][3];
       
       int j = i-1;

       while (j >= 0 && process[j][0] > key1)
       {
           process[j+1][0] = process[j][0];
           process[j+1][1] = process[j][1];
           process[j+1][2] = process[j][2];
           process[j+1][3] = process[j][3];
           
           j = j-1;
       }
       process[j+1][0] = key1;
       process[j+1][1] = key2;
       process[j+1][2] = key3;
       process[j+1][3] = key4;
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
		printf("Process [%d] : \t\t%d\t\t%d\t\t%d\n", process[i][3]+1, process[i][0], process[i][1], process[i][2]);
		wait += process[i][1];
		turnarround += process[i][2];
	}
	
	printf("\nAverage waiting time: %f\n", (float)wait/n);
	printf("Average Turnarround time: %f\n", (float)turnarround/n);
	
	//making gantt chart
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
			printf("%d", process[j][3]+1);	
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
