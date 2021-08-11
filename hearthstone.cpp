#include "hearthstone.h"
#include <algorithm>
#include <random>
#include <stdlib.h>    
#include <time.h>

using namespace std;
/*
string number = to_string(i);
string path = "image/" + size + "/" + number + ".png";
QString convPath = QString::fromStdString(path);*/
// cardLibrary.cardList[62].name
//  checkAbility(lightMinion[attacker], 21); 
// ID 18 here 
//abilityTarget = &lightMinion[attacker];
//checkAbility(lightMinion[attacker], 18);
// historyUpdate(cardLibrary.cardList[minion[0]].name + "be the new rich king");

// working
void Hearthstone::function2539(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " cast the most powerful magic");
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            darkMinion[i][20] = 1;
            takeHeal(0, 7, 10);
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            lightMinion[i][20] = 1;
            takeHeal(1, 7, 10);
        }
    }
}
void Hearthstone::function2139(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " recored the current time point");
    recordTime(1);
}
void Hearthstone::function139(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " sent you to the past");
    recordTime(2);
}
void Hearthstone::function3939(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theTarget == -1) return;
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                takeMagicDamage(1,i,8,0);
                historyUpdate(cardLibrary.cardList[darkMinion[i][0]].name + " took damage");
                checkMinionDie(1,i);
                break;
            }
        }
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                takeHeal(0, i, 8);
                historyUpdate(cardLibrary.cardList[lightMinion[i][0]].name + " gain heal");
                break;
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                takeMagicDamage(0, i, 8, 0);
                historyUpdate(cardLibrary.cardList[lightMinion[i][0]].name + " took damage");
                checkMinionDie(0, i);
                break;
            }
        }
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                takeHeal(1, i, 8);
                historyUpdate(cardLibrary.cardList[darkMinion[i][0]].name + " gain heal");
                break;
            }
        }
    }
}
void Hearthstone::function3952(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = minion[0];
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    if (camp == 0) {
        summonMinion(newMinion, 0, 7);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " bacame the death knight");
    }
    else {
        summonMinion(newMinion, 1, 7);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " bacame the death knight");
    }
}
void Hearthstone::function6851(int camp, int index, vector<int> sample, vector<int>& minion) {
    minion[3] -= 5;
    if (minion[3] <= 1) minion[3] = 1;
    minion[2] = minion[3];
    historyUpdate(cardLibrary.cardList[minion[0]].name + " suffered a heavy blow");
}
void Hearthstone::function5610(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = 68;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    newMinion.push_back(-1);
    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    if (camp == 0) {
        lightWeapon = newMinion;
        lightHaveWeapon = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " build a weapon for you");
    }
    else {
        darkWeapon = newMinion;
        darkHaveWeapon = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " build a weapon for you");
    }
}
void Hearthstone::function4710(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        darkHero[2] = 30;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " show it's great power");
    }
    else {
        lightHero[2] = 30;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " show it's great power");
    }
}
void Hearthstone::function4715(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        takeHeal(1, 7, 20);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is in self-conflict");
    }
    else {
        takeHeal(0, 7, 20);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is in self-conflict");
    }
}
void Hearthstone::function1315(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        historyUpdate("Void Lord got a nightmare");
        darkHero[2] -= darkEmpty;
        darkEmpty++;
        checkDie(1);     
    }
    else {
        historyUpdate("Azeroth got a nightmare");
        lightHero[2] -= lightEmpty;
        lightEmpty++;
        checkDie(0);       
    }
}
void Hearthstone::function4439(int camp, int index, vector<int> sample, vector<int>& minion) {
    freeControl = 1;
    historyUpdate(cardLibrary.cardList[minion[0]].name + " control all enemys' mind");
}
void Hearthstone::function3639(int camp, int index, vector<int> sample, vector<int>& minion) {
    int valid = 0;
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][0] == 5) {
            valid = 1;
        }
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][0] == 5) {
            valid = 1;
        }
    }

    if (valid == 1) {
        historyUpdate(cardLibrary.cardList[minion[0]].name + " build the portal");
        if (camp == 0) {
            int amount = 7 - lightMinion.size();
            if (amount > 3) amount = 3;
            vector<int> minions;
            for (int i = 0; i < amount; i++) {
                for (int j = 0; j < lightDeck.size(); j++) {
                    if (cardLibrary.cardList[lightDeck[j]].type != 1) {}
                    else {
                        minions.push_back(lightDeck[j]);
                        lightDeck.erase(lightDeck.begin() + j);
                        break;
                    }
                }
            }

            for (int i = 0; i < minions.size(); i++) {
                int minionID = minions[i];
                vector<int> newMinion;
                newMinion.push_back(minionID);
                newMinion.push_back(cardLibrary.cardList[minionID].attack);
                newMinion.push_back(cardLibrary.cardList[minionID].health);
                newMinion.push_back(cardLibrary.cardList[minionID].health);
                newMinion.push_back(uniqueID);
                uniqueID++;
                if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
                else newMinion.push_back(0);

                newMinion.push_back(cardLibrary.cardList[minionID].cost);
                newMinion.push_back(-1);
                newMinion.push_back(0);
                newMinion.push_back(-1);
                for (int i = 10; i < 60; i++) {
                    newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
                }
                summonMinion(newMinion, 0, 7);
                historyUpdate(cardLibrary.cardList[minionID].name + " was summoned");
            }
        }
        else {
            int amount = 7 - darkMinion.size();
            if (amount > 3) amount = 3;
            vector<int> minions;
            for (int i = 0; i < amount; i++) {
                for (int j = 0; j < darkDeck.size(); j++) {
                    if (cardLibrary.cardList[darkDeck[j]].type != 1) {}
                    else {
                        minions.push_back(darkDeck[j]);
                        darkDeck.erase(darkDeck.begin() + j);
                        break;
                    }
                }
            }

            for (int i = 0; i < minions.size(); i++) {
                int minionID = minions[i];
                vector<int> newMinion;
                newMinion.push_back(minionID);
                newMinion.push_back(cardLibrary.cardList[minionID].attack);
                newMinion.push_back(cardLibrary.cardList[minionID].health);
                newMinion.push_back(cardLibrary.cardList[minionID].health);
                newMinion.push_back(uniqueID);
                uniqueID++;
                if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
                else newMinion.push_back(0);

                newMinion.push_back(cardLibrary.cardList[minionID].cost);
                newMinion.push_back(-1);
                newMinion.push_back(0);
                newMinion.push_back(-1);
                for (int i = 10; i < 60; i++) {
                    newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
                }
                summonMinion(newMinion, 1, 7);
                historyUpdate(cardLibrary.cardList[minionID].name + " was summoned");
            }
        }
    }
}
void Hearthstone::function5448(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        if (lightMinion[index][17] == 1 || lightMinion[index][20] == 1) return;
        getSpecficCard(0,lightMinion[index][0]);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " made new undead");
    }
    else {
        if (darkMinion[index][17] == 1 || darkMinion[index][20] == 1) return;
        getSpecficCard(1,darkMinion[index][0]);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " made new undead");
    }
}
void Hearthstone::function4139(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " summoned the power of the Burning Legion");
    if (camp == 0) {
        int damage = 0;
        for (int i = 0; i < lightHand.size(); i++) {
            damage += cardLibrary.cardList[lightHand[i]].cost + getExtraManaCost(i,0);
        }
        takeMagicDamage(1,7,damage,0);
        checkDie(1);
    }
    else {
        int damage = 0;
        for (int i = 0; i < darkHand.size(); i++) {
            damage += cardLibrary.cardList[darkHand[i]].cost + getExtraManaCost(i,1);
        }
        takeMagicDamage(0,7,damage,0);
        checkDie(0);
    }
}
void Hearthstone::function5249(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " was slienced");
    minion[1] = cardLibrary.cardList[minion[0]].attack;
    minion[3] = cardLibrary.cardList[minion[0]].health;
    if (minion[2] > minion[3]) minion[2] = minion[3];
    minion[5] = 0;
    for (int j = 10; j < 17; j++) minion[j] = 0;
    for (int j = 18; j < 20; j++) minion[j] = 0;
    for (int j = 21; j < 60; j++) minion[j] = 0;
    int theChoice = -1;
    int theAttack = -1;
    int theTarget = -1;
}
void Hearthstone::function439(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " create smoke on it's position");
    int order = getMinionIndex(minion[4]);
    if (camp == 0) {
        if (lightHand.size() == 0) {
            lightSmoke[alignMinionRe[lightMinion.size()][order]] = 1;
        }
    }
    else {
        if (darkHand.size() == 0) {
            darkSmoke[alignMinionRe[darkMinion.size()][order]] = 1;
        }
    }
    
    if (theTarget == -1) return;
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                destoryMinion(1, i);
                historyUpdate(cardLibrary.cardList[darkMinion[i][0]].name + " was assassinated");
                break;
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                destoryMinion(0, i);
                historyUpdate(cardLibrary.cardList[lightMinion[i][0]].name + " was assassinated");
                break;
            }
        }
    }
}
void Hearthstone::function3447(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = 34;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    if (camp == 0) {
        if (lightMinion.size() == 5 || lightMinion.size() == 6) {
            theAttack = lightCardAtt[index] + lightCardAttT[index] + lightCardAttE[index];
            if (theAttack < 0) theAttack = 0;
            newMinion[1] = theAttack;
            removeCard(index, 0);
            summonMinion(newMinion, 0, 7);
            historyUpdate(cardLibrary.cardList[minion[0]].name + " was summoned");
        }
    }
    else {
        if (darkMinion.size() == 5 || darkMinion.size() == 6) {
            theAttack = darkCardAtt[index] + darkCardAttT[index] + darkCardAttE[index];
            if (theAttack < 0) theAttack = 0;
            newMinion[1] = theAttack;
            removeCard(index, 1);
            summonMinion(newMinion, 1, 7); 
            historyUpdate(cardLibrary.cardList[minion[0]].name + " was summoned");
        }
    }
}
void Hearthstone::function4946(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " gain more soul");
    if (camp == 0) {
        lightCardAttE[index] += 1;
    }
    else {
        darkCardAttE[index] += 1;
    }
}
void Hearthstone::function1826(int camp, int index, vector<int> sample, vector<int>& minion) {
    int order = getMinionIndex(minion[4]);
    if (camp == 0) {
       if (lightMinion.size() == 1) {}
       else {
           historyUpdate(cardLibrary.cardList[minion[0]].name + " is protecting it's friendly forces");
           if (order == 0) {
               lightMinion[order + 1][43] += 2;
           }
           else if (order == (lightMinion.size()-1)) {
               lightMinion[order - 1][43] += 2;
           }
           else {
               lightMinion[order - 1][43] += 2;
               lightMinion[order + 1][43] += 2;
           }
       }
    }
    else {
        if (darkMinion.size() == 1) {}
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " is protecting it's friendly forces");
            if (order == 0) {
                darkMinion[order + 1][43] += 2;
            }
            else if (order == (darkMinion.size() - 1)) {
                darkMinion[order - 1][43] += 2;
            }
            else {
                darkMinion[order - 1][43] += 2;
                darkMinion[order + 1][43] += 2;
            }
        }
    }
}
void Hearthstone::function1815(int camp, int index, vector<int> sample, vector<int>& minion) {
    srand(time(NULL));
    int chance = (rand() % 100);

    if (camp == 0) {
        takeHeal(0,7,6);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Holy Light");

        if (lightCemetery.size() > 0) {
            int minionID = lightCemetery[chance % lightCemetery.size()];
            vector<int> newMinion;
            newMinion.push_back(minionID);
            newMinion.push_back(cardLibrary.cardList[minionID].attack);
            newMinion.push_back(cardLibrary.cardList[minionID].health);
            newMinion.push_back(cardLibrary.cardList[minionID].health);
            newMinion.push_back(uniqueID);
            uniqueID++;
            if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
            else newMinion.push_back(0);

            newMinion.push_back(cardLibrary.cardList[minionID].cost);
            newMinion.push_back(-1);
            newMinion.push_back(0);
            newMinion.push_back(-1);
            for (int i = 10; i < 60; i++) {
                newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
            }
            if (lightMinion.size() < 7) historyUpdate(cardLibrary.cardList[newMinion[0]].name + " was resurrected");
            summonMinion(newMinion, 0, 7);
            
        }
    }
    else {
        takeHeal(1,7,6);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Holy Light");

        if (darkCemetery.size() > 0) {
            int minionID = darkCemetery[chance % darkCemetery.size()];
            vector<int> newMinion;
            newMinion.push_back(minionID);
            newMinion.push_back(cardLibrary.cardList[minionID].attack);
            newMinion.push_back(cardLibrary.cardList[minionID].health);
            newMinion.push_back(cardLibrary.cardList[minionID].health);
            newMinion.push_back(uniqueID);
            uniqueID++;
            if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
            else newMinion.push_back(0);

            newMinion.push_back(cardLibrary.cardList[minionID].cost);
            newMinion.push_back(-1);
            newMinion.push_back(0);
            newMinion.push_back(-1);
            for (int i = 10; i < 60; i++) {
                newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
            }
            if (darkMinion.size() < 7) historyUpdate(cardLibrary.cardList[newMinion[0]].name + " was resurrected");
            summonMinion(newMinion, 1, 7);

        }
    }
}
void Hearthstone::function2410(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        for (int i = 0; i < lightHand.size(); i++) {
            lightTurn[i] -= 1;
            lightCardAttT[i] += 2;
        }
    }
    else {
        for (int i = 0; i < darkHand.size(); i++) {
            darkTurn[i] -= 1;
            darkCardAttT[i] += 2;
        }
    }
    historyUpdate(cardLibrary.cardList[minion[0]].name + " improved the morale");
}
void Hearthstone::function639(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = 67;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    if (camp == 0) {
        if (darkMinion.size() != 7) historyUpdate(cardLibrary.cardList[minion[0]].name + " block the enemy's reinforcements");
        summonMinion(newMinion, 1, 7);
        summonMinion(newMinion, 1, 7);
    }
    else {
        if (lightMinion.size() != 7) historyUpdate(cardLibrary.cardList[minion[0]].name + " block the enemy's reinforcements");
        summonMinion(newMinion, 0, 7);
        summonMinion(newMinion, 0, 7);
    }
}
// unfinished
void Hearthstone::mapFunction() {
    functionList["function2539"] = &Hearthstone::function2539;
    functionList["function718"] = &Hearthstone::function718;
    functionList["function139"] = &Hearthstone::function139;
    functionList["function2139"] = &Hearthstone::function2139;
    functionList["function3939"] = &Hearthstone::function3939;
    functionList["function3952"] = &Hearthstone::function3952;
    functionList["function6851"] = &Hearthstone::function6851;
    functionList["function5610"] = &Hearthstone::function5610;
    functionList["function4710"] = &Hearthstone::function4710;
    functionList["function4715"] = &Hearthstone::function4715;
    functionList["function1315"] = &Hearthstone::function1315;
    functionList["function4439"] = &Hearthstone::function4439;
    functionList["function639"] = &Hearthstone::function639;
    functionList["function3639"] = &Hearthstone::function3639;
    functionList["function5448"] = &Hearthstone::function5448;
    functionList["function4139"] = &Hearthstone::function4139;
    functionList["function439"] = &Hearthstone::function439;
    functionList["function5249"] = &Hearthstone::function5249;
    functionList["function3447"] = &Hearthstone::function3447;
    functionList["function4946"] = &Hearthstone::function4946;
    functionList["function2410"] = &Hearthstone::function2410;
    functionList["function1826"] = &Hearthstone::function1826;
    functionList["function1815"] = &Hearthstone::function1815;
    functionList["function1621"] = &Hearthstone::function1621;
    functionList["function1139"] = &Hearthstone::function1139;
  //  functionList["function2522"] = &Hearthstone::function2522;
    functionList["function4839"] = &Hearthstone::function4839;
    functionList["function5710"] = &Hearthstone::function5710;
    functionList["function5022"] = &Hearthstone::function5022;
    functionList["function1726"] = &Hearthstone::function1726;
    functionList["function1715"] = &Hearthstone::function1715;
    functionList["function826"] = &Hearthstone::function826;
    functionList["function815"] = &Hearthstone::function815;
    functionList["function4522"] = &Hearthstone::function4522;
    functionList["function4539"] = &Hearthstone::function4539;
    functionList["function5810"] = &Hearthstone::function5810;
    functionList["function5139"] = &Hearthstone::function5139;
    functionList["function5522"] = &Hearthstone::function5522;
    functionList["function721"] = &Hearthstone::function721;
    functionList["function1239"] = &Hearthstone::function1239;
    functionList["function6426"] = &Hearthstone::function6426;
    functionList["function4610"] = &Hearthstone::function4610;
    functionList["function1022"] = &Hearthstone::function1022;
    functionList["function3539"] = &Hearthstone::function3539;
    functionList["function1021"] = &Hearthstone::function1021;
    functionList["function915"] = &Hearthstone::function915;
    functionList["function4010"] = &Hearthstone::function4010;
    functionList["function2623"] = &Hearthstone::function2623;
    functionList["function3336"] = &Hearthstone::function3336;
    functionList["function3337"] = &Hearthstone::function3337;
    functionList["function2935"] = &Hearthstone::function2935;
    functionList["function3114"] = &Hearthstone::function3114;
    functionList["function3214"] = &Hearthstone::function3214;
    functionList["function526"] = &Hearthstone::function526;
    functionList["function345"] = &Hearthstone::function345;
    functionList["function3822"] = &Hearthstone::function3822;
    functionList["function2326"] = &Hearthstone::function2326;
    functionList["function5310"] = &Hearthstone::function5310;
    functionList["function2810"] = &Hearthstone::function2810;
    functionList["function4210"] = &Hearthstone::function4210;
    functionList["function4339"] = &Hearthstone::function4339;
    functionList["function1410"] = &Hearthstone::function1410;
    functionList["function022"] = &Hearthstone::function022;
    functionList["function6000"] = &Hearthstone::function6000;
    functionList["function6200"] = &Hearthstone::function6200;
    functionList["function6101"] = &Hearthstone::function6101;
    functionList["function3021"] = &Hearthstone::function3021;
    functionList["function219"] = &Hearthstone::function219;
    functionList["function218"] = &Hearthstone::function218;
    functionList["function1539"] = &Hearthstone::function1539;
    functionList["function1939"] = &Hearthstone::function1939;
    functionList["function2010"] = &Hearthstone::function2010;
    functionList["function5910"] = &Hearthstone::function5910;
    functionList["function2722"] = &Hearthstone::function2722;
    functionList["function015"] = &Hearthstone::function015;
    functionList["function3726"] = &Hearthstone::function3726;
    //  functionList["function2226"] = &Hearthstone::function2226;
}
void Hearthstone::checkAbility(vector<int> sample, int ability, int camp, int index, vector<int>& minion) {
    if (sample[ability] == 1) {
        string name = "function" + to_string(sample[0]) + to_string(ability);
        callFunction(name, camp, index, sample, minion);
    }
}
void Hearthstone::checkAbilityForCard(int id, int ability, int camp, int index) {
    if (cardLibrary.cardList[id].ability[ability] == 1) {
        string name = "function" + to_string(id) + to_string(ability);
        empty.push_back(id);
        callFunction(name, camp, index, empty, empty);
        empty.erase(empty.begin());
    }
}
// Card Function
void Hearthstone::function6000(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (turn == 0) {
        if (lightMaxMana < 10) {
            lightMaxMana++;
            lightTurnMana++;
        }
        if (lightCurrMana < 10) lightCurrMana++;
    }
    else {
        if (darkMaxMana < 10) {
            darkMaxMana++;
            darkTurnMana++;
        }
        if (darkCurrMana < 10) darkCurrMana++;
    }
    historyUpdate("Used Lucky Coin");
}
void Hearthstone::function6101(int camp, int index, vector<int> sample, vector<int>& minion) { 
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                darkMinion[i][24] -= darkMinion[i][1];
                historyUpdate("Void Lord used " + cardLibrary.cardList[61].name + " on " + cardLibrary.cardList[darkMinion[i][0]].name);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                lightMinion[i][24] -= lightMinion[i][1];
                historyUpdate("Void Lord used " + cardLibrary.cardList[61].name + " on " + cardLibrary.cardList[lightMinion[i][0]].name);
                break;
            }
        }
    }
}
void Hearthstone::function6200(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        takeMagicDamage(1, 7, darkHand.size(), 0);
        historyUpdate("Azeroth used " + cardLibrary.cardList[62].name);
        checkDie(1);
    }
    else {
        takeMagicDamage(0, 7, lightHand.size(), 0);
        historyUpdate("Void Lord used " + cardLibrary.cardList[62].name);
        checkDie(0);
    }
}
void Hearthstone::function5710(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theTarget == -1) return;
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                for (int j = 0; j <= 3; j++) minion[j] = darkMinion[i][j];
                for (int j = 6; j < 60; j++) minion[j] = darkMinion[i][j];
                if (darkMinion[i][11] == 1) minion[5] = 1;
                darkMinion[i][20] = 1;
                historyUpdate(cardLibrary.cardList[minion[0]].name + " become the new rich king");
                theChoice = -1;
                theTarget = -1;
                checkAbility(minion, 10, 0, -1, minion);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                for (int j = 0; j <= 3; j++) minion[j] = lightMinion[i][j];
                for (int j = 6; j < 60; j++) minion[j] = lightMinion[i][j];
                if (lightMinion[i][11] == 1) minion[5] = 1;
                lightMinion[i][20] = 1;
                historyUpdate(cardLibrary.cardList[minion[0]].name + "be the new rich king");
                theChoice = -1;
                theTarget = -1;
                checkAbility(minion, 10, 1, -1, minion);
                break;
            }
        }
    }

    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][40] == 1 && lightMinion.size() < 7) {
                vector<int> minion = darkMinion[i];
                summonMinion(minion, 0, 7);
                darkMinion[i][20] = 1;
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][40] == 1 && darkMinion.size() < 7) {
                vector<int> minion = lightMinion[i];
                historyUpdate(cardLibrary.cardList[lightMinion[i][0]].name + " is rebell");
            }
        }
    }
}
void Hearthstone::function4210(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " absorbed the energy from the solar well");
    if (camp == 0) {
        int value = lightCurrMana;
        lightCurrMana = 0;
        minion[1] += (value + value);
    }
    else {
        int value = darkCurrMana;
        darkCurrMana = 0;
        minion[1] += (value + value);
    }
}
void Hearthstone::function5310(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " destoryed everthing");

    while (lightHand.size() > 0) lightHand.erase(lightHand.begin());
    while (darkHand.size() > 0) darkHand.erase(darkHand.begin());
    lightExtra = { 0,0,0,0,0,0,0,0,0,0 };
    darkExtra = { 0,0,0,0,0,0,0,0,0,0 };
    lightTurn = { 0,0,0,0,0,0,0,0,0,0 };
    darkTurn = { 0,0,0,0,0,0,0,0,0,0 };
    lightCardAtt = {};
    darkCardAtt = {};
    lightCardAttT = {};
    darkCardAttT = {};
    lightCardAttE = {};
    darkCardAttE = {};

    for (int i = 0; i < lightMinion.size(); i++) destoryMinion(0, i);
    for (int i = 0; i < darkMinion.size(); i++) destoryMinion(1, i);
}
void Hearthstone::function2810(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " is actually helping you");
    if (camp == 0) {
        historyUpdate("Void Lord draw an additional card");
        drawCard(darkHand, darkDeck,1);
        historyUpdate("Void Lord draw an additional card");
        drawCard(darkHand, darkDeck,1);
    }
    else {
        historyUpdate("Azeroth draw an additional card");
        drawCard(lightHand, lightDeck,0);
        historyUpdate("Azeroth draw an additional card");
        drawCard(lightHand, lightDeck,0);
    }
}
void Hearthstone::function4010(int camp, int index, vector<int> sample, vector<int>& minion) {
    static int j = 1;
    static int k = 3;
    if (camp == 0) {
        historyUpdate(cardLibrary.cardList[minion[0]].name + " disturbed Void Lord mind");
        for (int i = 0; i < darkHand.size(); i++) {
            srand(time(NULL));
            int newCost = ((rand() + j) * k) % 11;
            k++; j++;
            darkExtra[i] = newCost - cardLibrary.cardList[darkHand[i]].cost;
        }
    }
    else {
        historyUpdate(cardLibrary.cardList[minion[0]].name + " disturbed Azeroth's mind");
        for (int i = 0; i < lightHand.size(); i++) {
            srand(time(NULL));
            int newCost = ((rand() + j) * k) % 11;
            k++; j++;
            lightExtra[i] = newCost - cardLibrary.cardList[lightHand[i]].cost;
        }
    }
}
void Hearthstone::function1410(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " make a unequal deal with your opponent");
    if (lightHand.size() == 0 || darkHand.size() == 0) {}
    else {
        if (camp == 0) {
            int lightMax = -1;
            int darkMin = 999;
            int j = -1;
            int k = -1;
            for (int i = 0; i < lightHand.size(); i++) {
                if ((cardLibrary.cardList[lightHand[i]].cost + lightExtra[i]) > lightMax)
                {
                    lightMax = (cardLibrary.cardList[lightHand[i]].cost + lightExtra[i]);
                    j = i;
                }
            }
            for (int i = 0; i < darkHand.size(); i++) {
                if ((cardLibrary.cardList[darkHand[i]].cost + darkExtra[i]) < darkMin)
                {
                    darkMin = (cardLibrary.cardList[darkHand[i]].cost + darkExtra[i]);
                    k = i;
                }
            }

            lightExtra[j] = darkMin - cardLibrary.cardList[lightHand[j]].cost;
            darkExtra[k] = lightMax - cardLibrary.cardList[darkHand[k]].cost;
        }
        else {
            int darkMax = -1;
            int lightMin = 999;
            int j = -1;
            int k = -1;
            for (int i = 0; i < darkHand.size(); i++) {
                if ((cardLibrary.cardList[darkHand[i]].cost + darkExtra[i]) > darkMax)
                {
                    darkMax = (cardLibrary.cardList[darkHand[i]].cost + darkExtra[i]);
                    j = i;
                }
            }
            for (int i = 0; i < lightHand.size(); i++) {
                if ((cardLibrary.cardList[lightHand[i]].cost + lightExtra[i]) < lightMin) {
                    lightMin = (cardLibrary.cardList[lightHand[i]].cost + lightExtra[i]);
                    k = i;
                }
            }

            darkExtra[j] = lightMin - cardLibrary.cardList[darkHand[j]].cost;
            lightExtra[k] = darkMax - cardLibrary.cardList[lightHand[k]].cost;
        }
    }
}
void Hearthstone::function5910(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        if (darkHand.size() <= 0) {}
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " steal something from your opponent");
            srand(time(NULL));
            int target = rand() % darkHand.size();
            int card = darkHand[target];
            removeCard(target, 1);
            if (lightHand.size() < 10) {
                historyUpdate("Azeroth steal the card of " + cardLibrary.cardList[card].name);
                getSpecficCard(0, card);
            }
        }
    }
    else {
        if (lightHand.size() <= 0) {}
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " steal something from your opponent");
            srand(time(NULL));
            int target = rand() % lightHand.size();
            int card = lightHand[target];
            removeCard(target, 0);
            if (darkHand.size() < 10) {
                historyUpdate("Void Lord steal the card of " + cardLibrary.cardList[card].name);
                getSpecficCard(1, card);
            }
        }
    }
}
void Hearthstone::function1539(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " foresee everything");
    if (camp == 0) {
            historyUpdate("Azeroth draw an additional card");
            drawCard(lightHand, lightDeck, 0);
            historyUpdate("Azeroth Lord draw an additional card");
            drawCard(lightHand, lightDeck, 0);
            for (int i = 0; i < lightHand.size(); i++) {
                lightTurn[i] -= 1;
            }
    }
    else {
            historyUpdate("Void Lord draw an additional card");
            drawCard(darkHand, darkDeck, 1);
            historyUpdate("Void Lord draw an additional card");
            drawCard(darkHand, darkDeck, 1);
            for (int i = 0; i < darkHand.size(); i++) {
                darkTurn[i] -= 1;
            }
    }
}
void Hearthstone::function2010(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " recover the vitality");
    if (camp == 0) {
        int i = lightMaxMana - lightHand.size();
        while (i > 0) {
            i--;
            historyUpdate("Azeroth draw an additional card");
            drawCard(lightHand, lightDeck,0);
        }
    }
    else {
        int i = darkMaxMana - darkHand.size();
        while (i > 0) {
            i--;
            historyUpdate("Void Lord draw an additional card");
            drawCard(darkHand, darkDeck,1);
        }
    }
}
void Hearthstone::function4610(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theTarget == -1) return;
    else {
        vector<int> theMinion;
        if (camp == 0) {
            for (int i = 0; i < darkMinion.size(); i++) {
                if (darkMinion[i][4] == theTarget) {
                    theMinion = darkMinion[i];
                    darkMinion[i][20] = 1;
                    break;
                }
            }

            if (theMinion.empty()) return;

            minion[3] += theMinion[2];
            minion[2] = minion[3];
            minion[1] += theMinion[1];
            historyUpdate(cardLibrary.cardList[minion[0]].name + " ate " + cardLibrary.cardList[theMinion[0]].name);
        }
        else {
            for (int i = 0; i < lightMinion.size(); i++) {
                if (lightMinion[i][4] == theTarget) {
                    theMinion = lightMinion[i];
                    lightMinion[i][20] = 1;
                    break;
                }
            }

            if (theMinion.empty()) return;

            minion[3] += theMinion[2];
            minion[2] = minion[3];
            minion[1] += theMinion[1];
            historyUpdate(cardLibrary.cardList[minion[0]].name + " ate " + cardLibrary.cardList[theMinion[0]].name);
        }
    }
}
void Hearthstone::function5810(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theChoice == -1) return;
    
    srand(time(NULL));
    if (camp == 0) {
        historyUpdate("Void Lord made the choice");
        if (theChoice == 0) {
            historyUpdate("Azeroth draw an additional card");
            drawCard(lightHand, lightDeck,0);
            historyUpdate("Azeroth Lord draw an additional card");
            drawCard(lightHand, lightDeck,0);
        }
        else {
            if (darkHand.size() >= 1) {
                int value = rand() % darkHand.size();
                historyUpdate("Void Lord discard " + cardLibrary.cardList[darkHand[value]].name);
                removeCard(value, 1);
                if (darkHand.size() >= 1) {
                    value = rand() % darkHand.size();
                    historyUpdate("Void Lord discard " + cardLibrary.cardList[darkHand[value]].name);
                    removeCard(value, 1);
                }
            }
        }
    }
    else {
        historyUpdate("Azeroth made the choice");
        if (theChoice == 0) {
            historyUpdate("Void Lord draw an additional card");
            drawCard(darkHand, darkDeck,1);
            historyUpdate("Void Lord draw an additional card");
            drawCard(darkHand, darkDeck,1);
        }
        else {
            if (lightHand.size() >= 1) {
                int value = rand() % lightHand.size();
                historyUpdate("Azeroth discard " + cardLibrary.cardList[lightHand[value]].name);
                removeCard(value, 0);
                if (lightHand.size() >= 1) {
                    value = rand() % lightHand.size();
                    historyUpdate("Azeroth discard " + cardLibrary.cardList[lightHand[value]].name);
                    removeCard(value, 0);
                }
            }
        }
    }
}
void Hearthstone::function1939(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " cast star fall");
    srand(time(NULL));
    if (camp == 0) {
        for (int i = 0; i < 20; i++) {

            int target = rand() % (darkMinion.size() + 1);
            if (target == darkMinion.size()) {
                if (darkHero[2] > 0) takeMagicDamage(1, 7, 1, 0);
                else checkDie(1);
            }
            else {
                if (darkMinion[target][2] > 0 && darkMinion[target][20] != 1) takeMagicDamage(1, target, 1, 0);
                else i--;
            }
        }

        int j = 0;
        while (j < darkMinion.size()) {
            if (checkMinionDie(1, j)) {
                historyUpdate("Azeroth draw an additional card");
                drawCard(lightHand, lightDeck,0);
            }
            j++;
        }
    }
    else {
        for (int i = 0; i < 20; i++) {

            int target = rand() % (lightMinion.size() + 1);

            if (target == lightMinion.size()) {
                if (lightHero[2] > 0) takeMagicDamage(0, 7, 1, 0);
                else checkDie(0);
            }
            else {
                if (lightMinion[target][2] > 0 && lightMinion[target][20] != 1)  takeMagicDamage(0, target, 1, 0);
                else i--;
            }
        }

        int j = 0;
        while (j < lightMinion.size()) {
            if (checkMinionDie(0, j)) {
                historyUpdate("Void Lord draw an additional card");
                drawCard(darkHand, darkDeck,1);
            }
            j++;
        }
    }
}
void Hearthstone::function3539(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = 65;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    int health = 1;
    int attack = 1;
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][3] > health) health = lightMinion[i][3];
        if (lightMinion[i][1] > attack) attack = lightMinion[i][1];
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][3] > health) health = darkMinion[i][3];
        if (darkMinion[i][1] > attack) attack = darkMinion[i][1];
    }
    newMinion[1] = attack;
    newMinion[3] = health;
    newMinion[2] = newMinion[3];

    summonMinion(newMinion, getMinionCamp(minion[4]), getMinionIndex(minion[4]));
}
void Hearthstone::function1239(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = 64;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    summonMinion(newMinion, getMinionCamp(minion[4]), getMinionIndex(minion[4]));
}
void Hearthstone::function5139(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theChoice == -1) return;
    
    if (camp == 0) {
        historyUpdate("Void Lord made the choice");
        if (theChoice == 0) {
            for (int i = 0; i < darkMinion.size(); i++) {
                takeMagicDamage(1, i, 8, 0);
            }
            int j = 0;
            while (j < darkMinion.size()) {
                if (checkMinionDie(1, j)) {}
                j++;
            }
        }
        else {
            takeMagicDamage(1, 7, 20, 0);
            checkDie(1);
        }
    }
    else {
        historyUpdate("Azeroth made the choice");
        if (theChoice == 0) {
            for (int i = 0; i < lightMinion.size(); i++) {
                takeMagicDamage(0, i, 8, 0);
            }
            int j = 0;
            while (j < lightMinion.size()) {
                if (checkMinionDie(0, j)) {}
                j++;
            }
        }
        else {
            takeMagicDamage(0, 7, 20, 0);
            checkDie(0);
        }
    }
}
void Hearthstone::function4539(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theTarget == -1) return;
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                darkMinion[i][40] = 1;
                historyUpdate(cardLibrary.cardList[darkMinion[i][0]].name + "got the Damnation");
                break;
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                lightMinion[i][40] = 1;
                historyUpdate(cardLibrary.cardList[lightMinion[i][0]].name + "got the Damnation");
                break;
            }
        }
    }  
}
void Hearthstone::function1139(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theChoice == -1) return;

    if (camp == 0) {
        historyUpdate("Azeroth made the choice");
        if (theChoice == 1) {
            takeHeal(0, 7, 20);
        }
        else {
            for (int i = 0; i < lightMinion.size(); i++) {
                takeHeal(0, i, lightMinion[i][3] - lightMinion[i][2]);
            }
        }
    }
    else {
        historyUpdate("Void Lord made the choice");
        if (theChoice == 1) {
            takeHeal(1, 7, 20);
        }
        else {
            for (int i = 0; i < darkMinion.size(); i++) {
                takeHeal(1, i, darkMinion[i][3] - darkMinion[i][2]);
            }
        }
    }
}
void Hearthstone::function4339(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (theTarget == -1) return;
    historyUpdate(cardLibrary.cardList[minion[0]].name + " cast lightning attack");

    int parity = -999;
    if (camp == 0) {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][4] == theTarget) {
                parity = lightMinion[i][2] % 2;
                break;
            }
        }
        if (parity == -999) return;

        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][2] % 2 != parity) takeMagicDamage(1, i, 6, 0);
        }
        if (darkHero[2] % 2 != parity) takeMagicDamage(1, 7, 6, 0);

        checkDie(1);
        int j = 0;
        while (j < darkMinion.size()) {
            if (checkMinionDie(1, j)) {}
            j++;
        }
    }
    else {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][4] == theTarget) {
                parity = darkMinion[i][2] % 2;
                break;
            }
        }
        if (parity == -999) return;

        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][2] % 2 != parity) takeMagicDamage(0, i, 6, 0);
        }
        if (lightHero[2] % 2 != parity) takeMagicDamage(0, 7, 6, 0);

        checkDie(0);
        int j = 0;
        while (j < lightMinion.size()) {
            if (checkMinionDie(0, j)) {}
            j++;
        }
    }
}
void Hearthstone::function4839(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            darkMinion[i][13] = 2;
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            lightMinion[i][13] = 2;
        }
    }

    historyUpdate(cardLibrary.cardList[minion[0]].name + " gave out a cold breath");
}
void Hearthstone::function3114(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        if (darkMinion.size() == 7) return;
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " is annoying you");
            vector<int> tempMinion = lightMinion[index];
            lightMinion[index][20] = 1;
            darkMinion.push_back(tempMinion);
        }
    }
    else {
        if (lightMinion.size() == 7) return;
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " is annoying you");
            vector<int> tempMinion = darkMinion[index];
            darkMinion[index][20] = 1;
            lightMinion.push_back(tempMinion);
        }
    }
}
void Hearthstone::function3214(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " cast flame storm but absorbed your magic");
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) takeMagicDamage(1, i, 4, 0);
        takeMagicDamage(1, 7, 4, 0);

        checkDie(1);
        int j = 0;
        while (j < darkMinion.size()) {
            if (checkMinionDie(1, j)) {}
            j++;
        }

        if (lightCurrMana <= 1) lightCurrMana = 0;
        else lightCurrMana -= 1;
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) takeMagicDamage(0, i, 4, 0);
        takeMagicDamage(0, 7, 4, 0);

        checkDie(0);
        int j = 0;
        while (j < lightMinion.size()) {
            if (checkMinionDie(0, j)) {}
            j++;
        }

        if (darkCurrMana <= 1) darkCurrMana = 0;
        else darkCurrMana -= 1;
    }
}
void Hearthstone::function1715(int camp, int index, vector<int> sample, vector<int>& minion) {
    int minionID = 66;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(cardLibrary.cardList[minionID].attack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    if (camp == 0) {
        int spell = 1;

        int minionIndex = -1;

        if (darkMinion.size() >= 1) {
            for (int i = 0; i < darkMinion.size(); i++) {
                if (darkMinion[i][1] + darkMinion[i][2] >= 16) {
                    minionIndex = i;
                    spell = 3;
                    break;
                }
            }
        }
        if (darkMinion.size() >= 6) spell = 2;
        if (darkHero.size() <= 4) spell = 1;

        if (spell == 1) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast tidal surge");
            takeMagicDamage(1, 7, 4, 0);
            takeHeal(0, 7, 4);
            checkDie(1);
        }
        else if (spell == 2) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast lightning storm ");

            for (int i = 0; i < darkMinion.size(); i++) {
                takeMagicDamage(1, i, 3, 0);
            }
            int j = 0;
            while (j < darkMinion.size()) {
                if (checkMinionDie(1, j)) {}
                j++;
            }

            lightOverloadMana += 2;
            lightCurrMana -= 2;
            if (lightCurrMana < 0) lightCurrMana = 0;
        }
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast hex on " + cardLibrary.cardList[darkMinion[minionIndex][0]].name);
            darkMinion[minionIndex] = newMinion;
        }
    }
    else {
        int spell = 1;

        int minionIndex = -1;

        if (lightMinion.size() >= 1) {
            for (int i = 0; i < lightMinion.size(); i++) {
                if (lightMinion[i][1] + lightMinion[i][2] >= 16) {
                    minionIndex = i;
                    spell = 3;
                    break;
                }
            }
        }
        if (lightMinion.size() >= 6) spell = 2;
        if (lightHero.size() <= 4) spell = 1;

        if (spell == 1) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast tidal surge");
            takeMagicDamage(0, 7, 4, 0);
            takeHeal(1, 7, 4);
            checkDie(0);
        }
        else if (spell == 2) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast lightning storm ");

            for (int i = 0; i < lightMinion.size(); i++) {
                takeMagicDamage(0, i, 3, 0);
            }
            int j = 0;
            while (j < lightMinion.size()) {
                if (checkMinionDie(0, j)) {}
                j++;
            }

            darkOverloadMana += 2;
            darkCurrMana -= 2;
            if (darkCurrMana < 0) darkCurrMana = 0;
        }
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast hex on " + cardLibrary.cardList[lightMinion[minionIndex][0]].name);
            lightMinion[minionIndex] = newMinion;
        }
    }
}
void Hearthstone::function015(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        if (index != 0) {
            minion[1] += getAttack(lightMinion[index - 1]);
            lightMinion[index - 1][1] = 0;
            historyUpdate(cardLibrary.cardList[minion[0]].name + " steal attack from " + cardLibrary.cardList[lightMinion[index - 1][0]].name);
        }
    }
    else {
        if (index != 0) {
            minion[1] += getAttack(darkMinion[index - 1]);
            darkMinion[index - 1][1] = 0;
            historyUpdate(cardLibrary.cardList[minion[0]].name + " steal attack from " + cardLibrary.cardList[darkMinion[index - 1][0]].name);
        }
    }
}
void Hearthstone::function915(int camp, int index, vector<int> sample, vector<int>& minion) {
    srand(time(NULL));
    int chance = (rand() % 100);
    if (camp == 0) {
        if (chance % 2 == 0 && darkHand.size() > 0) {
            darkHand[chance % (darkHand.size())] = 63;
            darkCardAtt[chance % (darkHand.size())] = 1;
            darkExtra[chance % (darkHand.size())] = 0;
            darkCardAttE[chance % (darkHand.size())] = 0;
            historyUpdate("Someone was turned into a sheep");
        }
    }
    else {
        if (chance % 2 == 0 && lightHand.size() > 0) {
            lightHand[chance % (lightHand.size())] = 63;
            lightCardAtt[chance % (lightHand.size())] = 1;
            lightCardAttE[chance % (lightHand.size())] = 0;
            lightExtra[chance % (lightHand.size())] = 0;
            historyUpdate("Someone was turned into a sheep");
        }
    }
}
void Hearthstone::function815(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        int spell = 1;

        if (lightHand.size() <= 3) spell = 3;
        if (darkMinion.size() >= 5) spell = 2;
        if (darkHero.size() <= 6) spell = 1;

        if (spell == 1) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast fire ball");
            takeMagicDamage(1, 7, 6, 0);
            checkDie(1);
        }
        else if (spell == 2) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast frost nova");
            for (int i = 0; i < darkMinion.size(); i++) darkMinion[i][12] = 2;
        }
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast fire ball");
            historyUpdate("Azeroth draw an additional card");
            drawCard(lightHand, lightDeck,0);
            historyUpdate("Azeroth Lord draw an additional card");
            drawCard(lightHand, lightDeck,0);
        }
    }
    else {
        int spell = 1;

        if (darkHand.size() <= 3) spell = 3;
        if (lightMinion.size() >= 5) spell = 2;
        if (lightHero.size() <= 6) spell = 1;

        if (spell == 1) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast fire ball");
            takeMagicDamage(0, 7, 6, 0);
            checkDie(0);
        }
        else if (spell == 2) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast frost nova");
            for (int i = 0; i < lightMinion.size(); i++) lightMinion[i][12] = 1;
        }
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast fire ball");
            historyUpdate("Azeroth draw an additional card");
            drawCard(darkHand, darkDeck,1);
            historyUpdate("Azeroth Lord draw an additional card");
            drawCard(darkHand, darkDeck,1);
        }
    }
}
void Hearthstone::function718(int camp, int index, vector<int> sample, vector<int>& minion) {
    minion[5] = 1;
    historyUpdate(cardLibrary.cardList[minion[0]].name + " chase the enemys");
}
void Hearthstone::function218(int camp, int index, vector<int> sample, vector<int>& minion) {
    minion[5] = 1;
    historyUpdate(cardLibrary.cardList[minion[0]].name + " chase the enemys");
}
void Hearthstone::function219(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (minion[2] != minion[3]) {
        minion[1] *= 2;
        minion[19] = 0;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is frenzy");
    }
}
void Hearthstone::function1621(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (minion[42] == 0) return;

    if (minion[42] == 1) {
        minion[42] = 2;

        minion[1] -= 3;
        minion[3] -= 3;
        if (minion[1] < 0) minion[1] = 0;
        if (minion[3] < 0) minion[3] = 0;
        if (minion[2] > minion[3]) minion[2] = minion[3];
        minion[30] = 1;

        historyUpdate(cardLibrary.cardList[minion[0]].name + " become a human form");
    }
    else {
        minion[42] = 1;
        minion[1] += 3;
        minion[2] += 3;
        minion[3] += 3;

        historyUpdate(cardLibrary.cardList[minion[0]].name + " become a werewolf form");
    }
}
void Hearthstone::function3021(int camp, int index, vector<int> sample, vector<int>& minion) {
    srand(time(NULL));
    int chance = rand() % 100;
    if (chance % 2 == 1) {
        minion[5] = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " get another chance to attack");
    }
}
void Hearthstone::function1021(int camp, int index, vector<int> sample, vector<int>& minion) {
    srand(time(NULL));
    int chance = (rand() % 100);
    if (camp == 0) {
        if (chance % 2 == 0) {
            minion[8] = getAttack(minion);
            historyUpdate(cardLibrary.cardList[minion[0]].name + " deal critical damage");
            int minionID = minion[0];
            vector<int> newMinion;
            for (int i = 0; i < minion.size(); i++)
                newMinion.push_back(minion[i]);
            newMinion[8] = 0;
            newMinion[4] = uniqueID;
            uniqueID++;
            summonMinion(newMinion, getMinionCamp(minion[4]), getMinionIndex(minion[4]));
        }
    }
    else {
        if (chance % 2 == 0) {
            minion[8] = getAttack(minion);
            historyUpdate(cardLibrary.cardList[minion[0]].name + " deal critical damage");
            int minionID = minion[0];
            vector<int> newMinion;
            for (int i = 0; i < minion.size(); i++)
                newMinion.push_back(minion[i]);
            newMinion[8] = 0;
            newMinion[4] = uniqueID;
            uniqueID++;
            summonMinion(newMinion, getMinionCamp(minion[4]), getMinionIndex(minion[4]));
        }
    }
}
void Hearthstone::function721(int camp, int index, vector<int> sample, vector<int>& minion) {
    int additional = (minion[3] - minion[2]) * 3;
    minion[8] += additional;
    historyUpdate(cardLibrary.cardList[minion[0]].name + " made a hellish roar");
}

