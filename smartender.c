Axel TERRIER 2020

#include LiquidCrystal.h  on importe la bibliothèque pour LCD

LiquidCrystal monEcran(12, 11, 7, 6, 5, 2); initialisation de mon écran LCD en fonction de mes PIN

const int bout1 = 8; constante du bouton menu 1
const int bout2 = 3; constante du bouton menu 2
const int bout3 = 9; constante du bouton de validation

const int pompe0 = A0;  Affectation des pin de sorties aux différentes pompes
const int pompe1 = A1;
const int pompe2 = A2;
const int pompe3 = A3;
const int pompe4 = A4;
const int pompe5 = A5;
const int pompe6 = 13;
const int pompe7 = 10;
const int pompe8 = 4;
const int pompe9 = 1;
const int pompe10 = 0;

const byte NbCocktailMin = 1;
const byte NbCocktailMax = 5; 
A FIXER EN FONCTION DU NB DE COCKTAIL pour l'instant je travaille sur une Arduino Uno ma mémoire est limitée a 32ko


bool flag_pompe1 = true;    Variable permettant de détecter si un ingrédient est disponible
bool flag_pompe2 = true;    Si il l'est on l'affecte à une pompe
bool flag_pompe3 = true;
bool flag_pompe4 = true;
bool flag_pompe5 = true;
bool flag_pompe6 = true;
bool flag_pompe7 = true;
bool flag_pompe8 = true;
bool flag_pompe9 = true;
bool flag_pompe10 = true;
bool flag_pompe11 = true;
bool flag_pompe12 = true;
bool flag_pompe13 = true;
bool flag_pompe14 = true;
bool flag_pompe15 = true;
bool flag_pompe16 = true;
bool flag_pompe17 = true;
bool flag_pompe18 = true;
bool flag_pompe19 = true;
bool flag_pompe20 = true;
bool flag_pompe21 = true;
bool flag_pompe22 = true;
bool flag_pompe23 = true;

bool flag_comptage_while = false;

bool Whisky = false;    Variable permettant de tester si on a ou non l'ingrédient en question
byte Whiskyp = 50;      Permets de se souvenir a quelle pompe l'ingrédient est associé si on l'a
bool Captain = false;
byte Captainp = 50;
bool Rhum = false;
byte Rhump = 50;
bool Gin = false;
byte Ginp = 50;
bool Soho = false;
byte Sohop = 50;
bool Martini = false;
byte Martinip = 50;
bool Vodka = false;
byte Vodkap = 50;
bool Jaeger = false;
byte Jaegerp = 50;
bool Cointreau = false;
byte Cointreaup = 50;
bool Tequila = false;
byte Tequilap = 50;
bool Malibu = false;
int Malibup = 50;

bool Coca = false;
byte Cocap = 50;
bool EnergyDrink = false;
byte Energyp = 50;
bool JusAnanas = false;
byte Ananasp = 50;
bool JusOrange = false;
byte Orangep = 50;
bool JusCitron = false;
byte Citronp = 50;
bool LaitCoco = false;
byte Cocop = 50;
bool Sprite = false;
byte Spritep = 50;
bool EauGazeuse = false;
byte EauGazeusep = 50;
bool JusPomme = false;
byte JusPommep = 50;
bool SiropGrenadine = false;
byte SiropGrenadinep = 50;
bool GingerAle = false;
byte GingerAlep = 50;
bool Limonade = false;
byte Limonadep = 50;

bool PinaColada = false;    Grace a ces variables on test si les cocktail sont disponibles en fonction des ingrédients
bool RhumCoke = false;
bool RhumCokeLime = false;
bool Afterglow = false;
bool AlbermaleFizz = false;
bool Algonquin = false;
bool BellaLuna = false;
bool BlueLady = false;
bool Cendrillon = false;
bool Margarita = false;
bool RedApple = false;
bool RedSombrero = false;
bool SweetPoison = false;
bool SouthSide = false;
bool WhiteLion = false;

byte cpt = 0;

int flagbout3;
int pompe = 0;
int NbCocktail = 2;

