#include<iostream>
#include<fstream>
using namespace std;
#include "queue.h"
#include "stack.h"

class MoveDir{
	public:
		int i,j;
};

void path_Queue(int row,int col,int **maze,int **mark,int direction,int clock){
	
	MoveDir * md = new MoveDir[direction];
	
	if(direction==4){
		if(clock==1){
			md[0].i=-1;md[0].j=0;
			md[1].i=0;md[1].j=1;
			md[2].i=1;md[2].j=0;
			md[3].i=0;md[3].j=-1;
		}
		else{
		md[0].i=-1;md[0].j=0;
		md[1].i=0;md[1].j=-1;
		md[2].i=1;md[2].j=0;
		md[3].i=0;md[3].j=1;
		}
	}
	else if(direction==8){
		if(clock==1){
			
			md[0].i=-1;md[0].j=0;
			md[1].i=-1;md[1].j=1;
			md[2].i=0;md[2].j=1;
			md[3].i=1;md[3].j=1;
			md[4].i=1;md[4].j=0;
			md[5].i=1;md[5].j=-1;
			md[6].i=0;md[6].j=-1;
			md[7].i=-1;md[7].j=-1;
			
		}
		else{
			md[0].i=-1;md[0].j=0;
			md[1].i=-1;md[1].j=-1;
			md[2].i=0;md[2].j=-1;
			md[3].i=1;md[3].j=-1;
			md[4].i=1;md[4].j=0;
			md[5].i=1;md[5].j=1;
			md[6].i=0;md[6].j=1;
			md[7].i=-1;md[7].j=1;
		}
	}
	
	Queue Items(row*col);
	int MaxStackNumber=0;
	int time=0;
	int d=0;
	int g,h;
	mark[1][1]=1;
	QueueItem temp;
	temp.x=1;temp.y=1;temp.dis=0;
	Items.addQ(temp);
	while(1){
		
		time++;
		
		temp=Items.delQ();
		int a=temp.x;int b=temp.y;int distance=temp.dis;
		d=0;
		for(d=0;d<direction;d++){
			g= a + md[d].i;h = b+md[d].j;
			if(maze[g][h]==-1){
				mark[g][h]=1;
				cout<<"\n******* Queue *******"<<endl;
				cout<<"length: "<<temp.dis+1<<endl;
				cout<<"time: "<<time<<endl;
				cout<<"Max Stack Number: "<<MaxStackNumber<<endl;
				cout<<"*******     *******"<<endl<<endl;
				return;
			}
			if((!maze[g][h]) && (!mark[g][h]) ){
				
				time++;
				
				mark[g][h]=1;
				QueueItem addT;
				addT.x= g;addT.y=h;addT.dis=distance+1;
				Items.addQ(addT);
				if(MaxStackNumber<Items.QueueSize) MaxStackNumber=Items.QueueSize;
			}
		}
	}
	
}

