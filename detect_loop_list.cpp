/*
	Function To detect  Loop in the linked list 
	Flyod's cycle finding algorith 
*/

bool linked_list::detect_loop(){
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == found)
			return true;
	}
	return false;
}