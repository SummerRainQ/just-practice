#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;

int main(){
	srand(static_cast<unsigned int>(time(NULL)));
	int n,i,j;
	int foo[4],bar[4];
	int victory[2]={0,0};
	
	for(i=0;i<4;++i){
		do{
			foo[i]=rand()%10;
			for(j=0;j<i;++j){
				if(foo[i]==foo[j]){
					foo[i]=0;
					break;
				}
			}
		}while(foo[i]==0);
	}
	
	int count=0;
	while(victory[0]!=4){
		int A=0,B=0;
		cout<<"�п�J�|�Ӥ��P�Ʀr(��J""9999""�o�ѵ�): ";
		cin>>n;
		if(n==9999){
			cout<<"���׬O:";
			for (i=0;i<4;++i){
				cout<<foo[i];
			}
			cout<<"       GG"<<endl;
			break;
		}
		count+=1;
		for(i=3;i>=0;--i){
			bar[i]=n%10;
			n/=10;
		}
		for(i=0;i<4;++i){
			if(foo[i]==bar[i]){
				A+=1;
				continue;
			}
			for(j=0;j<4;++j){
				if(foo[i]==bar[j]) B+=1;
			}
		}
		victory[0]=A;
		victory[1]=B;
		cout<<A<<"A"<<B<<"B"<<"       ";
		if(victory[0]!=4) cout<<"�q���o"<<endl;
		else if(victory[0]==4){
		cout<<"����F!"<<endl;
		cout<<"�`�@�q�F:"<<count<<"��"<<endl;
		}
	}
	return 0;
}

