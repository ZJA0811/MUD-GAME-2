#include<string>
#include<iostream>
using namespace std;
enum GAMState {
	system_menu,		//�µĹ��£��ɵĻ��䣬�⽨����������
	playing_system_menu,	//�洢���ȣ���ȡ���ȣ��뿪��Ϸ
	continue_game,		//������Ϸ����·����̸��������״̬����Ʒ������
	show_exits,			//�����ѡ��ȥ����
	talk_with_npc,		//�����ѡ���˭��̸
	attack_npc,			//�����ѡ�񹥻�˭
	watch_npc,			//�����ѡ��۲�˭
	watch_state,		//��Ҳ쿴״̬�����ܡ���Ʒ
	list_goods,			//�г���ӵ����Ʒ
	list_skills,		//�г���ӵ�еļ���
	list_quests,			//�鿴����
	use_goods,
	use_skill,
	fighting,			//ս����
	player_act,			//�ֵ�����ж�	
	list_free_item,		//�г�����ʰȡ����Ʒ
	pick_item,			//��ȡ��Ʒ
	check_equipment,	//���װ��
	unloading_equipment,			//ж��װ��
	trading,			//����
	buy_goods,
	sell_goods
};
struct Skill {
	char Name[32];//��������
	char Desc[256];//��������
	short Power;//����
	short Level;  // ���ܵȼ�
	short LevelUp;//ÿ���ȼ��ļ�����Ҫ��ϰ�Ĵ���
	//short NeedLev;//������Ҫ���ﵽ��ĵȼ�
	short NeedExp;//��Ҫ���پ�������������ּ���
	short SkillKind;//��������ǹ����ȭ
	short MpCost; //�ͷż�������ħ��ֵ
	short AddHp;//��������ֵ
	short AddMaxHp;//��������ֵ����
	short AddMaxMp;//��������ֵ����
	short AddMp;//��������ֵ
	short AddAttack;//���ӹ���
	short AddSpeed;//�����ٶ�
	short AddDefence;//���ӷ���
	short AddExp;//���Ӿ���
};
struct Quest {
	char Desc[128];	//���64�������ַ�
	short Flag;	//0-δ���ܣ�1-���ܵ�δ��ɣ�2-�Ѿ����
	short RoleIndex;   //ί����
	short MapIndex;    //ί�������ڵ�ͼ
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
	short Experience[4];//��������ǹ��ȭ
	short TalkScript;//�������Ի�ʱ�Ľű�
	short FailScript;//������ʧ��ʱ�Ľű�
	struct HaveSkill {
		short SkillIndex;//���ܱ��
		short SkillLevel;
		short Times;//ʹ�ü��ܵ�һ��������������������
	};
	short SkillNum;
	HaveSkill MySkills[10];
	short GoodsNum;
	short MyGoods[10];
	short MyEquipment[10];// ����װ����λ�á�0 - ͷ��1 - ��2 - �֣�3 - ��
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
	short Experience[4];//��������ǹ��ȭ
	short TalkScript;//�������Ի�ʱ�Ľű�
	short FailScript;//������ʧ��ʱ�Ľű�
	struct HaveSkill {
		short SkillIndex;//���ܱ��
		short SkillLevel;
		short Times;
	};
	short SkillNum;
	HaveSkill MySkill[10];
	short GoodsNum;
	short MyGoods[10];
	short MyEquipment[10];// ����װ����λ�á�0 - ͷ��1 - ��2 - �֣�3 - ��
};
struct Spot {
	char Name[24];
	char Scene[256];
	short NpcNum;
	short Npcs[10];	//���5��
	short ExitNum;	//������Ŀ
	short Exits[5];	//�����4������
	short GoodsNum;	//���Լ�Ķ���
	short Goods[10];
	short EnterScript;		//����ʱ�����Ľű�
	short LeaveScript;		//�뿪ʱ�����Ľű�
};
struct Goods {
	char Name[32];	//��Ʒ����
	char Desc[256];	//��Ʒ����
	short Use;	//��Ʒ��;���ܳԻ�ֱ����(0)����װ��(1)�����߿���ѧϰ(2)��������Ʒ(3)
	short AddAttack;	//���ӹ���
	short AddDefence;	//���ӷ���
	short AddHP;		//��������ֵ
	short AddMaxHP;
	short AddMP;//����ħ��ֵ
	short AddMaxMP;
	short AddSpeed;	//�����ٶ�
	short SkillIndex;	//�������Ӧ�ļ���
	short Location;	//����װ����λ�á�0-ͷ��1-��2-�֣�3-��
	short Cost;		//ֵ����Ǯ
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
	bool LoadQuestData(char * pstFileName, char cHeadFlag);	//װ����������
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
	void RandomDrop(short nRoleIdx, short nGoodsIdx, short nProb);//���������Ʒ
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