void Hearthstone::function5022(int camp, int index, vector<int> sample, vector<int>& minion) {
    srand(time(NULL));
    int chance = (rand() % 99);
    if (camp == 0) {
        if (chance % 3 == 0) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Fear Sha");
            for (int i = 0; i < darkMinion.size(); i++) {
                darkMinion[i][1] -= 3;
                if (darkMinion[i][1] < 0) darkMinion[i][1] = 0;
            }
        }
        else if (chance % 3 == 1) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Despair Sha");
            for (int i = 0; i < darkMinion.size(); i++) {
                darkMinion[i][3] = darkMinion[i][2];
            }
        }
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Doubt Sha");
            for (int i = 0; i < darkMinion.size(); i++) {
                int min = darkMinion[i][1];
                if (darkMinion[i][2] < darkMinion[i][1]) min = darkMinion[i][2];
                darkMinion[i][1] = min;
                darkMinion[i][2] = min;
            }

            int j = 0;
            while (j < darkMinion.size()) {
                if (checkMinionDie(1, j)) {} j++;
            }
        }
    }
    else {
        if (chance % 3 == 0) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Fear Sha");
            for (int i = 0; i < lightMinion.size(); i++) {
                lightMinion[i][1] -= 3;
                if (lightMinion[i][1] < 0) lightMinion[i][1] = 0;
            }
        }
        else if (chance % 3 == 1) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Despair Sha");
            for (int i = 0; i < lightMinion.size(); i++) {
                lightMinion[i][3] = lightMinion[i][2];
            }
        }
        else {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast Doubt Sha");
            for (int i = 0; i < lightMinion.size(); i++) {
                int min = lightMinion[i][1];
                if (lightMinion[i][2] < lightMinion[i][1]) min = lightMinion[i][2];
                lightMinion[i][1] = min;
                lightMinion[i][2] = min;
            }

            int j = 0;
            while (j < lightMinion.size()) {
                if (checkMinionDie(0, j)) {} j++;
            }
        }
    }
}
void Hearthstone::function4522(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][40] == 1 && lightMinion.size() < 7) {
                vector<int> minion = darkMinion[i];
                summonMinion(minion, 0, 7);
                darkMinion[i][20] = 1;
                historyUpdate(cardLibrary.cardList[darkMinion[i][0]].name + " is rebell");
            }
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][40] == 1 && darkMinion.size() < 7) {
                vector<int> minion = lightMinion[i];
                summonMinion(minion, 1, 7);
                lightMinion[i][20] = 1;
                historyUpdate(cardLibrary.cardList[lightMinion[i][0]].name + " is rebell");
            }
        }
    }
}
void Hearthstone::function1022(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " cast blade storm");
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            takeMagicDamage(1, i, getAttack(minion), 0);
        }      

        int j = 0;
        while (j < darkMinion.size()) {
            if (checkMinionDie(1, j)) {}
            j++;
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            takeMagicDamage(0, i, getAttack(minion), 0);
        }

        int j = 0;
        while (j < lightMinion.size()) {
            if (checkMinionDie(0, j)) {}
            j++;
        }
    }
}
void Hearthstone::function022(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        takeMagicDamage(0, 7, getAttack(minion)*3, 0);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is betray his lord");
        checkDie(0);
    }
    else {
        takeMagicDamage(1, 7, getAttack(minion)*3, 0);
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is betray his lord");
        checkDie(1);
    }
}
void Hearthstone::function2722(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        for (int i = 0; i < lightMinion.size(); i++) {
            lightMinion[i][1] += 3;
            lightMinion[i][2] += 3;
            lightMinion[i][3] += 3;
        }
    }
    else {
        for (int i = 0; i < darkMinion.size(); i++) {
            darkMinion[i][1] += 3;
            darkMinion[i][2] += 3;
            darkMinion[i][3] += 3;
        }
    }
    historyUpdate(cardLibrary.cardList[minion[0]].name + "'s sacrifice improve morale");
}
void Hearthstone::function3822(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " blew itself up ");
    if (camp == 0) {
        for (int i = 0; i < darkMinion.size(); i++) {
            takeMagicDamage(1, i, darkMinion[i][3] / 2, 0);
        }

        int j = 0;
        while (j < darkMinion.size()) {
            if (checkMinionDie(1, j)){}j++;
        }
    }
    else {
        for (int i = 0; i < lightMinion.size(); i++) {
            takeMagicDamage(0, i, lightMinion[i][3] / 2, 0);
        }

        int j = 0;
        while (j < lightMinion.size()) {
            if (checkMinionDie(0, j)){}j++;
        }
    }
}
void Hearthstone::function5522(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " wailed");
    for (int i = 0; i < lightMinion.size(); i++) {
        lightMinion[i][1] = cardLibrary.cardList[lightMinion[i][0]].attack;
        lightMinion[i][3] = cardLibrary.cardList[lightMinion[i][0]].health;
        if (lightMinion[i][2] > lightMinion[i][3]) lightMinion[i][2] = lightMinion[i][3];
        for (int j = 10; j < 17; j++) lightMinion[i][j] = 0;
        for (int j = 18; j < 20; j++) lightMinion[i][j] = 0;
        for (int j = 21; j < 60; j++) lightMinion[i][j] = 0;
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        darkMinion[i][1] = cardLibrary.cardList[darkMinion[i][0]].attack;
        darkMinion[i][3] = cardLibrary.cardList[darkMinion[i][0]].health;
        if (darkMinion[i][2] > darkMinion[i][3]) darkMinion[i][2] = darkMinion[i][3];
        for (int j = 10; j < 17; j++) darkMinion[i][j] = 0;
        for (int j = 18; j < 20; j++) darkMinion[i][j] = 0;
        for (int j = 21; j < 60; j++) darkMinion[i][j] = 0;
    }
    for (int i = 0; i < lightMinion.size(); i++) {
        takeMagicDamage(0, i, 4, 0);
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        takeMagicDamage(1, i, 4, 0);
    }

    int j = 0;
    while (j < lightMinion.size()) {
        if (checkMinionDie(0, j)) {}
        j++;
    }
    j = 0;
    while (j < darkMinion.size()) {
        if (checkMinionDie(1, j)) {}
        j++;
    }
}
void Hearthstone::function2623(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + " lose the will to fight");
    minion[1] -= 3;
    if (minion[1] < 0) minion[1] = 0;
}
void Hearthstone::function2326(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        int id = inFrontOfList[lightMinion.size()][darkMinion.size()][index];
        if (id != -1) {
            darkMinion[id][8] -= (darkMinion[id][1] + darkMinion[id][24]);
            historyUpdate(cardLibrary.cardList[minion[0]].name + " is disabling " + cardLibrary.cardList[darkMinion[id][0]].name);
        }
    }
    else {
        int id = inFrontOfList[darkMinion.size()][lightMinion.size()][index];
        if (id != -1) {
            lightMinion[id][8] -= (lightMinion[id][1] + lightMinion[id][24]);
            historyUpdate(cardLibrary.cardList[minion[0]].name + " is disabling " + cardLibrary.cardList[lightMinion[id][0]].name);
        }
    }
}
void Hearthstone::function1726(int camp, int index, vector<int> sample, vector<int>& minion) {
    int valid = 0;
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][0] == 8) {
            valid = 1;
        }

    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][0] == 8) {
            valid = 1;
        }

    }

    if (valid == 1) minion[32] = 1;
}
void Hearthstone::function826(int camp, int index, vector<int> sample, vector<int>& minion) {
    int valid = 0;
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][0] == 17) {
            historyUpdate(cardLibrary.cardList[minion[0]].name + " has a bond with " + cardLibrary.cardList[lightMinion[i][0]].name);
            valid = 1;
        }
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][0] == 17) {
            valid = 1;     
            historyUpdate(cardLibrary.cardList[minion[0]].name + " has a bond with " + cardLibrary.cardList[darkMinion[i][0]].name);
        }
    }

    if (valid == 1) {
        minion[32] = 1;     
    }
}
void Hearthstone::function3726(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) historyUpdate(cardLibrary.cardList[minion[0]].name + " break Azeroth's dominance");
    else historyUpdate(cardLibrary.cardList[minion[0]].name + " break Void Lord's dominance");

    if (camp == 0) {
        lightDynamicS += 5;
    }
    else {
        darkDynamicS += 5;
    }
}
void Hearthstone::function345(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        int total = 0;
        int maxTotal = 0;
        for (int i = 0; i < lightMinion.size(); i++) {
            total += lightMinion[i][2];
            maxTotal += lightMinion[i][3];
        }

        if (total <= 10 && total != maxTotal) {
            for (int i = 0; i < lightMinion.size(); i++) {
                takeHeal(0, i, 3);
            }
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast super holy nova");
            function345(camp, index, sample, minion);
        }
    }
    else {
        int total = 0;
        int maxTotal = 0;
        for (int i = 0; i < darkMinion.size(); i++) {
            total += darkMinion[i][2];
            maxTotal += darkMinion[i][3];
        }

        if (total <= 10 && total != maxTotal) {
            for (int i = 0; i < darkMinion.size(); i++) {
                takeHeal(1, i, 3);
            }
            historyUpdate(cardLibrary.cardList[minion[0]].name + " cast super holy nova");
            function345(camp, index, sample, minion);
        }
    }
}
void Hearthstone::function526(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        lightHero[31] = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is protecting Azeroth");
    }
    else {
        darkHero[31] = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is protecting Void Lord");
    }
}
void Hearthstone::function6426(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        for (int i = 0; i < lightMinion.size(); i++) {
            lightMinion[i][8] += 1;
        }
    }
    else {
        for (int i = 0; i < darkMinion.size(); i++) {
            darkMinion[i][8] += 1;
        }
    }
}
void Hearthstone::function2935(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        historyUpdate(cardLibrary.cardList[minion[0]].name + " rescued Azeroth");
        takeHeal(0, 7, 30);
    }
    else {
        historyUpdate(cardLibrary.cardList[minion[0]].name + " rescued Void Lord");
        takeHeal(1, 7, 30);
    }  
}
void Hearthstone::function3336(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (minion[2] <= 0) {
        minion[2] = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is still alive");
    }
}
void Hearthstone::function3337(int camp, int index, vector<int> sample, vector<int>& minion) {
    historyUpdate(cardLibrary.cardList[minion[0]].name + "'s vital was hitted");
    destoryMinion(camp, index);
}

