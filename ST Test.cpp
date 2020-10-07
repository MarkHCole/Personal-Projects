#include <iostream>
#include <string>
#include <iomanip>
#include <thread>

using namespace std;

void populator(int);
void comparator();
void mitemconstructor();
void aitemconstructor();

float RegenComp = 0;
float GPH = 0;
float GPHComp = 0;
float Items[500][20];
const char* ItemNames[500][22] =
{
{"NULL", "NULL"},
{"Squire Sword", "Sword"},
{"Arming Sword", "Sword"},
{"Gladius", "Sword"},
{"Arboreal Blade", "Sword"},
{"Zweihander", "Sword"},
{"Cutlass", "Sword"},
{"Espada", "Sword"},
{"Hero's Sword", "Sword"},
{"Katana", "Sword"},
{"Regal Blade", "Sword"},
{"Celesteel Blade", "Sword"},
{"Damocles", "Sword"},
{"Luxurious Macuahuitl", "Sword"},
{"Mythril Edge", "Sword"},
{"Seafarer Blade", "Sword"},
{"Gentleman Blade", "Sword"},
{"Wood Axe", "Axe"},
{"Hatchet", "Axe"},
{"Iron Chopper", "Axe"},
{"Explorer's Axe", "Axe"},
{"Bardiche", "Axe"},
{"Molten Voulge", "Axe"},
{"Tomahawk", "Axe"},
{"Battleaxe", "Axe"},
{"Dwarven Greataxe", "Axe"},
{"Stonesplitter", "Axe"},
{"Raider Axe", "Axe"},
{"Executioner", "Axe"},
{"Purgatory", "Axe"},
{"Axe of The Fifth", "Axe"},
{"Shiv", "Dagger"},
{"Ice Pick", "Dagger"},
{"Swift Blade", "Dagger"},
{"Kunai", "Dagger"},
{"Stealth Knife", "Dagger"},
{"Balisong", "Dagger"},
{"Ritual Dagger", "Dagger"},
{"Assassin Tanto", "Dagger"},
{"Kingsguard", "Dagger"},
{"Fishmonger", "Dagger"},
{"Troll Tooth", "Dagger"},
{"Levia Fang", "Dagger"},
{"Misericordia", "Dagger"},
{"Luxurious Poignard", "Dagger"},
{"Cudgel", "Mace"},
{"Spiked Cudgel", "Mace"},
{"Darkwood Branch", "Mace"},
{"Warhammer", "Mace"},
{"Liberty Mace", "Mace"},
{"Morning Star", "Mace"},
{"Inflatable Maul", "Mace"},
{"Flanged Mace", "Mace"},
{"Skull Crusher", "Mace"},
{"Evening Star", "Mace"},
{"Meteor Hammer", "Mace"},
{"Powder Keg", "Mace"},
{"Whack-O'-Lantern", "Mace"},
{"Peppermint Mallet", "Mace"},
{"Tenderizer", "Mace"},
{"Wallace Mallet", "Mace"},
{"Javelin", "Spear"},
{"Hunting Spear", "Spear"},
{"Bladed Spear", "Spear"},
{"Sturdy Pitchfork", "Spear"},
{"Ranseur", "Spear"},
{"Trishula", "Spear"},
{"Warlord Halberd", "Spear"},
{"Spetum", "Spear"},
{"Triton Lance", "Spear"},
{"Royal Halberd", "Spear"},
{"Champion Lance", "Spear"},
{"Wyvern Glaive", "Spear"},
{"Luxurious Spear", "Spear"},
{"Training Bow", "Bow"},
{"Tailwind", "Bow"},
{"Elmwood Bow", "Bow"},
{"Reflex Bow", "Bow"},
{"Grand Harp", "Bow"},
{"Compound Bow", "Bow"},
{"Deadeye", "Bow"},
{"Raptoria", "Bow"},
{"Quetzalcoatl", "Bow"},
{"L'Arabesque", "Bow"},
{"Yumi", "Bow"},
{"Cupid Bow", "Bow"},
{"Bramblebane", "Bow"},
{"Carved Branch", "Staff"},
{"Sturdy Cane", "Staff"},
{"Oak Staff", "Staff"},
{"Owl Perch", "Staff"},
{"Luxurious Stick", "Staff"},
{"Bo Staff", "Staff"},
{"Jade Scepter", "Staff"},
{"Amber Staff", "Staff"},
{"Wizard Staff", "Staff"},
{"Staff of Seasons", "Staff"},
{"Celestial Staff", "Staff"},
{"Imperial Aquila", "Staff"},
{"Phoenix Staff", "Staff"},
{"Transcendence", "Staff"},
{"Tidebringer", "Staff"},
{"Zesty Scepter", "Staff"},
{"Baton", "Wand"},
{"Elvenwood Wand", "Wand"},
{"Hexer's Wand", "Wand"},
{"Steel Rod", "Wand"},
{"Star Rod", "Wand"},
{"Sylvanel", "Wand"},
{"Ruby Wand", "Wand"},
{"Wand of Midas", "Wand"},
{"Evergreen Wand", "Wand"},
{"Light Crossbow", "Crossbow"},
{"Hand Crossbow", "Crossbow"},
{"Arbalest", "Crossbow"},
{"Heavy Crossbow", "Crossbow"},
{"Hunter's Crossbow", "Crossbow"},
{"Scorpio", "Crossbow"},
{"Double Crossbow", "Crossbow"},
{"Chu-Ko-Nu", "Crossbow"},
{"Triple Crossbow", "Crossbow"},
{"Pellet Gun", "Gun"},
{"Handgun", "Gun"},
{"Smoothbore", "Gun"},
{"Long Rifle", "Gun"},
{"Blunderbuss", "Gun"},
{"Boomstick", "Gun"},
{"Kenora Mk. IV", "Gun"},
{"Prototype Gatling", "Gun"},
{"Dragonator", "Gun"},
{"Mintyleaf Herb", "Herbal Medicine"},
{"Sweet Grass", "Herbal Medicine"},
{"Moon Powder", "Herbal Medicine"},
{"Magical Mistletoe", "Herbal Medicine"},
{"Healing Salve", "Herbal Medicine"},
{"Silver Thistle", "Herbal Medicine"},
{"Bountiful Harvest", "Herbal Medicine"},
{"Bloodvine", "Herbal Medicine"},
{"Mandragoroot", "Herbal Medicine"},
{"Wolf's Bane", "Herbal Medicine"},
{"Mistpeak Bloom", "Herbal Medicine"},
{"Yggdrasil Branch", "Herbal Medicine"},
{"Luckiest Clover", "Herbal Medicine"},
{"Luxurious Panacea", "Herbal Medicine"},
{"Warm Tea", "Potion"},
{"Healing Potion", "Potion"},
{"Magic Potion", "Potion"},
{"Science Project", "Potion"},
{"XL Healing Potion", "Potion"},
{"XL Magic Potion", "Potion"},
{"Old Salt's Brew", "Potion"},
{"Phoenix Tonic", "Potion"},
{"Potion of Renewal", "Potion"},
{"Bottled Mirth", "Potion"},
{"Purple Bomb", "Potion"},
{"Gourd Elixir", "Potion"},
{"Soulfire Extract", "Potion"},
{"Tangy Decoction", "Potion"},
{"Scroll of Sparks", "Spell"},
{"Scroll of Cleansing", "Spell"},
{"Scroll of Armor", "Spell"},
{"Scroll of Storms", "Spell"},
{"Song of Valor", "Spell"},
{"Correspondence", "Spell"},
{"Monster Manual", "Spell"},
{"Tome of the Night", "Spell"},
{"Tome of Knowledge", "Spell"},
{"Tome of Secrets", "Spell"},
{"Naughty or Nice List", "Spell"},
{"Bagua Board", "Spell"},
{"Firework Bundle", "Spell"},
{"Tarot Deck", "Spell"},
{"Grimoire Aeternum", "Spell"},
{"Breastplate", "Heavy Armor"},
{"Iron Mail", "Heavy Armor"},
{"Scale Armor", "Heavy Armor"},
{"Hauberk", "Heavy Armor"},
{"Knight Breastplate", "Heavy Armor"},
{"Ceremonial Breastplate", "Heavy Armor"},
{"Paladin Plate", "Heavy Armor"},
{"Samurai Do", "Heavy Armor"},
{"Brinewater Do", "Heavy Armor"},
{"Warlord Plate", "Heavy Armor"},
{"General Plate", "Heavy Armor"},
{"Landsknecht Plate", "Heavy Armor"},
{"Berserker Armor", "Heavy Armor"},
{"Gaia Enforcer", "Heavy Armor"},
{"Leather Armor", "Light Armor"},
{"Gambeson", "Light Armor"},
{"Doublet", "Light Armor"},
{"Studded Armor", "Light Armor"},
{"Hide Armor", "Light Armor"},
{"Savage Garb", "Light Armor"},
{"Glade Guard Armor", "Light Armor"},
{"Pumpkin Armor", "Light Armor"},
{"Ninja Garb", "Light Armor"},
{"Windrunner Armor", "Light Armor"},
{"Drakeskin Armor", "Light Armor"},
{"Smith Attire", "Light Armor"},
{"Shirt", "Clothes"},
{"Black Robe", "Clothes"},
{"Druid's Robe", "Clothes"},
{"Disciple's Robe", "Clothes"},
{"Scholar's Tunic", "Clothes"},
{"Explorer's Outfit", "Clothes"},
{"Tailor Mantle", "Clothes"},
{"Witch's Outfit", "Clothes"},
{"Vestal Raiments", "Clothes"},
{"Midnight Apparel", "Clothes"},
{"Shaman Vestment", "Clothes"},
{"Luxurious Attire", "Clothes"},
{"Astravestimenta", "Clothes"},
{"Ostara Vest", "Clothes"},
{"Sturdy Cap", "Helmet"},
{"Warrior Helmet", "Helmet"},
{"Horned Helm", "Helmet"},
{"Raider Helm", "Helmet"},
{"Knight Heaume", "Helmet"},
{"Brinewater Helm", "Helmet"},
{"Eagle Helm", "Helmet"},
{"Paladin Helm", "Helmet"},
{"Samurai Kabuto", "Helmet"},
{"Gladiator Helm", "Helmet"},
{"General Heaume", "Helmet"},
{"Crusader Helmet", "Helmet"},
{"Warlord Helmet", "Helmet"},
{"Berserker Helmet", "Helmet"},
{"Leather Cap", "Rogue Hat"},
{"Canopy Cap", "Rogue Hat"},
{"Brimmed Hat", "Rogue Hat"},
{"Feathered Hat", "Rogue Hat"},
{"Tricorn", "Rogue Hat"},
{"Silk Hood", "Rogue Hat"},
{"Pirate Hat", "Rogue Hat"},
{"Lovely Hat", "Rogue Hat"},
{"Night Cowl", "Rogue Hat"},
{"Nomad Veil", "Rogue Hat"},
{"Harvester's Hood", "Rogue Hat"},
{"Windrunner Hat", "Rogue Hat"},
{"Drakeskin Mask", "Rogue Hat"},
{"Storm Dragon Mask", "Rogue Hat"},
{"Stitched Cone", "Magician Hat"},
{"Black Cowl", "Magician Hat"},
{"Druid Laurels", "Magician Hat"},
{"Bronze Circlet", "Magician Hat"},
{"Wizard Hat", "Magician Hat"},
{"Hat of the Four Winds", "Magician Hat"},
{"Witch Hat", "Magician Hat"},
{"Tactician Hat", "Magician Hat"},
{"Summoner Hat", "Magician Hat"},
{"Shaman Hat", "Magician Hat"},
{"Luxurious Headdress", "Magician Hat"},
{"Astral Hat", "Magician Hat"},
{"Raven Mask", "Magician Hat"},
{"Iron Armguards", "Gauntlets"},
{"Plated Gauntlets", "Gauntlets"},
{"Warrior Gauntlets", "Gauntlets"},
{"Demi Gauntlets", "Gauntlets"},
{"Pumpkin Gauntlets", "Gauntlets"},
{"Knight Gauntlets", "Gauntlets"},
{"Paladin Gauntlets", "Gauntlets"},
{"Sungrasp Gauntlets", "Gauntlets"},
{"Landsknecht Gauntlets", "Gauntlets"},
{"Samurai Kote", "Gauntlets"},
{"General Gauntlets", "Gauntlets"},
{"Berserker Gauntlets", "Gauntlets"},
{"Luxurious Gauntlets", "Gauntlets"},
{"Leather Gloves", "Gloves"},
{"Bracers", "Gloves"},
{"Thief's Gloves", "Gloves"},
{"Swift Mitts", "Gloves"},
{"Patchleather Bracers", "Gloves"},
{"Studded Gloves", "Gloves"},
{"Elven Vambraces", "Gloves"},
{"Ostara Gloves", "Gloves"},
{"Savage Claws", "Gloves"},
{"Black Wyrm Claws", "Gloves"},
{"Ninja Gloves", "Gloves"},
{"Windrunner Gloves", "Gloves"},
{"Drakeskin Gloves", "Gloves"},
{"Shin Guards", "Heavy Footwear"},
{"Long Boots", "Heavy Footwear"},
{"Iron Greaves", "Heavy Footwear"},
{"Hero's Boots", "Heavy Footwear"},
{"Reinforced Greaves", "Heavy Footwear"},
{"Knight Sollerets", "Heavy Footwear"},
{"Cindersole", "Heavy Footwear"},
{"Paladin Boots", "Heavy Footwear"},
{"Samurai Haidate", "Heavy Footwear"},
{"General Greaves", "Heavy Footwear"},
{"Berserker Stompers", "Heavy Footwear"},
{"Leather Boots", "Light Footwear"},
{"Trailblazers", "Light Footwear"},
{"Flip-Flops", "Light Footwear"},
{"Soft Shoes", "Light Footwear"},
{"Legionnaire Sandals", "Light Footwear"},
{"Thief's Shoes", "Light Footwear"},
{"Perennial Sandals", "Light Footwear"},
{"Elven Shoes", "Light Footwear"},
{"Savage Stride", "Light Footwear"},
{"Ninja Tabi", "Light Footwear"},
{"Windrunner Boots", "Light Footwear"},
{"Alpine Stride", "Light Footwear"},
{"Drakeskin Boots", "Light Footwear"},
{"Plaguewalkers", "Light Footwear"},
{"Shoes of Style", "Light Footwear"},
{"Wooden Shield", "Shield"},
{"Heavy Buckler", "Shield"},
{"Oaken Shield", "Shield"},
{"Iron Shield", "Shield"},
{"Aurum Ward", "Shield"},
{"Teardrop Shield", "Shield"},
{"Imperial Scutum", "Shield"},
{"Champion Vigil", "Shield"},
{"Mythril Aspis", "Shield"},
{"Wyrmguard", "Shield"},
{"Ancestor Totem", "Shield"},
{"Angelic Pavise", "Shield"},
{"Prometheon", "Shield"},
{"Milesian Shield", "Shield"},
{"Bunbun Buckler", "Shield"},
{"Iron Ring", "Ring"},
{"Alloy Loop", "Ring"},
{"Ruby Ring", "Ring"},
{"Emerald Ring", "Ring"},
{"Silver Band", "Ring"},
{"Ring of Passion", "Ring"},
{"Noble Ring", "Ring"},
{"Ring of Rhythm", "Ring"},
{"Knight Signet", "Ring"},
{"Batrachite Stone", "Ring"},
{"Soulstone Ring", "Ring"},
{"Ring of the Chosen", "Ring"},
{"Brimstone Coil", "Ring"},
{"Fairfolk Band", "Ring"},
{"Dawnflower Ring", "Ring"},
{"Memento", "Amulet"},
{"Jade Pendant", "Amulet"},
{"Iron Bond", "Amulet"},
{"Sun Pendant", "Amulet"},
{"Eclipse Amulet", "Amulet"},
{"Noble Chain", "Amulet"},
{"Lucky Medallion", "Amulet"},
{"Luxurious Charm", "Amulet"},
{"Holy Symbol", "Amulet"},
{"Titanium Torc", "Amulet"},
{"Magical Timepiece", "Amulet"},
{"Magatama Necklace", "Amulet"},
{"Stygian Phylactery", "Amulet"},
{"Ursa Totem", "Amulet"},
{"Chipped Runestone", "Runestone"},
{"Flawed Runestone", "Runestone"},
{"Chiseled Runestone", "Runestone"},
{"Ember Element", "Enchantment"},
{"Flame Element", "Enchantment"},
{"Blaze Element", "Enchantment"},
{"Bubble Element", "Enchantment"},
{"Tide Element", "Enchantment"},
{"Flood Element", "Enchantment"},
{"Breeze Element", "Enchantment"},
{"Gale Element", "Enchantment"},
{"Tempest Element", "Enchantment"},
{"Nature Element", "Enchantment"},
{"Wild Element", "Enchantment"},
{"Primal Element", "Enchantment"},
{"Light Element", "Enchantment"},
{"Holy Element", "Enchantment"},
{"Sacred Element", "Enchantment"},
{"Corrupted Element", "Enchantment"},
{"Unholy Element", "Enchantment"},
{"Nightmare Element", "Enchantment"},
{"Ram Spirit", "Enchantment"},
{"Wolf Spirit", "Enchantment"},
{"Ox Spirit", "Enchantment"},
{"Eagle Spirit", "Enchantment"},
{"Viper Spirit", "Enchantment"},
{"Cat Spirit", "Enchantment"},
{"Rhino Spirit", "Enchantment"},
{"Owl Spirit", "Enchantment"},
{"Armadillo Spirit", "Enchantment"},
{"Lizard Spirit", "Enchantment"},
{"Horse Spirit", "Enchantment"},
{"Hippo Spirit", "Enchantment"},
{"Shark Spirit", "Enchantment"},
{"Walrus Spirit", "Enchantment"},
{"Lion Spirit", "Enchantment"},
{"Bear Spirit", "Enchantment"},
{"Mammoth Spirit", "Enchantment"},
{"Dinosaur Spirit", "Enchantment"},

};
float MatRegen[10] = { 13, 13, 13, 13, 3.5, 3.5, 3.5, 3.5, .65, .65 };
float RegenBuff= 0.3;
const char* MatNames[] = { "Iron", "Wood", "Leather", "Herbs", "Steel", "Ironwood", "Cloth", "Oils", "Ether", "Jewels" };
float SurchargeMax = 1200;
int NumItems=0;
float RegenTime;
float RegenSlow=1;
int Common = 300;
int Uncommon = 66;
int Rare = 22;
int Wait = 20;
float RegenCompS=1000;
float Build[12][17];
float BuildComp[12][17];
float MatType=0;
float NumSlots = 2;
int TierMax = 10;
int TierMin = 1;
float Multicraft = 0;
bool A21 = false;
bool F2P = true;
bool Engineer = false;
bool Academy = false;
bool Chest = false;
float MatBuildComp[10] = { 0,0,0,0,0,0,0,0,0,0 };



