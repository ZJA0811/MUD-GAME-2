#include "Text.h"
#include<iostream>
using namespace std;
TextParser::TextParser(const char * stFileName, const char cHeadFlag) {
	ParserFile.open(stFileName);
	if (!ParserFile) {
		cerr << stFileName << "open failed!" << endl;
		exit(1);
	}
	cRecordHead = cHeadFlag;
	nRecordNum = 0;
	while (FindRecordHead()) {
		++nRecordNum;
	}	
	GotoFileHead();
}

TextParser::~TextParser() {
	ParserFile.close();
}

short TextParser::GetRecordNum() {
	return nRecordNum;
}

bool TextParser::FindRecordHead() {
	char c;
	while (!ParserFile.eof()) {
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
		if (c == cRecordHead)
			return true;
	}
	return false;
}

void TextParser::ReadString(char * String) {	
	char c;
	int index = 0;
	ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));

	while ((c == ' ' || c == '\t') && !ParserFile.eof()) {
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	}
	while (c != ' ' && c != '\t' && !ParserFile.eof()) {
		String[index] = c;
		index++;
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	}
	String[index] = '\0';
}

void TextParser::ReadInteger(short * nInt) {
	char c;
	char Integer[10];
	short Index = 0;
	ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	while ((c == ' ' || c == '\t') && !ParserFile.eof()) {
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	}

	while (c != ' ' && c != '\t') {
		Integer[Index] = c;
		Index++;
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	}
	Integer[Index] = '\0';
	*nInt = atoi(Integer);//atoi是把字符串变成整数的函数
}

void TextParser::GotoNextLine() {
	char c;
	ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	while (c != '\n') {
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	}
}

bool TextParser::GetWholeLine(char * stString) {
	char c;
	if (ParserFile.eof())
		return false;
	do {
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	} while (c == '\n' && !ParserFile.eof());
	if (ParserFile.eof())
		return false;
	short nIndex = 0;
	do {
		stString[nIndex] = c;
		nIndex++;
		ParserFile.read(reinterpret_cast<char *>(&c), sizeof(c));
	} while (c != '\n' && !ParserFile.eof());
	stString[nIndex] = '\0';
	return true;
}
void TextParser::GotoFileHead() {
	ParserFile.clear();
	ParserFile.seekg(0, ios::beg);
}