// keyword
void Hearthstone::recordTime(int instruction) {
    static vector<int> lightHand1; static vector<int> darkHand1; static vector<int> lightDeck1; static vector<int> darkDeck1; static vector<vector<int>> lightMinion1;
    static vector<vector<int>> darkMinion1; static vector<int> lightSmoke1; static vector<int> darkSmoke1; static int lightDeckInfo1; static int lightHandInfo1;
    static int darkDeckInfo1; static int darkHandInfo1; static int lightMaxMana1; static int lightCurrMana1; static int lightOverloadMana1; static int lightOverloadedMana1;
    static int darkMaxMana1; static int darkCurrMana1; static int darkOverloadMana1; static int darkOverloadedMana1; static int lightTurnMana1;
    static int darkTurnMana1; static vector<int> lightExtra1; static vector<int> darkExtra1; static vector<int> lightDynamic1; static vector<int> darkDynamic1;
    static vector<int> lightTurn1; static vector<int> darkTurn1; static vector<int> lightCardAtt1; static vector<int> darkCardAtt1; static vector<int> lightCardAttT1;
    static vector<int> darkCardAttT1; static vector<int> lightCardAttE1; static vector<int> darkCardAttE1; static int lightExtraS1; static int lightDynamicS1;
    static int darkExtraS1; static int darkDynamicS1; static int lightTurnS1; static int darkTurnS1; static vector<int> lightHero1; static vector<int> darkHero1;
    static int lightEmpty1; static int darkEmpty1; static int lightHaveWeapon1; static int darkHaveWeapon1; static vector<int> lightWeapon1;
    static vector<int> darkWeapon1; static vector<int> lightCemetery1; static vector<int> darkCemetery1;
    static int available = 0;
    if (instruction == 1) {
        lightHand1 = lightHand;   darkHand1 = darkHand;   lightDeck1 = lightDeck;   darkDeck1 = darkDeck; lightMinion1 = lightMinion;
        darkMinion1 = darkMinion;   lightSmoke1 = lightSmoke;   darkSmoke1 = darkSmoke;   lightDeckInfo1 = lightDeckInfo;   lightHandInfo1 = lightHandInfo;
        darkDeckInfo1 = darkDeckInfo;   darkHandInfo1 = darkHandInfo;   lightMaxMana1 = lightMaxMana;   lightCurrMana1 = lightCurrMana; lightOverloadMana1 = lightOverloadMana;
        lightOverloadedMana1 = lightOverloadedMana;
        darkMaxMana1 = darkMaxMana;   darkCurrMana1 = darkCurrMana;   darkOverloadMana1 = darkOverloadMana;   darkOverloadedMana1 = darkOverloadedMana; lightTurnMana1 = lightTurnMana;
        darkTurnMana1 = darkTurnMana;   lightExtra1 = lightExtra;   darkExtra1 = darkExtra;   lightDynamic1 = lightDynamic;   darkDynamic1 = darkDynamic;
        lightTurn1 = lightTurn;   darkTurn1 = darkTurn;   lightCardAtt1 = lightCardAtt;   darkCardAtt1 = darkCardAtt;   lightCardAttT1 = lightCardAttT;
        darkCardAttT1 = darkCardAttT;   lightCardAttE1 = lightCardAttE;   darkCardAttE1 = darkCardAttE;   lightExtraS1 = lightExtraS;   lightDynamicS1 = lightDynamicS;
        darkExtraS1 = darkExtraS;   darkDynamicS1 = darkDynamicS;   lightTurnS1 = lightTurnS;   darkTurnS1 = darkTurnS;   lightHero1 = lightHero;   darkHero1 = darkHero;
        lightEmpty1 = lightEmpty;   darkEmpty1 = darkEmpty;   lightHaveWeapon1 = lightHaveWeapon;   darkHaveWeapon1 = darkHaveWeapon;   lightWeapon1 = lightWeapon;
        darkWeapon1 = darkWeapon;   lightCemetery1 = lightCemetery;   darkCemetery1 = darkCemetery; available = 1;
    }
    else {
        if (available == 0) return;
        lightHand = lightHand1;   darkHand = darkHand1;   lightDeck = lightDeck1;   darkDeck = darkDeck1; lightMinion = lightMinion1;
        darkMinion = darkMinion1;   lightSmoke = lightSmoke1;   darkSmoke = darkSmoke1;   lightDeckInfo = lightDeckInfo1;   lightHandInfo = lightHandInfo1;
        darkDeckInfo = darkDeckInfo1;   darkHandInfo = darkHandInfo1;   lightMaxMana = lightMaxMana1;   lightCurrMana = lightCurrMana1; lightOverloadMana = lightOverloadMana1;
        lightOverloadedMana = lightOverloadedMana1;
        darkMaxMana = darkMaxMana1;   darkCurrMana = darkCurrMana1;   darkOverloadMana = darkOverloadMana1;   darkOverloadedMana = darkOverloadedMana1; lightTurnMana = lightTurnMana1;
        darkTurnMana = darkTurnMana1;   lightExtra = lightExtra1;   darkExtra = darkExtra1;   lightDynamic = lightDynamic1;   darkDynamic = darkDynamic1;
        lightTurn = lightTurn1;   darkTurn = darkTurn1;   lightCardAtt = lightCardAtt1;   darkCardAtt = darkCardAtt1;   lightCardAttT = lightCardAttT1;
        darkCardAttT = darkCardAttT1;   lightCardAttE = lightCardAttE1;   darkCardAttE = darkCardAttE1;   lightExtraS = lightExtraS1;   lightDynamicS = lightDynamicS1;
        darkExtraS = darkExtraS1;   darkDynamicS = darkDynamicS1;   lightTurnS = lightTurnS1;   darkTurnS = darkTurnS1;   lightHero = lightHero1;   darkHero = darkHero1;
        lightEmpty = lightEmpty1;   darkEmpty = darkEmpty1;   lightHaveWeapon = lightHaveWeapon1;   darkHaveWeapon = darkHaveWeapon1;   lightWeapon = lightWeapon1;
        darkWeapon = darkWeapon1;   lightCemetery = lightCemetery1;   darkCemetery = darkCemetery1;

        for (int i = lightDeck.size() - 1; i >= 0; i--) if (lightDeck[i] == 1) lightDeck.erase(lightDeck.begin() + i);
        for (int i = darkDeck.size() - 1; i >= 0; i--) if (darkDeck[i] == 1) darkDeck.erase(darkDeck.begin() + i);
        for (int i = lightMinion.size() - 1; i >= 0; i--) if (lightMinion[i][0] == 1) lightMinion[i][20] = 1;
        for (int i = darkMinion.size() - 1; i >= 0; i--) if (darkMinion[i][0] == 1) darkMinion[i][20] = 1;
        for (int i = lightHand.size() - 1; i >= 0; i--) if (lightHand[i] == 1) removeCard(i, 0);
        for (int i = darkHand.size() - 1; i >= 0; i--) if (darkHand[i] == 1) removeCard(i, 1);
    }
}
void Hearthstone::atTheEndOfTurn() { // ID 15 here
    if (turn == 0) {
        for (int i = 0; i < lightMinion.size(); i++) {
            checkAbility(lightMinion[i], 15, 0, i, lightMinion[i]);
        }
    }
    else {
        for (int i = 0; i < darkMinion.size(); i++) {
            checkAbility(darkMinion[i], 15, 1, i, darkMinion[i]);
        }
    }
}
void Hearthstone::atTheStartOfTurn() { // ID 14 here
    if (turn == 0) {
        for (int i = 0; i < lightMinion.size(); i++) {
            checkAbility(lightMinion[i], 14, 0, i, lightMinion[i]);
        }
    }
    else {
        for (int i = 0; i < darkMinion.size(); i++) {
            checkAbility(darkMinion[i], 14, 1, i, darkMinion[i]);
        }
    }
}
void Hearthstone::undercover(int camp) {
    int minionID = tempID;
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(theAttack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);
    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    }

    if (camp == 0) {
        if (darkMinion.size() == 7) addMinion(tempID, 7);
        else {
            // ID 49 here
            for (int i = 0; i < lightMinion.size(); i++) checkAbility(lightMinion[i], 49, 0, i, newMinion);
            checkAbility(newMinion, 10, 1, -1, newMinion); // ID 10 here
            darkMinion.push_back(newMinion);
            checkAbility(newMinion, 39, 1, -1, newMinion); // ID 39 here
            historyUpdate(cardLibrary.cardList[newMinion[0]].name + " is undercover now");
        }
    }
    else {
        if (lightMinion.size() == 7) addMinion(tempID, 7);
        else {
            // ID 49 here
            for (int i = 0; i < darkMinion.size(); i++) checkAbility(darkMinion[i], 49, 1, i, newMinion);
            checkAbility(newMinion, 10, 0, -1, newMinion); // ID 10 here
            lightMinion.push_back(newMinion);
            checkAbility(newMinion, 39, 0, -1, newMinion); // ID 39 here
            historyUpdate(cardLibrary.cardList[newMinion[0]].name + " is undercover now");
        }
    }
}
void Hearthstone::rescue(int camp) { // ID 35 here
    if (camp == 0) {
        for (int i = 0; i < lightMinion.size(); i++) {
            checkAbility(lightMinion[i], 35, 0, i, lightMinion[i]);
        }
    }
    else {
        for (int i = 0; i < darkMinion.size(); i++) {
            checkAbility(darkMinion[i], 35, 1, i, darkMinion[i]);
        }
    }
}
// method
void Hearthstone::comfirmPlayCard() {
    if (turn == 0) {
        lightCurrMana -= (cardLibrary.cardList[tempID].cost + getExtraManaCost(tempCardOrder,0));
        if (cardLibrary.cardList[tempID].type == 1) {
            theAttack = lightCardAtt[tempCardOrder] + lightCardAttT[tempCardOrder] + lightCardAttE[tempCardOrder];
            if (theAttack < 0) theAttack = 0;
        }
        removeCard(tempCardOrder, 0);
        if (cardLibrary.cardList[tempID].type == 2 || cardLibrary.cardList[tempID].type == 4) {
            string name = "function" + to_string(tempID) + "0" + to_string(tempPlayType);   
            callFunction(name, 0, -1, empty, empty);
        }
        else if (cardLibrary.cardList[tempID].type == 1) {

            if (tempPlayType == 7) {
                undercover(0);
            }
            else {
                addMinion(tempID, tempPlace);
            }
        }
        else if (cardLibrary.cardList[tempID].type == 3) {
            for (int i = 0; i < 60; i++) lightWeapon[i] = cardLibrary.cardList[tempID].ability[i];
            lightHaveWeapon = 1;
            historyUpdate("Equip " + cardLibrary.cardList[tempID].name);
            // ID 39 here
            // ID 10 here
        }
        else {}        
    }
    else {
        darkCurrMana -= (cardLibrary.cardList[tempID].cost + getExtraManaCost(tempCardOrder,1));
        if (cardLibrary.cardList[tempID].type == 1) {
            theAttack = darkCardAtt[tempCardOrder] + darkCardAttT[tempCardOrder] + darkCardAttE[tempCardOrder];
            if (theAttack < 0) theAttack = 0;
        }
        removeCard(tempCardOrder, 1);
        if (cardLibrary.cardList[tempID].type == 2 || cardLibrary.cardList[tempID].type == 4) {
            string name = "function" + to_string(tempID) + "0" + to_string(tempPlayType);
            callFunction(name, 1, -1, empty, empty);
        }
        else if (cardLibrary.cardList[tempID].type == 1) {
            if (tempPlayType == 7) {
                undercover(1);
            }
            else {
                addMinion(tempID, tempPlace);
            }
        }
        else if (cardLibrary.cardList[tempID].type == 3) {
            for (int i = 0; i < 60; i++) darkWeapon[i] = cardLibrary.cardList[tempID].ability[i];
            darkHaveWeapon = 1;
            historyUpdate("Equip " + cardLibrary.cardList[tempID].name);
            // ID 39 here
            // ID 10 here
        }
        else {}
       
    }

    updateEverything();   
}
int Hearthstone::getMinionCamp(int idNumber) {
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][4] == idNumber) return 0;
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][4] == idNumber) return 1;
    }
    return -1;
}
int Hearthstone::getMinionIndex(int idNumber) {
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][4] == idNumber) return i;
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][4] == idNumber) return i;
    }
    return -1;
}
int Hearthstone::getMinionID(int tempTarget) {
    if (tempTarget == 7) return 7;
    else if (tempTarget == 15) return 7;
    else if (tempTarget == 0) return alignMinion[lightMinion.size()][0];
    else if (tempTarget == 1) return alignMinion[lightMinion.size()][1];
    else if (tempTarget == 2) return alignMinion[lightMinion.size()][2];
    else if (tempTarget == 3) return alignMinion[lightMinion.size()][3];
    else if (tempTarget == 4) return alignMinion[lightMinion.size()][4];
    else if (tempTarget == 5) return alignMinion[lightMinion.size()][5];
    else if (tempTarget == 6) return alignMinion[lightMinion.size()][6];
    else if (tempTarget == 8) return alignMinion[darkMinion.size()][0];
    else if (tempTarget == 9) return alignMinion[darkMinion.size()][1];
    else if (tempTarget == 10) return alignMinion[darkMinion.size()][2];
    else if (tempTarget == 11) return alignMinion[darkMinion.size()][3];
    else if (tempTarget == 12) return alignMinion[darkMinion.size()][4];
    else if (tempTarget == 13) return alignMinion[darkMinion.size()][5];
    else if (tempTarget == 14) return alignMinion[darkMinion.size()][6];
    else return 7; // impossible to happen
}
void Hearthstone::keyPressEventCont(int camp, int index) {
    if (camp == 0) {
        printLabel(lightHand[index], "240x341");
        string cost = to_string(cardLibrary.cardList[lightHand[index]].cost + getExtraManaCost(index,0));
        QString convCost = QString::fromStdString(cost);
        ui.cardMana->setText(convCost);
        ui.cardMana->setVisible(true);
        ui.cardSkill->setVisible(false);

        if (cardLibrary.cardList[lightHand[index]].type == 2) {
            ui.cardAttack->setVisible(false);
            ui.cardHealth->setVisible(false);
        }
        else {
            string health = to_string(cardLibrary.cardList[lightHand[index]].health);
            QString convHealth = QString::fromStdString(health);
            ui.cardHealth->setText(convHealth);
            ui.cardHealth->setVisible(true);

            int attackV = lightCardAtt[index] + lightCardAttT[index] + lightCardAttE[index];
            if (attackV < 0) attackV = 0;
            string attack = to_string(attackV);
            QString convAttack = QString::fromStdString(attack);
            ui.cardAttack->setText(convAttack);
            ui.cardAttack->setVisible(true);       
        }
    }
    else {
        printLabel(darkHand[index], "240x341");
        string cost = to_string(cardLibrary.cardList[darkHand[index]].cost + getExtraManaCost(index,1));
        QString convCost = QString::fromStdString(cost);
        ui.cardMana->setText(convCost);
        ui.cardMana->setVisible(true);

        if (cardLibrary.cardList[darkHand[index]].type == 2) {
            ui.cardAttack->setVisible(false);
            ui.cardHealth->setVisible(false);
        }
        else {
            string health = to_string(cardLibrary.cardList[darkHand[index]].health);
            QString convHealth = QString::fromStdString(health);
            ui.cardHealth->setText(convHealth);
            ui.cardHealth->setVisible(true);

            int attackV = darkCardAtt[index] + darkCardAttT[index] + darkCardAttE[index];
            if (attackV < 0) attackV = 0;
            string attack = to_string(attackV);
            QString convAttack = QString::fromStdString(attack);
            ui.cardAttack->setText(convAttack);
            ui.cardAttack->setVisible(true);
        }
    }
}
void Hearthstone::getSpecficCard(int camp, int id) {
    if (camp == 0) {
        if (lightHand.size() < 10) {
            lightCardAtt.push_back(cardLibrary.cardList[id].attack);
            lightCardAttE.push_back(0);
            lightCardAttT.push_back(0);
            lightHand.push_back(id);
        }
        else
            historyUpdate("Azeroth's hand is full!");
            
    }
    else {
        if (darkHand.size() < 10) {
            darkCardAtt.push_back(cardLibrary.cardList[id].attack);
            darkCardAttE.push_back(0);
            darkCardAttT.push_back(0);
            darkHand.push_back(id);
        }
        else
            historyUpdate("Void Lord's hand is full!");
    }
}