int PX[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; Permets de faire défiler le tableau contenant le numéro des pompes
int px = -1;
String npompe[10] = {Pompe 0         ,Pompe 1         ,Pompe 2         ,Pompe 3         ,Pompe 4         ,Pompe 5         , Pompe 6         ,Pompe 7         ,Pompe 8         ,Pompe 9         };

char ipompe = 12;

void setup() {
  pinMode(bout1, INPUT);    On règle en entréesortie les PINs nécéssaire
  pinMode(bout2, INPUT);

  pinMode(pompe0, OUTPUT);
  pinMode(pompe1, OUTPUT);
  pinMode(pompe2, OUTPUT);
  pinMode(pompe3, OUTPUT);
  pinMode(pompe4, OUTPUT);
  pinMode(pompe5, OUTPUT);
  pinMode(pompe6, OUTPUT);
  pinMode(pompe7, OUTPUT);
  pinMode(pompe8, OUTPUT);
  pinMode(pompe9, OUTPUT);
  pinMode(pompe10, OUTPUT);

  bool etatBout1 = digitalRead(bout1);    On lis l'état des boutons
  bool etatBout2 = digitalRead(bout2);
  bool etatBout3 = digitalRead(bout3);

  initialisation de l'écran LCD
  monEcran.begin(16, 2); on initialise la communication avec 16 colonnes et 2 lignes
  monEcran.clear();  on efface l'écran

  monEcran.setCursor(0, 0);
  monEcran.print(Selection des   );
  monEcran.setCursor(0, 1);
  monEcran.print(boissons dispo  );
  while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU WHISKY + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Whisky          );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true)
    {
      Whisky = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);

      while(flag_pompe1)    Début de la fonction pour savoir si un ingrédient est disponible et si oui on l'associe a une pompe
      {
        monEcran.setCursor(0, 1);
        monEcran.print(npompe[ipompe]);
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe1 == true)
        {
                if(etatBout1 = digitalRead(bout1) == true)  Navigation dans l'indice des pompes
                {
                ipompe = ipompe + 1;
                  if(ipompe == 11)
                  {
                    ipompe = 0;
                  }

                }
                else if(etatBout2 = digitalRead(bout2) == true) Navigation dans l'indice des pompes
                {
                    ipompe = ipompe - 1;
                     if(ipompe == -1)
                     {
                        ipompe = 10;
                     }
                }
                else if(etatBout3 = digitalRead(bout3) == true) Validation de la pompe
               {
                  flag_pompe1 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Whisky          );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Whiskyp = ipompe;
      px = px + 1;
      PX[px] = ipompe;


    }
    else if(etatBout1 = digitalRead(bout1) == true) Message si l'ingrédient  n'es pas disponible
    {
      Whisky = 0;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Whisky...       );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else    Message en cas d'erreur
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





    while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU CAPTAIN + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Captain         );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true)
    {
      Captain = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      while(flag_pompe2)
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe2 == true) OUI - NON OU SELECTION FAITE
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe2 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Captain         );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Captainp = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Captain = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Captain...      );
      monEcran.setCursor(0, 1);
      monEcran.print(Tant pis...     );
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU RHUM + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Rhum            );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Rhum = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe3)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe3 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe3 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Rhum            );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Rhump = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Rhum = 0;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Rhum...         );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }




while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU GIN + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Gin             );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Gin = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe4)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe4 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe4 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Gin             );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Ginp = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Gin = 0;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Gin             );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU SOHO  + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Soho            );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Soho = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe5)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe5 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe5 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Soho            );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Sohop = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Soho = 0;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Soho            );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }



while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU MARTINI + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Martini        );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Martini = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe6)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe6 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe6 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Martini         );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Martinip = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Martini = 0;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Martini         ); X
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }



while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DE LA VODKA  + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Vodka           );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Vodka = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe7)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe7 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe7 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Vodka           );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Vodkap = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Vodka = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Vodka           );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }




