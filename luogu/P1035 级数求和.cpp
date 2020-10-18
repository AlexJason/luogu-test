#include <iostream>

using namespace std;

int main() {
	return cout<<([](int n=0, int k=0)->int{return cin>>k,( \
	[&](int &n,double sum=0.0)->void{while((sum+=1.0/(++n)) \
	<=k);})(n),n;})()<<endl,0;
}
