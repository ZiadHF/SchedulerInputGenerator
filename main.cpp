#include<fstream>
#include<iostream>
using namespace std;


int r(int x) {
	return (1 + rand() % x);
}

int main() {
	srand(time(0));
	FILE* outputFile;
	fopen_s(&outputFile, "input.txt", "w");
	int processor1,processor2,processor3,processor4;
	cout << "Enter number of each Processor: ";
	cin >> processor1 >> processor2 >> processor3 >> processor4;
	fprintf(outputFile, "%d %d %d %d\n", (processor1), (processor2), (processor3), (processor4));
	int timeslice;
	cout << "Enter Time Slice: ";
	cin >> timeslice;
	fprintf(outputFile, "%d\n",(timeslice));
	int rtf, maxw,stl,forkprob;
	cout << "Enter RTF, MaxW, STL and ForkProb: ";
	cin >> rtf >> maxw >> stl >> forkprob;
	fprintf(outputFile, "%d %d %d %d\n", (rtf), (maxw), (stl), (forkprob));
	int processes;
	cout << "Enter number of Processes: ";
	cin >> processes;
	fprintf(outputFile, "%d\n", processes);
	int at, ct, dl, n;
	cout << "Enter range of AT, CT, N, DL: ";
	cin >> at >> ct >> n >> dl;
	int R, D;
	cout << "Enter range of R, D: ";
	cin >> R >> D;
	int AT = 1;
	for (int i = 1; i <= processes; i++) {
		int io;
		if (n == 0)
			io = 0;
		else
			io = r(n) - 1;
		fprintf(outputFile, "%d %d %d %d %d", AT, i, r(ct), io, r(dl));
		AT += r(at) -1;
		if (io != 0) {
			fprintf(outputFile, " ");
			for (int i = 1; i <= io;i++) {
				fprintf(outputFile, "(%d,%d)",r(R),r(D));
				if (i == io)
					break;
				fprintf(outputFile, ",");
			}
		}
		fprintf(outputFile, "\n");
	}
	fprintf(outputFile, "SIGKILL Times\n");
	int sigkills;
	cout << "Enter range of SIGKILLs: ";
	cin >> sigkills;
	int begkilltime;
	int killtime;
	cout << "Enter beginning Kill Time and range of Kill Time: ";
	cin >> begkilltime >>killtime;
	for (int i = 1; i <= sigkills; i++) {
		fprintf(outputFile,"%d %d\n", begkilltime, r(processes));
		begkilltime += r(killtime) - 1;
	}
	fclose(outputFile);
}
