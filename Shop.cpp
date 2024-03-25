//
//  Shop.cpp
//  
//
//  Created by Lilia Rouhi on 1/5/1403 AP.
//

#include "Shop.hpp"
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
#include "Counsumable.h"
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
#include "AsianDad.h"
#include "PoisonDagger.h"
#include "Rocket.h"
#include "Saffron.h"
#include "Shield.h"
#include "Snipe.h"
#include "Spear.h"
#include "SpideNet.h"
#include "StaminPotion.h"
#include "Swatter.h"
#include "SweetTea.h"
#include "Sword.h"
#include "Throwable.h"
#include "Wand.h"
#include "WhipOfTruth.h"
#include "CheckNumber.h"
#include "Shop.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;



    Shop::Shop() = default;


    void Shop::showShop(){
        cout<<"********SHOP ITEMS********"<<endl<<endl<<endl;
        cout<<"ARMORS:"<<endl<<endl;
        cout<<"1.Armor"<<endl<<"Price:"<<endl<<"Best Match : Paladin"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"2.Shield"<<endl<<"Price:"<<endl<<"Best Match : Assasin"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"3.Magic Shield"<<endl<<"Price:"<<endl<<"Best Match : Wizard"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"4.Iron Body"<<endl<<"Price:"<<endl<<"Best Match : Cyborg"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"5.Bulletproof Jaket"<<endl<<"Price:"<<endl<<"Best Match : Sniper"<<endl<< "Is VIP : Yes"<<endl<<endl;
        cout<<"6.Cloak"<<endl<<"Price:"<<endl<<"Best Match : SuperHero"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"7.Asian Dad"<<endl<<"Price:"<<endl<<"Best Match : Asian Mom"<<endl<< "Is VIP : Yes"<<endl<<endl<<endl;
        cout<<"WEAPONS:"<<endl<<endl;
        cout<<"8.Sward"<<endl<<"Price:"<<endl<<"Best Match : Paladin"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"9.Spear"<<endl<<"Price:"<<endl<<"Best Match : Paladin"<<endl<< "Is VIP : Yes"<<endl<<endl;
        cout<<"10.Katana"<<endl<<"Price:"<<endl<<"Best Match : Assasin"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"11.Poison Dagger"<<endl<<"Price:"<<endl<<"Best Match : Assasin"<<endl<< "Is VIP : Yes"<<endl<<endl;
        cout<<"12.Wand "<<endl<<"Price:"<<endl<<"Best Match : Wizard"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"13.Book"<<endl<<"Price:"<<endl<<"Best Match : Wizard"<<endl<< "Is VIP : Yes"<<endl<<endl;
        cout<<"14.Laser Gun"<<endl<<"Price:"<<endl<<"Best Match : Cyborg"<<endl<< "Is VIP : No"<<endl<<endl<<endl;
        cout<<"15.Little Robots"<<endl<<"Price:"<<endl<<"Best Match : Cyborg"<<endl<< "Is VIP : Yes"<<endl<<endl;
        cout<<"16.Snipe"<<endl<<"Price:"<<endl<<"Best Match : Sniper"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"17.Colt"<<endl<<"Price:"<<endl<<"Best Match : Sniper"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"18.Eyelaser"<<endl<<"Price:"<<endl<<"Best Match : SuperHero"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"19.Whip of Truth "<<endl<<"Price:"<<endl<<"Best Match : SuperHero"<<endl<< "Is VIP : Yes"<<endl<<endl;
        cout<<"20.Swatter"<<endl<<"Price:"<<endl<<"Best Match : Asian Mom"<<endl<< "Is VIP : No"<<endl<<endl;
        cout<<"21.Pepper"<<endl<<"Price:"<<endl<<"Best Match : Asian Mom"<<endl<< "Is VIP : Yes"<<endl<<endl<<endl;
        cout<<"THROWABLE ITEMS:"<<endl<<endl;
        cout<<"22.Bow"<<endl<<"Price:"<<endl<<"Best Match : Paladin"<<endl<<endl;
        cout<<"23.Ninja Star"<<endl<<"Price:"<<endl<<"Best Match : Assasin"<<endl<<endl;
        cout<<"24.Fireball"<<endl<<"Price:"<<endl<<"Best Match : Wizard"<endl<<endl;
        cout<<"25.Rocket"<<endl<<"Price:"<<endl<<"Best Match : Cyborg"<<endl<<endl;
        cout<<"26.Grenade"<<endl<<"Price:"<<endl<<"Best Match : Sniper"<<endl<<endl;
        cout<<"27.Spider Net"<<endl<<"Price:"<<endl<<"Best Match : SuperHero"<<endl<<endl;
        cout<<"28.FlipFlop"<<endl<<"Price:"<<endl<<"Best Match : Asian Mom"<<endl<<endl<<endl;
        cout<<"COUNSUMEABLE ITEMS:"<<endl<<endl;
        cout<<"29.Healing Potion"<<endl<<"Price:"<<endl<<"Reinforcing effect on : HP"<<endl<<endl;
        cout<<"30.Damage Potion"<<endl<<"Price:"<<endl<<"Reinforcing effect on : Attack"<<endl<<endl;
        cout<<"31.Defense Poition"<<endl<<"Price:"<<endl<<"Reinforcing effect on : Defense"<endl<<endl;
        cout<<"32.Stamin Potion"<<endl<<"Price:"<<endl<<"Reinforcing effect on : Stamin"<<endl<<endl;
        cout<<"33.Food"<<endl<<"Price:"<<endl<<"Reinforcing effect on : HP and Stamin"<<endl<<endl;
        cout<<"34.Sweet Tea"<<endl<<"Price:"<<endl<<"Reinforcing effect on : HP"<<endl<<"Best Match : Asian Mom"<<endl<<endl;
        cout<<"35.Saffron"<<endl<<"Price:"<<endl<<"Reinforcing effect on : Attack"<<endl<<"Best Match : Asian Mom"<endl<<endl;
        cout<<"36.Aragh Nana"<<endl<<"Price:"<<endl<<"Reinforcing effect on : Defense"<<endl<<"Best Match : Asian Mom"<<endl<<endl;
        cout<<"37.Nuts"<<endl<<"Price:"<<endl<<"Reinforcing effect on :  Stamin"<<endl<<"Best Match : Asian Mom"<<endl<<endl;
    }


    
    void Shop::buy (Human* human){
        int choice = 1;
        Shop shop = Shop();
        while (choice!=0){
        menu:
            shop.showShop();
            cout<<"Enter the number of the Item you wanna buy or enter 0 to exit:"<<endl;
            string schoice;
            try{
            cin>>schoice;
            if(check_number(schoice)==0 || stoi(schoice)<0 ||stoi(schoice)>37){
                throw schoice;
                }
            }catch(...){
                while( check_number(schoice)==0 || stoi(schoice)<0 ||stoi(schoice)>37){
                    cout<<"Invalid choice."<<endl<<"Enter the number of the Item you wanna buy or enter 0 to exit:"<<end;
                    cin>>schoice;
                }
            }
            choice = stoi(schoice);
            if(choice == 1){
                Armor* item = new Armor();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if (choice == 2){
                Shield* item = new Shield();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 3){
                MagicShield* item = new MagicShield();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }

            }else if(choice == 4){
                IronBody* item = new IronBody();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 5){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                BulletproofJacket* item = new BulletproofJacket();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if (choice == 6){
                Cloack* item = new Cloack();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choise == 7){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                AsianDad* item = new AsianDad();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 8){
                Sward* item = new Sward();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 9){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                Spear* item = new Spear();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 10){
                Katana* item = new Katana();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 11){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                PoisonDagger* item = new PoisonDagger();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 12){
                Wand* item = new Wand();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 13){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                Book* item = new Book();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 14){
                LaserGun* item = new LaserGun();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 15){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                LittleRobots* item = new LittleRobots();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 16){
                Snipe* item = new Snipe();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 17){
                Colt* item = new Colt();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 18){
                Eyelaser* item = new Eyelaser();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if (choice == 19){
                if(human->getLevel() < 5){
                    cout<<"Sorry you should be at least at level 5 to buy this item"<<endl;
                    goto menu;
                }
                WhipOfTruth* item = new WhipOfTruth();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
            }else if(choice == 20){
                Swatter* item = new Swatter();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 21){
                Pepper* item = new Pepper();
                if(human->getCoin() < item->getPrice()){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
                bool exist = human->existInInventory(item);
                if(exist == true){
                    cout<<"You already have the item!"<<endl;
                    goto menu;
                }else{
                    human->setCoin(human->getCoin()-item->grtPrice());
                    human->addInventory(item);
                }
                
            }else if(choice == 22){
                Bow* item = new Bow();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if (choice == 23){
                NinjaStar* item = new NinjaStar();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }esle if(choice == 24){
                FireBall* item = new FireBall();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 25){
                Rocket* item = new Rocket();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 26){
                Grenade* item = new Grenade();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 27){
                SpiderNet* item = new SpiderNet();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 28){
                Flip_flops* item = new Flip_flops();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 29){
                HealingPotion* item = new HealingPotion();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if (choice == 30){
                DamagePotion* item = new DamagePotion();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if (choice == 31){
                DefensePotion* item = new DefensePotion();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if (choice == 32){
                StaminPotion* item = new StaminPotion();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
                
            }else if(choice == 33){
                Food* item = new Food();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 34){
                SweetTea* item = new SweetTea();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if (choice == 35){
                Saffron* item = new Saffron();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 36){
                AraghNana* item = new AraghNana();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if (choise == 37){
                Bow* item = new Bow();
                int count = 0;
                string scount;
                int nowcount = human->countInInventory(item);
                if(nowcount == 5){
                    cout<<"Sorry you already have 5 of this item you can't buy more!"<<endl;
                    goto menu;
                }
                cout << "How many do you want?"
                try{
                cin>>scount;
                if(check_number(scount)==0 || stoi(scount)<1){
                    throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 |||| stoi(scount)<1){
                        cout<<"Invalid input."<<endl;;
                        cin>>scount;
                    }
                }
                coutn = stoi(scount);
                while(count+nowcount > 5){
                    cout<<"Sorry you can't have more than 5 of this item!"<<endl;
                    cout << "How many do you want?"
                    try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1){
                        throw scount;
                        }
                    }catch(...){
                        while( check_number(scount)==0 |||| stoi(scount)<1){
                            cout<<"Invalid input."<<endl;;
                            cin>>scount;
                        }
                    }
                    coutn = stoi(scount);
                }
                
                if(human->getCoin() < item->getPrice()*count){
                    cout<<"Sorry you don't have enogh coin to buy the item"<<endl;
                    goto menu;
                }
               
                human->setCoin(human->getCoin() - item->getPrice()*count);
                human->addInventory(item , count);
                
            }else if(choice == 0){
                break;
            }
            
            
        }
        
    }
    

    
    void Shop::sell(Human* human){
        human->showInventory();
        int index = 1;
        string sindex;
        while (index!= 0){
            cout << "Enter the number of the item that you want to sell or enter 0 to exit:"<<endl;
            try{
                cin>>sindex;
                if(check_number(sindex)==0 || stoi(sindex)<0 ||stoi(sindex) > human->inventorySize()){
                    throw sindex;
                }
            }catch(...){
                while( check_number(sindex)==0 || stoi(sindex)<0 ||stoi(sindex)>human->inventorySize()){
                    cout<<"Invalid choice."<<endl<<"Enter the number of the Item you want to sell or enter 0 to exit:"<<end;
                    cin>>sindex;
                }
            }
            index = stoi(sindex);
            if(index == 0){
                break;
            }
            int nowcount = human->countItemsAt(index);
            int count = 0;
            string scount;
            if(nowcount > 1){
                cout << "How many do you want to sell?"<<endl;
                try{
                    cin>>scount;
                    if(check_number(scount)==0 || stoi(scount)<1 || stoi(scount)>nowcount){
                        throw scount;
                    }
                }catch(...){
                    while( check_number(scount)==0 || stoi(scount)<1 ||stoi(scount)>nowcount){
                        if(check_number(scount)==0 || stoi(scount)<1 ){
                            cout<<"Invalid input."<<endl;
                        }else{
                            cout<<"You don't have enough of this item to sell this many!"<<endl;
                        }
                        cin>>scount;
                    }
                }
                count = stoi(scount);
                double price = human->priceItemsAt(index);
                human->removeInventory(index , count);
                human->setCoin(human->getCoin() + price*count );
            }else{
                double price = human->priceItemsAt(index);
                human->removeInventory(index);
                human->setCoin(human->getCoin() + price );
                
            }
            
        }
        
    }
    

    
    void Shop::welcom(Human* human){
        cout<<"**********WELCOME TO THE SHOP**********"<<endl<<endl;
        int choice = 1;
        string schoice;
        cout<<"What do you want to do?"<<end<<"1.Buy Items"<<end<<"2.Sell Items"<<endl<<"Enter the number of your choice or 0 to exit the shop:"<<endl;
        try{
            cin>>schoice;
            if(check_number(schoice)==0 || stoi(schoice)<0 ||stoi(schoice)>2){
                throw schoice;
            }
        }catch(...){
            while( check_number(schoice)==0 || stoi(schoice)<0 ||stoi(schoice)>37){
                cout<<"Invalid choice."<<endl<<"Enter 1 to buy items , 2 to sell items or 0 to exit the shop:"<<end;
                cin>>schoice;
            }
        }
        choice = stoi(schoice);
        Shop shop = Shop();
        if(choice == 1){
            shop.buy(human);
        }else if(choice == 2){
            shop.sell(human);
        }else{
            
        }
        
    }
    
    
