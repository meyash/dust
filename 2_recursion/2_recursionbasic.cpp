#include<iostream>
using namespace std;

void fun(int n){
	if(n>0)
	{
	//fun(n-1);
	cout<<n;
	fun(n-1);
	}
}

int main(){
	int n{}; //lists initialization -- set to 0
	cout<<"enter n :";
	cin>>n;
	fun(n);
}
