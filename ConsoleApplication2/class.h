#include<string>
#include<iostream>
using namespace std;
enum GAMState {
	system_menu,		//新的故事，旧的回忆，封建归隐，关于
	playing_system_menu,	//存储进度，读取进度，离开游戏
	continue_game,		//继续游戏：赶路，交谈，攻击，状态，物品，进度
	show_exits,			//让玩家选择去哪里
	talk_with_npc,		//让玩家选择和谁交谈
	attack_npc,			//让玩家选择攻击谁
	watch_npc,			//让玩家选择观察谁
	watch_state,		//玩家察看状态、技能、物品
	list_goods,			//列出所拥有物品
	list_skills,		//列出所拥有的技能
	list_quests,			//查看任务
	use_goods,
	use_skill,
	fighting,			//战斗中
	player_act,			//轮到玩家行动	
	list_free_item,		//列出可以拾取的物品
	pick_item,			//捡取物品
	check_equipment,	//检查装备
	unloading_equipment,			//卸除装备
	trading,			//交易
	buy_goods,
	sell_goods
};
struct Skill {
	char Name[32];//技能名称
	char Desc[256];//技能描述
	short Power;//威力
	short Level;  // 技能等级
	short LevelUp;//每个等级的技能需要练习的次数
	//short NeedLev;//技能需要人物到达的等级
	short NeedExp;//需要多少经验才能领悟这种技能
	short SkillKind;//刀、剑、枪棍、拳
	short MpCost; //释放技能消耗魔法值
	short AddHp;//增加生命值
	short AddMaxHp;//增加生命值上限
	short AddMaxMp;//增加内力值上限
	short AddMp;//增加内力值
	short AddAttack;//增加攻击
	short AddSpeed;//增加速度
	short AddDefence;//增加防御
	short AddExp;//增加经验
};
struct Quest {
	char Desc[128];	//最多64个中文字符
	short Flag;	//0-未接受，1-接受但未完成，2-已经完成
	short RoleIndex;   //委托者
	short MapIndex;    //委托人所在地图
};

