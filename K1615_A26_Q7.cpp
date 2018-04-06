//Question Number 7   
//(Nikhil JSK) (K1615_A26_11601789)

#include<bits/stdc++.h>
using namespace std;

struct process{										//structure for maintaining process attibutes
	int arrival_time;
	int status;
	int burst_time;
	int priority;
	int id;
}p[20];

bool compare(process x, process y);
void display(queue <int> temp);

int main()
{
	int num,i;
	cout<<"Enter the number of processes:\n";
	cin>>num;
	
	queue <int> order_execution;
	
	cout<<"Enter the arrival time of each process:\n";
	for(i=0;i<num;i++)
	{
		cout<<"Enter the arrival time of P"<<i+1<<":"<<endl;
		cin>>p[i].arrival_time;
		p[i].id = i+1;
	}

	cout<<"Enter the burst time of each process:\n";
	for(i=0;i<num;i++)
	{
		cout<<"Enter the burst time of P"<<i+1<<":"<<endl;
		cin>>p[i].burst_time;
	}
	
	cout<<"Enter the priority of each process:\n";
	for(i=0;i<num;i++)
	{
		cout<<"Enter the priority of P"<<i+1<<":"<<endl;
		cin>>p[i].priority;
	}
	
	for(i=0;i<num;i++)										//initializing all the status values to 0
		p[i].status = 0;
		
	sort(p, p+num, compare);								//sorting the array of objects according to the arrival time
	
	
								//Processing first queue using priority scheduling
								
								
	cout<<"----------------Processing first queue using priority scheduling------------"<<endl<<endl<<endl;					
	int time = 0;			
	int count = 0, count2 = 0;
	i=0;
	while(count!=num)
	{
		if(p[i].status!=1 && p[i].status!=2)
		{	
			cout<<"Processing "<<p[i].id<<endl;
			for(int j=i+1;j<num;j++)
			{
				if(p[j].status != 1 && p[j].status!=2 && (p[j].priority < p[i].priority) && (p[j].arrival_time <= time))
				{
					cout<<"Process P"<<p[i].id<<" is interuppted by P"<<p[j].id<<".Pushing it into queue2"<<endl;
					cout<<"Process P"<<p[j].id<<" is processing"<<endl;
					p[i].status = 2;
					count2++;
					time += p[j].burst_time;
					p[j].status = 1;
					cout<<"Process P"<<p[j].id<<" is completely processed"<<endl;
					order_execution.push(p[j].id);
					count += 2;
					break;
				}
			}
			if(p[i].status != 2)
			{
				time += p[i].burst_time;
				p[i].status = 1;
				cout<<"Process P"<<p[i].id<<" is completely processed"<<endl;
				order_execution.push(p[i].id);
				count++;
			}
		}
		i = (i+1)%num;
	}
	
					//Processing second queue according to round robin scheduling
	int tq = 2;
	time = 0;
	count = 0;
	
	cout<<endl<<endl<<endl<<"----------------Processing second queue using round robin scheduling------------"<<endl<<endl<<endl;
	
	i=0;
	while(count != count2)
	{
		if(p[i].status == 2)
		{
			if(p[i].burst_time<2)
			{
				p[i].burst_time -= 1;
				time += 1;
				p[i].status = 1;
				cout<<"Completed executing P"<<p[i].id<<" at "<<time<<" time-units"<<endl;
				order_execution.push(p[i].id);
				count++; 
			}
			else
			{
				p[i].burst_time -= 2;
				time += tq;
				cout<<"Processing P"<<p[i].id<<" for 2 time-units"<<endl;
			}
		}
		i = (i+1)%num;
	}
									//displaying the queue for order of execution
	cout<<"Displaying the order of execution"<<endl;		
	display(order_execution);
	
	
	return 0;
}


									//--*-- FUNCTIONS FOR UTILITY --*--

bool compare(process a, process b)											//to sort the objects on basis of arrival time
{
	return a.arrival_time < b.arrival_time;
}

void display(queue <int> gt)												//to display objects in queue
{
	queue <int> g = gt;
	while(!g.empty())
	{
		cout<<"P"<<g.front()<<" -> ";
		g.pop();
	}
	cout<<"\n";
}
