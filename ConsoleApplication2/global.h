#ifndef GLOBAL_H_
#define GLOBAL_H_

#ifdef _WIN32_
#include <windows.h>
#include <conio.h>
#else
#define HANDLE long
#endif

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#ifdef _WIN32_
#define QUEST_COLOR		2//quest
#define SYSTEM_COLOR	15//system
#define WARNING_COLOR	12//warning
#define DESCRIPTION_COLOR	7//description
#define SKILL_NAME_COLOR	9//skill name
#define SPOT_NAME_COLOR		10//spot name
#define	NPC_NAME_COLOR		11//npc name
#define ITEM_NAME_COLOR		14//item name
#define SYSTEM_HINT_COLOR	13//system hint线索提示
#else
#define QUEST_STRING "\033[0;35m%s\033[0m"    //voilet紫罗兰
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

#ifdef _WIN32_
#define CLEAR "cls"//clear
#else
#define CLEAR "clear"
#endif

#define MAX_SKILL_LEVEL	 5		//每项技能最高十级
#define MAX_GOODS_NUM	5
#define MAX_SKILL_NUM	5
#define MAX_NPC_NUM		5
#define MAX_EXIT_NUM	4
#define VAR_NUM 32//var
#define SKILL_KIND 4//kind
#define SKILL_LVL 5
#endif