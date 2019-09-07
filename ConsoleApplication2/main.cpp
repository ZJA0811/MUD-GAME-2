#include"class.h"
#include<iostream>
#include<string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<windows.h>
#include"print.h"
#include"global.h"
using namespace std;
#ifdef _WIN32_
#define CLEAR "cls"//clear
#else
#define CLEAR "clear"
#endif
#ifdef _WIN32_
#define QUEST_COLOR		2//quest
#define SYSTEM_COLOR	15//system
#define WARNING_COLOR	12//warning
#define DESCRIPTION_COLOR	7//description
#define SKILL_NAME_COLOR	9//skill name
#define SPOT_NAME_COLOR		10//spot name
#define	NPC_NAME_COLOR		11//npc name
#define ITEM_NAME_COLOR		14//item name
#define SYSTEM_HINT_COLOR	13//system hintÏßË÷ÌáÊ¾
#else
#define QUEST_STRING "\033[0;35m%s\033[0m"    //voilet×ÏÂÞÀ¼
#define SYSTEM_STRING "\033[0;37m%s\033[0m"   //white
#define WARNING_STRING "\033[0;31m%s\033[0m"  //red
#define DESCRIPTION_STRING "\033[0;32m%s\033[0m"  //green
#define SKILL_NAME_STRING "\033[0;34m%s\033[0m"   //blue
#define SPOT_NAME_STRING "\033[0;36m%s\033[0m"    //seablue
#define NPC_NAME_STRING "\033[0;33m%s\033[0m"     //yellow
#define NICK_NAME_STRING "\033[7;36m%s\033[0m"    //seablue
#define ITEM_NAME_STRING "\033[0;32m%s\033[0m"  //green
#define SYSTEM_HINT_STRING "\033[4;37m%s\033[0m"   //white
#endif

int main() {
	Game game;
	game.LoadResFileName("res_index.txt", '#');
	game.PlayGame();
}