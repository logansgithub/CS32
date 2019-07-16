#include "LinkedList.h"
using namespace std;
	// copy constructor
	LinkedList::LinkedList(const LinkedList& rhs)
	{
		if (rhs.head == nullptr)
		{
			this->head = nullptr;
			return;
		}
		else {
			//create a head for this
			this->head = new Node;
			//same head values
			this->head->value = rhs.head->value;
			
			//initializing node pointers for the loop
			Node* lhsNode = head;
			Node* rhsStuff = rhs.head->next;
			
			while (rhsStuff != nullptr) //get rid of ->next ?
			{
				//last node next is the new node
				lhsNode->next = new Node ;
				//advance lhs to this new Node
				lhsNode = lhsNode->next;
				//fill in lhs value
				lhsNode->value = rhsStuff->value;
				//advance the node being looked at on right
				rhsStuff = rhsStuff->next;
			}
			//end lhs copy
			lhsNode->next = nullptr;
		}
	}

	//assignment operator
	LinkedList& LinkedList::operator= (const LinkedList& rhs) { //assignment operator
		  //check if left is same as right
			if (&rhs == this)
				return *this;
			else {
				this->~LinkedList(); //delete this so we can rebuild it with the same things as rhs

				//same code as copy constructor now
				//create a head for this
				head = new Node;
				//same head values
				this->head->value = rhs.head->value;

				//initializing node pointers for the loop
				Node* lhsNode = head;
				Node* rhsStuff = rhs.head->next;
				int t = 0;

				while (rhsStuff != nullptr) //get rid of ->next ?
				{
					//last node next is the new node
					lhsNode->next = new Node;
					//advance lhs to this new Node
					lhsNode = lhsNode->next;
					//fill in lhs value
					lhsNode->value = rhsStuff->value;
					//advance the node being looked at on right
					rhsStuff = rhsStuff->next;
				}
				//end lhs copy
				lhsNode->next = nullptr;
			}
			return *this;
	}


	// Destroys all the dynamically allocated memory
	// in the list.
	LinkedList::~LinkedList() 
	{
		if (head == nullptr) {
			return;
		}
		else {
			Node* toBeDeleted;

			while (head != nullptr) //moves the old head down one item and deletes old head
			{
				toBeDeleted = head;
				head = head->next;
				delete toBeDeleted;
			}
			//delete head;
			return;
		}
	}



	// Inserts val at the front of the list
	 void LinkedList::insertToFront(const ItemType &val) 
	{
		 Node*n = new Node;
		 n->value = val;
		 n->next = head;
		 head = n;
	}

	// Prints the LinkedList
	 void LinkedList::printList() const 
	 {
		 Node* n = head;
		 while (n != nullptr)
		 {
			 cout << n->value << " ";
			 n = n->next;
		 }
		 cout << endl;
		 return;
	 }

	// Sets item to the value at position i in this
	// LinkedList and return true, returns false if 
	// there is no element i
	 bool LinkedList::get(int i, ItemType& item) const 
	 {
		 if (i > size()  || i<0) {
			 return false;
		 }
		 Node* temp;
		 temp = head;

		 for (int p=0; p < i; p++) 
		 {
			 temp = temp->next;
		 }
		item = temp->value;
		 return true;
	 }

	// Reverses the LinkedList
	 void LinkedList::reverseList()
	 {
		 if (head == nullptr || head->next == nullptr) {
			 return;
		 }
		 /*
		 Node* reversefirst;
		 Node* reverserest;

		 reversefirst = head;
		 reverserest = reversefirst->next;

		 if (reverserest == nullptr) {
			 return;
		 }
		 ////////////////DOESNT WORK////////////
		 Node* end = nullptr;
		 Node* current = head;

		 while (current != nullptr) {
			 Node* next = current;

			 current->next = end;
			 end = current;
		 }
		 head = end;
		 ///////////////////////DOESNT WORK///////////////////////
		 Node* prev;
		 Node* current;
		 Node* nextNode;

		 prev = nullptr;
		 current = head;
		 nextNode = head->next;

		 while (current != nullptr) {
			 current = nextNode;
			 nextNode = current->next;
			 current->next = prev;
			 prev = current;
		 }
		 return;*/

		 ////////////////WORKING CODE!///////////////////////
		 Node* prev;
		 Node* current;
		//save each nodes previous one and reset its next pointer to be the previous one
		 prev = nullptr; //starting at the head, we want its next to be null
		 current = this->head;

		 while (current != nullptr) {
			 Node* nextNode = current->next;
			 current->next = prev;
			 prev = current;
			 current = nextNode;
		 }
		 head = prev;
		 return;
	 }

	// Prints the LinkedList in reverse order
	 void LinkedList::printReverse() const
	 {
		 /*
		 //copy construct a new LinkedList so we can reverse it later
		 LinkedList reversedList;
		 //same code as copy constructor
		 cout << head->next << endl;
		 if (this->head == nullptr)
		 {
			 return;
		 }
		 else if (this->head->next = nullptr) {
			 cout << this->head->value << endl;
			 return;
		 }
		 else {
			 cout << head->next;
			 //create a head for the copy
			 reversedList.head = new Node;

			 //same head values
			 reversedList.head->value = this->head->value;


			 //initializing node pointers for the loop
			 Node* revSideNode = reversedList.head;
			 Node* rhsStuff = this->head->next;

			 while (rhsStuff != nullptr) //get rid of ->next ?
			 {
				 cout << "here";
				 //last node next is the new node
				 revSideNode->next = new Node;
				 //advance lhs to this new Node
				 revSideNode = revSideNode->next;
				 //fill in lhs value
				 revSideNode->value = rhsStuff->value;
				 //advance the node being looked at on right
				 rhsStuff = rhsStuff->next;
			 }
			 //end lhs copy
			 revSideNode->next = nullptr;
		 }

		 //We have now made a copy of this in reversedList
		 return;

		 //call reverseList();
		// reversedList.reverseList;
		 //call printList();
		// reversedList.printList;
		*/

		 //make an array of size m_size and fill in the members in reverse order
		 //first find size
		 int size = 1;
		 Node* checker;
		 checker = head;

		 while (checker->next != nullptr)
		 {
			 size++;
			 checker = checker->next;
		 }
		 
		 //we now have the size of the list

		 ItemType* arr;
		 arr = new ItemType[size];

		 //reset checker to head
		 checker = head;
		 
		 //fill in the array in reverse order
		 for (int p = size-1; p >= 0; p--) {
			 arr[p] = checker->value;
			 checker = checker->next;
		 }

		 //print array
		 for (int t = 0; t < size; t++) {
			 cout << arr[t] << " ";
		 }
		 cout << endl;

		 //delete array
		 delete[]arr;
	 }
	 

	// Appends the values of other onto the end of this
	// LinkedList.
	void LinkedList::append(const LinkedList &other) 
	{
		if (this->head == nullptr) {
			*this = other;
			return;
		}
		else if (&other == nullptr) {
			return;
		}
		/* SHALLOW COPY
		//find end of this
		Node* end;
		end = this->head;
		while (end->next != nullptr) {
			end = end->next;
		}
		//we now have the last node in this
		Node* stuffInOther = other.head;
		//link the end of this to the head of other
		end->next = stuffInOther;
		*/

		//DEEP COPY
		//find end of this
		Node* end;
		end = this->head;
		while (end->next != nullptr) {
			end = end->next;
		}
		//we now have the last node in this
		Node* stuffInOther = other.head;

		//make copies of stuff in other in this
		while (stuffInOther != nullptr) //get rid of ->next ?
		{
			//last node next is the new node
			end->next = new Node;
			//advance lhs to this new Node
			end = end->next;
			//fill in lhs value
			end->value = stuffInOther->value;
			//advance the node being looked at on right
			stuffInOther = stuffInOther->next;
		}
		//end lhs copy
		end->next = nullptr;


	}

	// Exchange the contents of this LinkedList with the other
	// one.
	void LinkedList::swap(LinkedList &other) 
	{
		Node *temp;

		temp = this->head;
		this->head = other.head;
		other.head = temp;
		//shallow copy just swap heads
	}

	// Returns the number of items in the Linked List.
	int LinkedList::size() const
	{
		if (head == nullptr)
		{
			return 0;
		}
		
		int s = 1;
		Node* checker;
		checker = head;
	
		while (checker->next != nullptr)
		{
			s++;
			checker = checker->next;
		}
		return s;
	}

