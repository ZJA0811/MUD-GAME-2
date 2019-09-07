#ifndef TEXT_PARSER_
#define TEXT_PARSER_
#include<fstream>
using namespace std;
class TextParser {
private:
	ifstream ParserFile; // handle of parsered file
	short nRecordNum;		//record number
	char cRecordHead;		//record head char

public:
	TextParser(const char * stFileName, const char cHeadFlag);
	~TextParser();

	short GetRecordNum();
	bool FindRecordHead(); //find where record begin
	void ReadString(char * stString); //read a string
	void ReadInteger(short * nInt);	// read a integer
	void GotoNextLine();	//goto next line
	bool GetWholeLine(char * stString);	//get a line
	void GotoFileHead();		//goto file head
};
#endif

