#include "HashMapAVL.h"


typedef HashMapAVL EngVietDict;
void utf16();
wstring LoadText(const wchar_t* filePath);
void getDictFromFile(const wchar_t* filePath, EngVietDict& dict);
wstring findWord(EngVietDict dict, wstring source);
void show(Word data);
