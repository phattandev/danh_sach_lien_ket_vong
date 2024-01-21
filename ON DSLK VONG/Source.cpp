#include "Header.h"

void init(CLL& l) {
	l.head = l.tail = NULL;
}

bool isEmpty(CLL l) {
	return l.head == NULL;
}

Nodeptr makeNode(typeinfo x) {
	Nodeptr p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->link = NULL;
	return p;
}

Nodeptr findX(CLL l, typeinfo x) {
	while (l.head != NULL) {
		if (l.head->data == x)
			return l.head;
		l.head = l.head->link;
		if (l.head == l.tail->link)
			break;
	}
	return NULL;
}

//Them Dau DSLK Vong
void addFirst(CLL& l, typeinfo x) {
	Nodeptr p = makeNode(x);
	if (isEmpty(l)) {
		l.head = l.tail = p;
		l.head->link = l.head;
	}
	else {
		p->link = l.head;
		l.head = p;
		l.tail->link = p;
		/*l.tail->link = l.head;*/
	}
}

void addLast(CLL& l, typeinfo x) {
	Nodeptr p = makeNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
		l.head->link = l.head;
	}
	else {
		l.tail->link = p;
		l.tail = p;
		l.tail->link = l.head;
	}
}

//Them Cuoi DSLK Vong
void addLast(CLL& l, typeinfo x) {
	Nodeptr p = makeNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
		l.head->link = l.head;
	}
	else {
		l.tail->link = p;
		l.tail = p;
		p->link = l.head;
	}
}

//Chen sau DSLK Vong
void addAfter(CLL& l) {
	if (isEmpty(l))
		cout << "\nDanh sach rong!!!";
	else {
		typeinfo x;
		cout << "\nNhap gia tri phan tu ma ban muon chen sau no: ";
		cin >> x;
		if (findX(l, x) == NULL)
			cout << "\nKhong tim thay gia tri " << x << " trong danh sach de thuc hien chen sau : ";
		else {
			typeinfo value;
			cout << "\nNhap gia tri muon chen: ";
			cin >> value;
			Nodeptr r = findX(l, x), p = makeNode(value);
			if (r == l.tail) {
				r->link = p;
				l.tail = p;
				p->link = l.head;
			}
			else if (r == l.head) {
				p->link = r->link;
				r->link = p;
			}
			else {
				p->link = r->link;
				r->link = p;
			}
		}
	}
}

//Them Truoc DSLK Vong
void addBefore(CLL& l) {
	
	if (isEmpty(l))
		cout << "\nDanh sach rong!!!";
	else {
		typeinfo x;
		cout << "\nNhap gia tri phan tu ma ban muon them vao phia truoc no: ";
		cin >> x;
		Nodeptr r = findX(l, x);
		if (r == NULL)
			cout << "\nKhong tim thay gia tri phan tu " << x << " de tien hanh them vao truoc no. ";
		else {
			typeinfo value;
			cout << "\nNhap gia tri cua phan tu ban muon them vao truoc " << x <<":";
			cin >> value;
			if (r == l.head) {
				Nodeptr p = makeNode(value);
				p->link = l.head;
				l.head = p;
				l.tail->link = l.head;
			}
			else if (r == l.tail) {
				Nodeptr p = new Node;
				*p = *r;
				r->link = p;
				r->data = value;
				l.tail = p;
			}
			else {
				Nodeptr p = new Node;
				*p = *r;
				r->link = p;
				r->data = value;
			}
		}
	}
}

void print(CLL l) {
	while (l.head != NULL) {
		cout << l.head->data << "\t";
		l.head = l.head->link;
		if (l.head == l.tail->link)
			break;
	}
}

//Xoa dau dslk Vong
void deleteBegin(CLL& l) {
	if (isEmpty(l))
		cout << "\nDanh sach rong!!!";
	else {
		Nodeptr p = l.head;
		l.head = l.head->link;
		l.tail->link = l.head;
		delete(p);
	}
}

//Xoa Cuoi DSLK Vong
void deleteEnd(CLL& l) {
	if (isEmpty(l))
		cout << "\nDanh sach rong!!!";
	else {
		Nodeptr p, r = l.tail;
		for (p = l.head; p->link != l.tail; p = p->link);
		if (l.head == l.tail)
			l.head = l.tail = NULL;
		else {
			l.tail = p;
			p->link = l.head;
			delete(r);
		}
	}
}

//Xoa giua dslk vong
void deleteMid(CLL& l) {
	if (l.head == NULL)
		cout << "\nDanh sach rong!!!";
	else {
		typeinfo x;
		cout << "\nNhap gia tri muon xoa: ";
		cin >> x;
		Nodeptr r = findX(l, x);
		if (findX(l, x) == NULL)
			cout << "\nKhong ton tai gia tri " << x << " trong danh sach.";
		else{
			Nodeptr p;
			for (p = l.head; p->link != r; p = p->link);
			if (findX(l, x) == l.tail) {
				l.tail = p;
				p->link = l.head;
			}
			else if (findX(l, x) == l.head) {
				Nodeptr g = l.head;
				l.head = l.head->link;
				l.tail->link = l.head;
				delete(g);
			}
			else {
				p->link = r->link;
				delete(r);
			}
		}
	}
}

