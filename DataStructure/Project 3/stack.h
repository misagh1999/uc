class Item{
	public:
		int x,y,dir;
};

class Stack{
	private:
		int n;
		Item *arr;
		
		
	public:
		int top;
		bool IsEmpty,IsFull;
		Stack(int MAX_NUMBER=100){
			n=MAX_NUMBER;
			arr = new Item[n];
			top=0;
			IsEmpty=true;
			IsFull=false;
		}
		~Stack(){
			delete []arr;
		}
		void push(Item a){
			if(!IsFull){
				IsEmpty=false;
				arr[top++]=a;
				if(top==this->n) IsFull=true;
			}else{
				throw 2;
			}
		}
		Item pop(){
			if(!IsEmpty){
				IsFull=false;
				return arr[--top];
				if(top==this->n) IsEmpty=true;
			}else{
				throw 3;
			}
		}
		
		void print(){
			for(int i=0;i<top;i++)
				cout<<"("<<arr[i].x<<","<<arr[i].y<<")"<<endl;
			cout<<"length: "<<top<<endl;
			
		}
		
};
