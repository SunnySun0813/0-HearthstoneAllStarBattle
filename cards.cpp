#include "cards.h"

using namespace std;

Cards::Cards() {
    cardList[0].name = "Illidan Stormrage";
    cardList[0].cost = 3; cardList[0].attack = 7; cardList[0].health = 7; cardList[0].type = 1; cardList[0].rarity = 1;
    cardList[0].ability[7] = 1; cardList[0].ability[15] = 1; cardList[0].ability[22] = 1;


    cardList[1].name = "Chronormu";
    cardList[1].cost = 0; cardList[1].attack = 1; cardList[1].health = 1; cardList[1].type = 1; cardList[1].rarity = 1;
    cardList[1].ability[0] = 1; cardList[1].ability[39] = 1;

    cardList[2].name = "Varian Wrynn";
    cardList[2].cost = 2; cardList[2].attack = 7; cardList[2].health = 7; cardList[2].type = 1; cardList[2].rarity = 1;
    cardList[2].ability[11] = 1; cardList[2].ability[19] = 1; cardList[2].ability[18] = 1; cardList[2].ability[0] = 1;


    cardList[3].name = "Anduin Wrynn";
    cardList[3].cost = 2; cardList[3].attack = 4; cardList[3].health = 4; cardList[3].type = 1; cardList[3].rarity = 1;
    cardList[3].ability[0] = 1; cardList[3].ability[29] = 1; cardList[3].ability[45] = 1;

    cardList[4].name = "Valeera Sanguinar";
    cardList[4].cost = 1; cardList[4].attack = 6; cardList[4].health = 3; cardList[4].type = 1; cardList[4].rarity = 1;
    cardList[4].ability[27] = 1; cardList[4].ability[39] = 1; cardList[4].ability[1] = 1;

    cardList[5].name = "Medivh";
    cardList[5].cost = 2; cardList[5].attack = 6; cardList[5].health = 6; cardList[5].type = 1; cardList[5].rarity = 1;
    cardList[5].ability[29] = 1; cardList[5].ability[0] = 1; cardList[5].ability[26] = 1;

    cardList[6].name = "Antonidas";
    cardList[6].cost = 2; cardList[6].attack = 3; cardList[6].health = 3; cardList[6].type = 1; cardList[6].rarity = 1;
    cardList[6].ability[0] = 1; cardList[6].ability[39] = 1; 

    cardList[7].name = "Grommash Hellscream";
    cardList[7].cost = 3; cardList[7].attack = 6; cardList[7].health = 10; cardList[7].type = 1; cardList[7].rarity = 1;
    cardList[7].ability[11] = 1; cardList[7].ability[21] = 1; cardList[7].ability[0] = 1; cardList[7].ability[18] = 1;

    cardList[8].name = "Jaina Proudmoore";
    cardList[8].cost = 2; cardList[8].attack = 6; cardList[8].health = 4; cardList[8].type = 1; cardList[8].rarity = 1;
    cardList[8].ability[26] = 1; cardList[8].ability[15] = 1; cardList[8].ability[0] = 1;


    cardList[9].name = "Khadgar";
    cardList[9].cost = 2; cardList[9].attack = 5; cardList[9].health = 5; cardList[9].type = 1; cardList[9].rarity = 1;
    cardList[9].ability[29] = 1; cardList[9].ability[15] = 1; cardList[9].ability[0] = 1;

    cardList[10].name = "Blademaster Samuro";
    cardList[10].cost = 3; cardList[10].attack = 7; cardList[10].health = 6; cardList[10].type = 1; cardList[10].rarity = 1;
    cardList[10].ability[27] = 1; cardList[10].ability[0] = 1; cardList[10].ability[21] = 1; cardList[10].ability[22] = 1;

    cardList[11].name = "Malfurion Stormrage";
    cardList[11].cost = 2; cardList[11].attack = 4; cardList[11].health = 6; cardList[11].type = 1; cardList[11].rarity = 1;
    cardList[11].ability[39] = 1; cardList[11].ability[8] = 1;


    cardList[12].name = "Rexxar";
    cardList[12].cost = 1; cardList[12].attack = 6; cardList[12].health = 6; cardList[12].type = 1; cardList[12].rarity = 1;
    cardList[12].ability[39] = 1; cardList[12].ability[0] = 1;

    cardList[13].name = "Ysera";
    cardList[13].cost = 3; cardList[13].attack = 4; cardList[13].health = 12; cardList[13].type = 1; cardList[13].rarity = 1;
    cardList[13].ability[0] = 1; cardList[13].ability[15] = 1; cardList[13].ability[29] = 1;

    cardList[14].name = "GallyWix";
    cardList[14].cost = 0; cardList[14].attack = 3; cardList[14].health = 3; cardList[14].type = 1; cardList[14].rarity = 1;
    cardList[14].ability[10] = 1; cardList[14].ability[0] = 1;

    cardList[15].name = "Velen";
    cardList[15].cost = 1; cardList[15].attack = 4; cardList[15].health = 7; cardList[15].type = 1; cardList[15].rarity = 1;
    cardList[15].ability[39] = 1; cardList[15].ability[0] = 1;

    cardList[16].name = "Genn Greymane";
    cardList[16].cost = 2; cardList[16].attack = 5; cardList[16].health = 5; cardList[16].type = 1; cardList[16].rarity = 1;
    cardList[16].ability[0] = 1; cardList[16].ability[21] = 1; cardList[16].ability[42] = 2;

    cardList[17].name = "Thrall";
    cardList[17].cost = 2; cardList[17].attack = 4; cardList[17].health = 6; cardList[17].type = 1; cardList[17].rarity = 1;
    cardList[17].ability[26] = 1; cardList[17].ability[15] = 1; cardList[17].ability[0] = 1;

    cardList[18].name = "Uther Lightbringer";
    cardList[18].cost = 3; cardList[18].attack = 6; cardList[18].health = 8; cardList[18].type = 1; cardList[18].rarity = 1;
    cardList[18].ability[0] = 1; cardList[18].ability[15] = 1; cardList[18].ability[26] = 1; cardList[18].ability[30] = 1; cardList[18].ability[44] = 2;

    cardList[19].name = "Tyrande Whisperwind";
    cardList[19].cost = 2; cardList[19].attack = 4; cardList[19].health = 4; cardList[19].type = 1; cardList[19].rarity = 1;
    cardList[19].ability[39] = 1; cardList[19].ability[0] = 1;


    cardList[20].name = "Alextrasza";
    cardList[20].cost = 4; cardList[20].attack = 4; cardList[20].health = 12; cardList[20].type = 1; cardList[20].rarity = 1;
    cardList[20].ability[10] = 1; cardList[20].ability[0] = 1;


    cardList[21].name = "Nozdormu";
    cardList[21].cost = 3; cardList[21].attack = 8; cardList[21].health = 8; cardList[21].type = 1; cardList[21].rarity = 1;
    cardList[21].ability[0] = 1; cardList[21].ability[39] = 1;

    cardList[22].name = "Bolvar Fordragon";
    cardList[22].cost = 2; cardList[22].attack = 2; cardList[22].health = 7; cardList[22].type = 1; cardList[22].rarity = 1;
    cardList[22].ability[0] = 1; cardList[22].ability[33] = 1; cardList[22].ability[28] = 1;


    cardList[23].name = "Elune";
    cardList[23].cost = 4; cardList[23].attack = 4; cardList[23].health = 16; cardList[23].type = 1; cardList[23].rarity = 1;
    cardList[23].ability[0] = 1; cardList[23].ability[26] = 1;

    cardList[24].name = "Ogrim Doomhammer";
    cardList[24].cost = 2; cardList[24].attack = 6; cardList[24].health = 8; cardList[24].type = 1; cardList[24].rarity = 1;
    cardList[24].ability[0] = 1;  cardList[24].ability[10] = 1; cardList[24].ability[11] = 1;


    cardList[25].name = "Aegwynn";
    cardList[25].cost = 5; cardList[25].attack = 6; cardList[25].health = 14; cardList[25].type = 1; cardList[25].rarity = 1;
    cardList[25].ability[0] = 1;  cardList[25].ability[39] = 1; //cardList[25].ability[29] = 1; cardList[25].ability[22] = 1;

    cardList[26].name = "Chen Stormstout";
    cardList[26].cost = 2; cardList[26].attack = 1; cardList[26].health = 10; cardList[26].type = 1; cardList[26].rarity = 1;
    cardList[26].ability[0] = 1;  cardList[26].ability[33] = 1; cardList[26].ability[23] = 1;

    cardList[27].name = "Anduin Lothar";
    cardList[27].cost = 2; cardList[27].attack = 7; cardList[27].health = 7; cardList[27].type = 1; cardList[27].rarity = 1;
    cardList[27].ability[11] = 1; cardList[27].ability[22] = 1; cardList[27].ability[0] = 1;


    cardList[28].name = "Garona Halforcen";
    cardList[28].cost = 0; cardList[28].attack = 1; cardList[28].health = 1; cardList[28].type = 1; cardList[28].rarity = 1;
    cardList[28].ability[7] = 1; cardList[28].ability[10] = 1; cardList[28].ability[25] = 1;


    cardList[29].name = "Tirion Fordring";
    cardList[29].cost = 4; cardList[29].attack = 4; cardList[29].health = 10; cardList[29].type = 1; cardList[29].rarity = 1;
    cardList[29].ability[0] = 1; cardList[29].ability[29] = 1; cardList[29].ability[35] = 1;


    cardList[30].name = "Al Akir the Windlord";
    cardList[30].cost = 2; cardList[30].attack = 6; cardList[30].health = 10; cardList[30].type = 1; cardList[30].rarity = 1;
    cardList[30].ability[11] = 1; cardList[30].ability[21] = 1; cardList[30].ability[0] = 1;


    cardList[31].name = "Garrosh Hellscream";
    cardList[31].cost = 0; cardList[31].attack = 2; cardList[31].health = 10; cardList[31].type = 1; cardList[31].rarity = 1;
    cardList[31].ability[28] = 1; cardList[31].ability[0] = 1; cardList[31].ability[14] = 1; cardList[31].ability[33] = 1;

    cardList[32].name = "Kaelthas Sunstrider";
    cardList[32].cost = 1; cardList[32].attack = 7; cardList[32].health = 4; cardList[32].type = 1; cardList[32].rarity = 1;
    cardList[32].ability[0] = 1; cardList[32].ability[14] = 1; cardList[32].ability[29] = 1;


    cardList[33].name = "C Thun";
    cardList[33].cost = 3; cardList[33].attack = 10; cardList[33].health = 18; cardList[33].type = 1; cardList[33].rarity = 1;
    cardList[33].ability[0] = 1;  cardList[33].ability[36] = 1; cardList[33].ability[37] = 1;
 

    cardList[34].name = "Sargeras";
    cardList[34].cost = 20; cardList[34].attack = 20; cardList[34].health = 30; cardList[34].type = 1; cardList[34].rarity = 1;
    cardList[34].ability[0] = 1; cardList[34].ability[47] = 1;


    cardList[35].name = "Nefarian";
    cardList[35].cost = 2; cardList[35].attack = 7; cardList[35].health = 7; cardList[35].type = 1; cardList[35].rarity = 1;
    cardList[35].ability[0] = 1; cardList[35].ability[39] = 1;


    cardList[36].name = "Gul dan";
    cardList[36].cost = 0; cardList[36].attack = 5; cardList[36].health = 5; cardList[36].type = 1; cardList[36].rarity = 1;
    cardList[36].ability[0] = 1;  cardList[36].ability[16] = 1;  cardList[36].ability[39] = 1;

    cardList[37].name = "Onyxia";
    cardList[37].cost = 0; cardList[37].attack = 3; cardList[37].health = 3; cardList[37].type = 1; cardList[37].rarity = 1;
    cardList[37].ability[26] = 1; cardList[37].ability[7] = 1;


    cardList[38].name = "Mannoroth";
    cardList[38].cost = 1; cardList[38].attack = 5; cardList[38].health = 8; cardList[38].type = 1; cardList[38].rarity = 1;
    cardList[38].ability[0] = 1; cardList[38].ability[22] = 1;


    cardList[39].name = "Lich King";
    cardList[39].cost = 3; cardList[39].attack = 8; cardList[39].health = 8; cardList[39].type = 1; cardList[39].rarity = 1;
    cardList[39].ability[28] = 1; cardList[39].ability[5] = 1; cardList[39].ability[52] = 1; cardList[39].ability[39] = 1;


    cardList[40].name = "Yogg Saron";
    cardList[40].cost = 3; cardList[40].attack = 5; cardList[40].health = 20; cardList[40].type = 1; cardList[40].rarity = 1;
    cardList[40].ability[10] = 1; cardList[40].ability[0] = 1;

    cardList[41].name = "Archimonde";
    cardList[41].cost = 5; cardList[41].attack = 10; cardList[41].health = 12; cardList[41].type = 1; cardList[41].rarity = 1;
    cardList[41].ability[39] = 1; cardList[41].ability[0] = 1;

    cardList[42].name = "Kil jaeden";
    cardList[42].cost = 0; cardList[42].attack = 0; cardList[42].health = 20; cardList[42].type = 1; cardList[42].rarity = 1;
    cardList[42].ability[10] = 1; cardList[42].ability[0] = 1;


    cardList[43].name = "Lei Shen";
    cardList[43].cost = 2; cardList[43].attack = 6; cardList[43].health = 6; cardList[43].type = 1; cardList[43].rarity = 1;
    cardList[43].ability[39] = 1; cardList[43].ability[3] = 1;


    cardList[44].name = "N Zoth";
    cardList[44].cost = 5; cardList[44].attack = 6; cardList[44].health = 18; cardList[44].type = 1; cardList[44].rarity = 1;
    cardList[44].ability[39] = 1; cardList[44].ability[0] = 1;


    cardList[45].name = "Mal Ganis";
    cardList[45].cost = 1; cardList[45].attack = 5; cardList[45].health = 5; cardList[45].type = 1; cardList[45].rarity = 1;
    cardList[45].ability[39] = 1; cardList[45].ability[1] = 1; cardList[45].ability[22] = 1;


    cardList[46].name = "Galakrond";
    cardList[46].cost = 4; cardList[46].attack = 8; cardList[46].health = 12; cardList[46].type = 1; cardList[46].rarity = 1;
    cardList[46].ability[1] = 1; cardList[46].ability[10] = 1;


    cardList[47].name = "Cho Gall";
    cardList[47].cost = 4; cardList[47].attack = 5; cardList[47].health = 10; cardList[47].type = 1; cardList[47].rarity = 1;
    cardList[47].ability[0] = 1; cardList[47].ability[10] = 1; cardList[47].ability[15] = 1;


    cardList[48].name = "Sindragosa";
    cardList[48].cost = 5; cardList[48].attack = 7; cardList[48].health = 7; cardList[48].type = 1; cardList[48].rarity = 1;
    cardList[48].ability[0] = 1; cardList[48].ability[39] = 1;

    cardList[49].name = "The Jailer";
    cardList[49].cost = 5; cardList[49].attack = 1; cardList[49].health = 20; cardList[49].type = 1; cardList[49].rarity = 1;
    cardList[49].ability[0] = 1; cardList[49].ability[46] = 1;

    cardList[50].name = "Y Shaarj";
    cardList[50].cost = 3; cardList[50].attack = 10; cardList[50].health = 20; cardList[50].type = 1; cardList[50].rarity = 1;
    cardList[50].ability[0] = 1; cardList[50].ability[22] = 1;

    cardList[51].name = "Ragnaros";
    cardList[51].cost = 3; cardList[51].attack = 8; cardList[51].health = 8; cardList[51].type = 1; cardList[51].rarity = 1;
    cardList[51].ability[9] = 1; cardList[51].ability[39] = 1;


    cardList[52].name = "Malygos";
    cardList[52].cost = 4; cardList[52].attack = 8; cardList[52].health = 8; cardList[52].type = 1; cardList[52].rarity = 1;
    cardList[52].ability[0] = 1; cardList[52].ability[49] = 1;


    cardList[53].name = "Deathwing";
    cardList[53].cost = 5; cardList[53].attack = 15; cardList[53].health = 15; cardList[53].type = 1; cardList[53].rarity = 1;
    cardList[53].ability[0] = 1; cardList[53].ability[10] = 1;


    cardList[54].name = "Kel Thuzad";
    cardList[54].cost = 1; cardList[54].attack = 4; cardList[54].health = 8; cardList[54].type = 1; cardList[54].rarity = 1;
    cardList[54].ability[29] = 1; cardList[54].ability[0] = 1; cardList[54].ability[48] = 1;


    cardList[55].name = "Sylvanas Windrunner";
    cardList[55].cost = 1; cardList[55].attack = 5; cardList[55].health = 5; cardList[55].type = 1; cardList[55].rarity = 1;
    cardList[55].ability[0] = 1; cardList[55].ability[22] = 1;


    cardList[56].name = "Rend Blackhand";
    cardList[56].cost = 2; cardList[56].attack = 8; cardList[56].health = 6; cardList[56].type = 1; cardList[56].rarity = 1;
    cardList[56].ability[0] = 1; cardList[56].ability[10] = 1;

    cardList[57].name = "Ner zhul";
    cardList[57].cost = 1; cardList[57].attack = 1; cardList[57].health = 1; cardList[57].type = 1; cardList[57].rarity = 1;
    cardList[57].ability[1] = 1; cardList[57].ability[10] = 1;

    cardList[58].name = "Vashj";
    cardList[58].cost = 0; cardList[58].attack = 4; cardList[58].health = 4; cardList[58].type = 1; cardList[58].rarity = 1;
    cardList[58].ability[9] = 1; cardList[58].ability[10] = 1;

    cardList[59].name = "Edwin VanCleef";
    cardList[59].cost = 0; cardList[59].attack = 6; cardList[59].health = 3; cardList[59].type = 1; cardList[59].rarity = 1;
    cardList[59].ability[10] = 1; cardList[59].ability[0] = 1;


    cardList[60].name = "Lucky Coin";
    cardList[60].cost = 0; cardList[60].attack = -1; cardList[60].health = -1; cardList[60].type = 2; cardList[60].rarity = 5;
    cardList[60].ability[0] = 1;

    cardList[61].name = "Disarm";
    cardList[61].cost = 1; cardList[61].attack = -1; cardList[61].health = -1; cardList[61].type = 4; cardList[61].rarity = 5;
    cardList[61].ability[1] = 1;

    cardList[62].name = "Shadow Blast";
    cardList[62].cost = 1; cardList[62].attack = -1; cardList[62].health = -1; cardList[62].type = 4; cardList[62].rarity = 5;
    cardList[62].ability[0] = 1;

    cardList[63].name = "Sheep";
    cardList[63].cost = 0; cardList[63].attack = 1; cardList[63].health = 1; cardList[63].type = 1; cardList[63].rarity = 5;
    cardList[63].ability[0] = 1; 

    cardList[64].name = "Super Beast";
    cardList[64].cost = 1; cardList[64].attack = 5; cardList[64].health = 5; cardList[64].type = 1; cardList[64].rarity = 5;
    cardList[64].ability[0] = 1; cardList[64].ability[26] = 1; cardList[64].ability[11] = 1; cardList[64].ability[28] = 1;

    cardList[65].name = "Chromatic Dragon";
    cardList[65].cost = 0; cardList[65].attack = 1; cardList[65].health = 1; cardList[65].type = 1; cardList[65].rarity = 5;
    cardList[65].ability[0] = 1;

    cardList[66].name = "Frog";
    cardList[66].cost = 0; cardList[66].attack = 0; cardList[66].health = 1; cardList[66].type = 1; cardList[66].rarity = 5;
    cardList[66].ability[0] = 1; cardList[66].ability[28] = 1;

    cardList[67].name = "Ice Barrier";
    cardList[67].cost = 0; cardList[67].attack = 0; cardList[67].health = 5; cardList[67].type = 1; cardList[67].rarity = 5;
    cardList[67].ability[0] = 1; cardList[67].ability[50] = 1;

    cardList[68].name = "Battle Axe";
    cardList[68].cost = 0; cardList[68].attack = 5; cardList[68].health = 3; cardList[68].type = 3; cardList[68].rarity = 5;
    cardList[68].ability[0] = 1; cardList[68].ability[51] = 1;
}
