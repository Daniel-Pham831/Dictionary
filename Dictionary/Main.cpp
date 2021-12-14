#include "EngViet.h"


int main()
{	
	utf16();
	EngVietDict dict;
	// nho cai dat cay AVL
	getDictFromFile(L"Eng-Viet1.txt", dict);
	wcout << L"Xong 1!" << endl;
	getDictFromFile(L"Eng-Viet2.txt", dict);
	wcout << L"Xong 2!" << endl;
	getDictFromFile(L"Eng-Viet3.txt", dict);
	wcout << L"Xong 3!" << endl;
	getDictFromFile(L"Eng-Viet4.txt", dict);
	wcout << L"Xong 4!" << endl;
	wcout << L"Nạp hoàn tất";
	wcout << L"Có tổng cộng " << dict.getTotalWord() << L" từ vựng." << endl;
	system("pause");
	wstring word;
	do {
		system("cls");
		wcout << L"Vui lòng nhập từ cần tìm: ";
		getline(wcin, word);
		wstring kqua;
		kqua = findWord(dict, word);
		show(kqua);
		system("pause");
	} while (!word.empty());


	return 0;
}