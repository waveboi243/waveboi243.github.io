#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

void typeText(char text[], int nl);
void wait(double waittime);
int combatProcess(char monsterName[60], char monsterStats[2][100], char playerStats[2][100], char weapon[30], int initPlayerHP);
int checkForDeath(int monsterHP, int playerHP);

int main() {
  int x,x2;
  srandom(time(NULL));  
  char response[999];
  char weapons[6][10] = {
  "Knife",
  "Scythe",
  "Nunchucks",
  "Dagger",
  "Sword",
  "Mace"
  };
  typeText("Welcome to Saghal Briste, traveler. I am Neach Cuideachaidh, your guide.", 1);
  wait(1);
  typeText("What is your name?", 1);
  char name[999];
  fgets(name, 999, stdin);
  typeText("Nice to meet you, ", 0);
  typeText(name, 0);
  typeText("No time to chitchat, though, for there is a lot to be done.", 1);
  typeText("Not all that long ago, this world was known as Paradesa, or World of Paradise. ", 1);
  typeText("Many other worlds envied the peace of ours, and wanted our world's beauty for themselves. ", 1);
  typeText("One such world, An Namhaid, decided to make their thoughts a reality, and invaded. ", 1);
  typeText("The soldiers of An Namhaid, the Pupaidean,  pillaged our cities and took many of our people captive. ", 1);
  typeText("They  burned our capital to the ground and the ruler of An Namhaid, Ceannard Olc, declared himself Supreme Ruler over Paradesa.", 1);
  typeText("He renamed our now-ravaged world Saghal Briste.", 1);
  typeText("He then appointed two leaders, one for each sector or the world: ", 1);
  typeText("Duine nas Lugha, a humanoid lizard, leader of the Lower Sector. ", 1);
  typeText("And Neach Meadhanach, an 8-foot reanimated skeleton, leader of the Upper Sector. ", 1);
  typeText("We've lived under the suppresion of these tyrants for so long. Will you help us break free? (Enter Y or N)", 1);
  fflush(stdin);
  response[1] = tolower(getchar());
  if (response[1] == 'y') goto continueGame;
  typeText("Smart choice. Goodbye, then.", 1);
  return (0);
  continueGame:
    typeText("Good choice! Now that that's settled, what's your preferred weapon? ", 1);
    char weapon2[999];
    char weapon[999];
    fflush(stdin);
    while ((getchar()) != '\n');
    fgets(weapon2, 999, stdin);
    strncpy(weapon, weapon2, strlen(weapon2) - 1);
    typeText(weapon, 0);
    typeText("? Okay...", 1);
    typeText("Let's get you trained, then. ", 1);                     
    typeText("Traveling to Training Ground...", 1);
    wait(1);
    typeText("We've arrived. In a while, you'll start fighting dummies. Now, since you're blind, I'll have to help you enage in combat. I'll ask you what you want to do, and prepare you. Hopefully, you're able to dispatch a simple training dummy. Get ready!", 1);
    char playerStats[2][100] = {"150", "25"};
    char monsterStats[2][100] = {"100", "15"};
    int done = 1;
    while (done) {
      sprintf(playerStats[0], "%s", "150");
      sprintf(monsterStats[0], "%s", "100");
      x = combatProcess("Combat Dummy", monsterStats, playerStats, weapon, strtol(playerStats[0], NULL, 10));
      if (x == 0) typeText("Seriously? I don't think fleeing was nessecary at all. Try again, please. ", 1);
      if (x == 1) {
        int newPlayerHP = strtol(playerStats[0], NULL, 10) + 10;
        sprintf(playerStats[0], "%d", newPlayerHP);
        int newPlayerPower = strtol(playerStats[1], NULL, 10) + 5;
        sprintf(playerStats[1], "%d", newPlayerPower);
        typeText("Congrats! Want to do it again? (Y/N) ", 1);
        while ((getchar()) != '\n');
        if (tolower(getchar()) == 'y')
        {
          typeText("Alright!", 1);
          
        }
        else {
          typeText("Okay, then.", 1);
          break;
        }
      }
      if (x == 2) {
        typeText("Goodbye, traveler.", 1);
        return(0);
      }
    }
    typeText("Well, that went well...enough. Let's make our way to Inferius, the capital of the Lower Sector.", 1);
    typeText("[You walk along the road for a while.]", 1);
    wait(2);
    typeText("[You continue walking.]", 1);
    wait(2);
    typeText("[You're still walking...]", 1);
    wait(2);
    typeText("There's a lizard up ahead. Want to fight it (and possibly increase your battle experience?) (Y/N)", 1);
    fflush(stdin);
    while ((getchar()) != '\n');
    response[1] = tolower(getchar());
    if (response[1]=='y') {
      sprintf(monsterStats[1], "%s", "80");
      sprintf(monsterStats[2], "%s", "20");
      x = combatProcess("Small Lizard", monsterStats, playerStats, weapon, strtol(playerStats[0], NULL, 10));
      if (x == 1) {
        int newPlayerHP = strtol(playerStats[0], NULL, 10) + 10;
        sprintf(playerStats[0], "%d", newPlayerHP);
        int newPlayerPower = strtol(playerStats[1], NULL, 10) + 5;
        sprintf(playerStats[1], "%d", newPlayerPower);
      }
      if (x == 2) {
        typeText("Goodbye, traveler.", 1);
        return(0);
      }
  }
    else typeText("Bad choice, but okay. ", 1);
    typeText("[You walk along the road for a while.]", 1);
    wait(2);
    typeText("[You continue walking.]", 1);
    wait(2);
    for (x=0; x<3; x++)
      {typeText("[You're still walking...]", 1);
    wait(2);}
    typeText("It's ANOTHER lizard! This one is slightly bigger. Want to fight it (and pOsSiBlY increase your battle experience?) (Y/N)", 1);
    fflush(stdin);
    while ((getchar()) != '\n');
    response[1] = tolower(getchar());
    fflush(stdin);
    if (response[1]=='y') {
      sprintf(monsterStats[1], "%s", "100");
      sprintf(monsterStats[2], "%s", "22");
      x = combatProcess("Medium Lizard", monsterStats, playerStats, weapon, strtol(playerStats[0], NULL, 10));
      if (x == 1) {
        int newPlayerHP = strtol(playerStats[0], NULL, 10) + 10;
        sprintf(playerStats[0], "%d", newPlayerHP);
        int newPlayerPower = strtol(playerStats[1], NULL, 10) + 5;
        sprintf(playerStats[1], "%d", newPlayerPower);
      }
      if (x == 2) {
        typeText("Goodbye, traveler.", 1);
        return(0);
      }
  }
    else typeText("Okay... ", 1);
    typeText("[You walk along the road for a while.]", 1);
    wait(2);
    typeText("[You continue walking.]", 1);
    wait(2);
    for (x=0; x<3; x++)
      {typeText("[You're still walking...]", 1);
    wait(2);}
    typeText("Yet another lizard has crossed your path! This one is even larger. It's almost as if someone's sending these lizards. Want to fight it (and pOOsIBlY increase your battle experience?) (Y/N)", 1);
    fflush(stdin);
    while ((getchar()) != '\n');
    response[1] = tolower(getchar());
    if (response[1]=='y') {
      sprintf(monsterStats[1], "%s", "125");
      sprintf(monsterStats[2], "%s", "27");
      x = combatProcess("Large Lizard", monsterStats, playerStats, weapon, strtol(playerStats[0], NULL, 10));
      if (x == 1) {
        int newPlayerHP = strtol(playerStats[0], NULL, 10) + 10;
        sprintf(playerStats[0], "%d", newPlayerHP);
        int newPlayerPower = strtol(playerStats[1], NULL, 10) + 5;
        sprintf(playerStats[1], "%d", newPlayerPower);
      }
      if (x == 2) {
        typeText("Goodbye, traveler.", 1);
        return(0);
      }
  }
    else typeText("Alright... ", 1);
    typeText("Oh, my, another lizard. This one is GIGANTIC! Want to fight it (and pOOSiBLY increase your battle experience?) (Y/N)", 1);
    fflush(stdin);
    while ((getchar()) != '\n');
    response[1] = tolower(getchar());
    if (response[1]=='y') {
      sprintf(monsterStats[1], "150");
      sprintf(monsterStats[2], "30");
      x = combatProcess("Large Lizard", monsterStats, playerStats, weapon, strtol(playerStats[0], NULL, 10));
      if (x == 1) {
        int newPlayerHP = strtol(playerStats[0], NULL, 10) + 10;
        sprintf(playerStats[0], "%d", newPlayerHP);
        int newPlayerPower = strtol(playerStats[1], NULL, 10) + 5;
        sprintf(playerStats[1], "%d", newPlayerPower);
      }
      if (x == 2) {
        typeText("Goodbye, traveler.", 1);
        return(0);
      }
  }
    else typeText("That was a terrible choice! Whatever.", 1);
    // code here
  }
