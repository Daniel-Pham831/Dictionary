#include "EngViet.h"



void utf16() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
}
wstring LoadText(const wchar_t* filePath) {
	//đọc cả file
	wstring text;

	FILE* fp = nullptr;
	_wfopen_s(&fp, filePath, L"r, ccs=UTF-8"); // automatically skips BOM
	wifstream ifs(fp);

	typedef std::istreambuf_iterator<wchar_t> iter_type;
	iter_type begin(ifs);
	iter_type end;

	text.assign(begin, end);

	fclose(fp);

	return text;
}
void getDictFromFile(const wchar_t* filePath, EngVietDict& dict) {
	wstring fullDict = LoadText(filePath);
	wstring tempWord;
	for (int i = 0; i < (int)fullDict.length(); i++) {
		if (fullDict[i] == '@' && tempWord.length() != 0) {
			dict.insert(tempWord);
			tempWord = L"";
			i--;
			continue;
		}
		tempWord += fullDict[i];
	}
	dict.insert(tempWord);
}
wstring findWord(EngVietDict dict, wstring source) {
	return dict.findWord(source);
}
void show(Word data) {
	if (data == L"") {
		wcout << L"Không tìm thấy dữ liệu" << endl;
	}
	else {
		wcout << L"Tìm thấy!!" << endl;
		wcout << data;
	}
}