//
//  RecommendCharacter.cpp
//  
//
//  Created by Lilia Rouhi on 1/10/1403 AP.
//

#include "RecommendCharacter.hpp"
#include "RecommendCharacter.h"
#include "CheckNumber.h"
#include <iostream>
#include <vector>

using namespace std;




void recommendCharacter(){
    cout<<"First, let's answer some questions !"<<endl<<endl;
    vector<question> ques;
    question ques1 , ques2, ques3 , ques4 , ques5 , ques6 , ques7 , ques8 , ques9 , ques10;
    ques1.question = "1. What's your favorite type of movie?";
    ques1.option1="1. Epic Adventure";
    ques1.option2="2. Spy Thriller";
    ques1.option3="3. Superhero Blockbuster";
    ques1.option4="4. War Drama";
    ques1.option5="5. Fantasy Epic";
    ques1.option6="6. Sci-Fi Action";
    ques1.option7="7. Family Comedy";
    ques.push_back(ques1);
    ques2.question = "2. Where would you most like to travel?";
    ques2.option1="1. Medieval Castle ";
    ques2.option2="2. Mysterious City";
    ques2.option3="3. Metropolis";
    ques2.option4="4. War Zone";
    ques2.option5="5. Mystical Forest";
    ques2.option6="6. Futuristic City";
    ques2.option7="7. Home";
    ques.push_back(ques2);
    ques3.question = "3. Which of these activities would you enjoy the most?";
    ques3.option1="1. Sword Fighting ";
    ques3.option2="2. Stealth Training";
    ques3.option3="3. Saving the World";
    ques3.option4="4. Target Practice";
    ques3.option5="5. Spell casting ";
    ques3.option6="6. Tech Upgrade";
    ques3.option7="7. Cooking";
    ques.push_back(ques3);
    ques4.question = "4. Which superpower would you choose?";
    ques4.option1 = "1. Strength ";
    ques4.option2 = "2. Invisibility ";
    ques4.option3 = "3. Flight ";
    ques4.option4 = "4. Precision ";
    ques4.option5 = "5. Telekinesis ";
    ques4.option6 = "6. Technopathy  ";
    ques4.option7 = "7. Mind Reading ";
    ques.push_back(ques4);
    ques5.question = "5. How do you prefer to solve problems?";
    ques5.option1 = "1. Head-on ";
    ques5.option2 = "2. Quietly";
    ques5.option3 = "3. With a team";
    ques5.option4 = "4. Strategically";
    ques5.option5 = "5. With creativity";
    ques5.option6 = "6. With technology ";
    ques5.option7 = "7. With wisdom ";
    ques.push_back(ques5);
    ques6.question = "6. Which sport do you enjoy watching or playing";
    ques6.option1 = "1. Horse Riding ";
    ques6.option2 = "2. Martial Arts";
    ques6.option3 = "3. Wrestling ";
    ques6.option4 = "4. Target Shooting ";
    ques6.option5 = "5. Quidditch ";
    ques6.option6 = "6. Robot Combat ";
    ques6.option7 = "7. Partabe Dampayi ";
    ques.push_back(ques6);
    ques7.question = "7. Which animal best represents your personality?";
    ques7.option1 = "1. Lion ";
    ques7.option2 = "2. Fox ";
    ques7.option3 = "3. Eagle ";
    ques7.option4 = "4. Wolf";
    ques7.option5 = "5. Owl";
    ques7.option6 = "6. Panther";
    ques7.option7 = "7. Eshak ";
    ques.push_back(ques7);
    ques8.question = "8. Which historical era would you visit if you could time travel?";
    ques8.option1 = "1. Middle Ages";
    ques8.option2 = "2. Renaissance";
    ques8.option3 = "3. Modern Age";
    ques8.option4 = "4. World War II";
    ques8.option5 = "5. Ancient Times";
    ques8.option6 = "6. Future";
    ques8.option7 = "7. mehr 1th";
    ques.push_back(ques8);
    ques9.question = "9. What type of music do you enjoy listening to?";
    ques9.option1 = "1. Orchestral";
    ques9.option2 = "2. Hard Rock ";
    ques9.option3 = "3. Pop ";
    ques9.option4 = "4. Military Cadence ";
    ques9.option5 = "5. Gothic Style ";
    ques9.option6 = "6. Electronic ";
    ques9.option7 = "7. Bandari! ";
    ques.push_back(ques9);
    ques10.question = "10. What's your preferred mode of transportation?";
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
        cout<<ques[i].question << endl;
        cout<<ques[i].option1 << endl << ques[i].option2 << endl<<ques[i].option3 << endl << ques[i].option4 << endl<<ques[i].option5 << endl << ques[i].option6 << endl << ques[i].option7<<endl;
        cout<<"Enter your choice: "<<endl;
        int choice;
        string schoice;
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
        cout<<"We recommend you to choose <Assasin> as your character based on your personality!"<<endl;
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
    cout<< "1. Paladin" <<endl << "2. Assasin" << endl << "3. SuprHero"<< endl << "4. Sniper" << endl << "5. Wizard" << "6. Cyborg" << endl << "7. persian Mom" << endl;
    
}


