#include<iostream>
using namespace std;

	
void bubble_sort(int* a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(a[j-1]>a[j])
				swap(a[j-1],a[j]);
		}
	}
} 

void gnome_sort(int* a,int n)
{
	for(int pos=1;pos<n;)
	{
		if(a[pos]>=a[pos-1])
			pos++;
		else
		{
			swap(a[pos],a[pos-1]);
			if(pos>1)
				pos--;
			else
				pos++;

		}
	}
}

void insertion_sort(int* a,int n)
{
	for(int i=1;i<n;++i)
	{
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void selection_sort(int* a,int n)
{
	for(int pos=0;pos<n;++pos)
	{
		int min = pos;
		for(int i=pos+1;i<n;++i)
		{
			if(a[i]<a[min])
				min = i;
		}
		if(min != pos)
			swap(a[min],a[pos]);
	}
}


void merge(int A[],int p,int q,int r)
{
	int n1,n2;
	n1=q-p+1;
	n2=r-q;

	int i,j;
	int R[100];
	int L[100];
	for(i=0;i<n1;i++) L[i]=A[p+i];
	L[n1]=32767;
	
	for(j=0;j<n2;j++) R[j]=A[q+j+1];
	R[n2]=32767;

	i=j=0;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}

		else
		{
			A[k]=R[j];
			j++;
		}
	}
}

void merge_sort(int A[],int p,int r)
{
	if(p<r){
		int q=(p+r)/2;

		merge_sort(A,p,q);
		merge_sort(A,q+1,r);

		merge(A,p,q,r);
	}
}

void quick_sort(int a[],int start,int finish)
{
	if(start<finish)
	{
		int pivot = a[finish];
		int i = start;
		int j = finish-1;

		while(i<=j)
		{
			while(a[i]<pivot) i++;
			while(a[j]>pivot) j--;

			if(i>j) break;

			swap(a[i],a[j]);
			i++;
			j--;
		}
		swap(a[i],a[finish]);

		quick_sort(a,start,i-1);
		quick_sort(a,i+1,finish);
	}
}

void display(int* a,int n)
{
	cout<<"Sorted elments: ";
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}

int main()
{
	int choice;
	int a[10]={5,9,7,1,6,4,2,14,3,10};

	cout<<"Unorted elments: ";
	for(int i=0;i<10;++i)
		cout<<a[i]<<" ";
	cout<<endl<<endl;

	while(choice != 7)
	{
		cout<<"1. Bubble Sort\n";
		cout<<"2. Gnome Sort\n";
		cout<<"3. Insertion Sort\n";
		cout<<"4. Seclection Sort\n";
		cout<<"5. Merge Sort\n";
		cout<<"6. Quick Sort\n";
		cout<<"7. Exit\n";
		cout<<"Your choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			bubble_sort(a,10);
			display(a,10);
			break;
		case 2:
			gnome_sort(a,10);
			display(a,10);
			break;
		case 3:
			insertion_sort(a,10);
			display(a,10);
			break;
		case 4:
			selection_sort(a,10);
			display(a,10);
			break;
		case 5:
			merge_sort(a,0,10-1);
			display(a,10);
			break;
		case 6:
			quick_sort(a,0,10-1);
			display(a,10);
			break;
		case 7:
			exit(0);
		default:
			break;
		}
	}

	return 0;
}