int main()
{
    unsigned int nthreads = thread::hardware_concurrency();

    cout << nthreads << endl;
    int Mastery = 1;    
    for (int a = 0; a < 10; a++) {

        cout << "What is the Maximum Tier of Items you want to search.  Default 9" << endl;
        cin >> TierMax;

        cout << "What is the Minimum Tier of Items you want to search.  Default 1" << endl;
        cin >> TierMin;

        cout << "Do you want to include items in packs or special offers in your search?  1=Yes, 0=No" << endl;
        cin >> F2P;

        cout << "Do you want to include Crafty Engineer Pack?" << endl;
        cin >> Engineer;

        cout << "Do you want to include Scholar Pack?" << endl;
        cin >> Academy;

        cout << "Do you want to include items from chests?" << endl;
        cin >> Chest;
        
        cout << "Do you want to compare items as only Mastered (input 0), or as Mastered and Ascended (input 1)?" << endl;
        cin >> Mastery;

        if (Mastery == 1) {
            cout << "Do you want to compare all Ascension Trees as being at 21 stars for the extra multicraft chance? 1 for yes, 0 for no." << endl;
            cin >> A21;
        }

        if (a == 0) {
            cout << "Enter your resource regeneration buff amount as a decimal.  ex. .3 for 30%" << endl;
            cin >> RegenBuff;
            RegenBuff = RegenBuff + 1;
            cout << "Enter your resource regeneration rates." << endl;
            for (int a = 0; a < 10; a++) {
                cout << MatNames[a] << endl;
                cin >> MatRegen[a];
                MatRegen[a] = MatRegen[a] * RegenBuff;
            }

            cout << "Input maximum limit on Common Resources." << endl;
            cin >> Common;

            cout << "Input maximum limit on Uncommon Resources." << endl;
            cin >> Uncommon;

            cout << "Input maximum limit on Rare Resources." << endl;
            cin >> Rare;

            cout << "Input the maximum amount of time you want to wait before starting next round of crafts in minutes." << endl;
            cin >> Wait;

            cout << "Input the minimum amount of time you want to wait before starting next round of crafts in minutes." << endl;
            cin >> RegenSlow;
        }
        
        if (Mastery == 0) { mitemconstructor(); }
        else { aitemconstructor(); }
        cout << "How many item slots do you want to simulate for? More than 4 is NOT recommended." << endl;
        cin >> NumSlots;
        NumSlots = NumSlots - 1;

        for (int c = 0; c <= NumSlots; c++) {
            for (int d = 0; d < 17; d++) {
                BuildComp[c][d] = 0;
                Build[c][d] = 0;
            }
        }

        double TC = 1;

        for (int a = 0; a <= NumSlots; a++) {
            TC = TC * NumItems;
        }

        TC = TC / 300000000;
        bool YouSureBro;

        cout << "This operation will take approximately " << TC << " minutes to complete.  Are you sure you want to continue? 1=Yes, 0=No" << endl;
        cin >> YouSureBro;

        if (YouSureBro == true) {
            break;
        }else{
            return 0;
        }
    }




    populator(NumSlots);
    cout << setprecision(2) << endl;

    cout << endl << endl << endl << endl << endl << "*************************************************************" << endl;
    int Name = 0;
    int Limiter = 0;
    GPH = 0;
    int MatsTotal[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
    for (int d = 0; d <= NumSlots; d++) {
        Name = Build[d][0];
        Limiter = Build[d][16];
        
        cout << ItemNames[Name][0] << endl;
        cout << "Net per sale: " << setprecision(0) << Build[d][1] << endl;
        for (int e = 0; e < 10; e++) {
           if (Build[d][e+3] > 0) {
                cout << MatNames[e] << ": " << Build[d][e+3] << ", " << endl;
            }
            MatsTotal[e] = MatsTotal[e] + Build[d][e+3];
        }

        cout << "Minutes Between Crafts: " << setprecision(2) <<  Build[d][15] << endl;
        cout << "Crafts Per Hour: " << 60/Build[d][15] << endl;
        cout << "Net Gold Per Hour: " << fixed << 60 / Build[d][15] * Build[d][1] << endl;
        cout << "Limiting Factor: " << MatNames[Limiter] << " Regeneration" << endl;
        cout << endl;
        GPH = GPH + Build[d][14];
    }
    cout << "Total Materials Used: " << endl;
    for (int a = 0; a < 10; a++) {
        cout << MatNames[a] << ": " << MatsTotal[a] << ", ";
    }
    cout << endl;
    cout << "Gold Per Hour with Build: " << fixed << GPH << endl << "*************************************************************" << endl << endl;

    return 0;
}

    
void populator(int x) {

    int Comp0 = NumSlots - x;

    for (int b = 0; b < NumItems; b++) {
        for (int c = 0; c < 17; c++) {
            BuildComp[Comp0][c] = Items[b][c];
        }

        if (x > 0) {
            populator(x-1);
        }

        if (x == 0) { comparator(); }

        if (x == NumSlots) {
            cout << b+1 << " tests of " << NumItems << " complete." << endl;
        }
    }
   return;

}

void failconditionless5() {

}

void comparator() {

    for (int b = 0; b <= NumSlots; b++) {
        for (int c = 0; c < 10; c++) {
            if (NumSlots <= 3 && MatBuildComp[c] != 0 && BuildComp[b][c + 3] != 0) {
                MatBuildComp[0] = 0;
                MatBuildComp[1] = 0;
                MatBuildComp[2] = 0;
                MatBuildComp[3] = 0;
                MatBuildComp[4] = 0;
                MatBuildComp[5] = 0;
                MatBuildComp[6] = 0;
                MatBuildComp[7] = 0;
                MatBuildComp[8] = 0;
                MatBuildComp[9] = 0;
                GPHComp = 0;
                RegenComp = 0;
                RegenCompS = 1000;
                return;
            }            
            MatBuildComp[c] = MatBuildComp[c] + BuildComp[b][c+3];
        }        
       
        GPHComp = GPHComp + BuildComp[b][14];
        if (BuildComp[b][15] > RegenComp) {
            RegenComp = BuildComp[b][15];
        }
        if (BuildComp[b][15] < RegenCompS) {
            RegenCompS = BuildComp[b][15];
        }
    }

    for (int a = 0; a < 10; a++) {
        if (MatBuildComp[a] / MatRegen[a] > Wait) {
            MatBuildComp[0] = 0;
            MatBuildComp[1] = 0;
            MatBuildComp[2] = 0;
            MatBuildComp[3] = 0;
            MatBuildComp[4] = 0;
            MatBuildComp[5] = 0;
            MatBuildComp[6] = 0;
            MatBuildComp[7] = 0;
            MatBuildComp[8] = 0;
            MatBuildComp[9] = 0;
            GPHComp = 0;
            RegenComp = 0;
            RegenCompS = 1000;
            return;
        }
    }

    if (MatBuildComp[0] <= Common && MatBuildComp[1] <= Common && MatBuildComp[2] <= Common && MatBuildComp[3] <= Common &&
        MatBuildComp[4] <= Uncommon && MatBuildComp[5] <= Uncommon && MatBuildComp[6] <= Uncommon && MatBuildComp[7] <= Uncommon &&
        MatBuildComp[8] <= Rare && MatBuildComp[9] <= Rare && RegenComp <= Wait && (RegenCompS >= RegenSlow || RegenCompS==0) && GPH < GPHComp) {
        for (int d = 0; d <= NumSlots; d++) {
            for (int e = 0; e < 17; e++) {
                Build[d][e] = BuildComp[d][e];
                cout << Build[d][e] << ", ";
            }
            cout << endl;
        }
        GPH = GPHComp;
    }

    MatBuildComp[0] = 0;
    MatBuildComp[1] = 0;
    MatBuildComp[2] = 0;
    MatBuildComp[3] = 0;
    MatBuildComp[4] = 0;
    MatBuildComp[5] = 0;
    MatBuildComp[6] = 0;
    MatBuildComp[7] = 0;
    MatBuildComp[8] = 0;
    MatBuildComp[9] = 0;
    GPHComp = 0;
    RegenComp = 0;
    RegenCompS = 1000;
}

void mitemconstructor()
{   
        float ItemsLoader[][14] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,160,5,0,0,0,0,0,0,0,0,0},
{2,2,0,520,9,0,0,0,0,0,0,0,0,0},
{3,3,0,-960,11,0,0,0,0,0,0,0,0,0},
{4,3,4,200,13,4,0,0,0,0,0,0,0,0},
{5,3,1,3100,12,0,0,0,0,0,0,0,0,0},
{6,4,0,-2500,17,0,0,0,0,0,0,0,0,0},
{7,5,0,1960,33,0,0,0,8,0,0,0,0,0},
{8,5,1,10450,48,0,0,0,10,0,0,0,0,0},
{9,6,0,24000,68,0,0,0,21,0,0,0,0,0},
{10,7,0,58280,113,0,0,0,36,0,0,18,0,0},
{11,8,0,20800,159,0,0,0,51,0,0,0,0,5},
{12,8,4,150400,171,0,0,0,46,0,0,0,6,0},
{13,8,4,-11600,183,0,0,0,50,0,0,0,0,8},
{14,9,0,261600,207,0,0,0,58,0,0,0,0,12},
{15,9,1,732000,220,0,0,0,62,0,0,0,0,14},
{16,9,1,439200,192,0,0,0,58,0,0,0,14,0},
{17,1,0,940,0,9,0,0,0,0,0,0,0,0},
{18,2,0,-300,0,11,0,0,0,0,0,0,0,0},
{19,3,0,-420,0,14,0,0,0,0,0,0,0,0},
{20,3,1,5300,0,13,0,0,0,0,0,0,0,0},
{21,4,0,-3100,0,24,0,0,0,0,0,0,0,0},
{22,4,4,5900,8,27,0,0,0,0,0,0,0,0},
{23,5,0,8200,0,39,0,0,0,10,0,0,0,0},
{24,6,0,43950,0,79,0,0,0,25,0,0,0,0},
{25,7,0,73760,0,113,0,0,18,36,0,0,0,0},
{26,7,4,139720,0,124,0,0,0,39,0,0,0,0},
{27,8,0,43500,0,171,0,0,0,57,0,0,0,8},
{28,9,0,443120,0,182,0,0,0,54,0,0,0,13},
{29,9,4,493200,0,193,0,0,0,58,0,0,0,16},
{30,9,1,662000,0,193,0,0,0,58,0,0,0,16},
{31,1,0,140,4,0,0,0,0,0,0,0,0,0},
{32,1,4,1000,6,0,0,0,0,0,0,0,0,0},
{33,2,0,760,8,0,0,0,0,0,0,0,0,0},
{34,2,1,1660,13,0,0,0,0,0,0,0,0,0},
{35,3,0,-780,14,0,0,0,0,0,0,0,0,0},
{36,4,0,-5300,22,0,0,0,0,0,0,0,0,0},
{37,5,0,4080,35,0,0,0,9,0,0,0,0,0},
{38,5,1,15080,51,0,0,0,15,0,0,0,0,0},
{39,6,0,22920,71,0,0,0,22,0,0,0,0,0},
{40,7,0,-5250,112,0,0,0,35,0,0,0,0,0},
{41,8,0,-138800,143,0,0,0,46,0,0,0,0,0},
{42,8,4,190320,154,0,0,0,51,0,0,0,0,0},
{43,9,0,47600,175,0,0,0,60,0,0,0,0,0},
{44,9,4,58800,198,0,0,0,69,0,0,0,0,0},
{45,1,0,160,0,5,0,0,0,0,0,0,0,0},
{46,2,0,260,0,8,0,0,0,0,0,0,0,0},
{47,2,4,1600,0,9,0,3,0,0,0,0,0,0},
{48,3,0,-500,0,10,0,0,0,0,0,0,0,0},
{49,3,1,3000,2,11,0,0,0,0,0,0,0,0},
{50,4,0,-4000,5,15,0,0,0,0,0,0,0,0},
{51,4,1,1900,4,18,0,0,0,0,0,0,0,0},
{52,5,0,1340,0,30,0,0,0,7,0,0,0,0},
{53,6,0,21800,0,62,0,0,0,19,0,0,0,0},
{54,7,0,-2200,0,102,0,0,9,32,0,0,0,0},
{55,7,4,107280,0,112,0,0,0,35,0,0,0,0},
{56,8,0,-38720,0,154,0,0,0,51,0,0,6,0},
{57,8,1,156000,0,154,0,0,0,45,0,0,8,0},
{58,8,1,272000,0,154,0,0,0,45,0,0,8,0},
{59,9,0,378400,0,163,0,0,0,48,0,0,10,0},
{60,9,1,631600,0,173,0,0,0,52,0,0,12,0},
{61,1,0,580,0,7,0,0,0,0,0,0,0,0},
{62,2,0,360,0,11,0,0,0,0,0,0,0,0},
{63,3,0,240,0,17,0,0,0,0,0,0,0,0},
{64,3,1,6000,13,21,0,0,0,0,0,0,0,0},
{65,4,0,-2600,17,27,0,0,0,0,0,0,0,0},
{66,5,0,11240,0,48,0,0,0,12,0,0,0,0},
{67,5,1,39800,0,64,21,0,0,17,0,0,0,0},
{68,6,0,48160,0,79,0,0,0,25,0,0,0,0},
{69,6,4,51200,0,87,0,0,0,26,0,0,0,0},
{70,7,0,123380,0,124,0,0,0,39,0,10,0,0},
{71,8,0,89400,0,159,0,0,0,51,0,0,0,7},
{72,9,0,410050,0,182,0,0,0,54,0,0,0,13},
{73,9,4,326000,0,193,0,0,0,58,0,0,0,16},
{74,1,0,660,0,7,0,0,0,0,0,0,0,0},
{75,1,4,-300,0,7,0,0,0,0,0,0,0,0},
{76,2,0,860,0,12,0,0,0,0,0,0,0,0},
{77,3,0,-100,0,14,0,4,0,0,0,0,0,0},
{78,3,2,5900,0,16,13,0,0,0,0,0,0,0},
{79,4,0,-2600,0,24,15,0,0,0,0,0,0,0},
{80,5,0,7330,0,39,0,0,0,10,0,0,0,0},
{81,6,0,26720,0,79,0,0,0,25,0,0,0,0},
{82,6,4,56760,0,87,0,0,0,26,0,0,0,0},
{83,7,0,43000,0,124,0,39,0,39,0,0,0,0},
{84,8,0,7600,0,171,0,0,0,57,0,0,0,6},
{85,8,1,341440,0,171,0,0,0,50,0,0,0,8},
{86,9,0,157500,0,182,0,0,0,54,0,0,0,10},
{87,1,0,180,0,5,0,0,0,0,0,0,0,0},
{88,2,0,580,0,9,0,0,0,0,0,0,0,0},
{89,3,0,-640,0,11,0,0,0,0,0,0,0,0},
{90,3,2,9800,0,17,0,11,0,0,0,0,0,0},
{91,3,4,-175000,0,17,0,9,0,0,0,0,0,0},
{92,4,0,-1650,6,21,0,0,0,0,0,0,0,0},
{93,5,0,9600,0,39,0,0,0,10,0,0,0,0},
{94,5,4,17640,0,46,0,0,0,10,0,0,0,0},
{95,6,0,61800,0,79,0,0,0,25,0,0,0,0},
{96,6,1,74240,0,67,0,0,0,29,0,0,0,0},
{97,7,0,11800,0,113,0,0,0,36,0,18,0,0},
{98,8,0,61200,0,159,0,0,0,51,0,0,7,0},
{99,8,4,276050,0,160,0,0,0,46,0,0,8,0},
{100,9,0,427800,0,195,0,0,0,67,0,0,13,0},
{101,9,4,447280,0,193,0,0,0,58,0,0,16,0},
{102,9,1,706320,0,193,0,0,0,58,0,0,16,0},
{103,1,3,860,0,7,0,0,0,0,0,0,0,0},
{104,2,3,1100,0,13,0,0,0,0,0,0,0,0},
{105,3,3,2340,0,21,0,0,0,0,0,0,0,0},
{106,4,3,4300,9,27,0,0,0,0,0,0,0,0},
{107,5,3,26800,0,48,0,0,0,12,0,9,0,0},
{108,6,3,108800,0,79,0,25,0,25,0,0,0,0},
{109,7,3,76000,0,113,0,0,9,36,0,0,0,0},
{110,8,3,169500,0,159,0,0,0,51,0,0,0,7},
{111,9,3,469280,0,193,0,0,0,58,0,0,0,16},
{112,1,2,520,0,6,0,0,0,0,0,0,0,0},
{113,2,2,1400,0,10,0,0,0,0,0,0,0,0},
{114,3,2,1400,0,15,0,0,0,0,0,0,0,0},
{115,4,2,-300,0,26,0,0,0,0,0,0,0,0},
{116,5,2,21040,0,43,0,12,0,0,0,0,0,0},
{117,6,2,62800,0,87,0,0,0,25,0,0,0,0},
{118,7,2,137000,0,137,0,0,0,39,0,0,0,0},
{119,8,2,190160,0,175,0,0,26,51,0,0,0,0},
{120,9,2,514250,0,214,0,0,0,58,0,0,0,16},
{121,1,2,980,10,5,0,0,0,0,0,0,0,0},
{122,2,2,2100,15,7,0,0,0,0,0,0,0,0},
{123,3,2,2140,18,11,0,0,0,0,0,0,0,0},
{124,4,2,11480,30,17,0,0,0,0,0,0,0,0},
{125,5,2,25640,63,0,0,0,16,0,0,0,0,0},
{126,6,2,93400,99,0,0,0,29,0,0,0,0,0},
{127,7,2,161680,137,78,0,0,39,0,0,0,0,0},
{128,8,2,51500,219,0,0,0,51,0,0,0,0,0},
{129,9,2,488500,242,0,0,0,62,0,0,0,0,11},
{130,1,0,520,0,0,0,9,0,0,0,0,0,0},
{131,2,0,-1140,0,0,0,14,0,0,0,0,0,0},
{132,3,0,-5000,0,0,0,17,0,0,0,0,0,0},
{133,3,1,5500,0,0,0,21,0,0,0,0,0,0},
{134,4,0,2620,0,0,0,27,0,0,0,0,0,0},
{135,5,0,8200,0,0,0,48,0,0,0,12,0,0},
{136,5,1,24640,0,0,0,43,0,0,0,16,0,0},
{137,6,0,42760,0,0,0,79,0,0,0,25,0,0},
{138,7,0,25080,0,0,0,113,0,0,0,36,0,0},
{139,8,0,-21600,0,0,0,159,0,0,0,51,5,0},
{140,8,4,43200,0,0,0,171,0,0,0,46,6,0},
{141,9,0,258500,0,0,0,195,0,0,0,54,10,0},
{142,9,1,339600,0,0,0,207,0,0,0,58,12,0},
{143,9,4,220000,0,0,0,220,0,0,0,62,14,0},
{144,1,0,840,0,0,0,12,0,0,0,0,0,0},
{145,2,0,20,0,0,0,17,0,0,0,0,0,0},
{146,3,0,-6240,0,0,0,24,0,0,0,0,0,0},
{147,3,1,4950,0,0,0,27,0,0,0,0,0,0},
{148,4,0,5980,0,0,0,39,0,0,0,0,0,0},
{149,5,0,14800,0,0,0,68,0,0,0,21,0,0},
{150,5,1,35280,0,0,0,90,0,0,0,23,0,0},
{151,6,0,58000,0,0,0,90,0,0,0,29,0,0},
{152,7,0,7000,0,0,0,113,0,0,0,36,0,0},
{153,7,4,72000,0,0,0,124,0,0,0,39,0,0},
{154,8,0,136800,0,0,0,159,0,0,0,51,7,0},
{155,8,1,141850,0,0,0,171,0,0,0,46,8,0},
{156,9,0,242000,0,0,0,195,0,0,0,54,13,0},
{157,9,1,459200,0,0,0,207,0,0,0,58,16,0},
{158,1,0,800,0,0,0,9,0,0,0,0,0,0},
{159,1,4,1720,0,0,0,10,0,0,0,0,0,0},
{160,2,0,2150,0,0,0,16,0,0,0,0,0,0},
{161,3,0,5900,0,0,13,21,0,0,0,0,0,0},
{162,4,0,9620,0,0,20,33,0,0,0,8,0,0},
{163,4,1,16000,0,0,20,39,0,0,0,10,0,0},
{164,5,0,18800,0,0,30,48,0,0,0,12,0,0},
{165,5,4,28800,0,0,29,57,0,0,0,0,0,0},
{166,5,1,43480,0,0,36,57,0,0,0,16,0,0},
{167,6,0,50400,0,0,49,79,0,0,0,25,0,0},
{168,6,1,67850,0,0,45,90,0,0,0,29,0,0},
{169,7,0,18050,0,0,70,113,0,0,0,36,0,0},
{170,7,1,187280,0,0,62,124,0,0,0,39,0,0},
{171,8,0,72400,0,0,0,159,0,0,0,51,7,0},
{172,9,0,335600,0,0,0,195,0,0,0,54,13,0},
{173,1,0,180,5,0,0,0,0,0,0,0,0,0},
{174,2,0,1300,12,0,0,0,0,0,0,0,0,0},
{175,3,0,-960,14,0,0,0,0,0,0,0,0,0},
{176,4,0,1050,24,0,0,0,0,0,0,0,0,0},
{177,5,0,7680,39,0,0,0,10,0,0,0,0,0},
{178,5,4,14600,48,0,0,0,10,0,0,0,0,0},
{179,6,0,33320,79,0,0,0,25,0,0,0,0,0},
{180,7,0,89280,124,0,78,0,39,0,0,0,0,0},
{181,7,4,70600,136,0,68,0,43,0,0,0,0,0},
{182,7,1,289040,147,0,74,0,47,0,0,0,0,0},
{183,8,0,35200,159,0,0,0,51,0,0,0,0,7},
{184,8,1,304400,171,0,0,0,46,0,0,0,0,8},
{185,9,0,462000,195,0,0,0,54,0,0,0,0,13},
{186,9,4,583600,207,0,0,0,58,0,0,0,0,16},
{187,1,0,160,0,0,5,0,0,0,0,0,0,0},
{188,2,0,580,0,0,9,0,0,0,0,0,0,0},
{189,3,0,-1520,0,0,13,0,0,0,0,0,0,0},
{190,4,0,-3300,6,0,21,0,0,0,0,0,0,0},
{191,5,0,5680,0,0,39,0,0,0,10,0,0,0},
{192,6,0,32920,0,0,79,49,0,0,25,0,0,0},
{193,6,4,45050,0,0,90,45,0,0,29,0,0,0},
{194,6,1,73800,28,0,90,45,0,0,0,0,0,0},
{195,7,0,52000,0,0,124,0,0,0,39,20,0,0},
{196,8,0,-67350,0,0,159,99,0,0,51,0,0,0},
{197,9,0,311600,0,0,195,0,0,0,54,0,10,0},
{198,9,1,695200,0,0,207,0,0,0,58,0,12,0},
{199,1,0,160,0,0,5,0,0,0,0,0,0,0},
{200,2,0,-360,0,0,7,0,0,0,0,0,0,0},
{201,3,0,-1520,0,0,13,8,0,0,0,0,0,0},
{202,4,0,1600,0,0,21,13,0,0,0,0,0,0},
{203,5,0,7600,0,0,39,0,0,0,10,5,0,0},
{204,5,1,22640,0,0,48,0,0,0,12,0,0,0},
{205,5,1,31800,0,0,57,0,0,0,13,0,0,0},
{206,6,0,26700,0,0,79,0,0,0,25,12,0,0},
{207,6,4,71200,0,0,90,0,0,0,26,0,0,0},
{208,7,0,38600,0,0,113,0,0,0,36,0,0,0},
{209,8,0,80400,0,0,171,0,0,0,57,0,8,0},
{210,8,4,65600,0,0,171,0,0,0,46,0,0,8},
{211,9,0,271200,0,0,195,0,0,0,54,0,13,0},
{212,9,1,675000,0,0,207,0,0,0,58,0,16,0},
{213,1,0,160,4,0,0,0,0,0,0,0,0,0},
{214,2,0,1060,12,0,6,0,0,0,0,0,0,0},
{215,3,0,-860,14,0,0,0,0,0,0,0,0,0},
{216,4,0,-2800,21,0,0,0,0,0,0,0,0,0},
{217,5,0,8030,39,0,0,0,10,0,0,0,0,0},
{218,5,4,16240,42,0,0,0,12,0,0,0,0,0},
{219,5,1,23600,48,0,30,0,0,0,0,0,0,0},
{220,6,0,41720,79,0,0,0,25,0,0,0,0,0},
{221,7,0,108160,124,0,0,0,39,0,0,0,0,0},
{222,7,1,134240,136,0,0,0,43,0,0,0,0,0},
{223,8,0,35200,159,0,0,0,51,0,0,0,0,7},
{224,8,4,262880,171,0,0,0,46,0,0,0,0,8},
{225,8,1,305400,183,0,0,0,50,0,0,0,0,10},
{226,9,0,458400,195,0,0,0,54,0,0,0,0,13},
{227,1,0,120,0,0,4,0,0,0,0,0,0,0},
{228,1,4,680,0,0,7,0,0,0,0,0,0,0},
{229,2,0,560,0,0,7,0,0,0,0,0,0,0},
{230,3,0,-280,0,0,13,0,0,0,0,0,0,0},
{231,4,0,-4000,11,0,17,0,0,0,0,0,0,0},
{232,5,0,6680,0,0,33,0,0,0,8,0,0,0},
{233,6,0,24000,0,0,68,0,0,0,21,0,0,0},
{234,6,1,66800,0,0,79,0,0,0,25,0,0,0},
{235,7,0,51400,0,0,113,0,0,0,36,0,0,0},
{236,7,4,49350,0,0,124,0,0,0,31,0,0,0},
{237,7,1,126000,0,0,136,0,0,0,43,0,0,0},
{238,8,0,-53600,0,0,159,50,0,0,0,0,5,0},
{239,9,0,372800,0,0,207,0,0,0,58,0,12,0},
{240,9,4,460000,0,0,220,0,0,0,62,0,14,0},
{241,1,0,160,0,0,5,0,0,0,0,0,0,0},
{242,2,0,560,0,0,9,0,0,0,0,0,0,0},
{243,3,0,660,0,0,13,4,0,0,0,0,0,0},
{244,4,0,-2100,0,0,17,5,0,0,0,0,0,0},
{245,5,0,5600,0,0,33,10,0,0,8,0,0,0},
{246,5,4,12640,0,0,39,10,0,0,0,0,0,0},
{247,6,0,19150,0,0,68,21,0,0,21,0,0,0},
{248,7,0,20600,0,0,113,0,0,0,36,0,0,0},
{249,7,1,157280,0,0,124,0,0,0,39,0,0,0},
{250,8,0,45250,0,0,159,0,0,0,51,0,7,0},
{251,8,4,155600,0,0,195,0,0,0,54,0,13,0},
{252,9,0,247500,0,0,207,0,0,0,58,0,16,0},
{253,9,1,607500,0,0,220,0,0,0,77,0,19,0},
{254,1,0,160,4,0,0,0,0,0,0,0,0,0},
{255,2,0,1240,12,0,0,0,0,0,0,0,0,0},
{256,3,0,-660,14,0,9,0,0,0,0,0,0,0},
{257,4,0,-3300,24,0,15,0,0,0,0,0,0,0},
{258,4,1,600,20,0,0,9,0,0,0,0,0,0},
{259,5,0,11240,48,0,0,0,12,0,0,0,0,0},
{260,6,0,37520,79,0,0,25,25,0,0,0,0,0},
{261,6,4,51000,90,0,0,0,26,0,0,0,0,0},
{262,6,1,100350,90,0,0,0,23,0,0,0,0,0},
{263,7,0,70280,113,0,70,0,36,0,0,0,0,0},
{264,8,0,74800,171,0,0,0,57,0,0,0,0,8},
{265,9,0,434560,195,0,0,0,54,0,0,0,0,13},
{266,9,4,291600,207,0,0,0,58,0,0,0,0,16},
{267,1,0,160,0,0,5,0,0,0,0,0,0,0},
{268,2,0,540,0,0,7,0,0,0,0,0,0,0},
{269,3,0,-780,0,0,11,0,0,0,0,0,0,0},
{270,3,4,2250,0,0,14,4,0,0,0,0,0,0},
{271,3,1,4460,0,0,17,5,0,0,0,0,0,0},
{272,4,0,-6000,6,0,21,0,0,0,0,0,0,0},
{273,5,0,7600,0,0,39,0,0,0,10,0,0,0},
{274,5,1,23640,0,0,48,0,0,0,12,0,0,0},
{275,6,0,27360,0,0,68,21,0,0,21,0,0,0},
{276,6,4,56680,0,0,90,22,0,0,29,0,0,0},
{277,7,0,-7600,0,0,113,0,0,0,36,0,0,0},
{278,8,0,109650,0,0,159,0,0,0,51,0,7,0},
{279,9,0,363520,0,0,195,0,0,0,54,0,13,0},
{280,1,0,160,4,0,0,0,0,0,0,0,0,0},
{281,2,0,700,7,0,5,0,0,0,0,0,0,0},
{282,3,0,-540,11,0,0,0,0,0,0,0,0,0},
{283,3,1,3000,13,0,8,0,0,0,0,0,0,0},
{284,4,0,-1800,17,0,11,0,0,0,0,0,0,0},
{285,5,0,6680,39,0,0,0,10,0,0,0,0,0},
{286,5,4,15600,48,0,0,0,12,0,0,0,0,0},
{287,6,0,42950,79,0,0,25,25,0,0,0,0,0},
{288,7,0,82280,113,0,70,0,36,0,0,0,0,0},
{289,8,0,31600,159,0,0,0,51,0,0,0,0,7},
{290,9,0,422800,195,0,0,0,67,0,0,0,0,13},
{291,1,0,160,0,0,5,0,0,0,0,0,0,0},
{292,1,4,740,0,0,7,0,0,0,0,0,0,0},
{293,2,0,540,0,0,7,0,0,0,0,0,0,0},
{294,3,0,-420,0,0,11,0,0,0,0,0,0,0},
{295,3,1,3500,0,8,13,0,0,0,0,0,0,0},
{296,4,0,-4500,0,0,21,0,0,0,0,0,0,0},
{297,4,1,5300,0,0,24,0,0,0,0,0,0,0},
{298,5,0,5880,0,0,33,10,0,0,8,0,0,0},
{299,6,0,27720,0,0,68,21,0,0,21,0,0,0},
{300,7,0,2450,0,0,102,0,0,0,33,0,0,0},
{301,8,0,-45760,0,0,159,0,0,0,51,0,7,0},
{302,8,4,127600,0,0,171,0,0,0,46,0,8,0},
{303,9,0,326000,0,0,195,0,0,0,54,0,13,0},
{304,9,4,455600,0,0,207,0,0,0,58,0,16,0},
{305,9,1,695200,0,0,207,0,0,0,58,0,16,0},
{306,1,0,320,0,6,0,0,0,0,0,0,0,0},
{307,2,0,260,0,11,0,0,0,0,0,0,0,0},
{308,3,0,-360,0,14,0,9,0,0,0,0,0,0},
{309,4,0,-2400,15,24,0,0,0,0,0,0,0,0},
{310,4,4,5700,8,27,0,0,0,0,0,0,0,0},
{311,5,0,1080,0,39,0,0,0,10,0,0,0,0},
{312,5,1,21600,30,45,0,0,0,9,0,0,0,0},
{313,5,1,23100,29,57,0,0,0,0,0,0,0,0},
{314,6,0,22800,0,68,0,0,10,21,0,0,0,0},
{315,7,0,61320,0,113,0,0,18,36,0,0,0,0},
{316,8,0,2700,0,159,0,0,0,51,0,0,0,7},
{317,9,0,430400,0,182,0,0,0,54,0,0,0,13},
{318,9,4,411600,0,193,0,0,0,58,0,0,0,16},
{319,9,1,671600,0,193,0,0,0,58,0,0,0,16},
{320,9,1,556000,0,193,0,0,0,58,0,0,0,16},
{321,1,0,1720,11,0,0,0,0,0,0,0,0,0},
{322,2,0,3000,17,0,0,0,0,0,0,0,0,0},
{323,3,0,2640,24,0,0,15,0,0,0,0,0,0},
{324,3,4,3600,24,0,0,17,0,0,0,0,0,0},
{325,4,0,9900,39,0,0,25,0,0,0,0,0,0},
{326,4,1,13600,48,0,0,24,0,0,0,0,0,0},
{327,5,0,16300,57,0,0,0,16,0,0,0,0,0},
{328,5,1,32720,43,0,0,0,16,0,0,0,0,0},
{329,6,0,30800,79,0,0,49,25,0,0,0,0,0},
{330,7,0,8800,113,0,0,0,36,0,0,0,0,0},
{331,7,4,73360,124,0,0,0,39,0,0,0,0,0},
{332,7,1,192480,136,0,0,0,43,0,0,22,0,0},
{333,8,0,74800,171,0,0,0,57,0,0,0,0,8},
{334,9,0,169600,195,0,0,0,54,0,0,0,0,13},
{335,9,1,575600,207,0,0,0,58,0,0,0,0,16},
{336,1,0,1380,9,0,6,0,0,0,0,0,0,0},
{337,2,0,2600,12,0,8,0,0,0,0,0,0,0},
{338,3,0,820,13,0,0,0,0,0,0,0,0,0},
{339,4,0,7700,21,0,17,0,0,0,0,0,0,0},
{340,4,4,2800,25,0,16,0,0,0,0,0,0,0},
{341,5,0,9640,30,0,25,0,8,0,0,0,0,0},
{342,5,1,33120,36,0,24,0,9,0,0,0,0,0},
{343,5,4,-86520,51,0,43,0,15,0,0,0,0,0},
{344,6,0,54950,51,0,43,0,15,0,0,0,0,0},
{345,7,0,93280,93,0,0,0,29,0,0,20,0,0},
{346,7,1,155600,102,0,0,0,32,0,0,22,0,0},
{347,8,0,92750,119,0,0,0,39,0,0,0,0,7},
{348,9,0,264250,146,0,0,0,40,0,0,0,0,13},
{349,9,1,675600,0,136,0,0,0,38,0,0,0,16},
{350,4,3,-10400,0,0,0,15,0,0,0,0,0,0},
{351,7,3,12280,0,0,0,59,0,0,0,17,0,0},
{352,9,3,91600,0,0,0,99,0,0,0,25,7,0},
{353,4,0,-14900,26,0,0,0,0,0,0,0,0,0},
{354,7,0,115800,113,0,0,0,36,0,0,0,0,0},
{355,9,0,114200,159,0,0,0,41,0,0,0,7,0},
{356,4,0,-22400,0,26,0,0,0,0,0,0,0,0},
{357,7,0,150800,0,113,0,0,0,36,0,0,0,0},
{358,9,0,5000,0,149,0,0,0,41,0,0,7,0},
{359,4,0,-30900,0,0,26,0,0,0,0,0,0,0},
{360,7,0,97960,0,0,113,0,0,0,36,0,0,0},
{361,9,0,5000,0,0,159,0,0,0,41,0,7,0},
{362,4,0,-14960,0,0,0,26,0,0,0,0,0,0},
{363,7,0,137080,0,0,0,113,0,0,0,36,0,0},
{364,9,0,-99400,0,0,0,159,0,0,0,41,7,0},
{365,4,0,-14400,0,0,0,21,0,0,0,0,0,0},
{366,7,0,68200,0,0,0,113,0,0,0,36,0,0},
{367,9,0,-8200,0,0,0,159,0,0,0,41,7,0},
{368,4,0,-15960,0,0,0,21,0,0,0,0,0,0},
{369,7,0,46800,0,0,0,113,0,0,0,36,0,0},
{370,9,0,121400,0,0,0,159,0,0,0,41,7,0},
{371,4,0,-17200,0,0,0,24,0,0,0,0,0,0},
{372,4,0,-29600,24,0,0,0,0,0,0,0,0,0},
{373,4,0,-18400,0,24,0,0,0,0,0,0,0,0},
{374,4,0,-38100,0,0,24,0,0,0,0,0,0,0},
{375,4,0,-19400,0,0,0,24,0,0,0,0,0,0},
{376,4,0,-14400,0,0,24,0,0,0,0,0,0,0},
{377,7,0,159520,124,0,0,0,39,0,0,0,0,0},
{378,7,0,167200,0,0,124,0,0,0,39,0,0,0},
{379,7,0,128000,0,0,0,124,0,0,0,39,0,0},
{380,7,0,27200,0,0,0,124,0,0,0,39,0,0},
{381,7,0,58000,0,124,0,0,0,39,0,0,0,0},
{382,7,0,107600,0,124,0,0,0,39,0,0,0,0},
{383,9,0,95000,159,0,0,0,41,0,0,0,0,7},
{384,9,0,-8200,0,0,159,0,0,0,41,0,0,7},
{385,9,0,95000,0,149,0,0,0,41,0,0,0,7},
{386,9,0,-5800,0,149,0,0,0,41,0,0,0,7},
{387,9,0,33800,0,0,0,159,0,0,0,41,0,7},
{388,9,0,146600,0,0,0,159,0,0,0,41,0,7}
        };
    
        for (int a = 0; a < 13; a++) {
            Items[0][a] = ItemsLoader[0][a];
        }

        int b = 1;

        for (int a = 1; a < 389; a++) {
            if (ItemsLoader[a][1] >= TierMin && ItemsLoader[a][1] <= TierMax && ((F2P == false && ItemsLoader[a][2] == 0) || (F2P == true && ItemsLoader[a][2] == 1) || (Engineer == true && ItemsLoader[a][2] == 2) || (Academy == true && ItemsLoader[a][2] == 3) || (Chest == true && ItemsLoader[a][2]==4))) {
                Items[b][0] = ItemsLoader[a][0];
                Items[b][1] = ItemsLoader[a][3];
                Items[b][3] = ItemsLoader[a][4];
                Items[b][4] = ItemsLoader[a][5];
                Items[b][5] = ItemsLoader[a][6];
                Items[b][6] = ItemsLoader[a][7];
                Items[b][7] = ItemsLoader[a][8];
                Items[b][8] = ItemsLoader[a][9];
                Items[b][9] = ItemsLoader[a][10];
                Items[b][10] = ItemsLoader[a][11];
                Items[b][11] = ItemsLoader[a][12];
                Items[b][12] = ItemsLoader[a][13];
                Items[b][13] = 0;
                b++;
                NumItems++;
            }
        }

        RegenTime = 0;

        for (int a = 0; a < NumItems; a++) {
            for (int b = 0; b < 10; b++) {
                if ((Items[a][b + 3] / MatRegen[b] > RegenTime)) {
                    RegenTime = Items[a][b + 3] / MatRegen[b];
                    MatType = b;
                }
            }

            Items[a][16] = MatType;
            Items[a][15] = RegenTime;
            Items[a][14] = Items[a][1] * (60 / RegenTime);
            RegenTime = 0;
        }

        for (int a = 0; a < NumItems; a++) {
            for (int b = 0; b < 10; b++) {
                cout << Items[a][b] << ", ";
            }
            cout << endl;
        }
        cout << NumItems << " items loaded from database." << endl;
        return;
}

