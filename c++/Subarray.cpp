#include<iostream>
#include<climits>
using namespace std;

void generateSubarray(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<a[k]<<" ";
			}
			cout<<endl;
		}
	}
}

void MaxSumSubarray(int a[],int n){
	int max_sum=INT_MIN;//can't be 0, since all elements if -ve then sum is always less than 0

	int start=0,end=0;  //to save sub array

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			if(sum>max_sum){
				max_sum=sum;   //max_sum=max(max_sum,sum);

				//save max subarray start and end
				start=i;
				end=j;
			}
		}
	}
	cout<<"max subarray sum: "<<max_sum<<endl;
	for(int i=start;i<=end;i++)
		cout<<a[i]<<" ";
}

int main(){
	int a[] = {2,1,4,5,7,6};
	int n=sizeof(a)/sizeof(int);
	//generateSubarray(a,n);


	int arr[] = {2,-1,4,5,-7,6};
	generateSubarray(arr,n);
	MaxSumSubarray(arr,n);
	return 0;
}