void path_Stack(int row,int col,int **maze,int **mark,int direction,int clock){
	
	MoveDir * md = new MoveDir[direction];
	
	if(direction==4){
		if(clock==1){
			md[0].i=-1;md[0].j=0;
			md[1].i=0;md[1].j=1;
			md[2].i=1;md[2].j=0;
			md[3].i=0;md[3].j=-1;
		}
		else{
		md[0].i=-1;md[0].j=0;
		md[1].i=0;md[1].j=-1;
		md[2].i=1;md[2].j=0;
		md[3].i=0;md[3].j=1;
		}
	}
	else if(direction==8){
		if(clock==1){
			
			md[0].i=-1;md[0].j=0;
			md[1].i=-1;md[1].j=1;
			md[2].i=0;md[2].j=1;
			md[3].i=1;md[3].j=1;
			md[4].i=1;md[4].j=0;
			md[5].i=1;md[5].j=-1;
			md[6].i=0;md[6].j=-1;
			md[7].i=-1;md[7].j=-1;
			
		}
		else{
			md[0].i=-1;md[0].j=0;
			md[1].i=-1;md[1].j=-1;
			md[2].i=0;md[2].j=-1;
			md[3].i=1;md[3].j=-1;
			md[4].i=1;md[4].j=0;
			md[5].i=1;md[5].j=1;
			md[6].i=0;md[6].j=1;
			md[7].i=-1;md[7].j=1;
		}
	}
	
	Stack Items(row*col);
	int MaxStackNumber=0;
	int time=0;
	
	mark[1][1]=1;
	Item temp;
	temp.x=1;temp.y=1;temp.dir=1;
	Items.push(temp);
	while(!Items.IsEmpty){
		
		time++;
		
		temp=Items.pop();
		int a=temp.x;int b=temp.y;int d=temp.dir;
		while(d<direction){
			int g= a + md[d].i;int h = b+md[d].j;
			if(maze[g][h]==-1){
				mark[g][h]=1;
				temp.x= a;temp.y=b;temp.dir=++d;
				Items.push(temp);
				//Items.print();
				cout<<"\n******* Stack *******"<<endl;
				cout<<"length: "<<Items.top<<endl;
				cout<<"time: "<<time<<endl;
				cout<<"Max Stack Number: "<<MaxStackNumber<<endl;
				cout<<"*******     *******"<<endl<<endl;
				return;
			}
			if((!maze[g][h]) && (!mark[g][h]) ){
				
				time++;
				
				mark[g][h]=1;
				temp.x= a;temp.y=b;temp.dir=++d;
				Items.push(temp);
				if(MaxStackNumber<Items.top-1) MaxStackNumber=Items.top-1;
				a=g; b=h; d=0;
			}
			else ++d;
		}
	}	
}

/*
string showMenu(){
	cout<<"Enter your sample: "<<endl;
	cout<<"Choose a number (1-5) please"<<endl;
	cin>>samNum;
		switch(samNum){
			
			
		}
}
*/

int main(){
	
	int samNum;
	int clock,direction,moveNum;
	string fileName;
	while(1){
	
	do{
		cout<<"please enter sample (1-5) (exit:0) : ";
		cin>>samNum;
		switch(samNum){
			case 1:
				fileName="sample1.txt";
				break;
			case 2:
				fileName="sample2.txt";
				break;
			case 3:
				fileName="sample3.txt";
				break;
			case 4:
				fileName="sample4.txt";
				break;
			case 5:
				fileName="sample5.txt";
				break;
			case 0:
				exit(0);
			default:
				cout<<"your number is false";
		}
	}while(samNum>5 || samNum<0);
	do{
		cout<<"please enter move number(1-4): ";
		cin>>moveNum;
		switch(moveNum){
			case 1:
				clock=1;
				direction=4;
			break;
			case 2:
				clock=-1;
				direction=4;
			break;
			case 3:
				clock=1;
				direction=8;
			break;
			case 4:
				clock=-1;
				direction=8;
			break;
			default:
				cout<<"your number is false"<<endl;
		}
	}while(moveNum>4 || moveNum<0);
	
  fstream f1(fileName);
  int row,col;
  f1>>row;
  f1>>col;
  int **maze = new int *[row];
  for(int i=0;i<row;i++)
    maze[i]=new int[col];
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      char c;
      f1>>c;
      maze[i][j]= ((int) c)-48;
    }
  }
  
  	maze[row-2][col-2]=-1;
  
 	 int **mark = new int *[row];
	for(int i=0;i<row;i++)
    	mark[i]=new int[col];
    for(int i=0;i<row;i++)
    	for(int j=0;j<col;j++)
    		mark[i][j]=0;
	
//	path(row,col,maze,mark,8,1);
//	path_Queue(row,col,maze,mark,4,1);
	int sq;
	do{
		cout<<"enter a number:\n1:Stack\n2:Queue\n";
		cin>>sq;
		switch(sq){
			case 1:
				path_Stack(row,col,maze,mark,direction,clock);
			break;
			case 2:
				path_Queue(row,col,maze,mark,direction,clock);
			break;
			default:
			cout<<"your number is false"<<endl;
		}
		
	}while(sq>2 || sq<1);
	
	for(int i=0;i<row;i++)
  	delete [] maze[i];
 		 delete []maze;
  	for(int i=0;i<row;i++)
  		delete [] mark[i];
 	 delete []mark;
 }
 	 return 0;
}
