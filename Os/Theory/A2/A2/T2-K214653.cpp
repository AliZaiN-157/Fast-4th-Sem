#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Task
{
public:
	int priority;
	int burst;
	int arrival;
	int id;
	int waitTime;
	int turnaround;
	
	Task(int p, int b, int a, int i) : priority(p), burst(b), arrival(a), id(i), waitTime(0), turnaround(0) {}
	
	friend ostream& operator<<(ostream& os, const Task& t)
	{
		os << "Task " << t.id << " : Priority = " << t.priority << ", Burst = " << t.burst << ", Arrival = " << t.arrival;
		return os;
	}
};

class TaskCompare
{
public:
	bool operator()(const Task& t1, const Task& t2)
	{
		return t1.priority > t2.priority;
	}
};

class TaskCompare2
{
public:
	bool operator()(const Task& t1, const Task& t2)
	{
		return t1.burst > t2.burst;
	}
};

void sjf(vector<Task>& tasks)
{
	priority_queue<Task, vector<Task>, TaskCompare2> pq;

	int time = 0;
	int totalWait = 0;
	int totalTurnaround = 0;

	for (int i = 0; i < tasks.size(); i++)
	{
		pq.push(tasks[i]);
	}

	while (!pq.empty())
	{
		Task t = pq.top();
		pq.pop();

		if (time < t.arrival)
		{
			time = t.arrival;
		}

		t.waitTime = time - t.arrival;
		time += t.burst;
		t.turnaround = time - t.arrival;
		totalWait += t.waitTime;
		totalTurnaround += t.turnaround;
		cout << t << ", Wait = " << t.waitTime << ", Turnaround = " << t.turnaround << endl;
	}

	cout << "Average waiting time = " << (double)totalWait / tasks.size() << endl;
	cout << "Average turnaround time = " << (double)totalTurnaround / tasks.size() << endl;
}


void priorityScheduling(vector<Task>& tasks)
{
	priority_queue<Task, vector<Task>, TaskCompare> pq;

	int time = 0;
	int totalWait = 0;
	int totalTurnaround = 0;

	for (int i = 0; i < tasks.size(); i++)
	{
		pq.push(tasks[i]);
	}

	while (!pq.empty())
	{
		Task t = pq.top();
		pq.pop();

		if (time < t.arrival)
		{
			time = t.arrival;
		}

		t.waitTime = time - t.arrival;
		time += t.burst;
		t.turnaround = time - t.arrival;
		totalWait += t.waitTime;
		totalTurnaround += t.turnaround;
		cout << t << ", Wait = " << t.waitTime << ", Turnaround = " << t.turnaround << endl;
	}

	cout << "Average waiting time = " << (double)totalWait / tasks.size() << endl;
	cout << "Average turnaround time = " << (double)totalTurnaround / tasks.size() << endl;
}


void roundRobin(vector<Task>& tasks, int quantum)
{
	queue<Task> q;

	int time = 0;
	int totalWait = 0;
	int totalTurnaround = 0;

	for (int i = 0; i < tasks.size(); i++)
	{
		q.push(tasks[i]);
	}

	while (!q.empty())
	{
		Task t = q.front();
		q.pop();

		if (time < t.arrival)
		{
			time = t.arrival;
		}

		t.waitTime = time - t.arrival;

		if (t.burst > quantum)
		{
			t.burst -= quantum;
			time += quantum;
			q.push(t);
		}
		else
		{
			time += t.burst;
			t.turnaround = time - t.arrival;
			totalWait += t.waitTime;
			totalTurnaround += t.turnaround;
			cout << t << ", Wait = " << t.waitTime << ", Turnaround = " << t.turnaround << endl;
		}
	}

	cout << "Average waiting time = " << (double)totalWait / tasks.size() << endl;
	cout << "Average turnaround time = " << (double)totalTurnaround / tasks.size() << endl;
}


int main()
{
	ifstream infile("input1.txt");
	vector<Task> tasks;

	int priority, burst, arrival, id = 0;

	while (infile >> priority >> burst >> arrival)
	{
		tasks.push_back(Task(priority, burst, arrival, id++));
	}

	cout << "Priority scheduling" << endl;
	priorityScheduling(tasks);

	cout << endl << "Shortest job first" << endl;
	sjf(tasks);

	cout << endl << "Round robin" << endl;
	roundRobin(tasks, 3);	

	return 0;
}
// Priority Burst Arrival
//1 5 0
//2 3 1
//3 1 2
//4 2 3
//5 3 4