struct Npc {
	char Name[32];
	char Nick[32];
	char Desc[256];
	short HP;
	short MaxHP;
	short MaxMP;
	short MP;
	short Attack;
	short Defend;
	short Speed;
	short Money;
	short Experience[4];//刀、剑、枪、拳
	short TalkScript;//与该人物对话时的脚本
	short FailScript;//该人物失败时的脚本
	struct HaveSkill {
		short SkillIndex;//技能编号
		short SkillLevel;
		short Times;//使用技能到一定次数，可以升级技能
	};
	short SkillNum;
	HaveSkill MySkills[10];
	short GoodsNum;
	short MyGoods[10];
	short MyEquipment[10];// 可以装备的位置。0 - 头，1 - 身，2 - 手，3 - 脚
};
struct Player {
	char Name[32];
	char Nick[32];
	char Desc[256];
	short HP;
	short MaxHp;
	short MaxMp;
	short MP;
	short Attack;
	short Defend;
	short Speed;
	short Money;
	short Experience[4];//刀、剑、枪、拳
	short TalkScript;//与该人物对话时的脚本
	short FailScript;//该人物失败时的脚本
	struct HaveSkill {
		short SkillIndex;//技能编号
		short SkillLevel;
		short Times;
	};
	short SkillNum;
	HaveSkill MySkill[10];
	short GoodsNum;
	short MyGoods[10];
	short MyEquipment[10];// 可以装备的位置。0 - 头，1 - 身，2 - 手，3 - 脚
};
struct Spot {
	char Name[24];
	char Scene[256];
	short NpcNum;
	short Npcs[10];	//最多5个
	short ExitNum;	//出口数目
	short Exits[5];	//最多有4个出口
	short GoodsNum;	//可以捡的东西
	short Goods[10];
	short EnterScript;		//进入时触发的脚本
	short LeaveScript;		//离开时触发的脚本
};
struct Goods {
	char Name[32];	//物品名称
	char Desc[256];	//物品描述
	short Use;	//物品用途：能吃或直接用(0)，能装备(1)，或者可以学习(2)，任务物品(3)
	short AddAttack;	//增加攻击
	short AddDefence;	//增加防御
	short AddHP;		//增加生命值
	short AddMaxHP;
	short AddMP;//增加魔法值
	short AddMaxMP;
	short AddSpeed;	//增加速度
	short SkillIndex;	//技能书对应的技能
	short Location;	//可以装备的位置。0-头，1-身，2-手，3-脚
	short Cost;		//值多少钱
};
struct ScriptLine {
	short ScriptIndex;
	char ScriptLine[256];
};
struct store {
	Goods goods[10];
	ScriptLine Enter;
};
class Game {
public:
	Game() {};
	~Game() {};
	void PlayGame();
	void PrintLogo();
	void PrintMap();
	void PrintMenu();
	bool ReadWholeTextFile(char * stFileName, char * stBuffer);
	bool LoadResFileName(const char* pstFileName, const char cHeadFlag);
	bool LoadSpotsData(const char * pstFileName, const char cHeadFlag);	//load spots data
	bool LoadNpcsData(char * pstFileName, char cHeadFlag);	// load npc data
	bool LoadSkillsData(const char * pstFileName, const char cHeadFlag);//load skill data
	bool LoadGoodsData(char * pstFileName, char cHeadFlag);	//load goods data
	bool LoadQuestData(char * pstFileName, char cHeadFlag);	//装载任务数据
	bool LoadScripts(char * pstFileName, char cHeadFlag);	// load scripts
	void LoadNickData(const char * pstFileName, const char cHeadFlag);
	bool LoadPlayerData(bool bNewGame);
	bool SavePlayerData();
	short NumOfGoods(short RoleIDx, short nGoodsIdx);
	short GetUserInput();
	short GetUserInput(short nMin, short nMax);
	void ShowNpcName(short nNpcIndex);
	void ShowNpcState(short nNpcIndex);
	void ShowNpcDetail(short nNpcIndex);
	void ShowNpcDetailX(short nNpcIndex);
	void ShowGoodsName(short GoodsIndex);
	void ShowGoodsDetail(short GoodsIndex);
	void ShowSpotName(short nSpotIndex);
	void ShowSpotDetail(short nSpotIndex);
	void ShowSkillName(short Skilllndex);
	void ShowSkillDetail(short Skilllndex);
	void ShowQuests(bool bCompleted);
	void ShowEquipment(short nRoleIndex, short nLocation);
	void Refresh(short nRoleIndex);
	void ReadSubString(char * stString, char * stSubString);
	short SkillDamage(short nRoleIndex, short Skilllndex);
	short SkillMpCost(short nRoleIndex, short Skilllndex);
	void InitFight(short nNpcIndex);
	void EndFight(short nNpcIndex);
	void EscapeOut(short nRoleIndex, short nEnemyIndex);
	short DecideWhoAct();
	short UseWhichSkill(short nRoleIndex);
	short Damage(short nRoleIndex, short nEnemyIndex);
	short GetExperience(short nRoleIndex, short nEnemyIndex);
	void UpdateNick(short nRoleIdx);
	void SkillLevelUp(short nRoleIndex, short Skilllndex);
	void UpdateSkillLevel(short nRoleIndex, short Skilllndex);
	void Act(short nRoleIndex, short Skilllndex, short nEnemyIndex);
	void ExecuteScriptLine(char * stScriptLine);
	bool FindScripts(short nScriptsID);
	void RunScripts(short nScriptID);
	void SystemPause();
	void SystemOut(const char * stOutString);
	void SystemHint(const char * stHintString);
	void SystemWarning(const char * stWarningString);
	bool HaveSkill(short nRoleIndex, short Skilllndex);
	bool AddSkill(short nRoleIndex, short Skilllndex);
	void AddGoodsToSpot(short nSpotIndex, short GoodsIndex);
	bool AddGoods(short nRoleIndex, short GoodsIndex, bool bVisible);
	short HaveGoods(short nRoleIndex, short GoodsIndex);
	void RemoveGoodsFromSpot(short nSpotIndex, short nGoodsLocation);
	void PickGoods(short nRoleIndex, short nGoodsLocation);
	void SellGoods(short nRoleIndex, short nGoodsLocation);
	void BuyGoods(short nRoleIndex, short GoodsIndex);
	void EatOrUse(short nRoleIndex, short GoodsIndex);
	void UnEquip(short nRoleIndex, short nLocation);
	void Equip(short nRoleIndex, short nGoodsLocation);
	void LearnSkill(short nRoleIndex, short GoodsIndex);
	void UseGoods(short nRoleIndex, short nGoodsLocation);
	bool RemoveGoods(short nRoleIndex, short nGoodsLocation, bool bVisible);
	void RandomDrop(short nRoleIdx, short nGoodsIdx, short nProb);//随机掉落物品
	void AddMoney(short nRoleIdx, short nMoney);
	bool DelMoney(short nRoleIdx, short nMoney);
	bool AddNpc(short nSpotIndex, short nNpcIndex);
	bool RemoveNpc(short nSpotIndex, short nNpcIndex);
	short GetAddedSpeed(short nRoleIndex);
	short GetAddedAttack(short nRoleIndex);
	short GetAddedDefend(short nRoleIndex);
	void PrintNpcs(short nSpotIndex);
	void PrintGoodsOfNpc(short nNpcIndex);
	struct ResFiles {
		char SkillFile[128];
		char GoodsFile[128];
		char RoleFile[128];
		char SpotFile[128];
		char QuestFile[128];
		char ScriptFile[128];
		char MapFile[128];
		char LogoFile[128];
		char NickFile[128];

	} oResFiles;
	struct CGameEnvironment {
		short nCurrentMap;			//current map index
		short nCurrentNpc;
		short nCurrentEnemy;
		short nCurrentSkill;
		short nCurrentGoods;
		short nCurrentEquipment;
		bool bFighting;
		GAMState State;			//game state

	} oGameEnv;
	struct CActSlot {
		short RoleID;
		short ActSpeed;
	} ActSlot[2];
private:
	char LogoBuffer[2048];
	char MapBuffer[1024];
	short NpcsNum;
	short SkillsNum;
	short GoodsNum;
	short QuestsNum;
	short SpotsNum;
	short ScriptsNumber;
	short ScriptLineNumber;	//script lines' number
	short CurLineIndex;		//current scripts Index
	short IndexInCurLine;
	ScriptLine * pScripts;
	Npc * pNpcs;
	Spot * pSpots;
	Skill * pSkills;
	Goods * pGoods;
	Quest *pQuests;
	bool Running;
	bool RunningScripts;
	short Var[32];
	char SkillNicks[4][16];
	char LvlNicks[5][16];
	short NickExp[5];
};
