#include<iostream>

using namespace std;

void sorting(int a[],int n)
{
    int temp;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<(n-i);j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}

	cout<<"Array after bubble sort:";
	for(int i=0;i<n;i++)
		cout<<" "<<a[i];

}

int main(void)
{
    /*int a[50],n,i,j,temp;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the array elements: ";

	for(int i=0;i<n;++i)
		cin>>a[i];*/


	//int burst[]={24,3,4};
    cout<<"Enter The Number of Processes:";
    int no_process;
    cin>>no_process;
    int burst[no_process];
    cout<<"Enter the Burst Times Sequentially:";
    for(int i=0;i<no_process;i++)
    {

        cin>>burst[i];

    }

    sorting(burst,no_process);

    int waiting[no_process];
    waiting[0]=0;
    int turnartime[no_process];
    for(int i=1;i<no_process;i++)
    {
        waiting[i]=waiting[i-1]+burst[i-1];

    }
    for(int i=0;i<no_process;i++)
    {

        cout<<"waiting Time:"<<waiting[i]<<endl;

    }
    cout<<"\n";
    //Average Waiting time

    double toatalwait=0;
    for(int i=0;i<no_process;i++)
    {

       toatalwait=toatalwait+waiting[i];
    }
    double avgwait=toatalwait/no_process;
    cout<<"Average Waiting Time:"<<avgwait<<endl;

    //Turnaround Time Calculation

    for(int i=0;i<no_process;i++)
    {

        turnartime[i]=waiting[i]+burst[i];

    }
    //printing TAT

    for(int i=0;i<no_process;i++)
    {

        cout<<"Turn Around Time:"<<turnartime[i]<<endl;
    }
    //Sum og turn around time

    float totalturn=0;

    for(int i= 0;i<no_process;i++)
    {

        totalturn=totalturn+turnartime[i];
    }

    float avgturn;
    avgturn=totalturn/no_process;

    cout<<"Avg Turnaround Time:"<<avgturn<<endl;





    return 0;
}

