#include<iostream>

struct Node{
	int data;
	struct Node* Next;
};

class LinkedList{
	struct Node *start;
	public:
		LinkedList(){
			start = NULL;
		}
		
		struct Node* createNode(){
			struct Node *newNode = new struct Node();
			newNode->Next = NULL;
			return newNode;
		}
		
		bool insert_at_first(int data){
			struct Node *newNode = createNode();
			if(!newNode){
				return false;
			}
			newNode->data = data;
			newNode->Next = start;
			start = newNode;
			return true;
		}
		
	    bool insert_at_end(int data){
	    	struct Node *newNode = createNode();
			if(!newNode){
				return false;
			}
	    	newNode->data= data;
	    	struct Node* temp = start;
			while(temp->Next!=NULL){
				temp=temp->Next;
			}
			temp->Next = newNode;
			return true;      	
		}
		
		int delete_at_first(){
			if (start==NULL){
				std::cout<<"The Linkedlist is empty";	
				return -1;
			}
	    	struct Node *temp = start->Next;
	    	int data=start->data;
	    	delete start;
	    	start = temp;
	    	return data;
		}
	   	
	    int delete_after_node(){
			std:: cout<<"Enter the node after you want to delete"<<std:: endl;
			int input_data;
			std:: cin>>input_data;
			struct Node* temp = start;
			while(temp->data!=input_data){
				temp=temp->Next;
			}
			if(temp==NULL){
				std:: cout<<"The data is not found"<<std::endl;
				return -1;
			}
			struct Node* targetNode= temp->Next;
			if(targetNode==NULL){
				std:: cout<<"The data is not empty"<<std::endl;
				return -1;
			}
			temp->Next = targetNode->Next;
			int deleted_data=targetNode->data;
			delete targetNode;
			return deleted_data;
		}
	
		int delete_at_last(){
			if (start==NULL){
				std::cout<<"The Linkedlist is empty";	
				return -1;
			}
			struct Node* temp = start;
			struct Node* parent =start;
			while(temp->Next!=NULL){
				parent=temp;
				temp=temp->Next;
			}
		    int data=temp ->data;
			delete temp;
			parent -> Next=NULL;
			return data;
		}
		
		bool insert_before_node(int dataInNode, int dataToInsert){
			struct Node * temp = start ;
			struct Node * parent = start ;
			while(temp->data != dataInNode){
				parent = temp ;
				temp = temp->Next ;
			}
			if(!temp){
				std::cout<<"The data is not found";
			}
			struct Node * newNode = createNode() ;
			newNode->data = dataToInsert ;
			newNode->Next = temp->Next ;
			parent->Next = newNode ;
			return true;
		}
	
		int delete_before_node(){
			if(!start){
				std::cout<<"The list is empty"<<std::endl;
				return -1;
			}
			std:: cout<<"ENter the node before which you want to delete"<<std:: endl;
			int dataInNode;
			std:: cin>>dataInNode;
			if(start->data == dataInNode){
				std::cout<<"Invalid data. There is no node before it."<<std::endl;
				return -1;
			}
			struct Node * temp = start->Next;
			struct Node * target = start;
			if(!temp){
				std::cout<<"Invalid data. Node is not found."<<std::endl;
				return -1;
			}
			if(temp->data == dataInNode){
				int data_deleted = target->data;
				delete target;
				start = temp;
				return data_deleted;
			}
			target = temp->Next;
			struct Node * target_parent = start ;
			temp= temp->Next;
			while(temp->data != dataInNode){
				target_parent = target;
				target = temp ;
				temp = temp->Next ;
			}
			if(!temp){
				std::cout<<"The data is not found";
				return -1;
			}
			int data_deleted = target->data;
			target_parent->Next = target->Next;
			delete target;
			return data_deleted;	
		}
	
		bool insert_after_node (int data){
			std:: cout<<"Enter the node after you want to instert"<<std:: endl;
			int input_data;
			std:: cin>>input_data;
			struct Node* temp = start;
			while(temp->data!=input_data){
				temp=temp->Next;
			}
			if(temp==NULL){
				std:: cout<<"The data is not found"<<std::endl;
				return false;
			}
			struct Node *newNode = createNode();
			if(!newNode){
				return false;
			}
			newNode->data = data;
			newNode->Next = temp->Next;
			temp->Next = newNode;
			return true;
		}
	
		void Display(){
			struct Node* temp = start;
			while(temp!=NULL){
				std::cout<<temp->data<<std::endl;
				temp=temp->Next;
			}
		}
	
		~LinkedList(){
			struct Node *temp = start;
			while(temp!=NULL){
				temp = temp->Next;
				delete start;
				start = temp;			
			}
		}
			
};

int main(){
	LinkedList *lst = new LinkedList();
	lst->insert_at_first(10);
	lst->insert_at_first(20);
	lst->insert_at_first(30);
	lst->insert_at_first(40);
	lst->insert_at_end(50);
	lst->Display();	
	std::cout<<"the deleted item is "<<lst->delete_at_first()<<std::endl;
	std::cout<<"the deleted item is "<<lst->delete_at_last()<<std::endl;
	lst->insert_after_node(100);
	lst->Display();	
	std::cout<<"the deleted item is "<<lst->delete_after_node()<<std::endl;
	lst->Display();
	std::cout<<"the deleted item is "<<lst->delete_before_node()<<std::endl;	
	lst->Display();	
	
	delete lst;
	return 0;
}