void aitemconstructor() {

    float ItemsLoader[][16] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,160,48,8,1,0,0,0,0,0,0,0,0,0},
{2,2,0,520,104,26,4,0,0,0,0,0,0,0,0,0},
{3,3,0,360,168,84,11,0,0,0,0,0,0,0,0,0},
{4,3,4,1400,260,130,13,0,0,0,0,0,0,0,0,0},
{5,3,1,3100,310,155,3,0,0,0,0,0,0,0,0,0},
{6,4,0,4700,510,255,17,0,0,0,0,0,0,0,0,0},
{7,5,0,6400,1480,740,33,0,0,0,6,0,0,0,0,0},
{8,5,1,15250,2800,1400,48,0,0,0,8,0,0,0,0,0},
{9,6,0,31800,6000,3000,68,0,0,0,17,0,0,0,0,0},
{10,7,0,83960,16100,8050,113,0,0,0,29,0,0,18,0,0},
{11,8,0,88000,49000,24500,159,0,0,0,51,0,0,0,0,3},
{12,8,4,244000,55000,27500,171,0,0,0,46,0,0,0,4,0},
{13,8,4,68800,91000,45500,183,0,0,0,50,0,0,0,0,6},
{14,9,0,338640,75000,37500,207,0,0,0,58,0,0,0,0,8},
{15,9,1,742800,105000,52500,220,0,0,0,62,0,0,0,0,10},
{16,9,1,532800,99000,49500,192,0,0,0,58,0,0,0,10,0},
{17,1,0,940,282,47,0,9,0,0,0,0,0,0,0,0},
{18,2,0,-300,420,105,0,11,0,0,0,0,0,0,0,0},
{19,3,0,3900,390,195,0,14,0,0,0,0,0,0,0,0},
{20,3,1,5300,530,265,0,2,0,0,0,0,0,0,0,0},
{21,4,0,4100,1130,565,0,24,0,0,0,0,0,0,0,0},
{22,4,4,8300,1310,655,0,27,0,0,0,0,0,0,0,0},
{23,5,0,13000,2500,1250,0,37,0,0,0,8,0,0,0,0},
{24,6,0,47550,6000,3000,0,74,0,0,0,20,0,0,0,0},
{25,7,0,95960,17300,8650,0,106,0,0,18,29,0,0,0,0},
{26,7,4,155320,22000,11000,0,116,0,0,0,31,0,0,0,0},
{27,8,0,114300,53000,26500,0,171,0,0,0,57,0,0,0,6},
{28,9,0,461360,71000,35500,0,182,0,0,0,54,0,0,0,10},
{29,9,4,524400,90000,45000,0,193,0,0,0,58,0,0,0,13},
{30,9,1,676400,104000,52000,0,193,0,0,0,58,0,0,0,13},
{31,1,0,140,42,7,3,0,0,0,0,0,0,0,0,0},
{32,1,4,1000,200,50,4,0,0,0,0,0,0,0,0,0},
{33,2,0,760,152,38,4,0,0,0,0,0,0,0,0,0},
{34,2,1,1660,332,83,6,0,0,0,0,0,0,0,0,0},
{35,3,0,660,210,105,14,0,0,0,0,0,0,0,0,0},
{36,4,0,1900,910,455,22,0,0,0,0,0,0,0,0,0},
{37,5,0,8520,1740,870,35,0,0,0,7,0,0,0,0,0},
{38,5,1,24680,3800,1900,51,0,0,0,12,0,0,0,0,0},
{39,6,0,37320,5100,2550,71,0,0,0,18,0,0,0,0,0},
{40,7,0,29550,17400,8700,112,0,0,0,28,0,0,0,0,0},
{41,8,0,-71600,43000,21500,143,0,0,0,37,0,0,0,0,0},
{42,8,4,208560,51000,25500,154,0,0,0,41,0,0,0,0,0},
{43,9,0,137600,71000,35500,175,0,0,0,48,0,0,0,0,0},
{44,9,4,258800,130000,65000,198,0,0,0,55,0,0,0,0,0},
{45,1,0,160,48,8,0,1,0,0,0,0,0,0,0,0},
{46,2,0,660,132,33,0,8,0,0,0,0,0,0,0,0},
{47,2,4,1600,320,80,0,9,0,0,0,0,0,0,0,0},
{48,3,0,1900,190,95,0,10,0,0,0,0,0,0,0,0},
{49,3,1,3000,300,150,2,4,0,0,0,0,0,0,0,0},
{50,4,0,-400,680,340,5,15,0,0,0,0,0,0,0,0},
{51,4,1,6700,1150,575,4,18,0,0,0,0,0,0,0,0},
{52,5,0,6620,1550,775,0,28,0,0,0,5,0,0,0,0},
{53,6,0,29600,5300,2650,0,58,0,0,0,15,0,0,0,0},
{54,7,0,32600,15400,7700,0,96,0,0,9,26,0,0,0,0},
{55,7,4,132960,21000,10500,0,105,0,0,0,28,0,0,0,0},
{56,8,0,-8000,46000,23000,0,154,0,0,0,51,0,0,4,0},
{57,8,1,249600,60000,30000,0,126,0,0,0,17,0,0,8,0},
{58,8,1,296000,65000,32500,0,154,0,0,0,45,0,0,6,0},
{59,9,0,400600,73000,36500,0,163,0,0,0,48,0,0,7,0},
{60,9,1,760000,103000,51500,0,173,0,0,0,52,0,0,8,0},
{61,1,0,580,174,29,0,7,0,0,0,0,0,0,0,0},
{62,2,0,1560,312,78,0,11,0,0,0,0,0,0,0,0},
{63,3,0,2880,420,210,0,17,0,0,0,0,0,0,0,0},
{64,3,1,6000,600,300,0,21,0,0,0,0,0,0,0,0},
{65,4,0,8200,1210,605,17,27,0,0,0,0,0,0,0,0},
{66,5,0,15680,2900,1450,0,46,0,0,0,10,0,0,0,0},
{67,5,1,43640,5900,2950,0,64,0,0,0,17,0,0,0,0},
{68,6,0,52720,7300,3650,0,74,0,0,0,20,0,0,0,0},
{69,6,4,75200,8600,4300,0,81,0,0,0,20,0,0,0,0},
{70,7,0,127280,23000,11500,0,116,0,0,0,31,0,10,0,0},
{71,8,0,128400,45000,22500,0,159,0,0,0,51,0,0,0,5},
{72,9,0,410050,73000,36500,0,182,0,0,0,54,0,0,0,9},
{73,9,4,395600,150000,75000,0,193,0,0,0,58,0,0,0,11},
{74,1,0,660,198,33,0,2,0,0,0,0,0,0,0,0},
{75,1,4,1020,204,51,0,7,0,0,0,0,0,0,0,0},
{76,2,0,860,172,43,0,3,0,0,0,0,0,0,0,0},
{77,3,0,1100,350,175,0,14,0,4,0,0,0,0,0,0},
{78,3,2,5900,590,295,0,16,0,0,0,0,0,0,0,0},
{79,4,0,2200,700,350,0,24,15,0,0,0,0,0,0,0},
{80,5,0,15010,2100,1050,0,37,0,0,0,8,0,0,0,0},
{81,6,0,33920,6800,3400,0,74,0,0,0,20,0,0,0,0},
{82,6,4,77760,9600,4800,0,81,0,0,0,20,0,0,0,0},
{83,7,0,76600,18100,9050,0,116,0,39,0,31,0,0,0,0},
{84,8,0,7600,48000,24000,0,171,0,0,0,57,0,0,0,4},
{85,8,1,368800,61000,30500,0,171,0,0,0,50,0,0,0,6},
{86,9,0,247500,76000,38000,0,182,0,0,0,54,0,0,0,7},
{87,1,0,180,54,9,0,1,0,0,0,0,0,0,0,0},
{88,2,0,580,116,29,0,2,0,0,0,0,0,0,0,0},
{89,3,0,560,176,88,0,11,0,0,0,0,0,0,0,0},
{90,3,2,9800,980,490,0,17,0,0,0,0,0,0,0,0},
{91,3,4,-175000,2500,1250,0,15,0,9,0,0,0,0,0,0},
{92,4,0,5550,700,350,6,21,0,0,0,0,0,0,0,0},
{93,5,0,14400,2400,1200,0,37,0,0,0,8,0,0,0,0},
{94,5,4,21480,3300,1650,0,40,0,0,0,4,0,0,0,0},
{95,6,0,66600,8100,4050,0,74,0,0,0,20,0,0,0,0},
{96,6,1,82040,11300,5650,0,61,0,0,0,23,0,0,0,0},
{97,7,0,46600,15100,7550,0,106,0,0,0,29,0,18,0,0},
{98,8,0,128400,45000,22500,0,149,0,0,0,41,0,0,7,0},
{99,8,4,276050,53000,26500,0,160,0,0,0,46,0,0,6,0},
{100,9,0,504600,75000,37500,0,195,0,0,0,67,0,0,10,0},
{101,9,4,498640,91000,45500,0,193,0,0,0,58,0,0,13,0},
{102,9,1,796320,108000,54000,0,193,0,0,0,58,0,0,13,0},
{103,1,3,860,258,43,0,2,0,0,0,0,0,0,0,0},
{104,2,3,2300,700,175,0,13,0,0,0,0,0,0,0,0},
{105,3,3,8100,810,405,0,21,0,0,0,0,0,0,0,0},
{106,4,3,4700,1910,955,9,27,0,0,0,0,0,0,0,0},
{107,5,3,31600,4600,2300,0,46,0,0,0,10,0,9,0,0},
{108,6,3,116000,13400,6700,0,74,0,25,0,20,0,0,0,0},
{109,7,3,110800,25000,12500,0,106,0,0,9,29,0,0,0,0},
{110,8,3,240300,61000,30500,0,159,0,0,0,51,0,0,0,5},
{111,9,3,559280,86000,43000,0,193,0,0,0,58,0,0,0,13},
{112,1,2,520,104,26,0,6,0,0,0,0,0,0,0,0},
{113,2,2,1400,280,70,0,10,0,0,0,0,0,0,0,0},
{114,3,2,2600,500,250,0,15,0,0,0,0,0,0,0,0},
{115,4,2,4500,1410,705,0,26,0,0,0,0,0,0,0,0},
{116,5,2,23640,3900,1950,0,43,0,10,0,0,0,0,0,0},
{117,6,2,66400,8800,4400,0,82,0,0,0,20,0,0,0,0},
{118,7,2,195600,33000,16500,0,137,0,0,0,39,0,0,0,0},
{119,8,2,270560,53000,26500,0,165,0,0,26,41,0,0,0,0},
{120,9,2,549500,89000,44500,0,214,0,0,0,58,0,0,0,13},
{121,1,2,980,196,49,10,5,0,0,0,0,0,0,0,0},
{122,2,2,2100,420,105,15,7,0,0,0,0,0,0,0,0},
{123,3,2,3460,610,305,18,11,0,0,0,0,0,0,0,0},
{124,4,2,15320,2300,1150,30,17,0,0,0,0,0,0,0,0},
{125,5,2,31640,5300,2650,63,0,0,0,13,0,0,0,0,0},
{126,6,2,97000,11500,5750,99,0,0,0,23,0,0,0,0,0},
{127,7,2,177280,28000,14000,137,78,0,0,31,0,0,0,0,0},
{128,8,2,145100,53000,26500,219,0,0,0,41,0,0,0,0,0},
{129,9,2,578500,93000,46500,242,0,0,0,62,0,0,0,0,9},
{130,1,0,520,104,26,0,0,0,9,0,0,0,0,0,0},
{131,2,0,-1140,348,87,0,0,0,14,0,0,0,0,0,0},
{132,3,0,-3700,590,295,0,0,0,17,0,0,0,0,0,0},
{133,3,1,5500,790,395,0,0,0,16,0,0,0,0,0,0},
{134,4,0,6460,1030,515,0,0,0,27,0,0,0,0,0,0},
{135,5,0,13000,2500,1250,0,0,0,48,0,0,0,10,0,0},
{136,5,1,28480,4000,2000,0,0,0,43,0,0,0,8,0,0},
{137,6,0,47320,6100,3050,0,0,0,79,0,0,0,20,0,0},
{138,7,0,58680,17100,8550,0,0,0,113,0,0,0,29,0,0},
{139,8,0,58800,45000,22500,0,0,0,159,0,0,0,51,3,0},
{140,8,4,136800,54000,27000,0,0,0,171,0,0,0,46,4,0},
{141,9,0,284250,76000,38000,0,0,0,195,0,0,0,54,8,0},
{142,9,1,526800,93000,46500,0,0,0,207,0,0,0,58,10,0},
{143,9,4,400000,149000,74500,0,0,0,220,0,0,0,62,11,0},
{144,1,0,840,168,42,0,0,0,12,0,0,0,0,0,0},
{145,2,0,20,580,145,0,0,0,17,0,0,0,0,0,0},
{146,3,0,-1440,960,480,0,0,0,24,0,0,0,0,0,0},
{147,3,1,4950,1220,610,0,0,0,20,0,0,0,0,0,0},
{148,4,0,9820,1750,875,0,0,0,39,0,0,0,0,0,0},
{149,5,0,24400,3400,1700,0,0,0,68,0,0,0,17,0,0},
{150,5,1,39720,6300,3150,0,0,0,90,0,0,0,14,0,0},
{151,6,0,64600,7900,3950,0,0,0,90,0,0,0,23,0,0},
{152,7,0,41800,18100,9050,0,0,0,113,0,0,0,29,0,0},
{153,7,4,105600,24000,12000,0,0,0,124,0,0,0,31,0,0},
{154,8,0,151200,48000,24000,0,0,0,159,0,0,0,51,5,0},
{155,8,1,185600,56000,28000,0,0,0,171,0,0,0,35,8,0},
{156,9,0,242000,74000,37000,0,0,0,195,0,0,0,54,10,0},
{157,9,1,549200,101000,50500,0,0,0,207,0,0,0,58,13,0},
{158,1,0,800,160,40,0,0,0,9,0,0,0,0,0,0},
{159,1,4,1720,172,86,0,0,0,8,0,0,0,0,0,0},
{160,2,0,2600,260,130,0,0,0,16,0,0,0,0,0,0},
{161,3,0,8300,830,415,0,0,13,21,0,0,0,0,0,0},
{162,4,0,13460,1730,865,0,0,20,33,0,0,0,6,0,0},
{163,4,1,23200,3400,1700,0,0,20,39,0,0,0,8,0,0},
{164,5,0,23600,3800,1900,0,0,30,48,0,0,0,10,0,0},
{165,5,4,37680,5100,2550,0,0,29,57,0,0,0,0,0,0},
{166,5,1,43480,5500,2750,0,0,18,57,0,0,0,8,0,0},
{167,6,0,54000,8100,4050,0,0,49,79,0,0,0,20,0,0},
{168,6,1,83450,11100,5550,0,0,45,90,0,0,0,23,0,0},
{169,7,0,38800,17800,8900,0,0,70,113,0,0,0,29,0,0},
{170,7,1,212960,29000,14500,0,0,62,124,0,0,0,31,0,0},
{171,8,0,143200,49000,24500,0,0,0,159,0,0,0,51,5,0},
{172,9,0,425600,80000,40000,0,0,0,195,0,0,0,54,10,0},
{173,1,0,180,54,9,1,0,0,0,0,0,0,0,0,0},
{174,2,0,1300,260,65,3,0,0,0,0,0,0,0,0,0},
{175,3,0,1920,480,240,14,0,0,0,0,0,0,0,0,0},
{176,4,0,5850,910,455,24,0,0,0,0,0,0,0,0,0},
{177,5,0,12120,2100,1050,39,0,0,0,8,0,0,0,0,0},
{178,5,4,19400,2900,1450,48,0,0,0,8,0,0,0,0,0},
{179,6,0,45320,5900,2950,79,0,0,0,20,0,0,0,0,0},
{180,7,0,107280,21000,10500,124,0,78,0,31,0,0,0,0,0},
{181,7,4,125600,26000,13000,136,0,68,0,34,0,0,0,0,0},
{182,7,1,314720,41000,20500,147,0,74,0,38,0,0,0,0,0},
{183,8,0,106000,46000,23000,159,0,0,0,51,0,0,0,0,5},
{184,8,1,384800,56000,28000,171,0,0,0,46,0,0,0,0,6},
{185,9,0,538800,78000,39000,195,0,0,0,54,0,0,0,0,10},
{186,9,4,660400,91000,45500,207,0,0,0,58,0,0,0,0,13},
{187,1,0,160,48,8,0,0,1,0,0,0,0,0,0,0},
{188,2,0,580,116,29,0,0,2,0,0,0,0,0,0,0},
{189,3,0,-80,280,140,0,0,13,0,0,0,0,0,0,0},
{190,4,0,1500,630,315,6,0,21,0,0,0,0,0,0,0},
{191,5,0,10480,2200,1100,0,0,39,0,0,0,8,0,0,0},
{192,6,0,37480,6100,3050,0,0,79,49,0,0,20,0,0,0},
{193,6,4,52800,8400,4200,0,0,90,45,0,0,23,0,0,0},
{194,6,1,88200,9900,4950,22,0,90,45,0,0,0,0,0,0},
{195,7,0,85600,22000,11000,0,0,124,0,0,0,31,20,0,0},
{196,8,0,-51600,51000,25500,0,0,159,99,0,0,41,0,0,0},
{197,9,0,401600,80000,40000,0,0,195,0,0,0,54,0,8,0},
{198,9,1,772000,106000,53000,0,0,207,0,0,0,58,0,10,0},
{199,1,0,160,48,8,0,0,1,0,0,0,0,0,0,0},
{200,2,0,840,168,42,0,0,7,0,0,0,0,0,0,0},
{201,3,0,-80,280,140,0,0,13,8,0,0,0,0,0,0},
{202,4,0,6400,640,320,0,0,21,13,0,0,0,0,0,0},
{203,5,0,12400,2200,1100,0,0,39,0,0,0,8,5,0,0},
{204,5,1,26480,3800,1900,0,0,48,0,0,0,6,0,0,0},
{205,5,1,36240,5400,2700,0,0,57,0,0,0,10,0,0,0},
{206,6,0,34500,6000,3000,0,0,79,0,0,0,20,12,0,0},
{207,6,4,75760,9400,4700,0,0,90,0,0,0,20,0,0,0},
{208,7,0,38600,17500,8750,0,0,113,0,0,0,29,0,0,0},
{209,8,0,91200,48000,24000,0,0,171,0,0,0,57,0,6,0},
{210,8,4,200000,100000,50000,0,0,171,0,0,0,46,0,0,6},
{211,9,0,375600,84000,42000,0,0,195,0,0,0,54,0,10,0},
{212,9,1,698400,96000,48000,0,0,207,0,0,0,58,0,13,0},
{213,1,0,160,48,8,1,0,0,0,0,0,0,0,0,0},
{214,2,0,1060,212,53,3,0,6,0,0,0,0,0,0,0},
{215,3,0,460,310,155,14,0,0,0,0,0,0,0,0,0},
{216,4,0,800,800,400,21,0,0,0,0,0,0,0,0,0},
{217,5,0,12470,2400,1200,39,0,0,0,8,0,0,0,0,0},
{218,5,4,20680,3400,1700,42,0,0,0,10,0,0,0,0,0},
{219,5,1,28400,3800,1900,48,0,15,0,0,0,0,0,0,0},
{220,6,0,51320,6500,3250,79,0,0,0,20,0,0,0,0,0},
{221,7,0,133840,22000,11000,124,0,0,0,31,0,0,0,0,0},
{222,7,1,169040,29000,14500,136,0,0,0,34,0,0,0,0,0},
{223,8,0,106000,46000,23000,159,0,0,0,41,0,0,0,0,7},
{224,8,4,330080,50000,25000,171,0,0,0,35,0,0,0,0,8},
{225,8,1,318400,64000,32000,183,0,0,0,38,0,0,0,0,10},
{226,9,0,480600,81000,40500,195,0,0,0,54,0,0,0,0,10},
{227,1,0,120,36,6,0,0,1,0,0,0,0,0,0,0},
{228,1,4,680,204,34,0,0,2,0,0,0,0,0,0,0},
{229,2,0,560,112,28,0,0,2,0,0,0,0,0,0,0},
{230,3,0,1160,260,130,0,0,13,0,0,0,0,0,0,0},
{231,4,0,800,560,280,11,0,17,0,0,0,0,0,0,0},
{232,5,0,10520,1850,925,0,0,33,0,0,0,6,0,0,0},
{233,6,0,28800,6000,3000,0,0,68,0,0,0,17,0,0,0},
{234,6,1,77600,10100,5050,0,0,79,0,0,0,20,0,0,0},
{235,7,0,58600,16300,8150,0,0,113,0,0,0,29,0,0,0},
{236,7,4,116550,23000,11500,0,0,124,0,0,0,31,0,0,0},
{237,7,1,160800,30000,15000,0,0,136,0,0,0,34,0,0,0},
{238,8,0,16000,46000,23000,0,0,159,50,0,0,0,0,3,0},
{239,9,0,449600,80000,40000,0,0,207,0,0,0,58,0,10,0},
{240,9,4,460000,90000,45000,0,0,220,0,0,0,62,0,11,0},
{241,1,0,160,48,8,0,0,2,0,0,0,0,0,0,0},
{242,2,0,560,112,28,0,0,4,0,0,0,0,0,0,0},
{243,3,0,2100,210,105,0,0,13,4,0,0,0,0,0,0},
{244,4,0,1500,510,255,0,0,17,5,0,0,0,0,0,0},
{245,5,0,10400,2000,1000,0,0,33,10,0,0,6,0,0,0},
{246,5,4,16480,2800,1400,0,0,39,8,0,0,0,0,0,0},
{247,6,0,26950,4600,2300,0,0,68,21,0,0,17,0,0,0},
{248,7,0,54200,15500,7750,0,0,113,0,0,0,29,0,0,0},
{249,7,1,182960,26000,13000,0,0,124,0,0,0,31,0,0,0},
{250,8,0,88000,49000,24500,0,0,159,0,0,0,51,0,5,0},
{251,8,4,222800,109000,54500,0,0,195,0,0,0,54,0,9,0},
{252,9,0,337500,81000,40500,0,0,207,0,0,0,58,0,13,0},
{253,9,1,607500,103000,51500,0,0,220,0,0,0,46,0,15,0},
{254,1,0,160,48,8,1,0,0,0,0,0,0,0,0,0},
{255,2,0,1240,248,62,6,0,0,0,0,0,0,0,0,0},
{256,3,0,660,330,165,14,0,9,0,0,0,0,0,0,0},
{257,4,0,3900,1060,530,24,0,15,0,0,0,0,0,0,0},
{258,4,1,5400,1500,750,20,0,0,0,0,0,0,0,0,0},
{259,5,0,15680,2900,1450,48,0,0,0,10,0,0,0,0,0},
{260,6,0,42080,5600,2800,79,0,0,25,20,0,0,0,0,0},
{261,6,4,58800,9000,4500,90,0,0,0,20,0,0,0,0,0},
{262,6,1,103950,12000,6000,90,0,0,0,17,0,0,0,0,0},
{263,7,0,95960,17300,8650,113,0,70,0,29,0,0,0,0,0},
{264,8,0,106000,46000,23000,171,0,0,0,57,0,0,0,0,6},
{265,9,0,452800,76000,38000,195,0,0,0,54,0,0,0,0,10},
{266,9,4,310800,133000,66500,207,0,0,0,58,0,0,0,0,13},
{267,1,0,160,48,8,0,0,1,0,0,0,0,0,0,0},
{268,2,0,540,108,27,0,0,2,0,0,0,0,0,0,0},
{269,3,0,660,210,105,0,0,11,0,0,0,0,0,0,0},
{270,3,4,3600,360,180,0,0,14,0,0,0,0,0,0,0},
{271,3,1,4460,710,355,0,0,17,0,0,0,0,0,0,0},
{272,4,0,-1200,840,420,6,0,21,0,0,0,0,0,0,0},
{273,5,0,12400,2200,1100,0,0,39,0,0,0,8,0,0,0},
{274,5,1,27480,3900,1950,0,0,48,0,0,0,10,0,0,0},
{275,6,0,35040,4800,2400,0,0,68,21,0,0,17,0,0,0},
{276,6,4,60280,7300,3650,0,0,90,22,0,0,23,0,0,0},
{277,7,0,27200,16400,8200,0,0,113,0,0,0,29,0,0,0},
{278,8,0,109650,44000,22000,0,0,159,0,0,0,51,0,5,0},
{279,9,0,381760,76000,38000,0,0,195,0,0,0,41,0,13,0},
{280,1,0,160,48,8,1,0,0,0,0,0,0,0,0,0},
{281,2,0,700,140,35,2,0,5,0,0,0,0,0,0,0},
{282,3,0,780,210,105,11,0,0,0,0,0,0,0,0,0},
{283,3,1,3000,300,150,13,0,0,0,0,0,0,0,0,0},
{284,4,0,1800,540,270,17,0,11,0,0,0,0,0,0,0},
{285,5,0,11120,2000,1000,39,0,0,0,8,0,0,0,0,0},
{286,5,4,20400,3000,1500,48,0,0,0,10,0,0,0,0,0},
{287,6,0,48200,5900,2950,79,0,0,25,20,0,0,0,0,0},
{288,7,0,107960,17300,8650,113,0,70,0,29,0,0,0,0,0},
{289,8,0,102400,49000,24500,159,0,0,0,51,0,0,0,0,5},
{290,9,0,499600,78000,39000,195,0,0,0,67,0,0,0,0,10},
{291,1,0,160,48,8,0,0,1,0,0,0,0,0,0,0},
{292,1,4,740,222,37,0,0,2,0,0,0,0,0,0,0},
{293,2,0,540,108,27,0,0,2,0,0,0,0,0,0,0},
{294,3,0,780,198,99,0,0,11,0,0,0,0,0,0,0},
{295,3,1,3500,350,175,0,0,13,0,0,0,0,0,0,0},
{296,4,0,5100,700,350,0,0,21,0,0,0,0,0,0,0},
{297,4,1,5300,1250,625,0,0,18,0,0,0,0,0,0,0},
{298,5,0,9720,1740,870,0,0,33,10,0,0,6,0,0,0},
{299,6,0,32280,5100,2550,0,0,68,21,0,0,17,0,0,0},
{300,7,0,37250,14300,7150,0,0,102,0,0,0,26,0,0,0},
{301,8,0,-28000,44000,22000,0,0,159,0,0,0,51,0,5,0},
{302,8,4,194800,55000,27500,0,0,171,0,0,0,46,0,6,0},
{303,9,0,340400,80000,40000,0,0,195,0,0,0,54,0,10,0},
{304,9,4,525200,86000,43000,0,0,207,0,0,0,58,0,13,0},
{305,9,1,762400,106000,53000,0,0,207,0,0,0,58,0,13,0},
{306,1,0,320,96,16,0,2,0,0,0,0,0,0,0,0},
{307,2,0,1460,292,73,0,11,0,0,0,0,0,0,0,0},
{308,3,0,960,360,180,0,14,0,9,0,0,0,0,0,0},
{309,4,0,1200,840,420,15,24,0,0,0,0,0,0,0,0},
{310,4,4,8100,1530,765,0,27,0,0,0,0,0,0,0,0},
{311,5,0,5520,2400,1200,0,37,0,0,0,8,0,0,0,0},
{312,5,1,26400,3600,1800,0,45,0,0,0,9,0,0,0,0},
{313,5,1,29600,4400,2200,18,57,0,0,0,0,0,0,0,0},
{314,6,0,30600,5400,2700,0,64,0,0,10,17,0,0,0,0},
{315,7,0,79080,16500,8250,0,106,0,0,18,29,0,0,0,0},
{316,8,0,73500,49000,24500,0,159,0,0,0,51,0,0,0,5},
{317,9,0,461600,80000,40000,0,182,0,0,0,54,0,0,0,10},
{318,9,4,591600,90000,45000,0,193,0,0,0,58,0,0,0,13},
{319,9,1,695600,95000,47500,0,193,0,0,0,58,0,0,0,13},
{320,9,1,625600,100000,50000,0,193,0,0,0,58,0,0,0,13},
{321,1,0,1720,516,86,4,0,0,0,0,0,0,0,0,0},
{322,2,0,3000,600,150,4,0,0,0,0,0,0,0,0,0},
{323,3,0,5520,840,420,24,0,0,15,0,0,0,0,0,0},
{324,3,4,7200,1440,720,24,0,0,0,0,0,0,0,0,0},
{325,4,0,12300,1710,855,39,0,0,25,0,0,0,0,0,0},
{326,4,1,18400,2800,1400,18,0,0,24,0,0,0,0,0,0},
{327,5,0,20600,3500,1750,57,0,0,0,13,0,0,0,0,0},
{328,5,1,37520,5000,2500,43,0,0,0,13,0,0,0,0,0},
{329,6,0,51800,5900,2950,79,0,0,49,20,0,0,0,0,0},
{330,7,0,43600,14800,7400,113,0,0,0,29,0,0,0,0,0},
{331,7,4,99040,22000,11000,124,0,0,0,31,0,0,0,0,0},
{332,7,1,218160,30000,15000,136,0,0,0,34,0,0,22,0,0},
{333,8,0,106000,46000,23000,171,0,0,0,57,0,0,0,0,6},
{334,9,0,259600,70000,35000,195,0,0,0,54,0,0,0,0,10},
{335,9,1,590000,95000,47500,207,0,0,0,58,0,0,0,0,13},
{336,1,0,1380,414,69,2,0,6,0,0,0,0,0,0,0},
{337,2,0,2600,520,130,3,0,8,0,0,0,0,0,0,0},
{338,3,0,2140,610,305,13,0,0,0,0,0,0,0,0,0},
{339,4,0,10100,1490,745,21,0,17,0,0,0,0,0,0,0},
{340,4,4,7600,2200,1100,25,0,6,0,0,0,0,0,0,0},
{341,5,0,19240,2500,1250,30,0,25,0,6,0,0,0,0,0},
{342,5,1,40320,4800,2400,36,0,24,0,6,0,0,0,0,0},
{343,5,4,-75000,12500,6250,51,0,43,0,11,0,0,0,0,0},
{344,6,0,54950,7400,3700,51,0,43,0,12,0,0,0,0,0},
{345,7,0,118960,19600,9800,93,0,0,0,23,0,0,20,0,0},
{346,7,1,155600,29000,14500,102,0,0,0,26,0,0,18,0,0},
{347,8,0,173150,50000,25000,119,0,0,0,39,0,0,0,0,5},
{348,9,0,294750,76000,38000,146,0,0,0,40,0,0,0,0,9},
{349,9,1,765600,104000,52000,0,136,0,0,0,38,0,0,0,11},
{350,4,3,-5600,880,0,0,0,0,15,0,0,0,0,0,0},
{351,7,3,37960,11500,0,0,0,0,59,0,0,0,17,0,0},
{352,9,3,110800,40000,0,0,0,0,99,0,0,0,25,0,0},
{353,4,0,-12500,1630,1630,26,0,0,0,0,0,0,0,0,0},
{354,7,0,131400,21000,21000,113,0,0,0,36,0,0,0,0,0},
{355,9,0,194600,70000,70000,159,0,0,0,41,0,0,0,7,0},
{356,4,0,-18800,1480,1480,0,26,0,0,0,0,0,0,0,0},
{357,7,0,158000,20000,20000,0,113,0,0,0,36,0,0,0,0},
{358,9,0,5000,70000,70000,0,149,0,0,0,41,0,0,7,0},
{359,4,0,-21300,1710,1710,0,0,26,0,0,0,0,0,0,0},
{360,7,0,123640,19900,19900,0,0,113,0,0,0,36,0,0,0},
{361,9,0,5000,70000,70000,0,0,159,0,0,0,41,0,7,0},
{362,4,0,-11120,1960,1960,0,0,0,26,0,0,0,0,0,0},
{363,7,0,146200,19300,19300,0,0,0,113,0,0,0,36,0,0},
{364,9,0,-5800,70000,70000,0,0,0,159,0,0,0,41,7,0},
{365,4,0,-9600,1920,1920,0,0,0,21,0,0,0,0,0,0},
{366,7,0,101800,19300,19300,0,0,0,113,0,0,0,36,0,0},
{367,9,0,62600,70000,70000,0,0,0,159,0,0,0,41,7,0},
{368,4,0,-11520,2100,2100,0,0,0,21,0,0,0,0,0,0},
{369,7,0,81600,21000,21000,0,0,0,113,0,0,0,36,0,0},
{370,9,0,121400,70000,70000,0,0,0,159,0,0,0,41,7,0},
{371,4,0,-10000,1880,1880,0,0,0,24,0,0,0,0,0,0},
{372,4,0,-18800,1840,1840,24,0,0,0,0,0,0,0,0,0},
{373,4,0,-10720,2000,2000,0,24,0,0,0,0,0,0,0,0},
{374,4,0,-18900,1950,1950,0,0,24,0,0,0,0,0,0,0},
{375,4,0,-10520,2200,2200,0,0,0,24,0,0,0,0,0,0},
{376,4,0,-9600,2400,2400,0,0,24,0,0,0,0,0,0,0},
{377,7,0,168640,22000,22000,124,0,0,0,39,0,0,0,0,0},
{378,7,0,174400,22000,22000,0,0,124,0,0,0,39,0,0,0},
{379,7,0,143600,23000,23000,0,0,0,124,0,0,0,39,0,0},
{380,7,0,62000,26000,26000,0,0,0,124,0,0,0,39,0,0},
{381,7,0,91600,25000,25000,0,124,0,0,0,39,0,0,0,0},
{382,7,0,133280,26000,26000,0,124,0,0,0,39,0,0,0,0},
{383,9,0,95000,70000,70000,159,0,0,0,41,0,0,0,0,7},
{384,9,0,62600,70000,70000,0,0,159,0,0,0,41,0,0,7},
{385,9,0,95000,70000,70000,0,149,0,0,0,41,0,0,0,7},
{386,9,0,87800,70000,70000,0,149,0,0,0,41,0,0,0,7},
{387,9,0,114200,70000,70000,0,0,0,159,0,0,0,41,0,7},
{388,9,0,172280,70000,70000,0,0,0,159,0,0,0,41,0,7}
    };

    for (int a = 0; a < 13; a++) {
        Items[0][a] = ItemsLoader[0][a];
    }

    int b = 1;

    for (int a = 1; a < 389; a++) {
        if (ItemsLoader[a][1] >= TierMin && ItemsLoader[a][1] <= TierMax && ((F2P == false && ItemsLoader[a][2] == 0) || (F2P == true && ItemsLoader[a][2] == 1) || (Engineer == true && ItemsLoader[a][2] == 2) || (Academy == true && ItemsLoader[a][2] == 3) || (Chest == true && ItemsLoader[a][2] == 4))) {
            Items[b][0] = ItemsLoader[a][0];
            Items[b][1] = ItemsLoader[a][3]+ItemsLoader[a][4];
            if (A21 == true) {
                Items[b][1] = Items[b][1] + ItemsLoader[a][5];
            }

            Items[b][3] = ItemsLoader[a][6];
            Items[b][4] = ItemsLoader[a][7];
            Items[b][5] = ItemsLoader[a][8];
            Items[b][6] = ItemsLoader[a][9];
            Items[b][7] = ItemsLoader[a][10];
            Items[b][8] = ItemsLoader[a][11];
            Items[b][9] = ItemsLoader[a][12];
            Items[b][10] = ItemsLoader[a][13];
            Items[b][11] = ItemsLoader[a][14];
            Items[b][12] = ItemsLoader[a][15];
            Items[b][13] = 0;
            b++;
            NumItems++;
        }

    }

    RegenTime = 0;

    for (int a = 0; a < NumItems; a++) {
        for (int b = 0; b < 10; b++) {
            if ((Items[a][b + 3] / MatRegen[b] > RegenTime)) {
                RegenTime = Items[a][b + 3] / MatRegen[b];
                MatType = b;
            }
        }

        Items[a][16] = MatType;
        Items[a][15] = RegenTime;
        Items[a][14] = Items[a][1] * (60 / RegenTime);
        RegenTime = 0;

    }

    for (int a = 0; a < NumItems; a++) {
        for (int b = 0; b < 10; b++) {

            cout << Items[a][b] << ", ";
        }

        cout << endl;
    }

    cout <<  NumItems << " items loaded from database." << endl;
    return;
}