while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU JAEGER + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Jaeger eren mdr );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Jaeger = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe8)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe8 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe8 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jaeger          );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Jaegerp = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Jaeger = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jaeger);
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU COCA + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Coca            );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Coca = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe9)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe9 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe9 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Coca            );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Cocap = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Coca = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Coca            );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }


while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DE L'ENERGY DRINK + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Energy drink    );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      EnergyDrink = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe10)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe10 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe10 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Energy drink    );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Energyp = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      EnergyDrink = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Energy drink    );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU JUS D'ANANAS + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Jus d'ananas    );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      JusAnanas = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe11)
      {

        while(( (etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe11 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe11 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus d'ananas    );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Ananasp = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      JusAnanas = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus d'ananas    );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }




while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU JUS D'ORANGE + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Jus d'orange    );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      JusOrange = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe12)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe12 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe12 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus d'orange);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Orangep = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      JusOrange = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus d'orange    );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU JUS DE CITRON + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Jus de citron   );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      JusCitron = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe13)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe13 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe13 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus de citron   );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Citronp = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      JusCitron = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus de citron   );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }




while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU LAIT DE COCO + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Lait de coco    );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      LaitCoco = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe14)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe14 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe14 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Lait de coco    );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Cocop = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      LaitCoco = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Lait de coco    );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }





while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU SPRITE + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Sprite          );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Sprite = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe15)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe15 == true)
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe15 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sprite          );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Spritep = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Sprite = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sprite          );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }
while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU COINTREAU + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Cointreau         );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Captain = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe16)
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe16 == true) OUI - NON OU SELECTION FAITE
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe16 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Cointreau       );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Captainp = ipompe;
      Cointreaup = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Cointreau = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Pas de cointreau);
      monEcran.setCursor(0, 1);
      monEcran.print(Tant pis...     );
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }

    while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DE LA TEQUILA + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Tequila         );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Tequila = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe17)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe17 == true) X
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe17 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Tequila);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Tequilap = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Tequila = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Tequila         );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }


while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU MALIBU  + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Malibu          );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Malibu = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe18)
      {

        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe18 == true) X
        {

                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe18 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Malibu          );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Malibup = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Malibu = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Malibu          );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }

while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DE L'EAU GAZEUSE + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Eau gazeuse     );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      EauGazeuse = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe19)
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe19 == true) X
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe19 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Eau gazeuse     );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      EauGazeusep = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      EauGazeuse = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Eau gazeuse     );
      monEcran.setCursor(0, 1);
      monEcran.print(Ben voyons...   );
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }

while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU JUS DE POMME + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Jus de pomme    );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      JusPomme = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe20)
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe20 == true)
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe20 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus de pomme    );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      px = px + 1;
      JusPommep = ipompe;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      JusPomme = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Jus de pomme    );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }

while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DU SIROP DE GRENADINE + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Grenadine       );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      SiropGrenadine = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe21) X
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe21 == true)
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe21 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Grenadine       );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      SiropGrenadinep = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      SiropGrenadine = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Grenadine       );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }

while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DE LA GINGER ALE  + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Ginger Ale      );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      GingerAle = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe22)
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe22 == true)
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe22 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Ginger Ale      );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      GingerAlep = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      GingerAle = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Ginger Ale      );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }
while(etatBout3 = digitalRead(bout3) == false)
  {}
    monEcran.clear();                            SELECTION DE LA LIMONADE  + N° POMPE
    monEcran.setCursor(0, 0);
    monEcran.print(  Oui    Non  );
    monEcran.setCursor(0, 1);
    monEcran.print(Limonade        );
    while((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false))
    {
    }
    if(etatBout2 = digitalRead(bout2) == true && cpt10)
    {
      Limonade = true;
      correction_indice();
      delay(100);
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Sur quelle pompe);
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);

      while(flag_pompe23)
      {
        while(((etatBout2 = digitalRead(bout2) == false) && (etatBout1 = digitalRead(bout1) == false)) && flag_pompe23 == true)
        {
                if(etatBout1 = digitalRead(bout1) == true)
                {
                  ipompe = ipompe + 1;
                  if(flag_comptage_while == false)
                  {
                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                   while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                  {
                    ipompe = ipompe + 1;
                    flag_comptage_while = true;

                    if(ipompe   9)
                      {
                        ipompe = 0;
                      }
                  }
                      flag_comptage_while = false;
                      monEcran.setCursor(0, 1);
                      monEcran.print(npompe[ipompe]);

                }
                else if(etatBout2 = digitalRead(bout2) == true)
                {
                    ipompe = ipompe - 1;
                    if(flag_comptage_while == false)
                    {
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
                    {
                      ipompe = ipompe - 1;
                      flag_comptage_while = true;
                      if(ipompe   0)
                      {
                        ipompe = 9;
                      }
                    }
                    flag_comptage_while = false;
                    monEcran.setCursor(0, 1);
                    monEcran.print(npompe[ipompe]);
                }
                else if(etatBout3 = digitalRead(bout3) == true)
               {
                  flag_pompe23 = false;
               }
        }
      }
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Limonade        );
      monEcran.setCursor(0, 1);
      monEcran.print(npompe[ipompe]);
      Limonadep = ipompe;
      px = px + 1;
      PX[px] = ipompe;
    }
    else if(etatBout1 = digitalRead(bout1) == true)
    {
      Limonade = false;
      monEcran.clear();
      monEcran.setCursor(0, 0);
      monEcran.print(Pas de limonade );
      monEcran.setCursor(0, 1);
      monEcran.print(Ah... Dommage...);
    }
    else
    {
      monEcran.clear();
      monEcran.print(Aie... probleme);
    }

FIN DE LA SELECTION DES BOISSONS

while(etatBout3 = digitalRead(bout3) == false)    Après le dernier ingrédient on attends un appui sur le bouton VALIDER 
  {}