void Hearthstone::keyPressEvent(QKeyEvent* event)
{
    if (start == 0) return;
    if (event->key() == Qt::Key_1)
    {
        if (turn == 0 && lightHand.size() >= 1) {
            keyPressEventCont(0, 0);
        }
        else if (turn == 1 && darkHand.size() >= 1) {
            keyPressEventCont(1, 0);
        }
    }
    else if (event->key() == Qt::Key_2)
    {
        if (turn == 0 && lightHand.size() >= 2) {
            keyPressEventCont(0, 1);
        }
        else if (turn == 1 && darkHand.size() >= 2) {
            keyPressEventCont(1, 1);
        }
    }
    else if (event->key() == Qt::Key_3)
    {
        if (turn == 0 && lightHand.size() >= 3) {
            keyPressEventCont(0, 2);
        }
        else if (turn == 1 && darkHand.size() >= 3) {
            keyPressEventCont(1, 2);
        }
    }
    else if (event->key() == Qt::Key_4)
    {
        if (turn == 0 && lightHand.size() >= 4) {
            keyPressEventCont(0, 3);
        }
        else if (turn == 1 && darkHand.size() >= 4) {
            keyPressEventCont(1, 3);
        }
    }
    else if (event->key() == Qt::Key_5)
    {
        if (turn == 0 && lightHand.size() >= 5) {
            keyPressEventCont(0, 4);
        }
        else if (turn == 1 && darkHand.size() >= 5) {
            keyPressEventCont(1, 4);
        }
    }
    else if (event->key() == Qt::Key_6)
    {
        if (turn == 0 && lightHand.size() >= 6) {
            keyPressEventCont(0, 5);
        }
        else if (turn == 1 && darkHand.size() >= 6) {
            keyPressEventCont(1, 5);
        }
    }
    else if (event->key() == Qt::Key_7)
    {
        if (turn == 0 && lightHand.size() >= 7) {
            keyPressEventCont(0, 6);
        }
        else if (turn == 1 && darkHand.size() >= 7) {
            keyPressEventCont(1, 6);
        }
    }
    else if (event->key() == Qt::Key_8)
    {
        if (turn == 0 && lightHand.size() >= 8) {
            keyPressEventCont(0, 7);
        }
        else if (turn == 1 && darkHand.size() >= 8) {
            keyPressEventCont(1, 7);
        }
    }
    else if (event->key() == Qt::Key_9)
    {
        if (turn == 0 && lightHand.size() >= 9) {
            keyPressEventCont(0, 8);
        }
        else if (turn == 1 && darkHand.size() >= 9) {
            keyPressEventCont(1, 8);
        }
    }
    else if (event->key() == Qt::Key_0)
    {
        if (turn == 0 && lightHand.size() >= 10) {
            keyPressEventCont(0, 9);
        }
        else if (turn == 1 && darkHand.size() >= 10) {
            keyPressEventCont(1, 9);
        }
    }
    else if (event->key() == Qt::Key_Q) {
        if (alignMinion[darkMinion.size()][0] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][0]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_W) {
        if (alignMinion[darkMinion.size()][1] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][1]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_E) {
        if (alignMinion[darkMinion.size()][2] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][2]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_R) {
        if (alignMinion[darkMinion.size()][3] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][3]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_T) {
        if (alignMinion[darkMinion.size()][4] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][4]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_Y) {
        if (alignMinion[darkMinion.size()][5] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][5]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_U) {
        if (alignMinion[darkMinion.size()][6] != -1) printLabel(darkMinion[alignMinion[darkMinion.size()][6]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_A) {
        if (alignMinion[lightMinion.size()][0] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][0]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_S) {
        if (alignMinion[lightMinion.size()][1] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][1]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_D) {
        if (alignMinion[lightMinion.size()][2] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][2]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_F) {
        if (alignMinion[lightMinion.size()][3] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][3]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_G) {
        if (alignMinion[lightMinion.size()][4] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][4]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_H) {
        if (alignMinion[lightMinion.size()][5] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][5]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_J) {
        if (alignMinion[lightMinion.size()][6] != -1) printLabel(lightMinion[alignMinion[lightMinion.size()][6]][0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_I) {
        if (darkHaveWeapon == 1) printLabel(darkWeapon[0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_O) {
        printLabel(62, "240x341");
        if (turn == 1) {
            string message = to_string(cardLibrary.cardList[62].cost + getExtraManaCost(10,1));
            QString convMessage = QString::fromStdString(message);
            ui.cardSkill->setText(convMessage);
            ui.cardSkill->setVisible(true);
            ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false);
        }  
        else {
            ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
        }
    }
    else if (event->key() == Qt::Key_K) {
        if (lightHaveWeapon == 1) printLabel(lightWeapon[0], "240x341");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    }
    else if (event->key() == Qt::Key_L) {
        printLabel(61, "240x341");
        if (turn == 0) {
            string message = to_string(cardLibrary.cardList[61].cost + getExtraManaCost(10,0));
            QString convMessage = QString::fromStdString(message);
            ui.cardSkill->setText(convMessage);
            ui.cardSkill->setVisible(true);
            ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false);
        } 
        else {
            ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
        }
    }
}
void Hearthstone::destoryMinion(int player, int number) {
    if (player == 0) {
        historyUpdate(cardLibrary.cardList[lightMinion[number][0]].name + " died");
        for (int i = 0; i < lightMinion.size(); i++) 
            checkAbility(lightMinion[i], 48, 0, number, lightMinion[i]); // ID 48 here
       /* int j = darkMinion.size();
        for (int i = 0; i < j; i++)
            checkAbility(darkMinion[i], 52, 1, number, lightMinion[number]); // ID 52 here*/
        lightMinion[number][17] = 1;
        lightCemetery.push_back(lightMinion[number][0]);
        for (int i = 0; i < lightHand.size(); i++) checkAbilityForCard(lightHand[i], 46, 0, i);
        for (int i = 0; i < darkHand.size(); i++) checkAbilityForCard(darkHand[i], 46, 1, i); // ID 46 here  
        //    checkAbility(lightMinion[number], 22, 0, number, lightMinion[number]);
    }
    else {
        historyUpdate(cardLibrary.cardList[darkMinion[number][0]].name + " died");
        for (int i = 0; i < darkMinion.size(); i++) checkAbility(darkMinion[i], 48, 1, number, darkMinion[i]); // ID 48 here
       /* int j = lightMinion.size();
        for (int i = 0; i < j; i++) 
            checkAbility(lightMinion[i], 52, 0, number, darkMinion[number]); // ID 52 here*/
        darkMinion[number][17] = 1;
        darkCemetery.push_back(darkMinion[number][0]);
        for (int i = 0; i < lightHand.size(); i++) checkAbilityForCard(lightHand[i], 46, 0, i);
        for (int i = 0; i < darkHand.size(); i++) checkAbilityForCard(darkHand[i], 46, 1, i); // ID 46 here
        // ID 22 here
    //    checkAbility(darkMinion[number], 22, 1, number, darkMinion[number]);
    }
}
// weapon
void Hearthstone::updateWeapon(int player) {
    if (player == 0) {
        if (lightHaveWeapon == 0) return;
        else {
            lightWeapon[2]--;
            if (lightWeapon[2] <= 0) {
                lightHaveWeapon = 0;
                historyUpdate("Azeroth's weapon is broken");
            }
        }
    }
    else {
        if (darkHaveWeapon == 0) return;
        else {
            darkWeapon[2]--;
            if (darkWeapon[2] <= 0) {
                darkHaveWeapon = 0;
                historyUpdate("Void Lord's weapon is broken");
            }
        }
    }
}
void Hearthstone::takeHeal(int camp, int order, int heal) {
    string healValue;
    int initial;
    int last;
    if (camp == 0) {
        if (order == 7) {
            initial = lightHero[2];
            lightHero[2] += heal;
            if (lightHero[2] > lightHero[3])
                lightHero[2] = lightHero[3];
            last = lightHero[2];
            healValue = to_string(last - initial);
            historyUpdate("Azeroth get " + healValue + " heal");
        }
        else {
            initial = lightMinion[order][2];
            lightMinion[order][2] += heal;
            if (lightMinion[order][2] > lightMinion[order][3])
                lightMinion[order][2] = lightMinion[order][3];
            last = lightMinion[order][2];
            healValue = to_string(last - initial);
            historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " get " + healValue + " heal");

            if (lightMinion[order][2] == 10) checkAbility(lightMinion[order], 37, 0, order, lightMinion[order]); // ID 37 here
        }
    }
    else {
        if (order == 7) {
            initial = darkHero[2];
            darkHero[2] += heal;
            if (darkHero[2] > darkHero[3])
                darkHero[2] = darkHero[3];
            last = darkHero[2];
            healValue = to_string(last - initial);
            historyUpdate("Void Lord get " + healValue + " heal");
        }
        else {
            initial = darkMinion[order][2];
            darkMinion[order][2] += heal;
            if (darkMinion[order][2] > darkMinion[order][3])
                darkMinion[order][2] = darkMinion[order][3];
            last = darkMinion[order][2];
            healValue = to_string(last - initial);
            historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " get " + healValue + " heal");

            if (darkMinion[order][2] == 10) checkAbility(darkMinion[order], 37, 1, order, darkMinion[order]); // ID 37 here
        }  
    }
}
void Hearthstone::takeMagicDamage(int camp, int order, int damage, int poi) { 
    // ID 13 here
    if (camp == 0 && order != 7) {
        if (lightMinion[order][13] != 0) {
            historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " suffered fatal damage");
            destoryMinion(0, order);
            return;
        }
    }
    else if (camp == 1 && order != 7) {
        if (darkMinion[order][13] != 0) {
            historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " suffered fatal damage");
            destoryMinion(1, order);
            return;
        }
    }
    string damageValue;
    if (camp == 0) {// ID 30 here
        if (order == 7) {// ID 31 here
            if ((damage - lightHero[43]) <= 0) return; // ID 43 here

            if (lightHero[32] == 1) return;// ID 32 here
            if (lightHero[31] == 1) {
                lightHero[2] -= 1; 
                damageValue = to_string(1);
                historyUpdate("Azeroth took " + damageValue + " damage");
                return;
            }

            lightHero[2] -= (damage - lightHero[43]);
            damageValue = to_string(damage - lightHero[43]);
            historyUpdate("Azeroth took " + damageValue + " damage");
        }
        else {

            if ((damage - lightMinion[order][43]) <= 0) return; // ID 43 here

            if (lightMinion[order][30] == 1) {
                lightMinion[order][30] = 0; return;
            }
            if (lightMinion[order][32] == 1) return; 

            if (poi == 1) {
                historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " took toxic damage");
                destoryMinion(0, order);
            }
            else {
                if (lightMinion[order][31] == 1) {
                    lightMinion[order][2] -= 1;
                    damageValue = to_string(1);
                    historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " took " + damageValue + " damage");
                    //if (lightMinion[order][2] > 0)  checkAbility(lightMinion[order], 19, 0, order, lightMinion[order]);// ID 19 here
                    if (lightMinion[order][2] == 10) checkAbility(lightMinion[order], 37, 0, order, lightMinion[order]); // ID 37 here
                    return;
                }
                lightMinion[order][2] -= (damage - lightMinion[order][43]);
                damageValue = to_string(damage - lightMinion[order][43]);
                historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " took " + damageValue + " damage");
                //if (lightMinion[order][2] > 0)  checkAbility(lightMinion[order], 19, 0, order, lightMinion[order]);// ID 19 here
                if (lightMinion[order][2] == 10) checkAbility(lightMinion[order], 37, 0, order, lightMinion[order]); // ID 37 here
            }
        }
    }
    else {
        if (order == 7) {

            if ((damage - darkHero[43]) <= 0) return;  // ID 43 here

            if (darkHero[32] == 1) return;
            if (darkHero[31] == 1) {
                darkHero[2] -= 1; 
                damageValue = to_string(1);
                historyUpdate("Void Lord took " + damageValue + " damage");
                return;
            }

            darkHero[2] -= (damage - darkHero[43]);
            damageValue = to_string(damage - darkHero[43]);
            historyUpdate("Void Lord took " + damageValue + " damage");
        }
        else {
            if ((damage - darkMinion[order][43]) <= 0) return; // ID 43 here

            if (darkMinion[order][30] == 1) {
                darkMinion[order][30] = 0; return;
            }
            if (darkMinion[order][32] == 1) return;

            if (poi == 1) {
                historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " took toxic damage");
                destoryMinion(1, order);
            }
            else {
                if (darkMinion[order][31] == 1) {
                    darkMinion[order][2] -= 1; 
                    damageValue = to_string(1);
                    historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " took " + damageValue + " damage");
                   //if (darkMinion[order][2] > 0) checkAbility(darkMinion[order], 19, 1, order, darkMinion[order]);// ID 19 here
                    if (darkMinion[order][2] == 10) checkAbility(darkMinion[order], 37, 1, order, darkMinion[order]); // ID 37 here
                    return;
                }
                darkMinion[order][2] -= (damage - darkMinion[order][43]);
                damageValue = to_string(damage - darkMinion[order][43]);
                historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " took " + damageValue + " damage");

                //if (darkMinion[order][2] > 0) checkAbility(darkMinion[order], 19, 1, order, darkMinion[order]);// ID 19 here
                if (darkMinion[order][2] == 10) checkAbility(darkMinion[order], 37, 1, order, darkMinion[order]); // ID 37 here
            }
        }
    }
}
void Hearthstone::takePhysicalDamage(int camp, int order, int damage, int poi, int lif) {
    int lifesteal = 0;
    // ID 13 here
    if (camp == 0 && order != 7) {
        if (lightMinion[order][13] != 0) {
            historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " suffered fatal damage");
            destoryMinion(0, order);           
            return;
        }
    }
    else if (camp == 1 && order != 7) {
        if (darkMinion[order][13] != 0) {
            historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " suffered fatal damage");
            destoryMinion(1, order);          
            return;
        }
    }
    string damageValue;
    if (camp == 0) {// ID 30 here
        if (order == 7) {// ID 31 here
            if ((damage - lightHero[43]) <= 0) return; // ID 43 here

            if (lightHero[32] == 1) return;// ID 32 here
            if (lightHero[31] == 1) {
                lightHero[2] -= 1;
                damageValue = to_string(1);
                historyUpdate("Azeroth took " + damageValue + " damage");
                lifesteal = 1; // ID 16 here
                if (lif == 1) takeHeal(1,7,lifesteal);
                return;
            }

            lightHero[2] -= (damage - lightHero[43]);
            damageValue = to_string(damage - lightHero[43]);
            historyUpdate("Azeroth took " + damageValue + " damage");
            lifesteal = (damage - lightHero[43]); // ID 16 here
            if (lif == 1) takeHeal(1, 7, lifesteal);
        }
        else {

            if ((damage - lightMinion[order][43]) <= 0) return; // ID 43 here

            if (lightMinion[order][30] == 1) {
                lightMinion[order][30] = 0; return;
            }
            if (lightMinion[order][32] == 1) return;

            if (poi == 1) {
                historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " took toxic damage");
                // patch: poi can still life steal
                destoryMinion(0, order);
            }
            else {
                if (lightMinion[order][31] == 1) {
                    lightMinion[order][2] -= 1;
                    damageValue = to_string(1);
                    historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " took " + damageValue + " damage");
                    lifesteal = 1; // ID 16 here
                    if (lif == 1) takeHeal(1, 7, lifesteal);
                   // if (lightMinion[order][2] > 0)  checkAbility(lightMinion[order], 19, 0, order, lightMinion[order]);// ID 19 here
                    if (lightMinion[order][2] == 10) checkAbility(lightMinion[order], 37, 0, order, lightMinion[order]); // ID 37 here
                    return;
                }
                lightMinion[order][2] -= (damage - lightMinion[order][43]);
                damageValue = to_string(damage - lightMinion[order][43]);
                historyUpdate(cardLibrary.cardList[lightMinion[order][0]].name + " took " + damageValue + " damage");
                lifesteal = (damage - lightMinion[order][43]); // ID 16 here
                if (lif == 1) takeHeal(1, 7, lifesteal);
               // if (lightMinion[order][2] > 0)  checkAbility(lightMinion[order], 19, 0, order, lightMinion[order]);// ID 19 here
                if (lightMinion[order][2] == 10) checkAbility(lightMinion[order], 37, 0, order, lightMinion[order]); // ID 37 here
            }
        }
    }
    else {
        if (order == 7) {

            if ((damage - darkHero[43]) <= 0) return;  // ID 43 here

            if (darkHero[32] == 1) return;
            if (darkHero[31] == 1) {
                darkHero[2] -= 1;
                damageValue = to_string(1);
                historyUpdate("Void Lord took " + damageValue + " damage");
                lifesteal = 1; // ID 16 here
                if (lif == 1) takeHeal(0, 7, lifesteal);
                return;
            }

            darkHero[2] -= (damage - darkHero[43]);
            damageValue = to_string(damage - darkHero[43]);
            historyUpdate("Void Lord took " + damageValue + " damage");
            lifesteal = (damage - darkHero[43]); // ID 16 here
            if (lif == 1) takeHeal(0, 7, lifesteal);
        }
        else {
            if ((damage - darkMinion[order][43]) <= 0) return; // ID 43 here

            if (darkMinion[order][30] == 1) {
                darkMinion[order][30] = 0; return;
            }
            if (darkMinion[order][32] == 1) return;

            if (poi == 1) {
                historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " took toxic damage");
                destoryMinion(1, order);
            }
            else {
                if (darkMinion[order][31] == 1) {
                    darkMinion[order][2] -= 1;
                    damageValue = to_string(1);
                    historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " took " + damageValue + " damage");
                    lifesteal = 1; // ID 16 here
                    if (lif == 1) takeHeal(0, 7, lifesteal);
                   // if (darkMinion[order][2] > 0) checkAbility(darkMinion[order], 19, 1, order, darkMinion[order]);// ID 19 here
                    if (darkMinion[order][2] == 10) checkAbility(darkMinion[order], 37, 1, order, darkMinion[order]); // ID 37 here
                    return;
                }
                darkMinion[order][2] -= (damage - darkMinion[order][43]);
                damageValue = to_string(damage - darkMinion[order][43]);
                historyUpdate(cardLibrary.cardList[darkMinion[order][0]].name + " took " + damageValue + " damage");
                lifesteal = (damage - darkMinion[order][43]); // ID 16 here
                if (lif == 1) takeHeal(0, 7, lifesteal);

               // if (darkMinion[order][2] > 0) checkAbility(darkMinion[order], 19, 1, order, darkMinion[order]);// ID 19 here
                if (darkMinion[order][2] == 10) checkAbility(darkMinion[order], 37, 1, order, darkMinion[order]); // ID 37 here
            }
        }
    }
}
bool Hearthstone::checkMinionDie(int player, int number) {
    if (player == 0) {
        // ID 36 here
        checkAbility(lightMinion[number], 36, 0, number, lightMinion[number]);
        if (lightMinion[number][2] <= 0) {
            if (lightMinion[number][17] == 1) return 0;
            destoryMinion(0,number);
            return 1;
        }
        else {       
            checkAbility(lightMinion[number], 19, 0, number, lightMinion[number]); // ID 19 here
            return 0;
        }
    }
    else {
        // ID 36 here
        checkAbility(darkMinion[number], 36, 1, number, darkMinion[number]);
        if (darkMinion[number][2] <= 0) {     
            if (darkMinion[number][17] == 1) return 0;
            destoryMinion(1, number);
            return 1;
        }
        else {
            checkAbility(darkMinion[number], 19, 0, number, darkMinion[number]); // ID 19 here
            return 0;
        }
    }
}
void Hearthstone::battle(int camp) {
    bool died1;
    bool died2;

    if (camp == 0) {
        if (attacker == 7) lightHero[5] = 0;
        else lightMinion[attacker][5] = 0;

        if (attacker != 7) checkAbility(lightMinion[attacker], 21, 0, attacker, lightMinion[attacker]); // ID 21 here

        if (attacker != 7 && defencer != 7) {
            checkAbility(lightMinion[attacker], 23, 1, defencer, darkMinion[defencer]); // ID 23 here
            takePhysicalDamage(1, defencer, getAttack(lightMinion[attacker]), lightMinion[attacker][25], lightMinion[attacker][16]);
            lightMinion[attacker][27] = 0; // ID 27 here
            takePhysicalDamage(0, attacker, getAttack(darkMinion[defencer]), darkMinion[defencer][25], darkMinion[defencer][16]);
            historyUpdate(cardLibrary.cardList[lightMinion[attacker][0]].name + " attacked " + cardLibrary.cardList[darkMinion[defencer][0]].name);
            died1 = checkMinionDie(1, defencer);
            died2 = checkMinionDie(0, attacker);
            if (died1 == 1 && died2 == 0) { // ID 18 here
                checkAbility(lightMinion[attacker], 18, 0, attacker, lightMinion[attacker]);
            }
        }
        else if (attacker == 7 && defencer != 7) {
            checkAbility(lightWeapon, 51, 1, defencer, darkMinion[defencer]); // ID 51 here
            takePhysicalDamage(1, defencer, getAttack(lightHero), lightHero[25], lightHero[16]); 
            takePhysicalDamage(0, 7, getAttack(darkMinion[defencer]), 0, darkMinion[defencer][16]);
            historyUpdate("Azeroth attacked " + cardLibrary.cardList[darkMinion[defencer][0]].name);
            died1 = checkMinionDie(1, defencer);
            updateWeapon(0);
            checkDie(0);
        }
        else if (attacker != 7 && defencer == 7) {
            takePhysicalDamage(1, 7, getAttack(lightMinion[attacker]), 0, lightMinion[attacker][16]);
            lightMinion[attacker][27] = 0; // ID 27 here
            historyUpdate(cardLibrary.cardList[lightMinion[attacker][0]].name + " attacked Void Lord");
            checkDie(1);
        }
        else {
            takePhysicalDamage(1, 7, getAttack(lightHero), 0, lightHero[16]);
            historyUpdate("Azeroth attacked Void Lord");
            updateWeapon(0);
            checkDie(1);
        }
    }
    else {
        if (attacker == 7) darkHero[5] = 0;
        else darkMinion[attacker][5] = 0;

        if (attacker != 7) checkAbility(darkMinion[attacker], 21, 1, attacker, darkMinion[attacker]);// ID 21 here

        if (attacker != 7 && defencer != 7) {
            checkAbility(darkMinion[attacker], 23, 0, defencer, lightMinion[defencer]); // ID 23 here
            takePhysicalDamage(0, defencer, getAttack(darkMinion[attacker]), darkMinion[attacker][25], darkMinion[attacker][16]);
            darkMinion[attacker][27] = 0; // ID 27 here
            takePhysicalDamage(1, attacker, getAttack(lightMinion[defencer]), lightMinion[defencer][25], lightMinion[defencer][16]);
            historyUpdate(cardLibrary.cardList[darkMinion[attacker][0]].name + " attacked " + cardLibrary.cardList[lightMinion[defencer][0]].name);
            died1 = checkMinionDie(0, defencer);
            died2 = checkMinionDie(1, attacker);
            if (died1 == 1 && died2 == 0) { // ID 18 here
                checkAbility(darkMinion[attacker], 18, 1, attacker, darkMinion[attacker]);
            }       
        }
        else if (attacker == 7 && defencer != 7) {
            checkAbility(darkWeapon, 51, 0, defencer, lightMinion[defencer]); // ID 51 here
            takePhysicalDamage(0, defencer, getAttack(darkHero), darkHero[25], darkHero[16]);
            takePhysicalDamage(1, 7, getAttack(lightMinion[defencer]), 0, lightMinion[defencer][16]);
            historyUpdate("Void Lord attacked " + cardLibrary.cardList[lightMinion[defencer][0]].name);
            died1 = checkMinionDie(0, defencer);
            updateWeapon(1);
            checkDie(1);
        }
        else if (attacker != 7 && defencer == 7) {
            takePhysicalDamage(0, 7, getAttack(darkMinion[attacker]), 0, darkMinion[attacker][16]);
            darkMinion[attacker][27] = 0; // ID 27 here
            historyUpdate(cardLibrary.cardList[darkMinion[attacker][0]].name + " attacked Azeroth");
            checkDie(0);
        }
        else {
            takePhysicalDamage(0, 7, getAttack(darkHero), 0, darkHero[16]);
            historyUpdate("Void Lord attacked Azeroth");
            updateWeapon(1);
            checkDie(0);
        }
    }
    updateEverything();
}
void Hearthstone::addMinion(int minionID, int place ) {
    vector<int> newMinion;
    newMinion.push_back(minionID);
    newMinion.push_back(theAttack);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(cardLibrary.cardList[minionID].health);
    newMinion.push_back(uniqueID);
    uniqueID++;
    if (cardLibrary.cardList[minionID].ability[11] == 1) newMinion.push_back(1); // ID 11 here
    else newMinion.push_back(0);

    newMinion.push_back(cardLibrary.cardList[minionID].cost);
    newMinion.push_back(-1);
    newMinion.push_back(0);
    newMinion.push_back(-1);
    for (int i = 10; i < 60; i++) {
        newMinion.push_back(cardLibrary.cardList[minionID].ability[i]);
    } 

    if (turn == 0) {
        // ID 49 here
        for (int i = 0; i < darkMinion.size(); i++) checkAbility(darkMinion[i], 49, 1, i, newMinion);
        // ID 10 here
        checkAbility(newMinion, 10, 0, -1, newMinion);
        lightMinion.insert(lightMinion.begin() + placeList[place][lightMinion.size()], newMinion);
        // ID 39 here
        checkAbility(newMinion, 39, 0, -1, newMinion);
        historyUpdate("Placed " + cardLibrary.cardList[minionID].name); 
    }    
    else {
        // ID 49 here
        for (int i = 0; i < lightMinion.size(); i++) checkAbility(lightMinion[i], 49, 0, i, newMinion);
        // ID 10 here
        checkAbility(newMinion, 10, 1, -1, newMinion);
        darkMinion.insert(darkMinion.begin() + placeList[place][darkMinion.size()], newMinion);
        // ID 39 here
        checkAbility(newMinion, 39, 1, -1, newMinion);
        historyUpdate("Placed " + cardLibrary.cardList[minionID].name);
    }
}
int Hearthstone::getAttack(vector<int> minion) {
    if (minion[1] + minion[24] + minion[8] >= 1) return (minion[1] + minion[24] + minion[8]);
    else return 0;
}
void Hearthstone::playACard(int cardID) {
    if (turn == 0) {
        if ((lightCurrMana - (cardLibrary.cardList[cardID].cost + getExtraManaCost(tempCardOrder,0))) < 0) {
            historyUpdate("Do not have enought Mana");
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (cardLibrary.cardList[cardID].ability[i] == 1) {
                tempPlayType = i;
                break;
            }
        }

        tempID = cardID;

        if (cardLibrary.cardList[cardID].type == 1) {
            if (tempPlayType == 7) {
                comfirmPlayCard();
            }
            else {
                if (lightMinion.size() == 7) historyUpdate("Cannot place more minions!");
                else enterPlaceMode();
            }
        }
        else if (cardLibrary.cardList[cardID].type == 2 || cardLibrary.cardList[cardID].type == 4) {
            if (tempPlayType == 0) {
                comfirmPlayCard();
            }
            else if (tempPlayType == 1) {
                if (darkMinion.size() <= 0) historyUpdate("No target for selection");
                else {
                    minionAttack = 2;
                    enterSelectMode1();
                }
            }
            else {}
        }
        else if (cardLibrary.cardList[cardID].type == 3) {
            if (tempPlayType == 0) {
                comfirmPlayCard();
            }
            else {}
        }
        else {}
    }
    else {
        if ((darkCurrMana - (cardLibrary.cardList[cardID].cost + getExtraManaCost(tempCardOrder,1))) < 0) {
            historyUpdate("Do not have enought Mana");
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (cardLibrary.cardList[cardID].ability[i] == 1) {
                tempPlayType = i;
                break;
            }
        }

        tempID = cardID;

        if (cardLibrary.cardList[cardID].type == 1) {
            if (tempPlayType == 7) {
                comfirmPlayCard();
            }
            else {
                if (darkMinion.size() == 7) historyUpdate("Cannot place more minions!");
                else enterPlaceMode();
            } 
        }
        else if (cardLibrary.cardList[cardID].type == 2 || cardLibrary.cardList[cardID].type == 4) {
            if (tempPlayType == 0) {
                comfirmPlayCard();
            }
            else if (tempPlayType == 1) {
                if (lightMinion.size() <= 0) historyUpdate("No target for selection");
                else {
                    minionAttack = 2;
                    enterSelectMode1();
                }
            }
            else {}
        }
        else if (cardLibrary.cardList[cardID].type == 3) {
            if (tempPlayType == 0) {
                comfirmPlayCard();
            }
            else {}
        }
        else {}
    }
}
void Hearthstone::callFunction(const string& string, int camp, int index, vector<int> sample, vector<int> & minion)
{
    (this->*functionList[string])(camp,index,sample,minion);
}
void Hearthstone::removeCard(int cardOrder, int camp) {
    if (camp == 0) {
        if (cardOrder == 10) lightHero[7] = 0;
        else {
            lightHand.erase(lightHand.begin() + cardOrder);
            lightCardAtt.erase(lightCardAtt.begin() + cardOrder);
            lightCardAttE.erase(lightCardAttE.begin() + cardOrder);
            lightCardAttT.erase(lightCardAttT.begin() + cardOrder);
            lightExtra.erase(lightExtra.begin() + cardOrder);
            lightExtra.push_back(0);
        }
    }
    else {
        if (cardOrder == 10) darkHero[7] = 0;
        else {
            darkHand.erase(darkHand.begin() + cardOrder);
            darkCardAtt.erase(darkCardAtt.begin() + cardOrder);
            darkCardAttE.erase(darkCardAttE.begin() + cardOrder);
            darkCardAttT.erase(darkCardAttT.begin() + cardOrder);
            darkExtra.erase(darkExtra.begin() + cardOrder);
            darkExtra.push_back(0);
        }
    }
}
void Hearthstone::printLabel(int i, string size) {
    string number = to_string(i);
    string path = "image/" + size + "/" + number + ".png";
    QString convPath = QString::fromStdString(path);
    QPixmap theImage(convPath);
    ui.cardView->setPixmap(theImage);
}
void Hearthstone::checkDie(int i) {
    if (i == 0) {
        if (lightHero[2] <= 0) {
            rescue(0);
            if (lightHero[2] <= 0) endOfGame(i);
        }
    }
    else {
        if (darkHero[2] <= 0) {
            rescue(1);
            if (darkHero[2] <= 0) endOfGame(i); 
        }
    }

} 
void Hearthstone::historyUpdate(string message) {
    for (int i = 0; i < 9; i++) {
        historyText[i] = historyText[i+1];
    }
    historyText[9] = message;
    string combine = historyText[0] + "\n";
    for (int i = 1; i < 10; i++) {
        combine += historyText[i] + "\n";
    }

    QString convCombine = QString::fromStdString(combine);
    ui.history->setText(convCombine);
}
int Hearthstone::getExtraManaCost(int order,int camp) {
    if (camp == 0) {
        if (order == 10) {
            if (1 + lightExtraS + lightDynamicS + lightTurnS < 0) return -1;
            else return (lightExtraS + lightDynamicS + lightTurnS);
        }
        else {
            if (cardLibrary.cardList[lightHand[order]].cost + lightExtra[order] + lightDynamic[order] + lightTurn[order] < 0) return -(cardLibrary.cardList[lightHand[order]].cost);
            else return (lightExtra[order] + lightDynamic[order] + lightTurn[order]);
        }
    }
    else {
        if (order == 10) {
            if (1 + darkExtraS + darkDynamicS + darkTurnS < 0) return -1;
            else return (darkExtraS + darkDynamicS + darkTurnS);
        }
        else {
            if (cardLibrary.cardList[darkHand[order]].cost + darkExtra[order] + darkDynamic[order] + darkTurn[order] < 0) return -(cardLibrary.cardList[darkHand[order]].cost);
            else return (darkExtra[order] + darkDynamic[order] + darkTurn[order]);
        }
    }
}
void Hearthstone::summonMinion(vector<int> minion, int camp, int index) {
    if (camp == 0) {
        if (lightMinion.size() == 0) lightMinion.push_back(minion);
        else {
            if (lightMinion.size() == 7) return;
            else {
                historyUpdate("Summon " + cardLibrary.cardList[minion[0]].name);
                if (index >= lightMinion.size()) lightMinion.push_back(minion); // >: for push back =: for the minion is at last
                else {
                    lightMinion.insert(lightMinion.begin() + index + 1, minion);
                }
            }
        }
    }
    else {
        if (darkMinion.size() == 0) darkMinion.push_back(minion);
        else {
            if (darkMinion.size() == 7) return;
            else {
                historyUpdate("Summon " + cardLibrary.cardList[minion[0]].name);
                if (index >= darkMinion.size()) darkMinion.push_back(minion);
                else {
                    darkMinion.insert(darkMinion.begin() + index + 1, minion);
                }
            }
        }
    }
}
// Enable and Disable
void Hearthstone::smokeDisable() {
    if (lightSmoke[0] == 1) ui.lightMinion0->setEnabled(false);
    if (lightSmoke[1] == 1) ui.lightMinion1->setEnabled(false);
    if (lightSmoke[2] == 1) ui.lightMinion2->setEnabled(false);
    if (lightSmoke[3] == 1) ui.lightMinion3->setEnabled(false);
    if (lightSmoke[4] == 1) ui.lightMinion4->setEnabled(false);
    if (lightSmoke[5] == 1) ui.lightMinion5->setEnabled(false);
    if (lightSmoke[6] == 1) ui.lightMinion6->setEnabled(false);
    if (darkSmoke[0] == 1) ui.darkMinion0->setEnabled(false);
    if (darkSmoke[1] == 1) ui.darkMinion1->setEnabled(false);
    if (darkSmoke[2] == 1) ui.darkMinion2->setEnabled(false);
    if (darkSmoke[3] == 1) ui.darkMinion3->setEnabled(false);
    if (darkSmoke[4] == 1) ui.darkMinion4->setEnabled(false);
    if (darkSmoke[5] == 1) ui.darkMinion5->setEnabled(false);
    if (darkSmoke[6] == 1) ui.darkMinion6->setEnabled(false);
}
void Hearthstone::lightAttackActive() {
    ui.prompt2->setText("Attack Mode");
    disableAllButton();

    ui.cancel->setEnabled(true);
    ui.darkHero->setEnabled(true);
    if (alignMinion[darkMinion.size()][0] != -1) ui.darkMinion0->setEnabled(true);
    if (alignMinion[darkMinion.size()][1] != -1) ui.darkMinion1->setEnabled(true);
    if (alignMinion[darkMinion.size()][2] != -1) ui.darkMinion2->setEnabled(true);
    if (alignMinion[darkMinion.size()][3] != -1) ui.darkMinion3->setEnabled(true);
    if (alignMinion[darkMinion.size()][4] != -1) ui.darkMinion4->setEnabled(true);
    if (alignMinion[darkMinion.size()][5] != -1) ui.darkMinion5->setEnabled(true);
    if (alignMinion[darkMinion.size()][6] != -1) ui.darkMinion6->setEnabled(true);

    smokeDisable();
}
void Hearthstone::darkAttackActive() {
    ui.prompt2->setText("Attack Mode");
    disableAllButton();

    ui.cancel->setEnabled(true);
    ui.lightHero->setEnabled(true);
    if (alignMinion[lightMinion.size()][0] != -1) ui.lightMinion0->setEnabled(true);
    if (alignMinion[lightMinion.size()][1] != -1) ui.lightMinion1->setEnabled(true);
    if (alignMinion[lightMinion.size()][2] != -1) ui.lightMinion2->setEnabled(true);
    if (alignMinion[lightMinion.size()][3] != -1) ui.lightMinion3->setEnabled(true);
    if (alignMinion[lightMinion.size()][4] != -1) ui.lightMinion4->setEnabled(true);
    if (alignMinion[lightMinion.size()][5] != -1) ui.lightMinion5->setEnabled(true);
    if (alignMinion[lightMinion.size()][6] != -1) ui.lightMinion6->setEnabled(true);

    smokeDisable();
}
void Hearthstone::on_cancel_clicked() {
    updateEverything();
}
void Hearthstone::disableAllButton() {
    ui.lightHero->setEnabled(false);
    ui.darkHero->setEnabled(false);

    ui.cardBtn0->setEnabled(false);
    ui.cardBtn1->setEnabled(false);
    ui.cardBtn2->setEnabled(false);
    ui.cardBtn3->setEnabled(false);
    ui.cardBtn4->setEnabled(false);
    ui.cardBtn5->setEnabled(false);
ui.cardBtn6->setEnabled(false);
ui.cardBtn7->setEnabled(false);
ui.cardBtn8->setEnabled(false);
ui.cardBtn9->setEnabled(false);
ui.lightSkill->setEnabled(false);
ui.darkSkill->setEnabled(false);

ui.darkPlace0->setEnabled(false);
ui.darkPlace1->setEnabled(false);
ui.darkPlace2->setEnabled(false);
ui.darkPlace3->setEnabled(false);
ui.darkPlace4->setEnabled(false);
ui.darkPlace5->setEnabled(false);
ui.darkPlace6->setEnabled(false);
ui.darkPlace7->setEnabled(false);
ui.lightPlace0->setEnabled(false);
ui.lightPlace1->setEnabled(false);
ui.lightPlace2->setEnabled(false);
ui.lightPlace3->setEnabled(false);
ui.lightPlace4->setEnabled(false);
ui.lightPlace5->setEnabled(false);
ui.lightPlace6->setEnabled(false);
ui.lightPlace7->setEnabled(false);

ui.darkMinion0->setEnabled(false);
ui.darkMinion1->setEnabled(false);
ui.darkMinion2->setEnabled(false);
ui.darkMinion3->setEnabled(false);
ui.darkMinion4->setEnabled(false);
ui.darkMinion5->setEnabled(false);
ui.darkMinion6->setEnabled(false);
ui.lightMinion0->setEnabled(false);
ui.lightMinion1->setEnabled(false);
ui.lightMinion2->setEnabled(false);
ui.lightMinion3->setEnabled(false);
ui.lightMinion4->setEnabled(false);
ui.lightMinion5->setEnabled(false);
ui.lightMinion6->setEnabled(false);

ui.finish->setEnabled(false);
ui.cancel->setEnabled(false);
ui.lightChoice0->setEnabled(false);
ui.lightChoice1->setEnabled(false);
ui.darkChoice0->setEnabled(false);
ui.darkChoice1->setEnabled(false);
}
void Hearthstone::enterChooseOneMode(QString text0, QString text1) {
    ui.prompt2->setText("Choice Mode");
    disableAllButton();
    if (turn == 0) {
        ui.lightChoice0->setText(text0);
        ui.lightChoice1->setText(text1);
        ui.lightChoice0->setEnabled(true);
        ui.lightChoice1->setEnabled(true);
    }
    else {
        ui.darkChoice0->setText(text0);
        ui.darkChoice1->setText(text1);
        ui.darkChoice0->setEnabled(true);
        ui.darkChoice1->setEnabled(true);   
    }
}
void Hearthstone::enterThreatMode(QString text0, QString text1) {
    ui.prompt2->setText("Choice Mode");
    disableAllButton();
    if (turn == 0) {
        ui.darkChoice0->setText(text0);
        ui.darkChoice1->setText(text1);
        ui.darkChoice0->setEnabled(true);
        ui.darkChoice1->setEnabled(true);
    }
    else {
        ui.lightChoice0->setText(text0);
        ui.lightChoice1->setText(text1);
        ui.lightChoice0->setEnabled(true);
        ui.lightChoice1->setEnabled(true);
    }
}
void Hearthstone::enterSelectMode1() {
    ui.prompt2->setText("Select Mode");
    disableAllButton();
    ui.cancel->setEnabled(true);
    if (turn == 0) {
        if (alignMinion[darkMinion.size()][0] != -1) ui.darkMinion0->setEnabled(true);
        if (alignMinion[darkMinion.size()][1] != -1) ui.darkMinion1->setEnabled(true);
        if (alignMinion[darkMinion.size()][2] != -1) ui.darkMinion2->setEnabled(true);
        if (alignMinion[darkMinion.size()][3] != -1) ui.darkMinion3->setEnabled(true);
        if (alignMinion[darkMinion.size()][4] != -1) ui.darkMinion4->setEnabled(true);
        if (alignMinion[darkMinion.size()][5] != -1) ui.darkMinion5->setEnabled(true);
        if (alignMinion[darkMinion.size()][6] != -1) ui.darkMinion6->setEnabled(true);  
    }
    else {
        if (alignMinion[lightMinion.size()][0] != -1) ui.lightMinion0->setEnabled(true);
        if (alignMinion[lightMinion.size()][1] != -1) ui.lightMinion1->setEnabled(true);
        if (alignMinion[lightMinion.size()][2] != -1) ui.lightMinion2->setEnabled(true);
        if (alignMinion[lightMinion.size()][3] != -1) ui.lightMinion3->setEnabled(true);
        if (alignMinion[lightMinion.size()][4] != -1) ui.lightMinion4->setEnabled(true);
        if (alignMinion[lightMinion.size()][5] != -1) ui.lightMinion5->setEnabled(true);
        if (alignMinion[lightMinion.size()][6] != -1) ui.lightMinion6->setEnabled(true);
    }

    smokeDisable();
}
void Hearthstone::enterSelectMode5() {
    ui.prompt2->setText("Select Mode");
    disableAllButton();
    ui.cancel->setEnabled(true);
    if (alignMinion[lightMinion.size()][0] != -1) ui.lightMinion0->setEnabled(true);
    if (alignMinion[lightMinion.size()][1] != -1) ui.lightMinion1->setEnabled(true);
    if (alignMinion[lightMinion.size()][2] != -1) ui.lightMinion2->setEnabled(true);
    if (alignMinion[lightMinion.size()][3] != -1) ui.lightMinion3->setEnabled(true);
    if (alignMinion[lightMinion.size()][4] != -1) ui.lightMinion4->setEnabled(true);
    if (alignMinion[lightMinion.size()][5] != -1) ui.lightMinion5->setEnabled(true);
    if (alignMinion[lightMinion.size()][6] != -1) ui.lightMinion6->setEnabled(true);
    if (alignMinion[darkMinion.size()][0] != -1) ui.darkMinion0->setEnabled(true);
    if (alignMinion[darkMinion.size()][1] != -1) ui.darkMinion1->setEnabled(true);
    if (alignMinion[darkMinion.size()][2] != -1) ui.darkMinion2->setEnabled(true);
    if (alignMinion[darkMinion.size()][3] != -1) ui.darkMinion3->setEnabled(true);
    if (alignMinion[darkMinion.size()][4] != -1) ui.darkMinion4->setEnabled(true);
    if (alignMinion[darkMinion.size()][5] != -1) ui.darkMinion5->setEnabled(true);
    if (alignMinion[darkMinion.size()][6] != -1) ui.darkMinion6->setEnabled(true);
    smokeDisable();
}
void Hearthstone::enterSelectMode3() {
    ui.prompt2->setText("Select Mode");
    disableAllButton();
    ui.cancel->setEnabled(true);
    if (turn == 0) {
        if (alignMinion[lightMinion.size()][0] != -1) ui.lightMinion0->setEnabled(true);
        if (alignMinion[lightMinion.size()][1] != -1) ui.lightMinion1->setEnabled(true);
        if (alignMinion[lightMinion.size()][2] != -1) ui.lightMinion2->setEnabled(true);
        if (alignMinion[lightMinion.size()][3] != -1) ui.lightMinion3->setEnabled(true);
        if (alignMinion[lightMinion.size()][4] != -1) ui.lightMinion4->setEnabled(true);
        if (alignMinion[lightMinion.size()][5] != -1) ui.lightMinion5->setEnabled(true);
        if (alignMinion[lightMinion.size()][6] != -1) ui.lightMinion6->setEnabled(true);
    }
    else {
        if (alignMinion[darkMinion.size()][0] != -1) ui.darkMinion0->setEnabled(true);
        if (alignMinion[darkMinion.size()][1] != -1) ui.darkMinion1->setEnabled(true);
        if (alignMinion[darkMinion.size()][2] != -1) ui.darkMinion2->setEnabled(true);
        if (alignMinion[darkMinion.size()][3] != -1) ui.darkMinion3->setEnabled(true);
        if (alignMinion[darkMinion.size()][4] != -1) ui.darkMinion4->setEnabled(true);
        if (alignMinion[darkMinion.size()][5] != -1) ui.darkMinion5->setEnabled(true);
        if (alignMinion[darkMinion.size()][6] != -1) ui.darkMinion6->setEnabled(true);
    }

    smokeDisable();
}
void Hearthstone::enterPlaceMode() {
    if (turn == 0) {
        lightPlaceActive();
    }
    else {
        darkPlaceActive();
    }
}
void Hearthstone::lightPlaceActive() {
    ui.prompt2->setText("Place Mode");
    disableAllButton();
    ui.lightPlace0->setVisible(true);
    ui.lightPlace1->setVisible(true);
    ui.lightPlace2->setVisible(true);
    ui.lightPlace3->setVisible(true);
    ui.lightPlace4->setVisible(true);
    ui.lightPlace5->setVisible(true);
    ui.lightPlace6->setVisible(true);
    ui.lightPlace7->setVisible(true);
    ui.lightPlace0->setEnabled(true);
    ui.lightPlace1->setEnabled(true);
    ui.lightPlace2->setEnabled(true);
    ui.lightPlace3->setEnabled(true);
    ui.lightPlace4->setEnabled(true);
    ui.lightPlace5->setEnabled(true);
    ui.lightPlace6->setEnabled(true);
    ui.lightPlace7->setEnabled(true);
    ui.cancel->setEnabled(true);
}
void Hearthstone::darkPlaceActive() {
    ui.prompt2->setText("Place Mode");
    disableAllButton();
    ui.darkPlace0->setEnabled(true);
    ui.darkPlace1->setEnabled(true);
    ui.darkPlace2->setEnabled(true);
    ui.darkPlace3->setEnabled(true);
    ui.darkPlace4->setEnabled(true);
    ui.darkPlace5->setEnabled(true);
    ui.darkPlace6->setEnabled(true);
    ui.darkPlace7->setEnabled(true);
    ui.darkPlace0->setVisible(true);
    ui.darkPlace1->setVisible(true);
    ui.darkPlace2->setVisible(true);
    ui.darkPlace3->setVisible(true);
    ui.darkPlace4->setVisible(true);
    ui.darkPlace5->setVisible(true);
    ui.darkPlace6->setVisible(true);
    ui.darkPlace7->setVisible(true);
    ui.cancel->setEnabled(true);
}
// turn
void Hearthstone::startTurn() {
    // unfreeze
    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][12] != 0) lightMinion[i][12] -= 1;
        if (lightMinion[i][13] != 0) lightMinion[i][13] -= 1;
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][12] != 0) darkMinion[i][12] -= 1;
        if (darkMinion[i][13] != 0) darkMinion[i][13] -= 1;
    }
    if (darkHero[12] != 0) darkHero[12] -= 1;
    if (darkHero[13] != 0) darkHero[13] -= 1;
    if (lightHero[12] != 0) lightHero[12] -= 1;
    if (lightHero[13] != 0) lightHero[13] -= 1;

    ui.prompt2->setText("Normal Mode");
    if (turn == 0) {
        historyUpdate("");
        historyUpdate("Light League's action:");
        ui.prompt1->setText("Light League's Turn");
        ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
        updateManaStartTurn();
        atTheStartOfTurn();
        drawCard(lightHand, lightDeck,0);
    }
    else {
        historyUpdate("");
        historyUpdate("Dark League's action:");
        ui.prompt1->setText("Dark League's Turn");
        
        updateManaStartTurn();
        atTheStartOfTurn();
        drawCard(darkHand, darkDeck,1);
    }
    for (int i = 0; i < lightMinion.size(); i++) lightMinion[i][5] = 1;
    for (int i = 0; i < darkMinion.size(); i++) darkMinion[i][5] = 1;
    lightHero[5] = 1;
    darkHero[5] = 1;
    lightHero[7] = 1;
    darkHero[7] = 1;
    updateEverything();
}
void Hearthstone::drawCard(vector<int>& hand, vector<int>& deck, int camp) {
    if (camp == 0) {
        if (deck.size() == 0) {
            lightHero[2] -= lightEmpty;
            lightEmpty++;
            historyUpdate("Azeroth take damage by fatigue");
            checkDie(0);
        }
        else {
            int newCard = deck[0];
            deck.erase(deck.begin());
            if (hand.size() < 10) {
                lightCardAtt.push_back(cardLibrary.cardList[newCard].attack);
                lightCardAttE.push_back(0);
                lightCardAttT.push_back(0);
                hand.push_back(newCard);
            }       
            else
                historyUpdate("Azeroth's hand is full!");
        }
    }
    else {
        if (deck.size() == 0) {
            darkHero[2] -= darkEmpty;
            darkEmpty++;
            historyUpdate("Void Lord take damage by fatigue");
            checkDie(1);
        }
        else {
            int newCard = deck[0];
            deck.erase(deck.begin());
            if (hand.size() < 10) {
                darkCardAtt.push_back(cardLibrary.cardList[newCard].attack);
                darkCardAttE.push_back(0);
                darkCardAttT.push_back(0);
                hand.push_back(newCard);
            }
            else
                historyUpdate("Void Lord's hand is full!");
        }
    }
}
void Hearthstone::resetGlobal() {
    resetLocal();
    for (int i = 0; i < lightMinion.size(); i++) {
        lightMinion[i][24] = 0;
    }

    for (int i = 0; i < darkMinion.size(); i++) {
        darkMinion[i][24] = 0;
    }

    freeControl = 0;
    darkHero[24] = 0;
    lightHero[24] = 0;
    lightTurn = { 0,0,0,0,0,0,0,0,0,0 };
    darkTurn = { 0,0,0,0,0,0,0,0,0,0 };
    lightTurnS = 0;
    darkTurnS = 0;
    for (int i = 0; i < lightCardAttT.size(); i++) lightCardAttT[i] = 0;
    for (int i = 0; i < darkCardAttT.size(); i++) darkCardAttT[i] = 0;
}
void Hearthstone::resetLocal() {
    // attack
    attacker = -1; 
    defencer = -1; 
    // play card
    tempCardOrder = -1; 
    tempID = -1; 
    tempPlayType = -1;
    tempPlace = -1; 
    minionAttack = 1; //0: the minion is under attack 1: the minion is trying to attack 2: the minion is target
    theChoice = -1;
    theTarget = -1;
    theAttack = -1;
}
void Hearthstone::updateManaStartTurn() {
    if (turn == 0) {
        lightMaxMana -= lightTurnMana;
        lightTurnMana = 0;
        if (lightMaxMana < 10) {
            lightMaxMana++;

        }
        lightOverloadedMana = lightOverloadMana;
        if (lightOverloadedMana > lightMaxMana) lightOverloadedMana = lightMaxMana;
        lightOverloadMana = 0;
        lightCurrMana = lightMaxMana - lightOverloadedMana;
    }
    else {
        darkMaxMana -= darkTurnMana;
        darkTurnMana = 0;
        if (darkMaxMana < 10) {
            darkMaxMana++;
        }
        darkOverloadedMana = darkOverloadMana;
        if (darkOverloadedMana > darkMaxMana) darkOverloadedMana = darkMaxMana;
        darkOverloadMana = 0;
        darkCurrMana = darkMaxMana - darkOverloadedMana;
    }
}
void Hearthstone::on_finish_clicked() {
    atTheEndOfTurn(); 
    resetGlobal();
    printLabel(-1, "320x455");
    ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);

    updateEverything();
    if (turn == 0) {
        turn = 1;
        startTurn();
    }
    else {
        turn = 0;
        startTurn();
    }
}
// update
void Hearthstone::updateEverything() {
    ui.prompt2->setText("Normal Mode");
    removeMinion();
    // dynamic 
    for (int i = 0; i < lightMinion.size(); i++) lightMinion[i][8] = 0;
    for (int i = 0; i < darkMinion.size(); i++) darkMinion[i][8] = 0;
    lightHero[8] = 0;
    darkHero[8] = 0;
    lightDynamic = { 0,0,0,0,0,0,0,0,0,0 };
    darkDynamic = { 0,0,0,0,0,0,0,0,0,0 };
    lightDynamicS = 0;
    darkDynamicS = 0;

    for (int i = 0; i < lightMinion.size(); i++) { lightMinion[i][31] = 0; lightMinion[i][32] = 0; lightMinion[i][43] = 0;}
    for (int i = 0; i < darkMinion.size(); i++) { darkMinion[i][31] = 0; darkMinion[i][32] = 0; darkMinion[i][43] = 0;}
    lightHero[31] = 0;
    lightHero[32] = 0;
    lightHero[43] = 0;
    darkHero[31] = 0;
    darkHero[32] = 0;
    darkHero[43] = 0;

    for (int i = 0; i < lightMinion.size(); i++) {
        if (lightMinion[i][33] == 1) lightMinion[i][31] = 1;
        if (lightMinion[i][34] == 1) lightMinion[i][32] = 1;
        if (lightMinion[i][44] != 0) lightMinion[i][43] += lightMinion[i][44];
    }
    for (int i = 0; i < darkMinion.size(); i++) {
        if (darkMinion[i][33] == 1) darkMinion[i][31] = 1;
        if (darkMinion[i][34] == 1) darkMinion[i][32] = 1;
        if (darkMinion[i][44] != 0) darkMinion[i][43] += darkMinion[i][44];
    }

    for (int i = 0; i < lightMinion.size(); i++) checkAbility(lightMinion[i], 26, 0, i, lightMinion[i]);
    for (int i = 0; i < darkMinion.size(); i++) checkAbility(darkMinion[i], 26, 1, i, darkMinion[i]);
    for (int i = 0; i < lightMinion.size(); i++) checkAbility(lightMinion[i], 45, 0, i, lightMinion[i]);
    for (int i = 0; i < darkMinion.size(); i++) checkAbility(darkMinion[i], 45, 1, i, darkMinion[i]);
    for (int i = lightHand.size()-1; i >= 0; i--) checkAbilityForCard(lightHand[i], 47, 0, i);
    for (int i = darkHand.size()-1; i >= 0; i--) checkAbilityForCard(darkHand[i], 47, 1, i);
    // drity
    removeMinion();
    checkDie(1);
    checkDie(0);

    printLabel(-1, "320x455");
    ui.cardMana->setVisible(false); ui.cardAttack->setVisible(false); ui.cardHealth->setVisible(false); ui.cardSkill->setVisible(false);
    ui.prompt2->setText("Normal Mode");

    resetLocal();
    updateHero();
    updateMinion();
    updateGameInfo();
    if (turn == 0) {
        updateHandVisual(lightHand);
        updateManaVisual();
    }
    else {
        updateHandVisual(darkHand);
        updateManaVisual();
    }
    updateOtherVisual();
}
void Hearthstone::removeMinion() {
    for (int i = lightMinion.size() - 1; i >= 0; i--) {
        if (lightMinion[i][17] == 1) {
            // ID 22 here
            checkAbility(lightMinion[i], 22, 0, i, lightMinion[i]);
            int j = darkMinion.size();
            for (int k = 0; k < j; k++)
                checkAbility(darkMinion[k], 52, 1, i, lightMinion[i]); // ID 52 here
        }
    }
    for (int i = darkMinion.size() - 1; i >= 0; i--) {
        if (darkMinion[i][17] == 1) {
            // ID 22 here
            checkAbility(darkMinion[i], 22, 1, i, darkMinion[i]);
            int j = lightMinion.size();
            for (int k = 0; k < j; k++)
                checkAbility(lightMinion[k], 52, 0, i, darkMinion[i]); // ID 52 here
        }
    }

    for (int i = lightMinion.size()-1; i >= 0; i--) {
        if (lightMinion[i][17] == 1 || lightMinion[i][20] == 1) {
            lightMinion.erase(lightMinion.begin() + i);
        }
    }
    for (int i = darkMinion.size()-1; i >= 0; i--) {
        if (darkMinion[i][17] == 1 || darkMinion[i][20] == 1) {
            darkMinion.erase(darkMinion.begin() + i);
        }
    }
}
QString Hearthstone::printAttack(vector<int> minion) {
    string attack = to_string(getAttack(minion));
    return QString::fromStdString(attack);
}
QString Hearthstone::printHealth(vector<int> minion) {
    string health = to_string(minion[2]) + +"/" + to_string(minion[3]);
    return QString::fromStdString(health);
}
QString Hearthstone::printAbility(vector<int> minion) {
    string text = "";
    if (minion[12] != 0) text += "Fr ";
    if (minion[13] != 0) text += "SFr ";
    if (minion[14] == 1) text += "ST ";
    if (minion[15] == 1) text += "ET ";
    if (minion[16] == 1) text += "Li ";
    if (minion[19] == 1) text += "Fr ";
    if (minion[22] == 1) text += "Dea ";
    if (minion[25] == 1) text += "Po ";
    if (minion[26] == 1) text += "RT ";
    if (minion[27] == 1) text += "Ste ";
    if (minion[28] == 1) text += "Ta ";
    if (minion[29] == 1) text += "Co ";
    if (minion[30] == 1) text += "DS ";
    if (minion[31] == 1) text += "Pr ";
    if (minion[32] == 1) text += "Im ";
    if (minion[35] == 1) text += "Sa ";
    if (minion[40] == 1) text += "Da ";
    if (minion[42] == 1) text += "Res ";
    if (minion[42] == 2) text += "Def ";
    if (minion[43] != 0) text += "RD ";
    if (minion[45] == 1) text += "RT ";
    if (minion[48] == 1) text += "MD ";
    if (minion[50] == 1) text += "CA ";

    QString convText = QString::fromStdString(text);
    return convText;
}
void Hearthstone::updateMinion() {
    if (alignMinion[lightMinion.size()][0] == -1) {
        ui.lightMinion0->setEnabled(false); printButton(99, "80x80", "lightMinion0");
        ui.lightMinionA0->setText(""); ui.lightMinionH0->setText(""); ui.lightMinionI0->setText("");
    }
    else {
        ui.lightMinion0->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][0]][0], "80x80", "lightMinion0");
        ui.lightMinionA0->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][0]]));
        ui.lightMinionH0->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][0]]));
        ui.lightMinionI0->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][0]]));
        if (lightMinion[alignMinion[lightMinion.size()][0]][5] == 0) ui.lightMinion0->setEnabled(false); // if minion do not have attack chance
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][0]]) == 0) ui.lightMinion0->setEnabled(false);  // if minion do not have attack
        if (lightMinion[alignMinion[lightMinion.size()][0]][50] == 1) ui.lightMinion0->setEnabled(false);  // ID 50 here
    }

    if (alignMinion[lightMinion.size()][1] == -1) {
        ui.lightMinion1->setEnabled(false); printButton(99, "80x80", "lightMinion1");
        ui.lightMinionA1->setText(""); ui.lightMinionH1->setText(""); ui.lightMinionI1->setText("");
    }
    else {
        ui.lightMinion1->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][1]][0], "80x80", "lightMinion1");
        ui.lightMinionA1->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][1]]));
        ui.lightMinionH1->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][1]]));
        ui.lightMinionI1->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][1]]));
        if (lightMinion[alignMinion[lightMinion.size()][1]][5] == 0) ui.lightMinion1->setEnabled(false);
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][1]]) == 0) ui.lightMinion1->setEnabled(false);
        if (lightMinion[alignMinion[lightMinion.size()][1]][50] == 1) ui.lightMinion1->setEnabled(false);
    }

    if (alignMinion[lightMinion.size()][2] == -1) {
        ui.lightMinion2->setEnabled(false); printButton(99, "80x80", "lightMinion2");
        ui.lightMinionA2->setText(""); ui.lightMinionH2->setText(""); ui.lightMinionI2->setText("");
    }
    else {
        ui.lightMinion2->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][2]][0], "80x80", "lightMinion2");
        ui.lightMinionA2->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][2]]));
        ui.lightMinionH2->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][2]]));
        ui.lightMinionI2->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][2]]));
        if (lightMinion[alignMinion[lightMinion.size()][2]][5] == 0) ui.lightMinion2->setEnabled(false);
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][2]]) == 0) ui.lightMinion2->setEnabled(false);
        if (lightMinion[alignMinion[lightMinion.size()][2]][50] == 1) ui.lightMinion2->setEnabled(false);
    }

    if (alignMinion[lightMinion.size()][3] == -1) {
        ui.lightMinion3->setEnabled(false); printButton(99, "80x80", "lightMinion3");
        ui.lightMinionA3->setText(""); ui.lightMinionH3->setText(""); ui.lightMinionI3->setText("");
    }
    else {
        ui.lightMinion3->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][3]][0], "80x80", "lightMinion3");
        ui.lightMinionA3->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][3]]));
        ui.lightMinionH3->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][3]]));
        ui.lightMinionI3->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][3]]));
        if (lightMinion[alignMinion[lightMinion.size()][3]][5] == 0) ui.lightMinion3->setEnabled(false);
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][3]]) == 0) ui.lightMinion3->setEnabled(false);
        if (lightMinion[alignMinion[lightMinion.size()][3]][50] == 1) ui.lightMinion3->setEnabled(false);
    }

    if (alignMinion[lightMinion.size()][4] == -1) {
        ui.lightMinion4->setEnabled(false); printButton(99, "80x80", "lightMinion4");
        ui.lightMinionA4->setText(""); ui.lightMinionH4->setText(""); ui.lightMinionI4->setText("");
    }
    else {
        ui.lightMinion4->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][4]][0], "80x80", "lightMinion4");
        ui.lightMinionA4->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][4]]));
        ui.lightMinionH4->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][4]]));
        ui.lightMinionI4->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][4]]));
        if (lightMinion[alignMinion[lightMinion.size()][4]][5] == 0) ui.lightMinion4->setEnabled(false);
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][4]]) == 0) ui.lightMinion4->setEnabled(false);
        if (lightMinion[alignMinion[lightMinion.size()][4]][50] == 1) ui.lightMinion4->setEnabled(false);
    }

    if (alignMinion[lightMinion.size()][5] == -1) {
        ui.lightMinion5->setEnabled(false); printButton(99, "80x80", "lightMinion5");
        ui.lightMinionA5->setText(""); ui.lightMinionH5->setText(""); ui.lightMinionI5->setText("");
    }
    else {
        ui.lightMinion5->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][5]][0], "80x80", "lightMinion5");
        ui.lightMinionA5->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][5]]));
        ui.lightMinionH5->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][5]]));
        ui.lightMinionI5->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][5]]));
        if (lightMinion[alignMinion[lightMinion.size()][5]][5] == 0) ui.lightMinion5->setEnabled(false);
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][5]]) == 0) ui.lightMinion5->setEnabled(false);
        if (lightMinion[alignMinion[lightMinion.size()][5]][50] == 1) ui.lightMinion5->setEnabled(false);
    }

    if (alignMinion[lightMinion.size()][6] == -1) {
        ui.lightMinion6->setEnabled(false); printButton(99, "80x80", "lightMinion6");
        ui.lightMinionA6->setText(""); ui.lightMinionH6->setText(""); ui.lightMinionI6->setText("");
    }
    else {
        ui.lightMinion6->setEnabled(true); printButton(lightMinion[alignMinion[lightMinion.size()][6]][0], "80x80", "lightMinion6");
        ui.lightMinionA6->setText(printAttack(lightMinion[alignMinion[lightMinion.size()][6]]));
        ui.lightMinionH6->setText(printHealth(lightMinion[alignMinion[lightMinion.size()][6]]));
        ui.lightMinionI6->setText(printAbility(lightMinion[alignMinion[lightMinion.size()][6]]));
        if (lightMinion[alignMinion[lightMinion.size()][6]][5] == 0) ui.lightMinion6->setEnabled(false);
        if (getAttack(lightMinion[alignMinion[lightMinion.size()][6]]) == 0) ui.lightMinion6->setEnabled(false);
        if (lightMinion[alignMinion[lightMinion.size()][6]][50] == 1) ui.lightMinion6->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][0] == -1) {
        ui.darkMinion0->setEnabled(false); printButton(99, "80x80", "darkMinion0");
        ui.darkMinionA0->setText(""); ui.darkMinionH0->setText(""); ui.darkMinionI0->setText("");
    }
    else {
        ui.darkMinion0->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][0]][0], "80x80", "darkMinion0");
        ui.darkMinionA0->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][0]]));
        ui.darkMinionH0->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][0]]));
        ui.darkMinionI0->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][0]]));
        if (darkMinion[alignMinion[darkMinion.size()][0]][5] == 0) ui.darkMinion0->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][0]]) == 0) ui.darkMinion0->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][0]][50] == 1) ui.darkMinion0->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][1] == -1) {
        ui.darkMinion1->setEnabled(false); printButton(99, "80x80", "darkMinion1");
        ui.darkMinionA1->setText(""); ui.darkMinionH1->setText(""); ui.darkMinionI1->setText("");
    }
    else {
        ui.darkMinion1->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][1]][0], "80x80", "darkMinion1");
        ui.darkMinionA1->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][1]]));
        ui.darkMinionH1->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][1]]));
        ui.darkMinionI1->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][1]]));
        if (darkMinion[alignMinion[darkMinion.size()][1]][5] == 0) ui.darkMinion1->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][1]]) == 0) ui.darkMinion1->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][1]][50] == 1) ui.darkMinion1->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][2] == -1) {
        ui.darkMinion2->setEnabled(false); printButton(99, "80x80", "darkMinion2");
        ui.darkMinionA2->setText(""); ui.darkMinionH2->setText(""); ui.darkMinionI2->setText("");
    }
    else {
        ui.darkMinion2->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][2]][0], "80x80", "darkMinion2");
        ui.darkMinionA2->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][2]]));
        ui.darkMinionH2->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][2]]));
        ui.darkMinionI2->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][2]]));
        if (darkMinion[alignMinion[darkMinion.size()][2]][5] == 0) ui.darkMinion2->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][2]]) == 0) ui.darkMinion2->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][2]][50] == 1) ui.darkMinion2->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][3] == -1) {
        ui.darkMinion3->setEnabled(false); printButton(99, "80x80", "darkMinion3");
        ui.darkMinionA3->setText(""); ui.darkMinionH3->setText(""); ui.darkMinionI3->setText("");
    }
    else {
        ui.darkMinion3->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][3]][0], "80x80", "darkMinion3");
        ui.darkMinionA3->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][3]]));
        ui.darkMinionH3->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][3]]));
        ui.darkMinionI3->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][3]]));
        if (darkMinion[alignMinion[darkMinion.size()][3]][5] == 0) ui.darkMinion3->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][3]]) == 0) ui.darkMinion3->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][3]][50] == 1) ui.darkMinion3->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][4] == -1) {
        ui.darkMinion4->setEnabled(false); printButton(99, "80x80", "darkMinion4");
        ui.darkMinionA4->setText(""); ui.darkMinionH4->setText(""); ui.darkMinionI4->setText("");
    }
    else {
        ui.darkMinion4->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][4]][0], "80x80", "darkMinion4");
        ui.darkMinionA4->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][4]]));
        ui.darkMinionH4->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][4]]));
        ui.darkMinionI4->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][4]]));
        if (darkMinion[alignMinion[darkMinion.size()][4]][5] == 0) ui.darkMinion4->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][4]]) == 0) ui.darkMinion4->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][4]][50] == 1) ui.darkMinion4->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][5] == -1) {
        ui.darkMinion5->setEnabled(false); printButton(99, "80x80", "darkMinion5");
        ui.darkMinionA5->setText(""); ui.darkMinionH5->setText(""); ui.darkMinionI5->setText("");
    }
    else {
        ui.darkMinion5->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][5]][0], "80x80", "darkMinion5");
        ui.darkMinionA5->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][5]]));
        ui.darkMinionH5->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][5]]));
        ui.darkMinionI5->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][5]]));
        if (darkMinion[alignMinion[darkMinion.size()][5]][5] == 0) ui.darkMinion5->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][5]]) == 0) ui.darkMinion5->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][5]][50] == 1) ui.darkMinion5->setEnabled(false);
    }

    if (alignMinion[darkMinion.size()][6] == -1) {
        ui.darkMinion6->setEnabled(false); printButton(99, "80x80", "darkMinion6");
        ui.darkMinionA6->setText(""); ui.darkMinionH6->setText(""); ui.darkMinionI6->setText("");
    }
    else {
        ui.darkMinion6->setEnabled(true); printButton(darkMinion[alignMinion[darkMinion.size()][6]][0], "80x80", "darkMinion6");
        ui.darkMinionA6->setText(printAttack(darkMinion[alignMinion[darkMinion.size()][6]]));
        ui.darkMinionH6->setText(printHealth(darkMinion[alignMinion[darkMinion.size()][6]]));
        ui.darkMinionI6->setText(printAbility(darkMinion[alignMinion[darkMinion.size()][6]]));
        if (darkMinion[alignMinion[darkMinion.size()][6]][5] == 0) ui.darkMinion6->setEnabled(false);
        if (getAttack(darkMinion[alignMinion[darkMinion.size()][6]]) == 0) ui.darkMinion6->setEnabled(false);
        if (darkMinion[alignMinion[darkMinion.size()][6]][50] == 1) ui.darkMinion6->setEnabled(false);
    }
    
    if (freeControl == 0) {
        if (turn == 0) {
            ui.darkMinion0->setEnabled(false);
            ui.darkMinion1->setEnabled(false);
            ui.darkMinion2->setEnabled(false);
            ui.darkMinion3->setEnabled(false);
            ui.darkMinion4->setEnabled(false);
            ui.darkMinion5->setEnabled(false);
            ui.darkMinion6->setEnabled(false);
        }
        else {
            ui.lightMinion0->setEnabled(false);
            ui.lightMinion1->setEnabled(false);
            ui.lightMinion2->setEnabled(false);
            ui.lightMinion3->setEnabled(false);
            ui.lightMinion4->setEnabled(false);
            ui.lightMinion5->setEnabled(false);
            ui.lightMinion6->setEnabled(false);
        }
    } 
}
void Hearthstone::updateHandVisual(vector<int>& hand) {

    printButton(99, "120x171", "cardBtn0");
    printButton(99, "120x171", "cardBtn1");
    printButton(99, "120x171", "cardBtn2");
    printButton(99, "120x171", "cardBtn3");
    printButton(99, "120x171", "cardBtn4");
    printButton(99, "120x171", "cardBtn5");
    printButton(99, "120x171", "cardBtn6");
    printButton(99, "120x171", "cardBtn7");
    printButton(99, "120x171", "cardBtn8");
    printButton(99, "120x171", "cardBtn9");
    ui.cardBtn0->setEnabled(false);
    ui.cardBtn1->setEnabled(false);
    ui.cardBtn2->setEnabled(false);
    ui.cardBtn3->setEnabled(false);
    ui.cardBtn4->setEnabled(false);
    ui.cardBtn5->setEnabled(false);
    ui.cardBtn6->setEnabled(false);
    ui.cardBtn7->setEnabled(false);
    ui.cardBtn8->setEnabled(false);
    ui.cardBtn9->setEnabled(false);
    if (hand.size() >= 1) {
        printButton(hand[0], "120x171", "cardBtn0"); ui.cardBtn0->setEnabled(true);
        if (hand.size() >= 2) {
            printButton(hand[1], "120x171", "cardBtn1"); ui.cardBtn1->setEnabled(true);
            if (hand.size() >= 3) {
                printButton(hand[2], "120x171", "cardBtn2"); ui.cardBtn2->setEnabled(true);
                if (hand.size() >= 4) {
                    printButton(hand[3], "120x171", "cardBtn3"); ui.cardBtn3->setEnabled(true);
                    if (hand.size() >= 5) {
                        printButton(hand[4], "120x171", "cardBtn4"); ui.cardBtn4->setEnabled(true);
                        if (hand.size() >= 6) {
                            printButton(hand[5], "120x171", "cardBtn5"); ui.cardBtn5->setEnabled(true);
                            if (hand.size() >= 7) {
                                printButton(hand[6], "120x171", "cardBtn6"); ui.cardBtn6->setEnabled(true);
                                if (hand.size() >= 8) {
                                    printButton(hand[7], "120x171", "cardBtn7"); ui.cardBtn7->setEnabled(true);
                                    if (hand.size() >= 9) {
                                        printButton(hand[8], "120x171", "cardBtn8"); ui.cardBtn8->setEnabled(true);
                                        if (hand.size() >= 10) {
                                            printButton(hand[9], "120x171", "cardBtn9"); ui.cardBtn9->setEnabled(true);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void Hearthstone::updateHero() {
    // update hero attack and health
    lightHero[1] = 0; darkHero[1] = 0;
    lightHero[1] = getAttack(lightHero); darkHero[1] = getAttack(darkHero);
    if (lightHaveWeapon == 1) lightHero[1] += getAttack(lightWeapon);
    if (darkHaveWeapon == 1) darkHero[1] += getAttack(darkWeapon);
    
    /*
    
    if (lightHaveWeapon == 1) {
        
        for (int i = 10; i <= 23; i++) if (lightWeapon[i] == 1) lightHero[i] = 1;
        for (int i = 25; i <= 30; i++) if (lightWeapon[i] == 1) lightHero[i] = 1;
        for (int i = 35; i <= 42; i++) if (lightWeapon[i] == 1) lightHero[i] = 1;
        for (int i = 45; i <= 59; i++) if (lightWeapon[i] == 1) lightHero[i] = 1;
        lightHero[43] += lightWeapon[44];
        if (lightWeapon[33] == 1) lightHero[31] = 1;
        if (lightWeapon[34] == 1) lightHero[32] = 1;
    }
    if (darkHaveWeapon == 1) {
        
        for (int i = 10; i <= 23; i++) if (darkWeapon[i] == 1) darkHero[i] = 1;
        for (int i = 25; i <= 30; i++) if (darkWeapon[i] == 1) darkHero[i] = 1;
        for (int i = 35; i <= 42; i++) if (darkWeapon[i] == 1) darkHero[i] = 1;
        for (int i = 45; i <= 59; i++) if (darkWeapon[i] == 1) darkHero[i] = 1;
        darkHero[43] += darkWeapon[44];
        if (darkWeapon[33] == 1) darkHero[31] = 1;
        if (darkWeapon[34] == 1) darkHero[32] = 1;
    }*/
    string number = to_string(lightHero[1]);
    QString convNumber = QString::fromStdString(number);
    ui.lightHeroA->setText(convNumber);
    number = to_string(darkHero[1]);
    convNumber = QString::fromStdString(number);
    ui.darkHeroA->setText(convNumber);

    number = to_string(lightHero[2]) + "/" + to_string(lightHero[3]);
    convNumber = QString::fromStdString(number);
    ui.lightHeroH->setText(convNumber);
    number = to_string(darkHero[2]) + "/" + to_string(darkHero[3]);
    convNumber = QString::fromStdString(number);
    ui.darkHeroH->setText(convNumber);

    string text = "";
    if (lightHero[12] != 0) text += "Fr ";
    if (lightHero[13] != 0) text += "SFr ";
    if (lightHero[14] == 1) text += "ST ";
    if (lightHero[15] == 1) text += "ET ";
    if (lightHero[16] == 1) text += "Li ";
    if (lightHero[19] == 1) text += "Fr ";
    if (lightHero[22] == 1) text += "Dea ";
    if (lightHero[25] == 1) text += "Po ";
    if (lightHero[26] == 1) text += "RT ";
    if (lightHero[27] == 1) text += "Ste ";
    if (lightHero[28] == 1) text += "Ta ";
    if (lightHero[29] == 1) text += "Co ";
    if (lightHero[30] == 1) text += "DS ";
    if (lightHero[31] == 1) text += "Pr ";
    if (lightHero[32] == 1) text += "Im ";
    if (lightHero[35] == 1) text += "Sa ";
    if (lightHero[40] == 1) text += "Da ";
    if (lightHero[42] == 1) text += "Res ";
    if (lightHero[42] == 2) text += "Def ";
    if (lightHero[43] != 0) text += "RD ";
    if (lightHero[45] == 1) text += "RT ";
    if (lightHero[48] == 1) text += "MD ";
    if (lightHero[50] == 1) text += "CA ";
    ui.lightHeroI->setText(QString::fromStdString(text));
    
    text = "";
    if (darkHero[12] != 0) text += "Fr ";
    if (darkHero[13] != 0) text += "SFr ";
    if (darkHero[14] == 1) text += "ST ";
    if (darkHero[15] == 1) text += "ET ";
    if (darkHero[16] == 1) text += "Li ";
    if (darkHero[19] == 1) text += "Fr ";
    if (darkHero[22] == 1) text += "Dea ";
    if (darkHero[25] == 1) text += "Po ";
    if (darkHero[26] == 1) text += "RT ";
    if (darkHero[27] == 1) text += "Ste ";
    if (darkHero[28] == 1) text += "Ta ";
    if (darkHero[29] == 1) text += "Co ";
    if (darkHero[30] == 1) text += "DS ";
    if (darkHero[31] == 1) text += "Pr ";
    if (darkHero[32] == 1) text += "Im ";
    if (darkHero[35] == 1) text += "Sa ";
    if (darkHero[40] == 1) text += "Da ";
    if (darkHero[42] == 1) text += "Res ";
    if (darkHero[42] == 2) text += "Def ";
    if (darkHero[43] != 0) text += "RD ";
    if (darkHero[45] == 1) text += "RT ";
    if (darkHero[48] == 1) text += "MD ";
    if (darkHero[50] == 1) text += "CA ";
    ui.darkHeroI->setText(QString::fromStdString(text));
    

    // print weapon
    if (lightHaveWeapon == 0)
    {
        string number = to_string(-1);
        string path = "image/80x80/" + number + ".png";
        QString convPath = QString::fromStdString(path);
        QPixmap theImage(convPath);
        ui.lightWeapon->setPixmap(theImage);

        ui.lightWeaponA->setText("");
        ui.lightWeaponH->setText("");
        ui.lightWeaponI->setText("");
    }
    else {
        string number = to_string(lightWeapon[0]);
        string path = "image/80x80/" + number + ".png";
        QString convPath = QString::fromStdString(path);
        QPixmap theImage(convPath);
        ui.lightWeapon->setPixmap(theImage);

        ui.lightWeaponA->setText(printAttack(lightWeapon));
        ui.lightWeaponH->setText(printHealth(lightWeapon));
    }

    if (darkHaveWeapon == 0) {
        string number = to_string(-1);
        string path = "image/80x80/" + number + ".png";
        QString convPath = QString::fromStdString(path);
        QPixmap theImage(convPath);
        ui.darkWeapon->setPixmap(theImage);

        ui.darkWeaponA->setText("");
        ui.darkWeaponH->setText("");
        ui.darkWeaponI->setText("");
    }
    else {
        string number = to_string(darkWeapon[0]);
        string path = "image/80x80/" + number + ".png";
        QString convPath = QString::fromStdString(path);
        QPixmap theImage(convPath);
        ui.darkWeapon->setPixmap(theImage);

        ui.darkWeaponA->setText(printAttack(darkWeapon));
        ui.darkWeaponH->setText(printHealth(darkWeapon));
    }

    if (getAttack(lightHero) > 0 && lightHero[5] == 1 && turn == 0)  ui.lightHero->setEnabled(true);
    else ui.lightHero->setEnabled(false);
    if (getAttack(darkHero) > 0 && darkHero[5] == 1 && turn == 1)  ui.darkHero->setEnabled(true);
    else ui.darkHero->setEnabled(false);
    if (lightHero[7] == 1 && turn == 0)  ui.lightSkill->setEnabled(true);
    else ui.lightSkill->setEnabled(false);
    if (darkHero[7] == 1 && turn == 1)  ui.darkSkill->setEnabled(true);
    else ui.darkSkill->setEnabled(false);
}
void Hearthstone::updateManaVisual() {
    if (turn == 0)
        updateManaVisualCont(lightMaxMana, lightCurrMana, lightOverloadMana, lightOverloadedMana);
    else
        updateManaVisualCont(darkMaxMana, darkCurrMana, darkOverloadMana, darkOverloadedMana);
}
void Hearthstone::updateManaVisualCont(int max, int curr, int load, int loaded) {
    if (curr > 0 && max > 0) { ui.mana0->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana0->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana0->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana0->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana0->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana1->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana1->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana1->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana1->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana1->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana2->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana2->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana2->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana2->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana2->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana3->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana3->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana3->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana3->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana3->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana4->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana4->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana4->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana4->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana4->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana5->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana5->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana5->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana5->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana5->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana6->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana6->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana6->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana6->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana6->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana7->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana7->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana7->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana7->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana7->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana8->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana8->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana8->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana8->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana8->setPixmap(getColour("grey"));
                }
            }
        }
    }

    if (curr > 0 && max > 0) { ui.mana9->setPixmap(getColour("blue")); max--; curr--; }
    else {
        if (load > 0 && max > 0) { ui.mana9->setPixmap(getColour("red")); max--; load--; }
        else {
            if (loaded > 0 && max > 0) { ui.mana9->setPixmap(getColour("orange")); max--; loaded--; }
            else {
                if (max > 0) { ui.mana9->setPixmap(getColour("cyan")); max--; }
                else {
                    ui.mana9->setPixmap(getColour("grey"));
                }
            }
        }
    }
}
QPixmap Hearthstone::getColour(string colour) {
    string path = "image/colours/" + colour + ".png";
    QString convPath = QString::fromStdString(path);
    QPixmap theImage(convPath);
    return theImage;
}
void Hearthstone::updateOtherVisual() {
    ui.darkPlace0->setVisible(false);
    ui.darkPlace1->setVisible(false);
    ui.darkPlace2->setVisible(false);
    ui.darkPlace3->setVisible(false);
    ui.darkPlace4->setVisible(false);
    ui.darkPlace5->setVisible(false);
    ui.darkPlace6->setVisible(false);
    ui.darkPlace7->setVisible(false);
    ui.lightPlace0->setVisible(false);
    ui.lightPlace1->setVisible(false);
    ui.lightPlace2->setVisible(false);
    ui.lightPlace3->setVisible(false);
    ui.lightPlace4->setVisible(false);
    ui.lightPlace5->setVisible(false);
    ui.lightPlace6->setVisible(false);
    ui.lightPlace7->setVisible(false);

    ui.place->setEnabled(false);
    ui.finish->setEnabled(true);
    ui.cancel->setEnabled(false);
    ui.lightChoice0->setEnabled(false);
    ui.lightChoice1->setEnabled(false);
    ui.darkChoice0->setEnabled(false);
    ui.darkChoice1->setEnabled(false);

    if (lightSmoke[0] == 1) ui.lightMinionI0->setStyleSheet("background-color:#d3d3d3;");
    if (lightSmoke[1] == 1) ui.lightMinionI1->setStyleSheet("background-color:#d3d3d3;");
    if (lightSmoke[2] == 1) ui.lightMinionI2->setStyleSheet("background-color:#d3d3d3;");
    if (lightSmoke[3] == 1) ui.lightMinionI3->setStyleSheet("background-color:#d3d3d3;");
    if (lightSmoke[4] == 1) ui.lightMinionI4->setStyleSheet("background-color:#d3d3d3;");
    if (lightSmoke[5] == 1) ui.lightMinionI5->setStyleSheet("background-color:#d3d3d3;");
    if (lightSmoke[6] == 1) ui.lightMinionI6->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[0] == 1) ui.darkMinionI0->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[1] == 1) ui.darkMinionI1->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[2] == 1) ui.darkMinionI2->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[3] == 1) ui.darkMinionI3->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[4] == 1) ui.darkMinionI4->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[5] == 1) ui.darkMinionI5->setStyleSheet("background-color:#d3d3d3;");
    if (darkSmoke[6] == 1) ui.darkMinionI6->setStyleSheet("background-color:#d3d3d3;");
}
void Hearthstone::updateGameInfo() {
    lightDeckInfo = lightDeck.size();
    lightHandInfo = lightHand.size();
    darkDeckInfo = darkDeck.size();
    darkHandInfo = darkHand.size();

    int number;
    string message;
    QString convMessage;

    number = lightHand.size();
    message = "Light's hand: " + to_string(number);
    convMessage = QString::fromStdString(message);
    ui.gameInfo0->setText(convMessage);

    number = lightDeck.size();
    message = "Light's deck: " + to_string(number);
    convMessage = QString::fromStdString(message);
    ui.gameInfo1->setText(convMessage);

    number = darkHand.size();
    message = "Dark's hand: " + to_string(number);
    convMessage = QString::fromStdString(message);
    ui.gameInfo2->setText(convMessage);

    number = darkDeck.size();
    message = "Dark's deck: " + to_string(number);
    convMessage = QString::fromStdString(message);
    ui.gameInfo3->setText(convMessage);
}
void Hearthstone::printButton(int i, string size, string button) {
    QString convButton = QString::fromStdString(button);
    QPushButton* theButton = findChild<QPushButton*>(convButton);
    string number = to_string(i);
    string path = "image/" + size + "/" + number + ".png";
    QString convPath = QString::fromStdString(path);
    QPixmap pixmap(convPath);
    QIcon ButtonIcon(pixmap);
    theButton->setIcon(ButtonIcon);
    theButton->setIconSize(pixmap.rect().size());
}
// thread
Hearthstone::Hearthstone(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    hidePlayground();
    hideChoosePage();
    hideQuitPage();
    initialize();
    mapFunction();

    for (int i = 0; i < 10; i++)
        historyText[i] = "";
}
void Hearthstone::initialize() {
    for (int i = 0; i < 30; i++) {
        lightDeck.push_back(i);
    }
    shuffleDeck(lightDeck);
    for (int i = 0; i < 30; i++) {
        darkDeck.push_back(i + 30);
    }
    shuffleDeck(darkDeck);
}
void Hearthstone::on_start_clicked() {
    hideWelcome();
    prepareChoose();
    showChoosePage();
    
}
void Hearthstone::on_quit_clicked() {
    qApp->exit();
}
void Hearthstone::prepareChoose() {

    srand(time(NULL));
    firstHand = rand() / 10;
    firstHand %= 2;

    if (firstHand == 0) {
        ui.chooseInfo0->setText("Light League get first hand");
        ui.chooseInfo1->setText("Dark League get second hand");
        for (int i = 0; i < 3; i++) {
            lightHand.push_back(lightDeck[0]);
            lightDeck.erase(lightDeck.begin());
        }
        for (int i = 0; i < 4; i++) {
            darkHand.push_back(darkDeck[0]);
            darkDeck.erase(darkDeck.begin());
        }
        printButton(lightHand[0], "240x341", "chooseBtn0");
        printButton(lightHand[1], "240x341", "chooseBtn1");
        printButton(lightHand[2], "240x341", "chooseBtn2");
        printButton(darkHand[0], "240x341", "chooseBtn3");
        printButton(darkHand[1], "240x341", "chooseBtn4");
        printButton(darkHand[2], "240x341", "chooseBtn5");
        printButton(darkHand[3], "240x341", "chooseBtn6");
    }
    else {
        ui.chooseInfo0->setText("Dark League get first hand");
        ui.chooseInfo1->setText("Light League get second hand");
        for (int i = 0; i < 3; i++) {
            darkHand.push_back(darkDeck[0]);
            darkDeck.erase(darkDeck.begin());
        }
        for (int i = 0; i < 4; i++) {
            lightHand.push_back(lightDeck[0]);
            lightDeck.erase(lightDeck.begin());
        }
        printButton(lightHand[0], "240x341", "chooseBtn3");
        printButton(lightHand[1], "240x341", "chooseBtn4");
        printButton(lightHand[2], "240x341", "chooseBtn5");
        printButton(lightHand[3], "240x341", "chooseBtn6");
        printButton(darkHand[0], "240x341", "chooseBtn0");
        printButton(darkHand[1], "240x341", "chooseBtn1");
        printButton(darkHand[2], "240x341", "chooseBtn2");
    }
}
void Hearthstone::shuffleDeck(vector<int>& deck) {
    srand(time(NULL));
    static int times = rand() % 100 + 1;
    times = (times * times + rand() % 100) % 100 + 1;
    auto rng = default_random_engine{};
    for (int i = 0; i <= times; i++)
        shuffle(begin(deck), end(deck), rng);
}
void Hearthstone::on_done_clicked() {
    replaceCard(); hideChoosePage(); showPlayground(); shuffleDeck(lightDeck); shuffleDeck(darkDeck);
    printButton(100, "80x80", "lightHero"); printButton(101, "80x80", "darkHero"); printButton(61, "80x80", "lightSkill"); printButton(62, "80x80", "darkSkill");

    for (int i = 0; i < lightHand.size(); i++) {
        lightCardAtt.push_back(cardLibrary.cardList[lightHand[i]].attack);
        lightCardAttE.push_back(0);
        lightCardAttT.push_back(0);
    }
    for (int i = 0; i < darkHand.size(); i++) {
        darkCardAtt.push_back(cardLibrary.cardList[darkHand[i]].attack);
        darkCardAttE.push_back(0);
        darkCardAttT.push_back(0);
    }
    
    start = 1;

    if (firstHand == 0) {
        darkHand.push_back(60);
        darkCardAtt.push_back(cardLibrary.cardList[60].attack);
        darkCardAttE.push_back(0);
        darkCardAttT.push_back(0);
        
        turn = 0;
        firstHand = 1;
        startTurn();
    }
    else {
        lightHand.push_back(60);
        lightCardAtt.push_back(cardLibrary.cardList[60].attack);
        lightCardAttE.push_back(0);
        lightCardAttT.push_back(0);
        
        turn = 1;
        firstHand = 0;
        startTurn();
    }
}
// page switch
void Hearthstone::hideWelcome() {
    QPushButton* startFeature2 = findChild<QPushButton*>("start");
    startFeature2->hide();
    ui.logo->setVisible(false);
}
void Hearthstone::hideChoosePage() {
    ui.chooseBtn0->setVisible(false);
    ui.chooseBtn1->setVisible(false);
    ui.chooseBtn2->setVisible(false);
    ui.chooseBtn3->setVisible(false);
    ui.chooseBtn4->setVisible(false);
    ui.chooseBtn5->setVisible(false);
    ui.chooseBtn6->setVisible(false);
    ui.chooseBtn6->setVisible(false);
    ui.chooseBtn0r->setVisible(false);
    ui.chooseBtn1r->setVisible(false);
    ui.chooseBtn2r->setVisible(false);
    ui.chooseBtn3r->setVisible(false);
    ui.chooseBtn4r->setVisible(false);
    ui.chooseBtn5r->setVisible(false);
    ui.chooseBtn6r->setVisible(false);
    ui.done->setVisible(false);

    ui.chooseInfo0->setVisible(false);
    ui.chooseInfo1->setVisible(false);
    ui.prompt0->setVisible(false);
}
void Hearthstone::showChoosePage() {
    ui.chooseBtn0->setVisible(true);
    ui.chooseBtn1->setVisible(true);
    ui.chooseBtn2->setVisible(true);
    ui.chooseBtn3->setVisible(true);
    ui.chooseBtn4->setVisible(true);
    ui.chooseBtn5->setVisible(true);
    ui.chooseBtn6->setVisible(true);
    ui.done->setVisible(true);

    ui.chooseInfo0->setVisible(true);
    ui.chooseInfo1->setVisible(true);
    ui.prompt0->setVisible(true);
}
void Hearthstone::hidePlayground() {
    ui.lightWeaponI->setVisible(false);
    ui.darkWeaponI->setVisible(false);
    ui.place->setVisible(false);
    ui.cardMana->setVisible(false);
    ui.cardAttack->setVisible(false);
    ui.cardHealth->setVisible(false);
    ui.cardSkill->setVisible(false);

    ui.mana0->setVisible(false);
    ui.mana1->setVisible(false);
    ui.mana2->setVisible(false);
    ui.mana3->setVisible(false);
    ui.mana4->setVisible(false);
    ui.mana5->setVisible(false);
    ui.mana6->setVisible(false);
    ui.mana7->setVisible(false);
    ui.mana8->setVisible(false);
    ui.mana9->setVisible(false);

    ui.gameInfo0->setVisible(false);
    ui.gameInfo1->setVisible(false);
    ui.gameInfo2->setVisible(false);
    ui.gameInfo3->setVisible(false);

    ui.cardBtn0->setVisible(false);
    ui.cardBtn1->setVisible(false);
    ui.cardBtn2->setVisible(false);
    ui.cardBtn3->setVisible(false);
    ui.cardBtn4->setVisible(false);
    ui.cardBtn5->setVisible(false);
    ui.cardBtn6->setVisible(false);
    ui.cardBtn7->setVisible(false);
    ui.cardBtn8->setVisible(false);
    ui.cardBtn9->setVisible(false);

    ui.cardView->setVisible(false);
    ui.cancel->setVisible(false);
    ui.finish->setVisible(false);
    ui.prompt1->setVisible(false);
    ui.history->setVisible(false);
    ui.prompt2->setVisible(false);

    ui.darkChoice0->setVisible(false);
    ui.darkChoice1->setVisible(false);
    ui.darkSubFrame->setVisible(false);
    ui.darkPlace0->setVisible(false);
    ui.darkPlace1->setVisible(false);
    ui.darkPlace2->setVisible(false);
    ui.darkPlace3->setVisible(false);
    ui.darkPlace4->setVisible(false);
    ui.darkPlace5->setVisible(false);
    ui.darkPlace6->setVisible(false);
    ui.darkPlace7->setVisible(false);
    ui.darkMinion0->setVisible(false);
    ui.darkMinion1->setVisible(false);
    ui.darkMinion2->setVisible(false);
    ui.darkMinion3->setVisible(false);
    ui.darkMinion4->setVisible(false);
    ui.darkMinion5->setVisible(false);
    ui.darkMinion6->setVisible(false);
    ui.darkMinionA0->setVisible(false);
    ui.darkMinionA1->setVisible(false);
    ui.darkMinionA2->setVisible(false);
    ui.darkMinionA3->setVisible(false);
    ui.darkMinionA4->setVisible(false);
    ui.darkMinionA5->setVisible(false);
    ui.darkMinionA6->setVisible(false);
    ui.darkMinionH0->setVisible(false);
    ui.darkMinionH1->setVisible(false);
    ui.darkMinionH2->setVisible(false);
    ui.darkMinionH3->setVisible(false);
    ui.darkMinionH4->setVisible(false);
    ui.darkMinionH5->setVisible(false);
    ui.darkMinionH6->setVisible(false);
    ui.darkMinionI0->setVisible(false);
    ui.darkMinionI1->setVisible(false);
    ui.darkMinionI2->setVisible(false);
    ui.darkMinionI3->setVisible(false);
    ui.darkMinionI4->setVisible(false);
    ui.darkMinionI5->setVisible(false);
    ui.darkMinionI6->setVisible(false);

    ui.darkHeroI->setVisible(false);
    ui.lightHeroI->setVisible(false);

    ui.darkHero->setVisible(false);
    ui.darkHeroA->setVisible(false);
    ui.darkHeroH->setVisible(false);
    ui.darkWeapon->setVisible(false);
    ui.darkWeaponA->setVisible(false);
    ui.darkWeaponH->setVisible(false);
    ui.darkSkill->setVisible(false);

    ui.lightChoice0->setVisible(false);
    ui.lightChoice1->setVisible(false);
    ui.lightSubFrame->setVisible(false);
    ui.lightPlace0->setVisible(false);
    ui.lightPlace1->setVisible(false);
    ui.lightPlace2->setVisible(false);
    ui.lightPlace3->setVisible(false);
    ui.lightPlace4->setVisible(false);
    ui.lightPlace5->setVisible(false);
    ui.lightPlace6->setVisible(false);
    ui.lightPlace7->setVisible(false);
    ui.lightMinion0->setVisible(false);
    ui.lightMinion1->setVisible(false);
    ui.lightMinion2->setVisible(false);
    ui.lightMinion3->setVisible(false);
    ui.lightMinion4->setVisible(false);
    ui.lightMinion5->setVisible(false);
    ui.lightMinion6->setVisible(false);
    ui.lightMinionA0->setVisible(false);
    ui.lightMinionA1->setVisible(false);
    ui.lightMinionA2->setVisible(false);
    ui.lightMinionA3->setVisible(false);
    ui.lightMinionA4->setVisible(false);
    ui.lightMinionA5->setVisible(false);
    ui.lightMinionA6->setVisible(false);
    ui.lightMinionH0->setVisible(false);
    ui.lightMinionH1->setVisible(false);
    ui.lightMinionH2->setVisible(false);
    ui.lightMinionH3->setVisible(false);
    ui.lightMinionH4->setVisible(false);
    ui.lightMinionH5->setVisible(false);
    ui.lightMinionH6->setVisible(false);
    ui.lightMinionI0->setVisible(false);
    ui.lightMinionI1->setVisible(false);
    ui.lightMinionI2->setVisible(false);
    ui.lightMinionI3->setVisible(false);
    ui.lightMinionI4->setVisible(false);
    ui.lightMinionI5->setVisible(false);
    ui.lightMinionI6->setVisible(false);
    ui.lightHero->setVisible(false);
    ui.lightHeroA->setVisible(false);
    ui.lightHeroH->setVisible(false);
    ui.lightWeapon->setVisible(false);
    ui.lightWeaponA->setVisible(false);
    ui.lightWeaponH->setVisible(false);
    ui.lightSkill->setVisible(false);
}
void Hearthstone::showPlayground() {
    ui.lightWeaponI->setVisible(true);
    ui.darkWeaponI->setVisible(true);
    ui.place->setVisible(true);
    ui.mana0->setVisible(true);
    ui.mana1->setVisible(true);
    ui.mana2->setVisible(true);
    ui.mana3->setVisible(true);
    ui.mana4->setVisible(true);
    ui.mana5->setVisible(true);
    ui.mana6->setVisible(true);
    ui.mana7->setVisible(true);
    ui.mana8->setVisible(true);
    ui.mana9->setVisible(true);

    ui.gameInfo0->setVisible(true);
    ui.gameInfo1->setVisible(true);
    ui.gameInfo2->setVisible(true);
    ui.gameInfo3->setVisible(true);

    ui.cardBtn0->setVisible(true);
    ui.cardBtn1->setVisible(true);
    ui.cardBtn2->setVisible(true);
    ui.cardBtn3->setVisible(true);
    ui.cardBtn4->setVisible(true);
    ui.cardBtn5->setVisible(true);
    ui.cardBtn6->setVisible(true);
    ui.cardBtn7->setVisible(true);
    ui.cardBtn8->setVisible(true);
    ui.cardBtn9->setVisible(true);

    ui.cardView->setVisible(true);
    ui.finish->setVisible(true);
    ui.cancel->setVisible(true);
    ui.prompt1->setVisible(true);
    ui.history->setVisible(true);
    ui.prompt2->setVisible(true);

    ui.darkChoice0->setVisible(true);
    ui.darkChoice1->setVisible(true);
    ui.darkSubFrame->setVisible(true);
    ui.darkPlace0->setVisible(true);
    ui.darkPlace1->setVisible(true);
    ui.darkPlace2->setVisible(true);
    ui.darkPlace3->setVisible(true);
    ui.darkPlace4->setVisible(true);
    ui.darkPlace5->setVisible(true);
    ui.darkPlace6->setVisible(true);
    ui.darkPlace7->setVisible(true);
    ui.darkMinion0->setVisible(true);
    ui.darkMinion1->setVisible(true);
    ui.darkMinion2->setVisible(true);
    ui.darkMinion3->setVisible(true);
    ui.darkMinion4->setVisible(true);
    ui.darkMinion5->setVisible(true);
    ui.darkMinion6->setVisible(true);
    ui.darkMinionA0->setVisible(true);
    ui.darkMinionA1->setVisible(true);
    ui.darkMinionA2->setVisible(true);
    ui.darkMinionA3->setVisible(true);
    ui.darkMinionA4->setVisible(true);
    ui.darkMinionA5->setVisible(true);
    ui.darkMinionA6->setVisible(true);
    ui.darkMinionH0->setVisible(true);
    ui.darkMinionH1->setVisible(true);
    ui.darkMinionH2->setVisible(true);
    ui.darkMinionH3->setVisible(true);
    ui.darkMinionH4->setVisible(true);
    ui.darkMinionH5->setVisible(true);
    ui.darkMinionH6->setVisible(true);
    ui.darkMinionI0->setVisible(true);
    ui.darkMinionI1->setVisible(true);
    ui.darkMinionI2->setVisible(true);
    ui.darkMinionI3->setVisible(true);
    ui.darkMinionI4->setVisible(true);
    ui.darkMinionI5->setVisible(true);
    ui.darkMinionI6->setVisible(true);
    ui.darkHero->setVisible(true);
    ui.darkHeroA->setVisible(true);
    ui.darkHeroH->setVisible(true);
    ui.darkWeapon->setVisible(true);
    ui.darkWeaponA->setVisible(true);
    ui.darkWeaponH->setVisible(true);
    ui.darkSkill->setVisible(true);

    ui.darkHeroI->setVisible(true);
    ui.lightHeroI->setVisible(true);

    ui.lightChoice0->setVisible(true);
    ui.lightChoice1->setVisible(true);
    ui.lightSubFrame->setVisible(true);
    ui.lightPlace0->setVisible(true);
    ui.lightPlace1->setVisible(true);
    ui.lightPlace2->setVisible(true);
    ui.lightPlace3->setVisible(true);
    ui.lightPlace4->setVisible(true);
    ui.lightPlace5->setVisible(true);
    ui.lightPlace6->setVisible(true);
    ui.lightPlace7->setVisible(true);
    ui.lightMinion0->setVisible(true);
    ui.lightMinion1->setVisible(true);
    ui.lightMinion2->setVisible(true);
    ui.lightMinion3->setVisible(true);
    ui.lightMinion4->setVisible(true);
    ui.lightMinion5->setVisible(true);
    ui.lightMinion6->setVisible(true);
    ui.lightMinionA0->setVisible(true);
    ui.lightMinionA1->setVisible(true);
    ui.lightMinionA2->setVisible(true);
    ui.lightMinionA3->setVisible(true);
    ui.lightMinionA4->setVisible(true);
    ui.lightMinionA5->setVisible(true);
    ui.lightMinionA6->setVisible(true);
    ui.lightMinionH0->setVisible(true);
    ui.lightMinionH1->setVisible(true);
    ui.lightMinionH2->setVisible(true);
    ui.lightMinionH3->setVisible(true);
    ui.lightMinionH4->setVisible(true);
    ui.lightMinionH5->setVisible(true);
    ui.lightMinionH6->setVisible(true);
    ui.lightMinionI0->setVisible(true);
    ui.lightMinionI1->setVisible(true);
    ui.lightMinionI2->setVisible(true);
    ui.lightMinionI3->setVisible(true);
    ui.lightMinionI4->setVisible(true);
    ui.lightMinionI5->setVisible(true);
    ui.lightMinionI6->setVisible(true);
    ui.lightHero->setVisible(true);
    ui.lightHeroA->setVisible(true);
    ui.lightHeroH->setVisible(true);
    ui.lightWeapon->setVisible(true);
    ui.lightWeaponA->setVisible(true);
    ui.lightWeaponH->setVisible(true);
    ui.lightSkill->setVisible(true);

    ui.lightChoice0->setEnabled(false);
    ui.lightChoice1->setEnabled(false);
    ui.darkChoice0->setEnabled(false);
    ui.darkChoice1->setEnabled(false);
    ui.cancel->setEnabled(false);
}
void Hearthstone::hideQuitPage() {
    ui.quitMessage->setVisible(false);
    ui.quit->setVisible(false);
}
void Hearthstone::endOfGame(int i) {
    if (i == 0)
        ui.quitMessage->setText("Dark League Won!");
    else
        ui.quitMessage->setText("Light League Won!");

    hidePlayground();
    ui.quitMessage->setVisible(true);
    ui.quit->setVisible(true);
}
// replace cards
void Hearthstone::replaceCard() {
    if (firstHand == 0) {
        if (replace[0] == 1) { int replace = lightHand[0]; lightHand[0] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace);}
        if (replace[1] == 1) { int replace = lightHand[1]; lightHand[1] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace);}
        if (replace[2] == 1) { int replace = lightHand[2]; lightHand[2] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace); }
        if (replace[3] == 1) { int replace = darkHand[0]; darkHand[0] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
        if (replace[4] == 1) { int replace = darkHand[1]; darkHand[1] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
        if (replace[5] == 1) { int replace = darkHand[2]; darkHand[2] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
        if (replace[6] == 1) { int replace = darkHand[3]; darkHand[3] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
    }
    else {
        if (replace[0] == 1) { int replace = darkHand[0]; darkHand[0] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
        if (replace[1] == 1) { int replace = darkHand[1]; darkHand[1] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
        if (replace[2] == 1) { int replace = darkHand[2]; darkHand[2] = darkDeck[0]; darkDeck.erase(darkDeck.begin()); darkDeck.push_back(replace); }
        if (replace[3] == 1) { int replace = lightHand[0]; lightHand[0] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace); }
        if (replace[4] == 1) { int replace = lightHand[1]; lightHand[1] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace); }
        if (replace[5] == 1) { int replace = lightHand[2]; lightHand[2] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace); }
        if (replace[6] == 1) { int replace = lightHand[3]; lightHand[3] = lightDeck[0]; lightDeck.erase(lightDeck.begin()); lightDeck.push_back(replace); }
    }
}
void Hearthstone::on_chooseBtn0_clicked() {
    ui.chooseBtn0->setVisible(false);
    ui.chooseBtn0r->setVisible(true);
    replace[0] = 1;
}
void Hearthstone::on_chooseBtn1_clicked() {
    ui.chooseBtn1->setVisible(false);
    ui.chooseBtn1r->setVisible(true);
    replace[1] = 1;
}
void Hearthstone::on_chooseBtn2_clicked() {
    ui.chooseBtn2->setVisible(false);
    ui.chooseBtn2r->setVisible(true);
    replace[2] = 1;
}
void Hearthstone::on_chooseBtn3_clicked() {
    ui.chooseBtn3->setVisible(false);
    ui.chooseBtn3r->setVisible(true);
    replace[3] = 1;
}
void Hearthstone::on_chooseBtn4_clicked() {
    ui.chooseBtn4->setVisible(false);
    ui.chooseBtn4r->setVisible(true);
    replace[4] = 1;
}
void Hearthstone::on_chooseBtn5_clicked() {
    ui.chooseBtn5->setVisible(false);
    ui.chooseBtn5r->setVisible(true);
    replace[5] = 1;
}
void Hearthstone::on_chooseBtn6_clicked() {
    ui.chooseBtn6->setVisible(false);
    ui.chooseBtn6r->setVisible(true);
    replace[6] = 1;
}
void Hearthstone::on_chooseBtn0r_clicked() {
    ui.chooseBtn0->setVisible(true);
    ui.chooseBtn0r->setVisible(false);
    replace[0] = 0;
}
void Hearthstone::on_chooseBtn1r_clicked() {
    ui.chooseBtn1->setVisible(true);
    ui.chooseBtn1r->setVisible(false);
    replace[1] = 0;
}
void Hearthstone::on_chooseBtn2r_clicked() {
    ui.chooseBtn2->setVisible(true);
    ui.chooseBtn2r->setVisible(false);
    replace[2] = 0;
}
void Hearthstone::on_chooseBtn3r_clicked() {
    ui.chooseBtn3->setVisible(true);
    ui.chooseBtn3r->setVisible(false);
    replace[3] = 0;
}
void Hearthstone::on_chooseBtn4r_clicked() {
    ui.chooseBtn4->setVisible(true);
    ui.chooseBtn4r->setVisible(false);
    replace[4] = 0;
}
void Hearthstone::on_chooseBtn5r_clicked() {
    ui.chooseBtn5->setVisible(true);
    ui.chooseBtn5r->setVisible(false);
    replace[5] = 0;
}
void Hearthstone::on_chooseBtn6r_clicked() {
    ui.chooseBtn6->setVisible(true);
    ui.chooseBtn6r->setVisible(false);
    replace[6] = 0;
}
// play cards
void Hearthstone::on_cardBtn0_clicked() {
    tempCardOrder = 0; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn1_clicked() {
    tempCardOrder = 1; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn2_clicked() {
    tempCardOrder = 2; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn3_clicked() {
    tempCardOrder = 3; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn4_clicked() {
    tempCardOrder = 4; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn5_clicked() {
    tempCardOrder = 5; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn6_clicked() {
    tempCardOrder = 6; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn7_clicked() {
    tempCardOrder = 7; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn8_clicked() {
    tempCardOrder = 8; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
void Hearthstone::on_cardBtn9_clicked() {
    tempCardOrder = 9; 
    if (turn == 0) playACard(lightHand[tempCardOrder]); else playACard(darkHand[tempCardOrder]);
}
// place minion
void Hearthstone::checkMinionPlayType() {
    if (turn == 0) {
        if (tempPlayType == 0) {
            comfirmPlayCard();
        }
        else if (tempPlayType == 3) {
            if (lightMinion.size() <= 0) comfirmPlayCard();
            else {
                minionAttack = 2;
                ui.place->setEnabled(true);
                enterSelectMode3();
            }
        }
        else if (tempPlayType == 1) {
            if (darkMinion.size() <= 0) comfirmPlayCard();
            else {
                minionAttack = 2;
                ui.place->setEnabled(true);
                enterSelectMode1();
            }
        }
        else if (tempPlayType == 5) {
            if (darkMinion.size() <= 0 && lightMinion.size() <= 0) comfirmPlayCard();
            else {
                minionAttack = 2;
                ui.place->setEnabled(true);
                enterSelectMode5();
            }
        }
        else if (tempPlayType == 8) {
            if (tempID == 11)  enterChooseOneMode("Restore all health for friendly minion", "Restore 20 health for your hero");
            else qApp->exit();
        }
        else if (tempPlayType == 9) {
            if (tempID == 51)  enterThreatMode("All your minions take 8 damages", "Your hero take 20 damage");
            else if (tempID == 58) enterThreatMode("Let opponent draw 2 cards", "Discard two cards");
            else qApp->exit();
        }
        else { 
            comfirmPlayCard();
        }
    }
    else {
        if (tempPlayType == 0) {
            comfirmPlayCard();
        }
        else if (tempPlayType == 3) {
            if (darkMinion.size() <= 0) comfirmPlayCard();
            else {
                minionAttack = 2;
                ui.place->setEnabled(true);
                enterSelectMode3();
            }
        }
        else if (tempPlayType == 5) {
            if (darkMinion.size() <= 0 && lightMinion.size() <= 0) comfirmPlayCard();
            else {
                minionAttack = 2;
                ui.place->setEnabled(true);
                enterSelectMode5();
            }
        }
        else if (tempPlayType == 1) {
            if (lightMinion.size() <= 0) comfirmPlayCard();
            else {
                minionAttack = 2;
                ui.place->setEnabled(true);
                enterSelectMode1();
            }
        }
        else if (tempPlayType == 8) {
            if (tempID == 11)  enterChooseOneMode("Restore all health for friendly minion", "Restore 20 health for your hero");
            else qApp->exit();
        }
        else if (tempPlayType == 9) {
            if (tempID == 51)  enterThreatMode("All your minions take 8 damages", "Your hero take 20 damage");
            else if (tempID == 58) enterThreatMode("Let opponent draw 2 cards", "Discard two cards");
            else qApp->exit();
        }
        else {
            comfirmPlayCard();
        }
    }
}
void Hearthstone::on_lightPlace0_clicked() {
    tempPlace = 0;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace1_clicked() {
    tempPlace = 1;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace2_clicked() {
    tempPlace = 2;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace3_clicked() {
    tempPlace = 3;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace4_clicked() {
    tempPlace = 4;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace5_clicked() {
    tempPlace = 5;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace6_clicked() {
    tempPlace = 6;
    checkMinionPlayType();
}
void Hearthstone::on_lightPlace7_clicked() {
    tempPlace = 7;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace0_clicked() {
    tempPlace = 0;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace1_clicked() {
    tempPlace = 1;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace2_clicked() {
    tempPlace = 2;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace3_clicked() {
    tempPlace = 3;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace4_clicked() {
    tempPlace = 4;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace5_clicked() {
    tempPlace = 5;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace6_clicked() {
    tempPlace = 6;
    checkMinionPlayType();
}
void Hearthstone::on_darkPlace7_clicked() {
    tempPlace = 7;
    checkMinionPlayType();
}
// minion
bool Hearthstone::availableTarget(int camp, int index) { // ID 27 here   
    if (camp == 0) {
        if (index == 7) { if (lightHero[27] == 1) { historyUpdate("Character with stealth cannot be target"); return 0; } } 
        else { 
            if (lightMinion[index][27] == 1) { 
                historyUpdate("Character with stealth cannot be target"); 
                return 0; 
            }  
            return 1;
        }
        
    }
    else {
        if (index == 7) { if (darkHero[27] == 1) { historyUpdate("Character with stealth cannot be target"); return 0; } }
        else {
            if (darkMinion[index][27] == 1) {
                historyUpdate("Character with stealth cannot be target");
                return 0;
            }
            return 1;
        }
    }
    return 1;
}
bool Hearthstone::availableAttack(int camp, int index) {
    if (camp == 0) {
        if (index == 7) {
            if (lightHero[27] == 1) {historyUpdate("Character with stealth cannot be target");return 0;}      // ID 27 here   
            int taunt = 0;
            for (int i = 0; i < lightMinion.size(); i++) { if (lightMinion[i][28] == 1)  taunt = 1;}// ID 28 here

            if (taunt == 1) {historyUpdate("You must attack minion with taunt firstly");return 0;}
            else {return 1;}
        }
        else {
            if (lightMinion[index][27] == 1) { historyUpdate("Character with stealth cannot be target"); return 0; } // ID 27 here
            
            if (lightMinion[index][28] == 1) return 1;// ID 28 here
            else {
                int taunt = 0;
                for (int i = 0; i < lightMinion.size(); i++) { if (lightMinion[i][28] == 1)  taunt = 1; }

                if (taunt == 1) { historyUpdate("You must attack minion with taunt firstly"); return 0; } 
                else { // not taunt at all
                    if (lightMinion[index][29] == 0) return 1; // ID 29 here
                    else { // target is commander
                        int common = 0;
                        for (int i = 0; i < lightMinion.size(); i++) { if (lightMinion[i][29] == 0 && lightMinion[i][27] == 0)  common = 1; }

                        if (common == 1) { historyUpdate("You must destroy all non-commanders' minions firstly"); return 0; }
                        else { return 1; }
                    }
                }
            }  
        }
    }
    else {
        if (index == 7) {
            if (darkHero[27] == 1) { historyUpdate("Character with stealth cannot be target"); return 0; } // ID 27 here
            int taunt = 0;
            for (int i = 0; i < darkMinion.size(); i++) { if (darkMinion[i][28] == 1)  taunt = 1; }// ID 28 here

            if (taunt == 1) { historyUpdate("You must attack minion with taunt firstly"); return 0; }
            else { return 1; }
        }
        else {
            if (darkMinion[index][27] == 1) { historyUpdate("Character with stealth cannot be target"); return 0; } // ID 27 here

            if (darkMinion[index][28] == 1) return 1;// ID 28 here
            else {
                int taunt = 0;
                for (int i = 0; i < darkMinion.size(); i++) { if (darkMinion[i][28] == 1)  taunt = 1; }

                if (taunt == 1) { historyUpdate("You must attack minion with taunt firstly"); return 0; }
                else { // not taunt at all
                    if (darkMinion[index][29] == 0) return 1;// ID 29 here
                    else { // target is commander
                        int common = 0;
                        for (int i = 0; i < darkMinion.size(); i++) { if (darkMinion[i][29] == 0 && darkMinion[i][27] == 0)  common = 1; }

                        if (common == 1) { historyUpdate("You must destroy all non-commanders' minions firstly"); return 0; }
                        else { return 1; }
                    }
                }
            }
        }
    }
}
void Hearthstone::getTarget(int order) {
    int id = getMinionID(order);
    if (0 <= order && order <= 7) {
        if (id == 7) {
            theTarget = 0;
        }
        else {
            theTarget = lightMinion[id][4];
        }
    }
    else {
        if (id == 7) {
            theTarget = 0;
        }
        else {
            theTarget = darkMinion[id][4];
        }
    }
}
void Hearthstone::on_lightMinion0_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][0];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][0];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(0);
        if (availableTarget(0, getMinionID(0)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightMinion1_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][1];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][1];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();     
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(1);
        if (availableTarget(0, getMinionID(1)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightMinion2_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][2];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][2];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(2);
        if (availableTarget(0, getMinionID(2)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightMinion3_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][3];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][3];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(3);
        if (availableTarget(0, getMinionID(3)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightMinion4_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][4];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][4];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(4);
        if (availableTarget(0, getMinionID(4)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightMinion5_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][5];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][5];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(5);
        if (availableTarget(0, getMinionID(5)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightMinion6_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[lightMinion.size()][6];
        if (lightMinion[attacker][12] != 0 || lightMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[lightMinion.size()][6];
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(6);
        if (availableTarget(0, getMinionID(6)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_lightHero_clicked() {
    if (minionAttack == 1) {
        if (lightHero[12] != 0 || lightHero[13] != 0) {
            historyUpdate("Frozen hero cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        attacker = 7;
        lightAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = 7;
        if (availableAttack(0, defencer)) battle(1);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(7);
        if (availableTarget(0, getMinionID(7)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion0_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][0];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][0];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(8);
        if (availableTarget(1, getMinionID(8)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion1_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][1];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][1];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(9);
        if (availableTarget(1, getMinionID(9)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion2_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][2];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][2];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(10);
        if (availableTarget(1, getMinionID(10)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion3_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][3];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][3];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(11);
        if (availableTarget(1, getMinionID(11)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion4_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][4];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][4];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(12);
        if (availableTarget(1, getMinionID(12)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion5_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][5];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][5];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(13);
        if (availableTarget(1, getMinionID(13)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkMinion6_clicked() {
    if (minionAttack == 1) {
        attacker = alignMinion[darkMinion.size()][6];
        if (darkMinion[attacker][12] != 0 || darkMinion[attacker][13] != 0) {
            historyUpdate("Frozen minion cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = alignMinion[darkMinion.size()][6];
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(14);
        if (availableTarget(1, getMinionID(14)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}
void Hearthstone::on_darkHero_clicked() {
    if (minionAttack == 1) {
        if (darkHero[12] != 0 || darkHero[13] != 0) {
            historyUpdate("Frozen hero cannot attack");
            updateEverything();
            return;
        }
        minionAttack = 0;
        attacker = 7;
        darkAttackActive();
    }
    else if (minionAttack == 0) {
        minionAttack = 1;
        defencer = 7;
        if (availableAttack(1, defencer)) battle(0);
        else on_cancel_clicked();
    }
    else if (minionAttack == 2) {
        minionAttack = 1;
        getTarget(15);
        if (availableTarget(1, getMinionID(15)))comfirmPlayCard();
        else on_cancel_clicked();
    }
}

// choice
void Hearthstone::on_darkChoice0_clicked() {
    theChoice = 0;
    comfirmPlayCard();
}
void Hearthstone::on_darkChoice1_clicked() {
    theChoice = 1;
    comfirmPlayCard();
}
void Hearthstone::on_lightChoice0_clicked() {
    theChoice = 0;
    comfirmPlayCard();
}
void Hearthstone::on_lightChoice1_clicked() {
    theChoice = 1;
    comfirmPlayCard();
}
// skill
void Hearthstone::on_darkSkill_clicked() {
   tempCardOrder = 10; playACard(62); 
}
void Hearthstone::on_lightSkill_clicked() {
    tempCardOrder = 10; playACard(61);
}
void Hearthstone::on_place_clicked() {
    theTarget = -1;
    comfirmPlayCard();
}

// comment 
/*
void Hearthstone::function2226(int camp, int index, vector<int> sample, vector<int>& minion) {
    if (camp == 0) {
        lightHero[32] = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is take care of Azeroth");
    }
    else {
        darkHero[32] = 1;
        historyUpdate(cardLibrary.cardList[minion[0]].name + " is take care of Lord");
    }
} */

/*void Hearthstone::function2522(int camp, int index, vector<int> sample, vector<int>& minion) {
    srand(time(NULL));
    int chance = (rand() % 100);
    if (camp == 0) {
        int amount = 0;
        for (int i = 0; i < lightMinion.size(); i++) {
            if (lightMinion[i][17] == 0 && lightMinion[i][20] == 0) amount++;
        }

        if (amount > 0) {
            while (1) {
                if (lightMinion[chance % lightMinion.size()][17] == 0 && lightMinion[chance % lightMinion.size()][20] == 0 && lightMinion[chance % lightMinion.size()][2] > 0) {
                    lightMinion[chance % lightMinion.size()][41] = 1;
                    historyUpdate(cardLibrary.cardList[lightMinion[chance % lightMinion.size()][0]].name + " be the new guardidan");
                    break;
                }
                else {
                    chance++;
                }
            }
        }
    }
    else {
        int amount = 0;
        for (int i = 0; i < darkMinion.size(); i++) {
            if (darkMinion[i][17] == 0 && darkMinion[i][20] == 0) amount++;
        }

        if (amount > 0) {
            while (1) {
                if (darkMinion[chance % darkMinion.size()][17] == 0 && darkMinion[chance % darkMinion.size()][20] == 0 && darkMinion[chance % lightMinion.size()][2] > 0) {
                    darkMinion[chance % darkMinion.size()][41] = 1;
                    historyUpdate(cardLibrary.cardList[darkMinion[chance % darkMinion.size()][0]].name + " be the new guardidan");
                    break;
                }
                else {
                    chance++;
                }
            }
        }
    }
}*/
