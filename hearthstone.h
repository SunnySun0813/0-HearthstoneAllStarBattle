#pragma once

#include <QtWidgets/QWidget>
#include <string>
#include "cards.h"
#include "ui_hearthstone.h"
#include <vector>
#include <string>
#include <map>
#include <QKeyEvent>

using namespace std;

class Hearthstone : public QWidget
{
    Q_OBJECT

public:   

    // function
    int getMinionID(int tempTarget);
    void mapFunction();
    void function2539(int camp, int index, vector<int> sample, vector<int>& minion);
    void function718(int camp, int index, vector<int> sample, vector<int>& minion);
    void function139(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2139(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3939(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3952(int camp, int index, vector<int> sample, vector<int>& minion);
    void function6851(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5610(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4710(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4715(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1315(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4439(int camp, int index, vector<int> sample, vector<int>& minion);
    void function639(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3639(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5249(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5448(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4139(int camp, int index, vector<int> sample, vector<int>& minion);
    void function439(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3447(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4946(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2410(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1826(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1815(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1621(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1139(int camp, int index, vector<int> sample, vector<int>& minion);
   // void function2522(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4839(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5710(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5022(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1726(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1715(int camp, int index, vector<int> sample, vector<int>& minion);
    void function826(int camp, int index, vector<int> sample, vector<int>& minion);
    void function815(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4522(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4539(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5139(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5810(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5522(int camp, int index, vector<int> sample, vector<int>& minion);
    void function721(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1239(int camp, int index, vector<int> sample, vector<int>& minion);
    void function6426(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4610(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1022(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3539(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1021(int camp, int index, vector<int> sample, vector<int>& minion);
    void function915(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4010(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2623(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3336(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3337(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2935(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4210(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3114(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3214(int camp, int index, vector<int> sample, vector<int>& minion);
    //void function2226(int camp, int index, vector<int> sample, vector<int>& minion);
    void function526(int camp, int index, vector<int> sample, vector<int>& minion);
    void function345(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3822(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2326(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3726(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5310(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2810(int camp, int index, vector<int> sample, vector<int>& minion);
    void function4339(int camp, int index, vector<int> sample, vector<int>& minion);
    void function022(int camp, int index, vector<int> sample, vector<int>& minion);
    void function015(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2722(int camp, int index, vector<int> sample, vector<int>& minion);
    void function6000(int camp, int index, vector<int> sample, vector<int>& minion);
    void function6101(int camp, int index, vector<int> sample, vector<int>& minion);
    void function6200(int camp, int index, vector<int> sample, vector<int>& minion);
    void function3021(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1539(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1939(int camp, int index, vector<int> sample, vector<int>& minion);
    void function219(int camp, int index, vector<int> sample, vector<int>& minion);
    void function218(int camp, int index, vector<int> sample, vector<int>& minion);
    void function2010(int camp, int index, vector<int> sample, vector<int>& minion);
    void function5910(int camp, int index, vector<int> sample, vector<int>& minion);
    void function1410(int camp, int index, vector<int> sample, vector<int>& minion);
    // keyword
    void recordTime(int instruction);
    void rescue(int camp);
    void atTheEndOfTurn();
    void atTheStartOfTurn();
    void undercover(int camp);
    // method
    void getSpecficCard(int camp, int id);
    int getMinionCamp(int idNumber);
    int getMinionIndex(int idNumber);
    bool availableTarget(int camp, int index);
    bool availableAttack(int camp, int index);
    void destoryMinion(int player, int number);
    void takeHeal(int camp, int order, int heal);
    void takeMagicDamage(int camp, int order, int damage, int poi);
    void takePhysicalDamage(int camp, int order, int damage, int poi, int lif);
    void checkMinionPlayType();
    int getExtraManaCost(int order, int camp);
    void checkAbilityForCard(int id, int ability, int camp, int index);
    void checkAbility(vector<int> sample, int ability, int camp, int index, vector<int>& minion);
    void comfirmPlayCard();
    void keyPressEvent(QKeyEvent* event);
    void keyPressEventCont(int camp, int index);
    void addMinion(int minionID, int place);
    void summonMinion(vector<int> minion, int camp, int index);
    QString printHealth(vector<int> minion);
    void battle(int camp);
    int getAttack(vector<int> minion);
    void playACard(int cardID);
    void historyUpdate(string message);   
    void printLabel(int i, string size);
    void checkDie(int i);
    bool checkMinionDie(int player, int number);
    void updateWeapon(int player);
    void removeCard(int cardOrder, int camp);
    void callFunction(const string& string, int camp, int index, vector<int> sample, vector<int>& minion);
    // Enable and Disable
    void smokeDisable();
    void enterChooseOneMode(QString text0, QString text1);
    void enterThreatMode(QString text0, QString text1);
    void enterSelectMode1();
    void enterSelectMode3();
    void enterSelectMode5();
    void enterPlaceMode();
    void disableAllButton();
    void lightPlaceActive();
    void darkPlaceActive();
    void lightAttackActive();
    void darkAttackActive();
    // turn
    void startTurn();
    void drawCard(vector<int>& hand, vector<int>& deck, int camp);
    void updateManaStartTurn();
    void resetLocal();
    void resetGlobal();
    // update
    void updateEverything();
    void removeMinion();
    void updateMinion();
    void updateHero();
    void updateHandVisual(vector<int>& hand);
    void updateGameInfo();
    void updateManaVisual();
    void updateManaVisualCont(int max, int curr, int load, int loaded);
    void updateOtherVisual();
    QPixmap getColour(string colour);
    QString printAttack(vector<int> minion);
    void printButton(int i, string size, string button);
    QString printAbility(vector<int> minion);
    // thread
    Hearthstone(QWidget* parent = Q_NULLPTR);
    void initialize();
    void prepareChoose();
    void replaceCard();
    void shuffleDeck(vector<int>& deck);
    // page switch
    void hideWelcome();
    void hideChoosePage();
    void showChoosePage();
    void hidePlayground();
    void showPlayground();
    void hideQuitPage();
    void endOfGame(int i);

private slots:
    // choice
    void on_darkChoice0_clicked();
    void on_darkChoice1_clicked();
    void on_lightChoice0_clicked();
    void on_lightChoice1_clicked();
    // special button
    void on_place_clicked();
    void on_quit_clicked();
    void on_finish_clicked();
    void on_start_clicked();
    void on_done_clicked();
    void on_cancel_clicked();
    // replace cards
    void on_chooseBtn0_clicked();
    void on_chooseBtn1_clicked();
    void on_chooseBtn2_clicked();
    void on_chooseBtn3_clicked();
    void on_chooseBtn4_clicked();
    void on_chooseBtn5_clicked();
    void on_chooseBtn6_clicked();
    void on_chooseBtn0r_clicked();
    void on_chooseBtn1r_clicked();
    void on_chooseBtn2r_clicked();
    void on_chooseBtn3r_clicked();
    void on_chooseBtn4r_clicked();
    void on_chooseBtn5r_clicked();
    void on_chooseBtn6r_clicked();
    // play cards
    void on_cardBtn0_clicked();
    void on_cardBtn1_clicked();
    void on_cardBtn2_clicked();
    void on_cardBtn3_clicked();
    void on_cardBtn4_clicked();
    void on_cardBtn5_clicked();
    void on_cardBtn6_clicked();
    void on_cardBtn7_clicked();
    void on_cardBtn8_clicked();
    void on_cardBtn9_clicked();
    // place button
    void on_lightPlace0_clicked();
    void on_lightPlace1_clicked();
    void on_lightPlace2_clicked();
    void on_lightPlace3_clicked();
    void on_lightPlace4_clicked();
    void on_lightPlace5_clicked();
    void on_lightPlace6_clicked();
    void on_lightPlace7_clicked();
    void on_darkPlace0_clicked();
    void on_darkPlace1_clicked();
    void on_darkPlace2_clicked();
    void on_darkPlace3_clicked();
    void on_darkPlace4_clicked();
    void on_darkPlace5_clicked();
    void on_darkPlace6_clicked();
    void on_darkPlace7_clicked();
    // minion
    void getTarget(int order);
    void on_lightMinion0_clicked();
    void on_lightMinion1_clicked();
    void on_lightMinion2_clicked();
    void on_lightMinion3_clicked();
    void on_lightMinion4_clicked();
    void on_lightMinion5_clicked();
    void on_lightMinion6_clicked();
    void on_lightHero_clicked();
    void on_darkMinion0_clicked();
    void on_darkMinion1_clicked();
    void on_darkMinion2_clicked();
    void on_darkMinion3_clicked();
    void on_darkMinion4_clicked();
    void on_darkMinion5_clicked();
    void on_darkMinion6_clicked();
    void on_darkHero_clicked();
    void on_darkSkill_clicked();
    void on_lightSkill_clicked();
    
private:
    // Minion
    vector<vector<int>> lightMinion;
    vector<vector<int>> darkMinion;
    // play card control
    int uniqueID = 2;
    int turn; // who's turn
    int tempPlace = -1; // the place that you want to place the minion
    int tempPlayType = -1; // record the the play type of the card you play
    int tempCardOrder = -1; // record the card you play
    int tempID = -1; // record card ID
    int theTarget = -1;
    int attacker = -1; // the attacked minion
    int defencer = -1; // the minion under attacked
    int minionAttack = 1; //0: the minion is under attack 1: the minion is trying to attack 2: the minion is target
    int theChoice = -1;
    int theAttack = -1;
    int freeControl = 0;
    int start = 0;
    // global control 
    // fixed 
    
    // Setting
    int replace[7] = { 0,0,0,0,0,0,0 };
    vector<int> lightSmoke = { 0,0,0,0,0,0,0 };
    vector<int> darkSmoke = { 0,0,0,0,0,0,0 };
    vector<int> empty = {};
    Ui::HearthstoneClass ui;
    Cards cardLibrary;
    typedef void (Hearthstone::* pFunc)(int,int,vector<int>,vector<int>&);
    map<string, pFunc> functionList;
    int firstHand;
    string historyText[10];
    // horizontal: you
    // vetical: opponent
    int inFrontOfList[8][8][7] =
    { {{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{0,-1,-1,-1,-1,-1,-1},{1,-1,-1,-1,-1,-1,-1},{1,-1,-1,-1,-1,-1,-1},{2,-1,-1,-1,-1,-1,-1},{2,-1,-1,-1,-1,-1,-1},{3,-1,-1,-1,-1,-1,-1},{3,-1,-1,-1,-1,-1,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{-1,0,-1,-1,-1,-1,-1},{0,1,-1,-1,-1,-1,-1},{0,1,-1,-1,-1,-1,-1},{1,2,-1,-1,-1,-1,-1},{1,2,-1,-1,-1,-1,-1},{2,3,-1,-1,-1,-1,-1},{2,3,-1,-1,-1,-1,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{-1,0,-1,-1,-1,-1,-1},{0,1,-1,-1,-1,-1,-1},{0,1,2,-1,-1,-1,-1},{1,2,3,-1,-1,-1,-1},{1,2,3,-1,-1,-1,-1},{2,3,4,-1,-1,-1,-1},{2,3,4,-1,-1,-1,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{-1,-1,0,-1,-1,-1,-1},{-1,0,1,-1,-1,-1,-1},{-1,0,1,2,-1,-1,-1},{0,1,2,3,-1,-1,-1},{0,1,2,3,-1,-1,-1},{1,2,3,4,-1,-1,-1},{1,2,3,4,-1,-1,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{-1,-1,0,-1,-1,-1,-1},{-1,0,1,-1,-1,-1,-1},{-1,0,1,2,-1,-1,-1},{0,1,2,3,-1,-1,-1},{0,1,2,3,4,-1,-1},{1,2,3,4,5,-1,-1},{1,2,3,4,5,-1,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,0,-1,-1,-1},{-1,-1,0,1,-1,-1,-1},{-1,-1,0,1,2,-1,-1},{-1,0,1,2,3,-1,-1},{-1,0,1,2,3,4,-1},{0,1,2,3,4,5,-1},{0,1,2,3,4,5,-1}},
        {{-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,0,-1,-1,-1},{-1,-1,0,1,-1,-1,-1},{-1,-1,0,1,2,-1,-1},{-1,0,1,2,3,-1,-1},{-1,0,1,2,3,4,-1},{0,1,2,3,4,5,-1},{0,1,2,3,4,5,6}} };
    int placeList[8][7] = { {0,0,0,0,0,0,0},{0,0,0,0,0,0,1},{0,0,0,0,1,1,2},{0,0,1,1,2,2,3},
                            {0,1,2,2,3,3,4},{0,1,2,3,4,4,5},{0,1,2,3,4,5,6},{0,1,2,3,4,5,6}};
    int alignMinion[8][7] = { {-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,0,-1,-1,-1},{-1,-1,0,1,-1,-1,-1},{-1,-1,0,1,2,-1,-1}, // size position -> index
                              {-1,0,1,2,3,-1,-1}, {-1,0,1,2,3,4,-1}, {0,1,2,3,4,5,-1}, {0,1,2,3,4,5,6}};
    int alignMinionRe[8][7] = { {-1,-1,-1,-1,-1,-1,-1},{3,-1,-1,-1,-1,-1,-1},{2,3,-1,-1,-1,-1,-1},{2,3,4,-1,-1,-1,-1}, // size index -> position
                              {1,2,3,4,-1,-1,-1}, {1,2,3,4,5,-1,-1}, {0,1,2,3,4,5,-1},{0,1,2,3,4,5,6} };
    // Card
    vector<int> lightHand;
    vector<int> darkHand;
    vector<int> lightDeck;
    vector<int> darkDeck;
    int lightDeckInfo;
    int lightHandInfo;
    int darkDeckInfo;
    int darkHandInfo;
    // Mana
    int lightMaxMana = 0;
    int lightCurrMana = 0;
    int lightOverloadMana = 0;
    int lightOverloadedMana = 0;
    int darkMaxMana = 0;
    int darkCurrMana = 0;
    int darkOverloadMana = 0;
    int darkOverloadedMana = 0;
    int lightTurnMana = 0;
    int darkTurnMana = 0;
    vector<int> lightExtra = { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> darkExtra = { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> lightDynamic = { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> darkDynamic = { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> lightTurn = { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> darkTurn = { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> lightCardAtt = {};
    vector<int> darkCardAtt = {};
    vector<int> lightCardAttT = {};
    vector<int> darkCardAttT = {};
    vector<int> lightCardAttE = {};
    vector<int> darkCardAttE = {};
    int lightExtraS = 0;
    int lightDynamicS = 0;
    int darkExtraS = 0;
    int darkDynamicS = 0;
    int lightTurnS = 0;
    int darkTurnS = 0;
    // Hero
    vector<int> lightHero = { 97,0,100,100,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    vector<int> darkHero = { 98,0,100,100,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int lightEmpty = 1;
    int darkEmpty = 1;   
    int lightHaveWeapon = 0;
    int darkHaveWeapon = 0;
    vector<int> lightWeapon = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    vector<int> darkWeapon = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    vector<int> lightCemetery = {};
    vector<int> darkCemetery = {};
        
};