On cherche a détecter si les cocktail sont disponibles grace
aux variables booléennes mise a TRUE si l'ingrédient est associé a une pompe

    if(Rhum & LaitCoco & JusAnanas) Es ce que les 3 ingrédients sont tous disponible 
    {
      PinaColada = true;  Ils sont disponibles donc le cocktail l'es également
    }

    if(Rhum & Coca)
    {
      RhumCoke = true;
    }

    if(Rhum & Coca & JusCitron)
    {
      RhumCokeLime = true;
    }

    if(JusOrange & JusAnanas & SiropGrenadine)
    {
      Afterglow = true;
    }
    if(Gin & JusCitron & SiropGrenadine & EauGazeuse)
    {
      AlbermaleFizz = true;
    }

    if(Whisky & Martini & JusAnanas)
    {
      Algonquin = true;
    }

    if(JusOrange & JusAnanas & Limonade)
    {
      BellaLuna = true;
    }

    if(Cointreau & JusCitron)
    {
      BlueLady = true;
    }

    if(JusCitron & JusOrange & JusAnanas & Limonade)
    {
      Cendrillon = true;
    }

    if(Cointreau & Tequila & JusCitron)
    {
      Margarita = true;
    }

    if(Vodka & JusPomme & JusCitron & SiropGrenadine)
    {
      RedApple = true;
    }

    if(JusAnanas & JusOrange & JusCitron & SiropGrenadine & GingerAle)
    {
      RedSombrero = true;
    }

    if(Rhum & Malibu & JusAnanas)
    {
      SweetPoison = true;
    }

    if(Gin & JusCitron & EauGazeuse)
    {
      SouthSide = true;
    }

    if(Rhum & JusCitron & SiropGrenadine & Cointreau)
    {
      WhiteLion = true;
    }

}
void loop() {           Partie du code que l'on va executer en boucle
  bool etatBout1 = digitalRead(bout1);
  bool etatBout2 = digitalRead(bout2);
  bool etatBout3 = digitalRead(bout3);
while((digitalRead(bout1) == true)  (digitalRead(bout2) == true)) On attends un appui pour passer d'un cocktail a l'autre
{}

  switch(NbCocktail)  En fonction de l'indice du cocktail que l'on a
  {
      delay(200);
      case 1     Si l'indice vaut 1
       monEcran.setCursor(0, 0);
        monEcran.print(NbCocktail);
        monEcran.setCursor(1, 0);
        monEcran.print()Pina Colada    );
      if(PinaColada == true)   Si le cocktail est disponible
      {
        monEcran.setCursor(0, 1);
        monEcran.print(              );
        if(etatBout3 = digitalRead(bout3) == true)  On choisi ce cocktail avec le bouton VALIDER
        {
          CPinaColada();                            On lance la fonction pour le préparer (la fonction est en dessous)
        }
        else if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
      else    Si le cocktail n'es pas dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print( indisponible );
        if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
       break;
       case 2
       monEcran.setCursor(0, 0);
        monEcran.print(NbCocktail);
        monEcran.setCursor(1, 0);
        monEcran.print()Cuba Libre    );
      if(RhumCokeLime == true)   Si le cocktail est dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print(              );
        if(etatBout3 = digitalRead(bout3) == true)  On choisi ce cocktail
        {
          CRhumCoke();                            On lance la fonction pour le préparer
        }
        else if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
      else    Si le cocktail n'es pas dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print( indisponible );
        if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
       break;
       case 3
       monEcran.setCursor(0, 0);
        monEcran.print(NbCocktail);
        monEcran.setCursor(1, 0);
        monEcran.print()Rhum & Coke   );
      if(RhumCoke == true)   Si le cocktail est dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print(              );
        if(etatBout3 = digitalRead(bout3) == true)  On choisi ce cocktail
        {
          CRhumCoke();                            On lance la fonction pour le préparer
        }
        else if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 6;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
      else    Si le cocktail n'es pas dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print( indisponible );
        if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
       break;
       case 4
       monEcran.setCursor(0, 0);
        monEcran.print(NbCocktail);
        monEcran.setCursor(1, 0);
        monEcran.print()AfterGlow      );
      if(Afterglow == true)   Si le cocktail est dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print(              );
        if(etatBout3 = digitalRead(bout3) == true)  On choisi ce cocktail
        {
          CAfterglow();                            On lance la fonction pour le préparer
        }
        else if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
      else    Si le cocktail n'es pas dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print( indisponible );
        if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
       break;
       case 5
       monEcran.setCursor(0, 0);
        monEcran.print(NbCocktail);
        monEcran.setCursor(1, 0);
        monEcran.print()Algonquin     );
      if(Algonquin == true)   Si le cocktail est dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print(              );
        if(etatBout3 = digitalRead(bout3) == true)  On choisi ce cocktail
        {
          CAlgonquin();                            On lance la fonction pour le préparer
        }
        else if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktailNbCocktailMin)
          {
            NbCocktail = NbCocktailMax;
          }
        }
      }
      else    Si le cocktail n'es pas dispo
      {
        monEcran.setCursor(0, 1);
        monEcran.print( indisponible );
        if(etatBout1 = digitalRead(bout1) == true)On passe au cocktail suivant
        {
          NbCocktail++;
          if(NbCocktail5)
          {
            NbCocktail = 1;
          }
        }
        else if(etatBout2 = digitalRead(bout2) == true)On revient au cocktail précédent
        {
          NbCocktail--;
          if(NbCocktail1)
          {
            NbCocktail = 5;
          }
        }
      }
       break;
  }
}



void CPinaColada() {    Voici la fonction qui va réaliser le cocktail Piña Colada
          switch (Rhump) {    Dans ce switch on va chercher la pompe associée au Rhum stockée dans la variable Rhump
            case 1
              digitalWrite(pompe1, HIGH); Si il s'agit de la pompe 1
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            ); On affiche l'ingrédient en train d'être servi
              delay(6000);                        On règle le temps de fonctionnement de la pompe de manière a avoir le bon dosage en mL
              digitalWrite(pompe1, LOW);          Mon temps sera certainement différent du votre puisque cela diffère en fonction des pompes
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              digitalWrite(pompe5, LOW);
              delay(6000);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(6000);
            break;
          }

          switch (Ananasp) {    On teste ensuiite l'ingredient n°2 avec la même structure
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          nas);
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Ananas          );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }

          switch (Cocop) {    et ainsi de suite jusqu'a avoir tous les ingrédients
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Lait de coco    );
              delay(4000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(4000);
            break;
          }
          monEcran.setCursor(0, 1);
          monEcran.print(C'est pret !    );
          delay(3000);
          monEcran.clear();
}

