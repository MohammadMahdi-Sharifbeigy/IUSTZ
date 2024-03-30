//
//  RecommendCharacter.cpp
//  
//
//  Created by Lilia Rouhi on 1/10/1403 AP.
//


#include "Login.h"
#include "CheckNumber.h"
#include <iostream>
#include <vector>
#include <string.h>
#include "Character.h"
#include "Human.h"
#include "Item.h"
#include "Passive.h"
#include "AraghNana.h"
#include "Armor.h"
#include "Book.h"
#include "Bow.h"
#include "BulletproofJacket.h"
#include "Cloak.h"
#include "Colt.h"
#include "Consumable.h"
#include "DamagePotion.h"
#include "DefensePotion.h"
#include "EyeLaser.h"
#include "FireBall.h"
#include "Flip_flops.h"
#include "Food.h"
#include "Grenade.h"
#include "HealingPotion.h"
#include "IronBody.h"
#include "Katana.h"
#include "LaserGun.h"
#include "LittleRobots.h"
#include "MagicShield.h"
#include "NinjaStar.h"
#include "Nuts.h"
#include "Pepper.h"
#include "PersianDad.h"
#include "PoisonDagger.h"
#include "Rocket.h"
#include "Saffron.h"
#include "Shield.h"
#include "Snipe.h"
#include "Spear.h"
#include "SpiderNet.h"
#include "StaminaPotion.h"
#include "Swatter.h"
#include "SweetTea.h"
#include "Sword.h"
#include "Throwable.h"
#include "Wand.h"
#include "WhipOfTruth.h"
#include "CheckNumber.h"
#include "Shop.h"
#include "ItemFactory.h"
#include "Paladin.h"
#include "Assassin.h"
#include "SuperHero.h"
#include "Sniper.h"
#include "Wizard.h"
#include "Cyborg.h"
#include "AsianMom.h"




using namespace std;