void wait(double waittime)
{
    usleep(waittime*1000000);
}

void typeText(char *text, int nl)
  {
    int index = 0;
    while (index<strlen(text))
      {
        putchar(text[index]);
        fflush(stdout);
        index++;
        wait(0);
      }
    if (nl) putchar('\n');
    wait(0.15);
  }
int checkForDeath(int monsterHP, int playerHP) {
  if (monsterHP <= 0) {
      typeText("You have triumphed over your enemy!", 1); 
      return(1);
      }
  else if (playerHP <= 0) {
      typeText("You have died. Better luck next time!", 1); 
      return(2);
      }
  else return(0);
}
int combatProcess(char monsterName[60], char monsterStats[2][100], char playerStats[2][100], char weapon[30], int initPlayerHP)
{
  int response;
  int x,x2,x3 = 0;
  typeText("You approach ", 0);
  typeText(monsterName, 0);
  typeText(".", 1);
  continueCombatProcess:
    x = strtol(monsterStats[0], NULL, 10);
    x2 = strtol(playerStats[0], NULL, 10);
    x3 = checkForDeath(x, x2);
    switch(x3) {
      case 1:
        return(1);
        break;
      case 2:
        return(2);
    }
    typeText(monsterName, 0);
    typeText("'s current HP: ", 0);
    typeText(monsterStats[0], 1);
    typeText("Your current HP: ", 0);
    typeText(playerStats[0], 1);
    typeText(monsterName, 0);
    typeText(" attacks! ", 1);
    if (random() % 2 == 0)
    {
      typeText("It deals ", 0);
      typeText(monsterStats[1], 0);
      typeText(" damage. ", 1);
      int newPlayerHP = strtol(playerStats[0], NULL, 10) -strtol(monsterStats[1], NULL, 10);
      sprintf(playerStats[0], "%d", newPlayerHP);
    }
    else typeText("It misses.", 1);
    x = strtol(monsterStats[0], NULL, 10);
    x2 = strtol(playerStats[0], NULL, 10);
    x3 = checkForDeath(x, x2);
    switch(x3) {
      case 1:
        return(1);
        break;
      case 2:
        return(2);
        break;
      }
    typeText("You may: [1] attack, [2] skip your turn, [3] attempt to heal, or [4] flee. ", 1);
    typeText("What would you like to do? (enter the number) ", 0);
    fflush(stdin);
    scanf("%d",&response);
    switch(response)
      {
        case 2:
          typeText("You skipped your turn. Bad move lol", 1);
          goto continueCombatProcess;
        case 1:
          typeText("You attack with your ", 0);
          typeText(weapon, 0);
          typeText(".", 1);
          x = random() % (2 - 0 + 1) + 0;
          if (x==0) 
            typeText("It's not very effective...", 1); 
          else if (x==2) 
            typeText("It's very effective!", 1);
          int damage = strtol(playerStats[1], NULL, 10) * ((x+1)/2);
          typeText("You deal ", 0); 
          printf("%d", damage);
          typeText(" damage. ", 1);
          int newMonsterHP = strtol(monsterStats[0], NULL, 10) - damage;
          sprintf(monsterStats[0], "%d", newMonsterHP);
          goto continueCombatProcess;
        case 3:
          if (strtol(playerStats[0], NULL, 10)>=initPlayerHP)                   {typeText("You don't need to heal.", 1);}
          else {
            typeText("You attempt to heal. ", 1);
            x = random() % 3;
            if(x==0) {
              typeText("You suceed!", 1); 
              int newPlayerHP = strtol(playerStats[0], NULL, 10) + 30;
              sprintf(playerStats[0], "%d", newPlayerHP);
            }
            else {typeText("You fail. ", 1);}
          }
          goto continueCombatProcess;
        case 4:
          typeText("You flee. Terrible move.", 1);
          return(0);
        default:
          typeText("You failed to make a decision. Biig L.", 1);
          goto continueCombatProcess;
    }
}

  
