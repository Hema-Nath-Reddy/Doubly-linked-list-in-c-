#include<iostream>
using namespace std;
struct node{
	node* prev;
	int data;
	node* next;
};
class Double{	
	node* head=NULL;
	node* tail=NULL;
	public:
		void insertbeg(int data){
			node* newnode=new node();
			newnode->data=data;
			newnode->prev=NULL;
			newnode->next=head;
			if (head == NULL) {
       			head = newnode;
    		} else {
        		head->prev = newnode;
       			head = newnode;
    		}
    		cout<<"Insertion succesful."<<endl;
		}	
		void insertmiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->next==NULL){
				cout<<"There is only node node in the list."<<endl;
				cout<<"Please enter 1 or 3 depending on the position of the node to be inserted."<<endl;
			}
			else{
				cout<<"Enter index: ";
				int index;
				cin>>index;				
				if(index>Count()||index<0){
					cout<<"Invalid index."<<endl;
				} 
				else{
					int data;
					cout<<"Enter the element: ";
					cin>>data;
					if(index==0){			
						insertbeg(data);
					}else if(index==Count()){
						insertend(data);
					}else{
						int count=1;
						node* temp=head;
						while(count!=index){
							temp=temp->next;
							count++;
						}
						node* temp2;
						node* newnode=new node();
						newnode->data=data;
						temp2=temp->next;
						temp->next=newnode;
						newnode->next=temp2;
						newnode->prev=temp;
						temp2->prev=newnode;
						cout<<"Insertion succesful."<<endl;
					}			
				}
				
			}	
		}
		void insertend(int data){
			node* newnode=new node();
			newnode->data=data;
			if(head==NULL){
				head=newnode;
			}else{
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=newnode;
				newnode->prev=temp;
				newnode->next=NULL;
				tail=newnode;
			}
			cout<<"Insertion succesful."<<endl;
		}
		void deletebeg(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}
			else{
				node* temp=head;
				head=head->next;
				head->prev=NULL;
				delete temp;
				cout<<"Deletion successful."<<endl;
			}
		}
		void deletemiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->next==NULL){
				cout<<"There is only one node in the list."<<endl;
				cout<<"Please enter 4 or 6 if the node has to be deleted."<<endl;
			}
			else{
				int index;
				cout<<"Enter the index: ";
				cin>>index;
				if(index>Count()||index<0){
					cout<<"Invaild index."<<endl;
				}
				else{
					if(index==0){
						deletebeg();
					}else if(index==Count()){
						deletend();
					}else{
						node* temp=head;
						node* temp2;
						int count=1;
						while(count<=index){
							temp2=temp;
							temp=temp->next;
							count++;
						}
						temp2->next=temp->next;
						node* temp3=temp->next;
						temp3->prev=temp2;
						delete temp;
						cout<<"Deletion succesful."<<endl;
					}			
				}
			}
		}
		void deletend(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->next==NULL){
				node* temp=head;
				delete temp;
				head=NULL;
				tail=NULL;
				cout<<"Deletion successful."<<endl;
			}
			else{
				node* temp=tail->prev;
				node* temp2=tail;
				temp->next=NULL;
				delete temp2;
				tail=temp;
				cout<<"Deletion successful."<<endl;
			}
		}
		int Count(){
			int c=1;
			if(head==NULL){
				c=0;
			}else{
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
					c++;
				}
			}
			return c;
		}
		void traversehead(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=head;
				cout<<"The elements of the list are: "<<endl;
				while(temp!=NULL){
					cout<<temp->data<<endl;
					temp=temp->next;
				}
			}
		}
		void traversetail(){
			if(tail==NULL){
				cout<<"Empty list."<<endl;
			}else{
				cout<<"The elements of the list are: "<<endl;
				node* temp=tail;
				while(temp!=NULL){
					cout<<temp->data<<endl;
					temp=temp->prev;
				}
			}
		}
		void search(){
			node* temp=head;
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				int element;
				cout<<"Enter the element: ";
				cin>>element;
				bool found=false;
				int c=0;
				while(temp->next!=NULL){
					if(temp->data==element){
						cout<<element<<" has been found at index: "<<c<<endl;
						found=true;
						break;
					}
					temp=temp->next;
					c++;
				}
				if(!found){
					cout<<element<<" is not present in the list."<<endl;
				}
			}
		}
};
int main(){
	Double li;
	int choice;
	do{
		cout<<endl<<"1. Insert an element in the beginning."<<endl;
		cout<<"2. Insert an element in the middle."<<endl;
		cout<<"3. Insert an element in the end."<<endl;
		cout<<"4. Delete an element in the beginning."<<endl;
		cout<<"5. Delete an element in the middle."<<endl;
		cout<<"6. Delete an element in the end."<<endl;
		cout<<"7. Display the list(from head)."<<endl;
		cout<<"8. Display the list(from tail)."<<endl;
		cout<<"9. Count the number of the nodes in the list."<<endl;
		cout<<"10. Search for an element in the list."<<endl;
		cout<<"11. Exit."<<endl<<endl;
		int element;
		cout<<"Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the element: ";
				cin>>element;
				li.insertbeg(element);
				break;
			case 2:
				li.insertmiddle();
				break;
			case 3:
				cout<<"Enter the element: ";
				cin>>element;
				li.insertend(element);
				break;
			case 4:
				li.deletebeg();
				break;
			case 5:
				li.deletemiddle();
				break;
			case 6:
				li.deletend();
				break;
			case 7:
				li.traversehead();
				break;
			case 8:
				li.traversetail();
				break;
			case 9:
				cout<<"The number of nodes in the list are: "<<li.Count()<<endl;
				break;
			case 10:
				li.search();
				break;
			case 11:
				cout<<"Exited.";
				break;
			default:
				cout<<"Enter your choice from 1-11."<<endl;
				break;	
		}
	}while(choice!=11);
	return 0;
}
