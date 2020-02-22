#include <iostream>
using namespace std;

struct node {
	int id;
	int data;
	node *next;
};

int id = 0;
node *n;
node *t = NULL;
node *h = NULL;

void add(int data) {
	if(t == NULL) {
		n = new node;
		n->data = data;
		n->id = id;
		n->next = NULL;
		id++;
		t = n;
		h = n;
	}
	else {
		n = new node;
		t->next = n;
		
		n->data = data;
		n->id = id;
		id++;
		
		n->next = NULL;
		t = n;
	}
}

void print() {
	node* c = h;
	while(c->next != NULL) {
		cout << "id: " << c->id << " " << "data: " << c->data << endl;
		c = c->next;
	}
		cout << "id: " << c->id << " " << "data: " << c->data << endl;
}

void reset_id() {
	node *c = h;
	int n_id = 0;
	
	while(c->next != NULL) {
		c->id = n_id;
		c = c->next; 
		n_id++;
	}
	c->id = n_id;
}

void del(int u_id) {
	
	node* c = h;
	node* p;
	
	if(u_id == 0) {
		if(id != 1) {
			h = h->next;
		}
		else {
			h = NULL;
			t = NULL;
			id--;
			cout<<"dupa"<<endl;
			return;
		}
		id--;
		reset_id();
		return;
	}
	
	if(u_id+1 == id) {
		while(c->id != u_id-1) {
			c = c->next;
		}
		t = c;
		t->next = NULL;
		id--;
		return;
	}

	while(c->id != u_id ) {
		if(c->id == u_id-1) {
			p = c;
		}
		c = c->next;
	}
	
	c = c->next;
	p->next = c;
	reset_id();
	id--;
}

int main() {
	int u_input;
	int u_value;
	int u_id;
	
	while(1) {
		cout << "[1] add" << endl;
		cout << "[2] del" << endl;
		
		if(t!= NULL) {
			print();
		}
		
		cin >> u_input;
		
		switch(u_input) {
			case 1:
				cout << "What vlaue do you want to add?" << endl;
				cin >> u_value;
				add(u_value);
				break;
			case 2:
				cout << "Please pass id of tha value that you want to delate " << endl;
				cin >> u_id;
				if(u_id<id) {
				del(u_id);
				}
				break;
			default:
				break;
		}
		system("cls");

		
	}
	
	return 0;
}
