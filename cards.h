#pragma once
#include <string>

using namespace std;

struct Card {
    string name = "";
    int rarity = -1; // 1:legendary to 5:free
    int type = -1; // 1:minion 2:spell 3:weapon 4:skill
    int health = -1;
    int attack = -1;
    int cost = -1;
    int minionType = -1;
    int classes = -1;
    int spellSchool = -1;
    int version = -1;
    int ability[60] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
};

class Cards
{
    public:
        Cards();
        Card cardList[100];
};

