#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;

int main(){
	cout<<"這是一個猜數字的遊戲,許\多人都稱他為1A2B,外國人則稱他為mastermind"<<endl
		<<"玩法如下:"<<endl<<"         "<<"輸入一個值之後會告訴你幾A幾B"<<endl
		<<"         "<<"一個A代表有一個數字正確並且位置正確"<<endl
		<<"         "<<"一個B代表有一個數字正確但是位置不正確"<<endl
		<<"         "<<"最多只能猜7次,努力猜到4個A吧騷年!"<<endl<<endl;
	
	srand(static_cast<unsigned int>(time(NULL)));
	int n,i,j;
	int foo[4],bar[4];
	int A=0,B=0; 
	char con;
	do{
		for(i=0;i<4;++i){
			do{
				foo[i]=rand()%10;
				for(j=0;j<i;++j){
					if(foo[i]==foo[j]){
						foo[i]=-1;
						break;
					}
				}
			}while(foo[i]==-1);
		}
	
		int count=0;
		do{
			A=0,B=0;
			cout<<"請輸入四個不同數字(輸入""9999""得解答): ";
			GETVAL:
				cin>>n;
			
			if(n<10000 && n>0122){
				if(n==9999){
					cout<<"答案是:";
					for (i=0;i<4;++i){
						cout<<foo[i];
					}
					cout<<"       GG"<<endl;
					break;
				}
				
				for(i=3;i>=0;--i){
					bar[i]=n%10;
					n/=10;
				}
				
				for(i=0;i<4;++i){
					for(j=0;j<i;++j){
						if(bar[i]==bar[j]){
							cout<<"我是說四個'不同'數字,好ㄇ?"<<endl<<"請再輸入一次四個'不同'數字(輸入""9999""得解答): "; 
							goto GETVAL;
						}
					}
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
				
				count+=1;
				cout<<A<<"A"<<B<<"B"<<"       ";
				if(A!=4){
					cout<<"猜錯囉"<<endl;
					if(count==7){
						cout<<"你已經輸了,答案是: ";
						for(i=0;i<4;++i){
							cout<<foo[i];
						}
						cout<<endl;
						break;
					}
				}
				else if(A==4){
				cout<<"答對了!"<<endl;
				cout<<"總共猜了:"<<count<<"次"<<endl;
				break;
				}
			}else{
				cout<<"請一次輸入四位數字,不要想偷雞"<<endl;
			} 
		}while(A!=4);
		cout<<"想繼續嗎?(y/n): ";
		cin>>con;
		if(con=='y') cout<<endl;
	}while(con=='y');
	return 0;
}
