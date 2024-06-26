#include "Login.h"
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Audio.hpp>
#include "AraghNana.h"
#include "Armor.h"
#include "AsianMom.h"
#include "Assassin.h"
#include "Book.h"
#include "Bow.h"
#include "BulletproofJacket.h"
#include "Character.h"
#include "CheckNumber.h"
#include "Cloak.h"
#include "Colt.h"
#include "Consumable.h"
#include "Cyborg.h"
#include "DamagePotion.h"
#include "DefensePotion.h"
#include "EyeLaser.h"
#include "FireBall.h"
#include "Flip_flops.h"
#include "Food.h"
#include "Grenade.h"
#include "HealingPotion.h"
#include "Human.h"
#include "IronBody.h"
#include "Item.h"
#include "ItemFactory.h"
#include "Katana.h"
#include "LaserGun.h"
#include "LittleRobots.h"
#include "MagicShield.h"
#include "NinjaStar.h"
#include "Nuts.h"
#include "Paladin.h"
#include "Passive.h"
#include "Pepper.h"
#include "PersianDad.h"
#include "PoisonDagger.h"
#include "Rocket.h"
#include "Saffron.h"
#include "Shield.h"
#include "Shop.h"
#include "Snipe.h"
#include "Sniper.h"
#include "Spear.h"
#include "SpiderNet.h"
#include "StaminaPotion.h"
#include "SuperHero.h"
#include "Swatter.h"
#include "SweetTea.h"
#include "Sword.h"
#include "Throwable.h"
#include "Wand.h"
#include "WhipOfTruth.h"
#include "Wizard.h"

using namespace std;

static void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

static void saveCharacter(Human* human) {
  string username = human->getUserName();
  if (human->getRole() == characterType::PALADIN) {
    Paladin* player = dynamic_cast<Paladin*>(human);
    player->PaladinToFile(username);

  } else if (human->getRole() == characterType::ASSASSIN) {
    Assassin* player = dynamic_cast<Assassin*>(human);
    player->AssassinToFile(player);

  } else if (human->getRole() == characterType::SUPERHERO) {
    SuperHero* player = dynamic_cast<SuperHero*>(human);
    player->SuperHeroToFile(username);

  } else if (human->getRole() == characterType::SNIPER) {
    Sniper* player = dynamic_cast<Sniper*>(human);
    player->SniperToFile(username);

  } else if (human->getRole() == characterType::WIZARD) {
    Wizard* player = dynamic_cast<Wizard*>(human);
    player->WizardToFile(username);

  } else if (human->getRole() == characterType::CYBORG) {
    Cyborg* player = dynamic_cast<Cyborg*>(human);
    player->CyborgToFile(username);

  } else {
    AsianMom* player = dynamic_cast<AsianMom*>(human);
    player->AsianMomToFile(username);
  }
}

