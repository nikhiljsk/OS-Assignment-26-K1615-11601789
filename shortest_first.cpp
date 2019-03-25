//Question Number 6   (Nikhil JSK) (K1615_A26_11601789)

#include<bits/stdc++.h>
using namespace std;

struct process{															//structure for maintaining process attibutes
	int id;
	int burst_time;
	int arrival_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;
	int status;				
}p[20];

bool compare(process c, process v);
void display(queue <int> q);

int main()
{
	int n,i;
	cout<<"Enter the number of processes:\n";
	cin>>n;
	queue <int> order;
		
	cout<<"Enter the arrival time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of P"<<i+1<<":"<<endl;
		cin>>p[i].arrival_time;
		p[i].id = i+1;
	}

	cout<<"Enter the burst time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the burst time of P"<<i+1<<":"<<endl;
		cin>>p[i].burst_time;
	}
	
	for(i=0;i<n;i++)									//initializing all objects with status 0					
		p[i].status = 0;	
		
	sort(p, p+n, compare);								//to sort the objects according to burst time
	

	int min = p[0].arrival_time;						//finding the least arrival time object
	int loc=0;
	for(i=0;i<n;i++)
	{
		if(min > p[i].arrival_time)
			loc = i;
	}
	
	int time = p[loc].burst_time + 3;
	
							
							// Processing the process according to shortest job first
	
	cout<<"Processing P"<<p[loc].id<<" from 3"<<" to "<<time<<" seconds"<<endl;
	p[loc].status = 1;
	p[loc].completion_time = time;
	order.push(p[loc].id);
	
	i=0;
	int process_count = 1;
	while(process_count!=n)
	{
		if(p[i].status!=1 && p[i].arrival_time <= time)
		{
			if(p[i].burst_time>10)
			{
				cout<<"Processing P"<<p[i].id<<" from "<<time<<" to "<<time + 10<<" seconds"<<endl;
				time += 10;
				p[i].burst_time -= 10;
			}
			else
			{
				cout<<"Processing P"<<p[i].id<<" from "<<time<<" to "<<time + p[i].burst_time<<" seconds"<<endl;
				time += p[i].burst_time;
				order.push(p[i].id);
				p[i].status = 1;
				p[i].completion_time = time;
				process_count++;
			}
		}
		i = (i+1)%n;
	}
	
	cout<<"\n\nQueue order is "<<endl;						//displaying the queue
	display(order);
	
	cout<<"\nTurnaround time for each process"<<endl;
	for(i=0;i<n;i++)
	{
		p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
		cout<<"P"<<p[i].id<<" : "<<p[i].turnaround_time<<endl;
	}
	
	cout<<"Waiting time for each process is: "<<endl;
	for(i=0;i<n;i++)
	{
		p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
		cout<<"P"<<p[i].id<<" : "<<p[i].waiting_time<<endl;
	}
	
	
	int sum = 0;
	for(i=0;i<n;i++)
	{
		sum+= p[i].turnaround_time;
	}
	cout<<"\nAverage turnaround time is "<<sum/n<<endl;
	
	sum = 0;
	for(i=0;i<n;i++)
	{
		sum+= p[i].waiting_time;
	}
	cout<<"\nAverage waiting time is "<<sum/n<<endl;

	return 0;
}

									//--*-- FUNCTIONS FOR UTILITY --*--


bool compare(process a, process b)						//to sort the objects on basis of burst time
{
	return a.burst_time < b.burst_time;
}


void display(queue <int> gt)							//to display objects in queue
{	
	queue <int> g = gt;
	while(!g.empty())
	{
		cout<<"P"<<g.front()<<" -> ";
		g.pop();
	}
	cout<<"\n";
}


