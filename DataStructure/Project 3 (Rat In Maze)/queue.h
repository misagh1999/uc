class QueueItem{
	public:
		int x,y,dis;
};

class Queue{
	
	private:
		int front,rear;
		QueueItem *arr;
		int n;
		
	public:
		bool IsEmpty,IsFull;
		int QueueSize;
		Queue(int MAX_NUMBER=100){
			n=MAX_NUMBER;
			arr = new QueueItem[n];
			front=rear=-1;
			IsEmpty=true;
			IsFull=false;
			QueueSize=0;
		}
		~Queue(){
			delete []arr;
		}
		/*
		inline bool IsEmpty(){
			if(rear==n-1) return true;
			else return false;
		}
		inline bool IsFull(){
			if(front==rear) return true;
			else return false;
		}
		*/
		void addQ(QueueItem a){
			rear=(rear+1)%n;
			if(front==rear) throw 2;
			else{
				arr[rear]=a;
				QueueSize++;
			} 
		}
		QueueItem delQ(){
			if(front==rear)
				throw "aaa";
			front=(front+1)%n;
			QueueSize--;
			return arr[front];
		}
		/*
		void print(){
			for(int i=front-1;i<rear;i++)
				cout<<arr[i]<<endl;
		}
		*/
		
};