Human* Login(){
    cout<<"***Welcom to our game***"<<endl;
    cout<<"1.Sign in"<<endl<<"2.Already have an account?"<<endl<<"Enter your choice:"<<endl;
    int choice;
    string schoice;
    try{
    cin>>schoice;
    if(check_number(schoice)==0 || stoi(schoice)<1 ||stoi(schoice)>2){
        throw schoice;
        }
    }catch(...){
        while( check_number(schoice)==0 || stoi(schoice)<1 ||stoi(schoice)>2){
            cout<<"Invalid choice.Try again: "<<endl;
            cin>>schoice;
        }
    }
    choice = stoi(schoice);
    if(choice == 1){
        cout<<"Enter your nam: "<<endl;
        string username;
        cin>>username;
        cout<<"Now , let's answer some questions !"<<endl<<endl;
        vector<question> ques;
        question ques1 , ques2, ques3 , ques4 , ques5 , ques6 , ques7 , ques8 , ques9 , ques10;
        ques1.questionText = "1. What's your favorite type of movie?";
        ques1.option1="1. Epic Adventure";
        ques1.option2="2. Spy Thriller";
        ques1.option3="3. Superhero Blockbuster";
        ques1.option4="4. War Drama";
        ques1.option5="5. Fantasy Epic";
        ques1.option6="6. Sci-Fi Action";
        ques1.option7="7. Family Comedy";
        ques.push_back(ques1);
        ques2.questionText = "2. Where would you most like to travel?";
        ques2.option1="1. Medieval Castle ";
        ques2.option2="2. Mysterious City";
        ques2.option3="3. Metropolis";
        ques2.option4="4. War Zone";
        ques2.option5="5. Mystical Forest";
        ques2.option6="6. Futuristic City";
        ques2.option7="7. Home";
        ques.push_back(ques2);
        ques3.questionText = "3. Which of these activities would you enjoy the most?";
        ques3.option1="1. Sword Fighting ";
        ques3.option2="2. Stealth Training";
        ques3.option3="3. Saving the World";
        ques3.option4="4. Target Practice";
        ques3.option5="5. Spell casting ";
        ques3.option6="6. Tech Upgrade";
        ques3.option7="7. Cooking";
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
        ques8.questionText = "8. Which historical era would you visit if you could time travel?";
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
        for(int i=0; i<10; i++){
            cout<<ques[i].questionText << endl;
            cout<<ques[i].option1 << endl << ques[i].option2 << endl<<ques[i].option3 << endl << ques[i].option4 << endl<<ques[i].option5 << endl << ques[i].option6 << endl << ques[i].option7<<endl;
            cout<<"Enter your choice: "<<endl;
            try{
                cin>>schoice;
                if(check_number(schoice)==0 || stoi(schoice)<1 ||stoi(schoice)>7){
                    throw schoice;
                }
            }catch(...){
                while( check_number(schoice)==0 || stoi(schoice)<1 ||stoi(schoice)>7){
                    cout<<"Invalid choice.Try again: "<<endl;
                    cin>>schoice;
                }
            }
            choice = stoi(schoice);
            characters[choice-1]++;
            
        }
        int *max = max_element(characters,characters+10);
        int maxindex = distance(characters, max);
        vector <int> maxin;
        maxin.push_back(maxindex);
        for(int i=0; i<7; i++){
            if(characters[i]==*max && i!= maxindex){
                maxin.push_back(i);
            }
        }
        maxindex = rand() % maxin.size();
        
        if(maxindex == 0){
            cout<<"We recommend you to choose <Paladin> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }else if(maxindex == 1){
            cout<<"We recommend you to choose <Assassin> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }else if(maxindex == 2){
            cout<<"We recommend you to choose <SuperHero> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }else if(maxindex == 3){
            cout<<"We recommend you to choose <Sniper> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }else if(maxindex == 4){
            cout<<"We recommend you to choose <Wizard> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }else if(maxindex == 5){
            cout<<"We recommend you to choose <Cyborg> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }else{
            cout<<"We recommend you to choose <Asian Mom> as your character based on your personality!"<<endl;
            cout<<"But you are free to choose any character you want!"<<endl;
        }
        
        cout<< "***CHARACHTERS***"<<endl;
        cout<< "1. Paladin" <<endl << "2. Assassin" << endl << "3. SuprHero"<< endl << "4. Sniper" << endl << "5. Wizard" << "6. Cyborg" << endl << "7. Asian Mom" << endl;
        cout<<"Enter your choice: "<<endl;
        try{
            cin>>schoice;
            if(check_number(schoice)==0 || stoi(schoice)<1 ||stoi(schoice)>7){
                throw schoice;
            }
        }catch(...){
            while( check_number(schoice)==0 || stoi(schoice)<1 ||stoi(schoice)>7){
                cout<<"Invalid choice.Try again: "<<endl;
                cin>>schoice;
            }
        }
        choice = stoi(schoice);
        cout<<"Enter the name of your character: "<<endl;
        string name;
        cin>>name;
        cout<<"Enter the age of your character: "<<endl;
        string sage;
        int age;
        try{
            cin>>sage;
            if(check_number(sage)==0 || stoi(sage)<1 ){
                throw sage;
            }
        }catch(...){
            while( check_number(sage)==0 || stoi(sage)<1 ){
                cout<<"Invalid input.Try again: "<<endl;
                cin>>sage;
            }
        }
        age = stoi(sage);
        if (choice == 1){
            Human* player =  new Paladin(name, age, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
            static_cast<Paladin*>(player)->PaladinToFile(username);
            return player;
        }else if (choice == 2){
            Human* player =  new Assassin(name, age, 100.0, 3.0, 5.0, characterType::ASSASSIN , 1000);
            static_cast<Assassin*>(player)->AssasinToFile(username);
            return player;
        }else if (choice == 3){
            Human* player =  new SuperHero(name, age, 100.0, 3.0, 5.0, characterType::SUPERHERO, 1000);
            static_cast<SuperHero*>(player)->SuperHeroToFile(username);
            return player;
        }else if (choice == 4){
            Human* player =  new Sniper(name, age, 100.0, 3.0, 5.0, characterType::SNIPER, 1000);
            static_cast<Sniper*>(player)->SniperToFile(username);
            return player;
        }else if (choice == 5){
            Human* player =  new Wizard(name, age, 100.0, 3.0, 5.0, characterType::WIZARD, 1000);
            static_cast<Wizard*>(player)->WizardToFile(username);
            return player;
        }else if (choice == 6){
            Human* player =  new Cyborg(name, age, 100.0, 3.0, 5.0, characterType::CYBORG, 1000);
            static_cast<Cyborg*>(player)->CyborgToFile(username);
            return player;
        }else{
            Human* player =  new AsianMom(name, age, 100.0, 3.0, 5.0, characterType::ASIANMOM, 1000);
            static_cast<AsianMom*>(player)->AsianMomToFile(username);
            return player;
        }
        
        
    }else{
        cout<<"Enter your name:"<<endl;
        string username;
        cin>>username;
        username=username+".csv";
        ifstream file("usernames");
        int check=0;
        string checkusername;
        string role;
        while (getline(file , checkusername)){
            getline(file,role);
            if(username == checkusername){
                check++;
                if(role=="Paladin"){
                    Human* player = new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
                    static_cast<Paladin*>(player)->FileToPaladin(username);
                    return player;
                }else if (role == "Assasin"){
                    Human* player =  new Assassin("name", 1, 100.0, 3.0, 5.0, characterType::ASSASSIN, 1000);
                    static_cast<Assassin*>(player)->FileToAssasin(username);
                    return player;
                }else if (role == "SuperHero"){
                    Human* player =  new SuperHero("name", 1, 100.0, 3.0, 5.0, characterType::SUPERHERO, 1000);
                    static_cast<SuperHero*>(player)->FileToSuperHero(username);
                    return player;
                }else if (role == "Sniper"){
                    Human* player =  new Sniper("name", 1, 100.0, 3.0, 5.0, characterType::SNIPER, 1000);
                    static_cast<Sniper*>(player)->FileToSniper(username);
                    return player;
                }else if (role == "Wizard"){
                    Human* player =  new Wizard("name", 1, 100.0, 3.0, 5.0, characterType::WIZARD, 1000);
                    static_cast<Wizard*>(player)->FileToWizard(username);
                    return player;
                }else if (role == "Cyborg"){
                    Human* player =  new Cyborg("name", 1, 100.0, 3.0, 5.0, characterType::CYBORG, 1000);
                    static_cast<Cyborg*>(player)->FileToCyborg(username);
                    return player;
                }else{
                    Human* player =  new AsianMom("name", 1, 100.0, 3.0, 5.0, characterType::ASIANMOM, 1000);
                    static_cast<AsianMom*>(player)->FileToAsianMom(username);
                    return player;
                    
                }
            }
        }
        
    }
               
}


