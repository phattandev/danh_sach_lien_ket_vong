#include "Header.h"

int main() {
	CLL l;
	init(l);
	typeinfo x;
	do {
		cout << "Nhap x(-99 to stop):";
		cin >> x;
		if (x == -99)
			break;
		addLast(l, x);
	} while (true);

	cout << "\n-----Danh sach-----\n";
	print(l);

	/*cout << "\n-----Xoa dau-----\n";
	deleteBegin(l);
	cout << "Sau khi xoa: ";
	print(l);
	cout << "\n-----Xoa cuoi-----\n";
	deleteEnd(l);
	print(l);*/

	//Goi va xu ly ngoai ham main
	/*cout << "\n-----Chen giua(Chen Sau)-----";
	addAfter(l);
	cout << "\nSau khi chen: ";
	print(l);


	cout << "\n-----Chen giua(Chen Truoc)-----";
	addBefore(l);
	cout << "\nSau khi chen: ";
	print(l);*/
	


	/*cout << "\n-----Xoa x-----\n";
	deleteMid(l);
	cout << "\nSau khi xoa: ";
	print(l);*/



	return 0;
}