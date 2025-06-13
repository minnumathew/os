#include<stdio.h>Add commentMore actions
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
void producer();
void consumer();
int wait(int);
int signal(int);
void main()
{
int n;
printf("1.Producer\n2.Consumer\n3.Exit\n");
scanf("%d",&n);
do{
switch(n)
{
case 1:
{
if(mutex==1&&empty!=0)
{
producer();
}
else
{
printf("Buffer is Full\n");
}
break;
case 2:
{
if(mutex==1&&full!=0)
{

consumer();
}
else
{
printf("Buffer is Empty\n");
}
}
break;
case 3:
{
break;
}
}
}
printf("1.Producer\n2.Consumer\n3.Exit\n");
scanf("%d",&n);
}while(n!=3);
}

int wait(int s)
{
return(--s);
}
int signal(int s)
{
return(++s);
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);

x++;
printf("Producer produces item:%d\n",x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("Consumer consumes item:%d\n",x);
x--;
mutex=signal(mutex);
}
