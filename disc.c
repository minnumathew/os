#include <stdio.h>Add commentMore actions
#include <stdlib.h>
#include <math.h>
void fcfs() {
int head, a[20], i, distance, n, seektime = 0;
printf("\nEnter Head position: ");
scanf("%d", &head);
printf("\nEnter number of disk requests: ");
scanf("%d", &n);
printf("\nEnter the disk requests: ");
for (i = 1; i <= n; i++)
scanf("%d", &a[i]);
a[0] = head;
printf("*FCFS DISK SCHEDULING*\n");
for (i = 0; i < n; i++) {
distance = abs(a[i] - a[i + 1]);
printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
seektime += distance;
}
printf("Total seek time is : %d\n", seektime);
}
void cscan() {
int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
printf("Enter the number of Requests\n");
scanf("%d", &n);
printf("Enter the Requests sequence\n");
for (i = 0; i < n; i++)
scanf("%d", &RQ[i]);
printf("Enter initial head position\n");
scanf("%d", &initial);
printf("Enter total disk size\n");
scanf("%d", &size);
printf("Enter the head movement direction for high 1 and for low 0\n");
scanf("%d", &move);
for (i = 0; i < n; i++) {
for (j = 0; j < n - i - 1; j++) {
if (RQ[j] > RQ[j + 1]) {
int temp = RQ[j];
RQ[j] = RQ[j + 1];

RQ[j + 1] = temp;
}
}
}
int index = 0;
for (i = 0; i < n; i++) {
if (initial < RQ[i]) {
index = i;
break;
}
}
if (move == 1) {
for (i = index; i < n; i++) {
TotalHeadMoment += abs(RQ[i] - initial);
initial = RQ[i];
}
TotalHeadMoment += abs(size - RQ[i - 1] - 1);
TotalHeadMoment += size - 1;
initial = 0;
for (i = 0; i < index; i++) {
TotalHeadMoment += abs(RQ[i] - initial);
initial = RQ[i];
}
} else {
for (i = index - 1; i >= 0; i--) {
TotalHeadMoment += abs(RQ[i] - initial);
initial = RQ[i];
}
TotalHeadMoment += RQ[i + 1];
TotalHeadMoment += size - 1;
initial = size - 1;
for (i = n - 1; i >= index; i--) {
TotalHeadMoment += abs(RQ[i] - initial);
initial = RQ[i];
}
}
printf("Total head movement is %d\n", TotalHeadMoment);
}
void scan() {
int queue[25], n, headposition, i, j, k, seek = 0, maxrange, difference, temp;

int queue1[20], queue2[20], temp1 = 0, temp2 = 0;
float averageSeekTime;
printf("Enter the maximum range of Disk: ");
scanf("%d", &maxrange);
printf("Enter the number of queue requests: ");
scanf("%d", &n);
printf("Enter the initial head position: ");
scanf("%d", &headposition);
printf("Enter the disk positions to be read(queue): ");
for (i = 1; i <= n; i++) {
scanf("%d", &temp);
if (temp > headposition) {
queue1[temp1++] = temp;
} else {
queue2[temp2++] = temp;
}
}
for (i = 0; i < temp1 - 1; i++) {
for (j = i + 1; j < temp1; j++) {
if (queue1[i] > queue1[j]) {
temp = queue1[i];
queue1[i] = queue1[j];
queue1[j] = temp;
}
}
}
for (i = 0; i < temp2 - 1; i++) {
for (j = i + 1; j < temp2; j++) {
if (queue2[i] < queue2[j]) {
temp = queue2[i];
queue2[i] = queue2[j];
queue2[j] = temp;
}
}
}
for (i = 1, j = 0; j < temp1; i++, j++) {
queue[i] = queue1[j];
}
queue[i++] = maxrange;

for (j = 0; j < temp2; i++, j++) {
queue[i] = queue2[j];
}
queue[i] = 0;
queue[0] = headposition;
for (j = 0; j <= n; j++) {
difference = abs(queue[j + 1] - queue[j]);
seek += difference;
printf("Disk head moves from position %d to %d with Seek %d \n",
queue[j], queue[j + 1], difference);
}
averageSeekTime = seek / (float)n;
printf("Total Seek Time = %d\n", seek);
printf("Average Seek Time = %f\n", averageSeekTime);
}
int main() {
int ch;
do {
printf("Enter choice:\n1. FCFS\n2. CSCAN\n3. SCAN\n4. Exit\n");
scanf("%d", &ch);
switch (ch) {
case 1:
fcfs();
break;
case 2:
cscan();
break;
case 3:
scan();
break;
}
} while (ch != 4);
return 0;
}