void correction_indice ()
{
  ipompe = 0;
  cpt++;
  if(cpt  10)
  {
    monEcran.clear();
    monEcran.setCursor(0, 0);
    monEcran.print(Les pompes sont );
    monEcran.setCursor(0, 1);
    monEcran.print(toutes occupees );
    delay(2000);
  }
  else
  {
    while(ipompe == PX[0]  ipompe == PX[1]  ipompe == PX[2]  ipompe == PX[3]  ipompe == PX[4]  ipompe == PX[5]  ipompe == PX[6]  ipompe == PX[7]  ipompe == PX[8]  ipompe == PX[9])
    {
      ipompe++;
      if(ipompe9)
      {
        ipompe = 0;
      }
    }
  }

}


void CRhumCoke() {      RhumCokeLime
          switch (Rhump) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              digitalWrite(pompe5, LOW);
              delay(6000);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(6000);
            break;
          }

          switch (Cocap) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }
          monEcran.setCursor(0, 1);
          monEcran.print(C'est pret !    );
          delay(3000);
          monEcran.clear();

}

void CRhumCokeLime() {      RhumCokeLime
          switch (Rhump) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              digitalWrite(pompe5, LOW);
              delay(6000);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Rhum            );
              delay(6000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(6000);
            break;
          }

          switch (Cocap) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Coca            );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }

          switch (Citronp) {    Ingredient 3
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus de citron   );
              delay(4000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(4000);
            break;
          }
          monEcran.setCursor(0, 1);
          monEcran.print(C'est pret !    );
          delay(3000);
          monEcran.clear();
}



void CAfterglow() {      Afterglow - Jus d'orangeJus d'ananasSirop de grenadine
          switch (Orangep) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              digitalWrite(pompe5, LOW);
              delay(6000);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'orange    );
              delay(6000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(6000);
            break;
          }

          switch (Ananasp) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }
          switch (SiropGrenadinep) {    Ingredient 3
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Grenadine       );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }
}

void CAlgonquin() {      Afterglow - Jus d'orangeJus d'ananasSirop de grenadine
          switch (Whiskyp) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              digitalWrite(pompe5, LOW);
              delay(6000);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Whisky          );
              delay(6000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(6000);
            break;
          }

          switch (Martinip) {    Ingredient 2
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Martini         );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }
          switch (Ananasp) {    Ingredient 3
            case 1
              digitalWrite(pompe1, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe1, LOW);
            break;
            case 2
              digitalWrite(pompe2, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe2, LOW);
            break;
            case 3
              digitalWrite(pompe3, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe3, LOW);
            break;
            case 4
              digitalWrite(pompe4, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe4, LOW);
            break;
            case 5
              digitalWrite(pompe5, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe5, LOW);
            break;
            case 6
              digitalWrite(pompe6, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe6, LOW);
            break;
            case 7
              digitalWrite(pompe7, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe7, LOW);
            break;
            case 8
              digitalWrite(pompe8, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe8, LOW);
            break;
            case 9
              digitalWrite(pompe9, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe9, LOW);
            break;
            case 0
              digitalWrite(pompe0, HIGH);
              monEcran.setCursor(0, 1);
              monEcran.print(Jus d'ananas    );
              delay(12000);
              digitalWrite(pompe0, LOW);
            break;
            default
              monEcran.setCursor(0, 1);
              monEcran.print(Probleme);
              delay(12000);
            break;
          }
}


Merci d'avoir pris le temps de lire et d'essayer de comprendre mon code !
Il est très très loin d'être parfait c'est pourquoi si vous rencontrez des soucis ou que vous avez
des suggestions pour d'éventuelles améliorations n'hésitez pas a m'en faire part via mon application
ou mon site web

Buvez de manière responsable )