static void giveBasicItems(Human* player) {
  if (player->getRole() == characterType::PALADIN) {
    Item* armor = ItemFactory::createItem(1, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
    Item* weapon = ItemFactory::createItem(8, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);

  } else if (player->getRole() == characterType::ASSASSIN) {
    Item* armor = ItemFactory::createItem(2, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
    Item* weapon = ItemFactory::createItem(10, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);

  } else if (player->getRole() == characterType::SUPERHERO) {
    Item* armor = ItemFactory::createItem(6, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
    Item* weapon = ItemFactory::createItem(18, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);

  } else if (player->getRole() == characterType::SNIPER) {
    Item* armor = ItemFactory::createItem(5, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
     Item* weapon = ItemFactory::createItem(16, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);

  } else if (player->getRole() == characterType::WIZARD) {
    Item* armor = ItemFactory::createItem(3, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
     Item* weapon = ItemFactory::createItem(12, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);

  } else if (player->getRole() == characterType::CYBORG) {
    Item* armor = ItemFactory::createItem(4, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
     Item* weapon = ItemFactory::createItem(14, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);

  } else {
    Item* armor = ItemFactory::createItem(7, player, true);
    Item* potion = ItemFactory::createItem(29, player, true);
     Item* weapon = ItemFactory::createItem(20, player, true);
    player->addInventory(weapon);
    player->addInventory(armor);
    player->addInventory(potion);
  }
}

static Human* Login() {
  cout << "***Welcome to our game***" << endl;
menu:
  cout << "1.Sign up" << endl
       << "2.Already have an account? Login" << endl
       << "Enter your choice:" << endl;
  int choice;
  string schoice;
  try {
    cin >> schoice;
    if (check_number(schoice) == 0 || stoi(schoice) < 1 || stoi(schoice) > 2) {
      throw schoice;
    }
  } catch (...) {
    while (check_number(schoice) == 0 || stoi(schoice) < 1 ||
           stoi(schoice) > 2) {
      cout << "Invalid choice.Try again: " << endl;
      cin >> schoice;
    }
  }
  choice = stoi(schoice);
  clearScreen();
  if (choice == 1) {
  signup:
    cout << "***Sign up***" << endl;
    cout << "Enter your name: " << endl;
    string username;
    cin >> username;
    // username must be unique
    ifstream file("usernames.csv");
    string checkusername;
    string role;
    string line;
    while (getline(file, line)) {  // Read the data line
      stringstream ss(line);
      getline(ss, checkusername, ',');
      getline(ss, role, ',');
      if (username == checkusername) {
        cout << "This username is already taken. Please choose another one."
             << endl;
        goto signup;
      }
    }
    clearScreen();
    cout << "Now, let's answer some questions!" << endl << endl;
    vector<question> ques;
    question ques1, ques2, ques3, ques4, ques5, ques6, ques7, ques8, ques9,
        ques10;
    ques1.questionText = "1. What's your favorite type of movie?";
    ques1.option1 = "1. Epic Adventure";
    ques1.option2 = "2. Spy Thriller";
    ques1.option3 = "3. Superhero Blockbuster";
    ques1.option4 = "4. War Drama";
    ques1.option5 = "5. Fantasy Epic";
    ques1.option6 = "6. Sci-Fi Action";
    ques1.option7 = "7. Family Comedy";
    ques.push_back(ques1);
    ques2.questionText = "2. Where would you most like to travel?";
    ques2.option1 = "1. Medieval Castle ";
    ques2.option2 = "2. Mysterious City";
    ques2.option3 = "3. Metropolis";
    ques2.option4 = "4. War Zone";
    ques2.option5 = "5. Mystical Forest";
    ques2.option6 = "6. Futuristic City";
    ques2.option7 = "7. Home";
    ques.push_back(ques2);
    ques3.questionText =
        "3. Which of these activities would you enjoy the most?";
    ques3.option1 = "1. Sword Fighting ";
    ques3.option2 = "2. Stealth Training";
    ques3.option3 = "3. Saving the World";
    ques3.option4 = "4. Target Practice";
    ques3.option5 = "5. Spell casting ";
    ques3.option6 = "6. Tech Upgrade";
    ques3.option7 = "7. Cooking";
    ques.push_back(ques3);
    ques4.questionText = "4. Which superpower would you choose?";
    ques4.option1 = "1. Strength ";
    ques4.option2 = "2. Invisibility ";
    ques4.option3 = "3. Flight ";
    ques4.option4 = "4. Precision ";
    ques4.option5 = "5. Telekinesis ";
    ques4.option6 = "6. Technopathy  ";
    ques4.option7 = "7. Mind Reading ";
    ques.push_back(ques4);
    ques5.questionText = "5. How do you prefer to solve problems?";
    ques5.option1 = "1. Head-on ";
    ques5.option2 = "2. Quietly";
    ques5.option3 = "3. With a team";
    ques5.option4 = "4. Strategically";
    ques5.option5 = "5. With creativity";
    ques5.option6 = "6. With technology ";
    ques5.option7 = "7. With wisdom ";
    ques.push_back(ques5);
    ques6.questionText = "6. Which sport do you enjoy watching or playing";
    ques6.option1 = "1. Horse Riding ";
    ques6.option2 = "2. Martial Arts";
    ques6.option3 = "3. Wrestling ";
    ques6.option4 = "4. Target Shooting ";
    ques6.option5 = "5. Quidditch ";
    ques6.option6 = "6. Robot Combat ";
    ques6.option7 = "7. Partabe Dampayi ";
    ques.push_back(ques6);
    ques7.questionText = "7. Which animal best represents your personality?";
    ques7.option1 = "1. Lion ";
    ques7.option2 = "2. Fox ";
    ques7.option3 = "3. Eagle ";
    ques7.option4 = "4. Wolf";
    ques7.option5 = "5. Owl";
    ques7.option6 = "6. Panther";
    ques7.option7 = "7. Eshak ";
    ques.push_back(ques7);
    ques8.questionText =
        "8. Which historical era would you visit if you could time travel?";
    ques8.option1 = "1. Middle Ages";
    ques8.option2 = "2. Renaissance";
    ques8.option3 = "3. Modern Age";
    ques8.option4 = "4. World War II";
    ques8.option5 = "5. Ancient Times";
    ques8.option6 = "6. Future";
    ques8.option7 = "7. mehr 1th";
    ques.push_back(ques8);
    ques9.questionText = "9. What type of music do you enjoy listening to?";
    ques9.option1 = "1. Orchestral";
    ques9.option2 = "2. Hard Rock ";
    ques9.option3 = "3. Pop ";
    ques9.option4 = "4. Military Cadence ";
    ques9.option5 = "5. Gothic Style ";
    ques9.option6 = "6. Electronic ";
    ques9.option7 = "7. Bandari! ";
    ques.push_back(ques9);
    ques10.questionText = "10. What's your preferred mode of transportation?";
    ques10.option1 = "1. Horseback ";
    ques10.option2 = "2. Motorcycle ";
    ques10.option3 = "3. Jetpack ";
    ques10.option4 = "4. Jeep";
    ques10.option5 = "5. Flying Broomstick";
    ques10.option6 = "6. Teleportation ";
    ques10.option7 = "7. Family Van";
    ques.push_back(ques10);

    int characters[7];
    for (int i = 0; i < 7; i++) {
      characters[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
      cout << ques[i].questionText << endl;
      cout << ques[i].option1 << endl
           << ques[i].option2 << endl
           << ques[i].option3 << endl
           << ques[i].option4 << endl
           << ques[i].option5 << endl
           << ques[i].option6 << endl
           << ques[i].option7 << endl;
      cout << "Enter your choice: " << endl;
      try {
        cin >> schoice;
        if (check_number(schoice) == 0 || stoi(schoice) < 1 ||
            stoi(schoice) > 7) {
          throw schoice;
        }
      } catch (...) {
        while (check_number(schoice) == 0 || stoi(schoice) < 1 ||
               stoi(schoice) > 7) {
          cout << "Invalid choice.Try again: " << endl;
          cin >> schoice;
        }
      }
      choice = stoi(schoice);
      characters[choice - 1]++;
      clearScreen();
    }
    int* max = max_element(begin(characters), characters + 7);
    long maxindex = distance(begin(characters), max);
    vector<int> maxin;
    maxin.push_back(maxindex);
    for (int i = 0; i < 7; i++) {
      if (characters[i] == *max && i != maxindex) {
        maxin.push_back(i);
      }
    }
    int random = rand() % maxin.size();
    maxindex = maxin[random];

            // Load an audio file
        sf::SoundBuffer MagicBuffer;
        if (!MagicBuffer.loadFromFile("Magic2.wav")) {
            std::cerr << "Could not load the Magic audio file!" << std::endl;
        }

        // Create a sound object and play it
        sf::Sound MagicSound;
        MagicSound.setBuffer(MagicBuffer);
        MagicSound.play();

        // Wait until the sound is finished
        while (MagicSound.getStatus() == sf::Sound::Playing) {
        // Keep the program running until the sound has finished playing
        sf::sleep(sf::milliseconds(100));
    } 


     if(maxindex == 0){
            cout<<
R"(
We recommend you to choose <Paladin> as your character based on your personality!
 But you are free to choose any character you want!         .  ,   A           {}
                                                            . / \, | ,        .--.
                                                            .|    =|= >      /.--.\
                                                            . \ /` | `       |====|
                                                            .  `   |         |`::`|
                                                            .      |     .-;`\..../`;_.-^-._
 ***CHARACHTERS***                                          .     /\\/  /  |...::..|`   :   `|
                                                            .     |:'\ |   /'''::''|   .:.   |
1. Paladin                                                  .      \ /\;-,/\   ::  |..:::::..|
2. Assassin                                                 .      |\ <` >  >._::_.| ':::::' |
3. SuprHero                                                 .      | `""`  /   ^^  |   ':'   |
4. Sniper                                                   .      |       |       \    :    /
5. Wizard                                                   .      |       |        \   :   /
6. Cyborg                                                   .      |       |___/\___|`-.:.-`
7. Asian Mom"                                               .      |        \_ || _/    `
Enter your choice:                                          .      |        <_ >< _>
                                                            .      |        |  ||  |
                                                            .      |        |  ||  |
                                                            .      |       _\.:||:./_
                                                            .      |      /____/\____\  )" << endl;
        }else if(maxindex == 1){
            cout<<
R"(
We recommend you to choose <Assassin> as your character based on your personality!
 But you are free to choose any character you want!         .                       _
                                                            .                       \`\
                                                            .                        \ \
                                                            .                         \.\
                                                            .                          \.\
                                                            .                 _         \.\/)
                                                            .            _ _-' ')__     (\.\/)
                                                            .           /       /  \.'`'-\/)\\
 ***CHARACHTERS***                                          .           \__ ,.-'(_  Y    (_\.\)
                                                            .            / <     ,\  \    ,\\.\\
1. Paladin                                                  .            \_ \ _. /y(_|    : |\.\|
2. Assassin                                                 .                _\_\\   |    : | \.\
3. SuprHero                                                 .            (   `'-._>/ )     \|  \.\
4. Sniper                                                   .            \         `:=.    (\   \.\
5. Wizard                                                   .             \_      (    `--._)`--'\.\=7
6. Cyborg                                                   .            _/|\_    \-._     `-:_ /```-3
7. Asian Mom"                                               .           /  |  `-   \  t--._    Y    _3
                                                            .        ,-'   |       /  |   /``'-.\--T x\
Enter your choice:                                          .      _/     _(    ,./  /   (          \ x\
                                                            .         _.-/  \  /    <     \          \ x\
                                                            .      <`'  /   |\/      `-.   :          \_x\
                                                            .       \  /    |           `. |
                                                            .        \_|    /             `
                                                            .          |   /                `.
                                                            .         /  _/\                /     )" << endl;
        }else if(maxindex == 2){
           cout <<
R"(
                                                            .                    ,,,,
We recommend you to choose <SuperHero> as your character    .              ,;) .';;;;',
based on your personality!                                  .  ;;,,_,-.-.,;;'_,(|);;;/),,_
But you are free to choose any character you want!          .   `';;/:|:);{ ;;;|| );/ /;;;[__
                                                            .      L;/-';/ {;;[',/;[/;;;.') ]
                                                            .       .:`''` - {;;'.__/;;;/  . _'-._
***CHARACHTERS***                                           .     .'/   (     {;NULL;/.'_7:.  '). ]_
                                                            .   .''/     ( '._ );}{;//.'    '-:  '.,L
1. Paladin                                                  . .'. /       (  ( |;;;/_/         (._./;]   _,
2. Assassin                                                 .  . /        |( ( /;;/_/             ';;;],;;_,
3. SuprHero                                                 . . /         )__(/;;/_/                (;;'''''
4. Sniper                                                   .  /        _;:':;;;;:';-._             );
5. Wizard                                                   . /        /   (  `'`   --.'-._          V
6. Cyborg                                                   .        .'     '.  ,'         '-,
7. Asian Mom"                                               .       /    /   r--,..__       '.]
                                                            .     .'    '  .'        '--._     ]
                                                            .     (     :.(;>        _ .' '- ;/
                                                            .     |      /:;(    ,_.';(   __.'
Enter your choice:                                          .      '- -''|;:/    (;;;;-'--'
                                                            .            |;/      ;;(
                                                            .            ''      /;;|
                                                            .                    (;;|
                                                            .                      V                        )" << endl ;
        }else if(maxindex == 3){
            cout<<
R"(
We recommend you to choose <Sniper> as your character       .      |\
based on your personality!                                  .      || .---.
                                                            .      ||/_____\
                                                            .      ||(== ==)
But you are free to choose any character you want!          .      || \_-_/_
                                                            .      :-"`'V'//-.
***CHARACHTERS***                                           .     / ,   |// , `\
                                                            .    / /NULL//Ll|| |
1. Paladin                                                  .   /_/||__//   || |
2. Assassin                                                 .   \ \/---|[]==|| |
3. SuprHero                                                 .    \/\__/ |   \| |
4. Sniper                                                   .    /\|_   | Ll_\ |
5. Wizard                                                   .    `--|`^"""^`||_|
6. Cyborg                                                   .       |   |   ||/
7. Asian Mom"                                               .       |   |   |
                                                            .       |   |   |
Enter your choice:                                          .       |   |   |
                                                            .       L___l___J
                                                            .        |_ | _|
                                                            .       (___|___)
                                                            .        ^^^ ^^^           )"<<endl;
        }else if(maxindex == 4){
            cout <<
R"(
We recommend you to choose <Wizard> as your character   .                    ____
based on your personality!                              .                  .'* *.'
But you are free to choose any character you want!      .               __/_*_*(_
                                                        .              / _______ \
                                                        .            _\_)/&__&\(_/_
                                                        .            / _((\- -/))_ \
                                                        .            \ \())(-)(()/ /
***CHARACHTERS***                                       .             ' \(((()))/ '
                                                        .            / ' \)).))/  ' \
1. Paladin                                              .           / _ \ - | -  /_  \
2. Assassin                                             .          (   ( .;''';.  .'  )
3. SuprHero                                             .          _\"__ /      \ __"/_
4. Sniper                                               .            \/  \ NULL /  \/
5. Wizard                                               .             .'  '... ' ' )
6. Cyborg                                               .              / /  |  \ \
7. Asian Mom"                                           .             / .   .   . \
                                                        .            /   .     .   \
                                                        .           /   /   |   \   \
                                                        .         .'   /    b    '.  '.
Enter your choice:                                      .     _.-'    /     Bb     '-. '-._
                                                        . _.-'       |      BBb       '-.  '-.
                                                        .(________mrf\____.dBBBb.________)____)   )" << endl ;
        }else if(maxindex == 5){
            cout<<
R"(
                                                        .              _____
We recommend you to choose <Cyborg> as your character   .             X_____\
based on your personality!                              .     .-^-.  ||_| |_||  .-^-.
But you are free to choose any character you want!      .    /_\_/_\_|  |_|  |_/_\_/_\
                                                        .    ||(_)| __\_____/__ |(_)||
                                                        .    \/| | |::|\```/|::| | |\/
***CHARACHTERS***                                       .    /`--- |::|'NULL'|:: |_---'\
                                                        .   / /  \ |::|-|-|-|::| /  \ \
1. Paladin                                              .  /_/   /|`--'-+-+-`--'|\   \_\
2. Assassin                                             .  | \  / |===/_\ /_\===| \  / |
3. SuprHero                                             .  |  \/  /---/-/-\-\  o\  \/  |
4. Sniper                                               .  | ||| | O / /   \ \   | ||| |
5. Wizard                                               .  | ||| ||----\ | /----|o|||| |
6. Cyborg                                               .  \/|\/  |     |||     |o|\/|\/
7. Asian Mom"                                           .  \_o/   |----|||||----|-' \o_/
                                                        .         |##  |   |  ##|
                                                        .         ||__ |   | __||
                                                        .        [|'  `|] [|'  `|]
                                                        .        [|`--'|] [|`--'|]
                                                        .        /|__| |\ /| |__|\
Enter your choice:                                      .        ||__|_|| ||_|__||
                                                        .        \|----|/ \|----|/
                                                        .        /______\ /______\
                                                        .        |__||__| |__||__|          )" << endl ;
        }else{
            cout<<""<<endl;
            cout << R"(
We recommend you to choose <Asian Mom> as your character.        w*W*W*W*w
based on your personality!                              .         \"."."/
                                                        .          //`\\
                                                        .         (/a a\)
But you are free to choose any character you want!      .         (\_-_/)
                                                        .        .-~'='~-.
 ***CHARACHTERS***                                      .       /`~`"Y"`~`\
                                                        .      / /(_ * _)\ \
1. Paladin                                              .     / /  )   (  \ \
2. Assassin                                             .     \ \_/\\_//\_/ /
3. SuprHero                                             .      \/_) '*' (_\/
4. Sniper                                               .        |       |
5. Wizard                                               .        |       |
6. Cyborg                                               .        |       |
7. Asian Mom"                                           .        |       |
                                                        .        |       |
Enter your choice:                                      .        |       |
                                                        .        |       |
                                                        .        |       |
                                                        .        w*W*W*W*w     )" << endl ;
        }
    try {
      cin >> schoice;
      if (check_number(schoice) == 0 || stoi(schoice) < 1 ||
          stoi(schoice) > 7) {
        throw schoice;
      }
    } catch (...) {
      while (check_number(schoice) == 0 || stoi(schoice) < 1 ||
             stoi(schoice) > 7) {
        cout << "Invalid choice.Try again: " << endl;
        cin >> schoice;
      }
    }
    choice = stoi(schoice);
    clearScreen();
    cout << "Enter the name of your character: " << endl;
    string name;
    cin >> name;
    clearScreen();
    cout << "Enter the age of your character: " << endl;
    string sage;
    int age;
    try {
      cin >> sage;
      if (check_number(sage) == 0 || stoi(sage) < 1) {
        throw sage;
      }
    } catch (...) {
      while (check_number(sage) == 0 || stoi(sage) < 1) {
        cout << "Invalid input.Try again: " << endl;
        cin >> sage;
      }
    }
    age = stoi(sage);
    clearScreen();
    if (choice == 1) {
      Paladin* player =
          new Paladin(name, age, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
      player->setUserName(username);
      giveBasicItems(player);
      //  player->addInventory(weapon);
      
      player->PaladinToFile(username);
      return player;
    } else if (choice == 2) {
      Assassin* player = new Assassin(name, age, 100.0, 3.0, 5.0,
                                      characterType::ASSASSIN, 1000);
      player->setUserName(username);
      giveBasicItems(player);
      //  player->addInventory(weapon);
      
      player->AssassinToFile(player);
      return player;
    } else if (choice == 3) {
      SuperHero* player = new SuperHero(name, age, 100.0, 3.0, 5.0,
                                        characterType::SUPERHERO, 1000);
      player->setUserName(username);
       giveBasicItems(player);
      player->SuperHeroToFile(username);
      return player;
    } else if (choice == 4) {
      Sniper* player =
          new Sniper(name, age, 100.0, 3.0, 5.0, characterType::SNIPER, 1000);
      player->setUserName(username);
      giveBasicItems(player);
      player->SniperToFile(username);
      return player;
    } else if (choice == 5) {
      Wizard* player =
          new Wizard(name, age, 100.0, 3.0, 5.0, characterType::WIZARD, 1000);
      player->setUserName(username);
      giveBasicItems(player);
      player->WizardToFile(username);
      return player;
    } else if (choice == 6) {
      Cyborg* player =
          new Cyborg(name, age, 100.0, 3.0, 5.0, characterType::CYBORG, 1000);
      player->setUserName(username);
       giveBasicItems(player);
      player->CyborgToFile(username);
      return player;
    } else {
      AsianMom* player = new AsianMom(name, age, 100.0, 3.0, 5.0,
                                      characterType::ASIANMOM, 1000);
      player->setUserName(username);
       giveBasicItems(player);
      player->AsianMomToFile(username);
      return player;
    }

  } else {
    cout << "Enter your name:" << endl;
    string username;
    cin >> username;
    string usernameWithExtension = username + ".csv";
    ifstream file("usernames.csv");
    int check = 0;
    string checkusername;
    string role;
    string line;
    clearScreen();
    while (getline(file, line)) {  // Read the data line
      stringstream ss(line);
      getline(ss, checkusername, ',');
      getline(ss, role, ',');
      if (username == checkusername) {
        check++;
        if (role == "Paladin") {
          Paladin* player = new Paladin("name", 1, 100.0, 3.0, 5.0,
                                        characterType::PALADIN, 1000);
          player->FileToPaladin(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        } else if (role == "Assassin") {
          Assassin* player = new Assassin("name", 1, 100.0, 3.0, 5.0,
                                          characterType::ASSASSIN, 1000);
          player->FileToAssassin(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        } else if (role == "SuperHero") {
          SuperHero* player = new SuperHero("name", 1, 100.0, 3.0, 5.0,
                                            characterType::SUPERHERO, 1000);
          player->FileToSuperHero(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        } else if (role == "Sniper") {
          Sniper* player = new Sniper("name", 1, 100.0, 3.0, 5.0,
                                      characterType::SNIPER, 1000);
          player->FileToSniper(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        } else if (role == "Wizard") {
          Wizard* player = new Wizard("name", 1, 100.0, 3.0, 5.0,
                                      characterType::WIZARD, 1000);
          player->FileToWizard(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        } else if (role == "Cyborg") {
          Cyborg* player = new Cyborg("name", 1, 100.0, 3.0, 5.0,
                                      characterType::CYBORG, 1000);
          player->FileToCyborg(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        } else {
          AsianMom* player = new AsianMom("name", 1, 100.0, 3.0, 5.0,
                                          characterType::ASIANMOM, 1000);
          player->FileToAsianMom(username);
          if (player->getName() == "Error404" && player->getAge() == 0) {
            cout << "Sorry it seems like you don't have an account" << endl;
            goto menu;
          }
          return player;
        }
        break;
      }
    }
    if (check == 0) {
      cout << "Sorry it seems like you don't have an account" << endl;
      goto menu;
    }
    return new Wizard("name", 1, 100.0, 3.0, 5.0, characterType::WIZARD, 1000);
  }
}

static vector<Human*> LoginMultiplayer() {
  vector<Human*> players;
  int choice;
  string schoice;
  cout << "***Welcome to our game***" << endl;
  cout << "***CHARACHTERS***" << endl;
  cout << "1. Paladin" << endl
       << "2. Assassin" << endl
       << "3. SuprHero" << endl
       << "4. Sniper" << endl
       << "5. Wizard" << endl
       << "6. Cyborg" << endl
       << "7. Asian Mom" << endl;
  cout << "Enter first character type: " << endl;
  try {
    cin >> schoice;
    if (check_number(schoice) == 0 || stoi(schoice) < 1 || stoi(schoice) > 7) {
      throw schoice;
    }
  } catch (...) {
    while (check_number(schoice) == 0 || stoi(schoice) < 1 ||
           stoi(schoice) > 7) {
      cout << "Invalid choice.Try again: " << endl;
      cin >> schoice;
    }
  }
  choice = stoi(schoice);
  cout << "Enter the name of first character: " << endl;
  string name;
  cin >> name;
  cout << "Enter the age of first character: " << endl;
  string sage;
  int age;
  try {
    cin >> sage;
    if (check_number(sage) == 0 || stoi(sage) < 1) {
      throw sage;
    }
  } catch (...) {
    while (check_number(sage) == 0 || stoi(sage) < 1) {
      cout << "Invalid input.Try again: " << endl;
      cin >> sage;
    }
  }
  age = stoi(sage);
  if (choice == 1) {
    Paladin* player =
        new Paladin(name, age, 100.0, 3.0, 5.0, characterType::PALADIN, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 2) {
    Assassin* player =
        new Assassin(name, age, 100.0, 3.0, 5.0, characterType::ASSASSIN, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 3) {
    SuperHero* player = new SuperHero(name, age, 100.0, 3.0, 5.0,
                                      characterType::SUPERHERO, 5000);
    giveBasicItems(player);
      for (int i = 1; i < 3; i++) {
        player->setCurrXP(player->getMaxXP() + 1);
        player->levelUp();
        clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 4) {
    Sniper* player =
        new Sniper(name, age, 100.0, 3.0, 5.0, characterType::SNIPER, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 5) {
    Wizard* player =
        new Wizard(name, age, 100.0, 3.0, 5.0, characterType::WIZARD, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 6) {
    Cyborg* player =
        new Cyborg(name, age, 100.0, 3.0, 5.0, characterType::CYBORG, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else {
    AsianMom* player =
        new AsianMom(name, age, 100.0, 3.0, 5.0, characterType::ASIANMOM, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  }

  clearScreen();

  cout << "Enter second character type: " << endl;
  cout << "***CHARACHTERS***" << endl;
  cout << "1. Paladin" << endl
       << "2. Assassin" << endl
       << "3. SuprHero" << endl
       << "4. Sniper" << endl
       << "5. Wizard" << endl
       << "6. Cyborg" << endl
       << "7. Asian Mom" << endl;
  cout << "Enter second character type: " << endl;
  try {
    cin >> schoice;
    if (check_number(schoice) == 0 || stoi(schoice) < 1 || stoi(schoice) > 7) {
      throw schoice;
    }
  } catch (...) {
    while (check_number(schoice) == 0 || stoi(schoice) < 1 ||
           stoi(schoice) > 7) {
      cout << "Invalid choice.Try again: " << endl;
      cin >> schoice;
    }
  }
  choice = stoi(schoice);
  cout << "Enter the name of second character: " << endl;
  cin >> name;
  cout << "Enter the age of second character: " << endl;
  try {
    cin >> sage;
    if (check_number(sage) == 0 || stoi(sage) < 1) {
      throw sage;
    }
  } catch (...) {
    while (check_number(sage) == 0 || stoi(sage) < 1) {
      cout << "Invalid input.Try again: " << endl;
      cin >> sage;
    }
  }
  age = stoi(sage);
  if (choice == 1) {
    Paladin* player =
        new Paladin(name, age, 100.0, 3.0, 5.0, characterType::PALADIN, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 2) {
    Assassin* player =
        new Assassin(name, age, 100.0, 3.0, 5.0, characterType::ASSASSIN, 5000);
     giveBasicItems(player);
    for (int i = 0; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 3) {
    SuperHero* player = new SuperHero(name, age, 100.0, 3.0, 5.0,
                                      characterType::SUPERHERO, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 4) {
    Sniper* player =
        new Sniper(name, age, 100.0, 3.0, 5.0, characterType::SNIPER, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 5) {
    Wizard* player =
        new Wizard(name, age, 100.0, 3.0, 5.0, characterType::WIZARD, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else if (choice == 6) {
    Cyborg* player =
        new Cyborg(name, age, 100.0, 3.0, 5.0, characterType::CYBORG, 5000);
    giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  } else {
    AsianMom* player =
        new AsianMom(name, age, 100.0, 3.0, 5.0, characterType::ASIANMOM, 5000);
     giveBasicItems(player);
    for (int i = 1; i < 3; i++) {
      player->setCurrXP(player->getMaxXP() + 1);
      player->levelUp();
      clearScreen();
    }
    player->setCurrentHP(player->getMaxHP());
    player->setLevel(6);
    players.push_back(player);
  }
  return players;
}
