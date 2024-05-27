#include <iostream>
#include "sqlite3.h"
#include<cstring>
#include<vector>
#include<iomanip>
#include<cstdlib>
using namespace std;
 sqlite3 *db;
 sqlite3_stmt *stmt;
 int Easy,Medium,Hard,Easy_Trivia,Hard_Trivia,Easy_riddle,Med_riddle,Hard_riddle,entertainment,geography,sport,education;
 int choice,mode,info;
 string user_name;
 string query;
 string easy_answer[]={"peach","concur","fragile","generous","keen","noble","resilient","quaint","diligent","harmonious"};
 string order[]={"First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Ninth","Tenth","Eleventh","Twelfth","thirteenth","fourteenth","fifteenth"};
 string Med_answer[]={"fervent","candid","vibrant","dwarf","jovial","eloquent","benevolent","pristine","bountiful","jubilant"};
 string hard_answer[]={"obfuscate","reticent","esoteric","sycophant","perspicacious","equanimity","enigma"
 ,"proclivity","diatribe","ephemeral","egregious","ubiquitous","cacophony","zestful","yearning"};
 string ans1[] = {"nile", "7 to 8","ras dashen", "addis ababa", "9th january"
"abyssinia","axum", "oromia", "commercial bank of ethiopia","east africa","11","yes"
 };
string ans2[] = {"dek island", "6",  "somalia", "united states", "may 28",
"the yeha temple", "halie selassie"};
string Ans1[5] = {"echo", "candle", "piano", "rain", "towel"};
string Ans2[5] = {"glove", "clock", "fire", "keyboard", "e"};
string Ans3[5] = {"coin", "computer", "breath", "clock", "stamp"};
string questgk_e_t[]={"true","false","false","true","false","false"};
string questgk_s_t[]={"true","false","true","true","false","true"};
string questgk_g_t[]={"true","false","true","true","true","true"};
string questgk_ed_t[]={"true","false","false","true","true","false"};
void Word_Game()
{



 string guess;
 const unsigned char *ANSWER;
 const unsigned char *QUESTION;
 const unsigned char *MEANING;
 const unsigned char *HINT;
    //open a new database
    //sqlite3_open("word_game.db", &db);

 int level,easy_score=0,med_score=0,hard_score=0,total=0;
 //string QUESTION,ANSWER;
        while(true){
                menu:
                menu2:
                menu1:
         cout<<"\t\t\t\t***********************\n";
         cout<<"\t\t\t**************************************\n";
         cout<<"\t\t******************************************************\n";
         cout<<"\t\tHello, Welcome to NH4 Filling The Missing Word Game \n";
         cout<<"\t\tThank you for playing with us \n\n\n";
         //cout<<"*************************************************************************************************************************\n";

         cout<<"\tMENU:\n\n\t1.Easy level\n\t2.Medium level\n\t3.Advanced level\n\t4.High_score\n\t5.Exit\n";

         cin>>level;
         system("cls");
        if(level==1){


         cout<<"##############################################################\n";
         cout<<"Press @ key to exit this game\n";
         cout<<"This level is pretty simple enjoy!!\n\n";

               const char *query="SELECT * FROM Easy";//* selects all the given column
               Easy=sqlite3_prepare_v2(db,query,-1, &stmt, nullptr);
               /*if(Easy!=SQLITE_OK)
                  {
                cout<<"Error: "<<sqlite3_errmsg(db)<<"\n";
                      }*/
                for(int i=0;i<10;){
                if(Easy == SQLITE_OK){
                while(Easy=sqlite3_step(stmt)== SQLITE_ROW)
                     {

                int trial=1;
                cout<<"\nHere is the "<<order[i]<<" word\n";
                QUESTION=sqlite3_column_text(stmt,0);// this is: questions column in easy table at column 0
                cout<<QUESTION;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in easy table at column 1
                MEANING=sqlite3_column_text(stmt,2);//this is : the meaning column in table easy at column 2
                cout<<"\nPlease complete the word\n";
                cin>>guess;
                for(int i=0;i<guess.length();++i){
                guess[i]=tolower(guess[i]);}
                while(guess!=easy_answer[i]&&trial<3&&guess!="@") {
                cout<<"Incorrect guess.Please try again\n";
                cin>>guess;
                for(int i=0;i<guess.length();++i){
                guess[i]=tolower(guess[i]);}
                trial++;}
                if(guess=="@"){
                system("cls");
                goto
                menu;
                    }

         else if(guess==easy_answer[i]){
         cout<<"Awesome! you guessed correctly.\n";
         easy_score++;
         cout<<"----------------------------------------------------------------\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t\t"<<MEANING<<endl;
         cout<<"----------------------------------------------------------------\n";}


         else{
         cout<<"you loose!!\n";
         cout<<"-------------------------------------------------------------------\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t\t"<<MEANING<<endl;
         cout<<"--------------------------------------------------------------------\n";
         }
           i++;}}}
        }


         else if(level==2){

            cout<<"#######################################################\n";
            cout<<"Press @ key to exit this game\n";
            cout<<"WELCOME TO MEDIUM LEVEL\n";
            cout<<"This Might be Little Challenging, Keep Up The Good Work!!\n";
            cout<<"Lets get ready!!\n";

            const char *medium="SELECT * FROM Medium";//* selects all the given column
            Medium=sqlite3_prepare_v2(db,medium,-1, &stmt, nullptr);

                for(int i=0;i<10;){
                if(Medium == SQLITE_OK){
                while(Medium=sqlite3_step(stmt)== SQLITE_ROW)
                     {

                int trial=1;
                cout<<"\nHere is the "<<order[i]<<" word\n";
                QUESTION=sqlite3_column_text(stmt,0);// this is: questions column in Medium table at column 0
                cout<<QUESTION;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Medium table at column 1
                MEANING=sqlite3_column_text(stmt,2);//this is : the meaning column in table easy at column 2
                cout<<"\nPlease enter your guess \n";
                cin>>guess;
                for(int i=0;i<guess.length();++i){
                guess[i]=tolower(guess[i]);}
                while(guess!=Med_answer[i]&&trial<3&&guess!="@") {
                cout<<"Incorrect guess.Please try again\n";
                cin>>guess;
                for(int i=0;i<guess.length();++i){
                guess[i]=tolower(guess[i]);}
                trial++;}
                if(guess=="@"){
                system("cls");
                goto
                menu1;
            }

         else if(guess==Med_answer[i]){
         cout<<"Awesome! you guessed correctly.\n";
         med_score++;
         cout<<"******************\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t"<<MEANING<<endl; }


         else {
         cout<<"you loose!!\nDefinition:\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t"<<MEANING<<endl;}
           i++;}}}
             }

       else if(level==3)
       {
         cout<<"##########################################\n";
         cout<<"Press @ key to exit this game\n";
         cout<<"WELCOME TO HARD LEVEL\n";
         cout<<"This level is extremely difficult ,don't give up!!\n\n";
         cout<<"Here you go!!\n";
         const char *hard="SELECT * FROM Hard";//* selects all the given column
         Hard=sqlite3_prepare_v2(db,hard,-1, &stmt, nullptr);

                for(int i=0;i<10;){
                if(Hard == SQLITE_OK){
                while(Hard=sqlite3_step(stmt)== SQLITE_ROW)
                     {

                int trial=1;
                cout<<"\nHere is the "<<order[i]<<" word\n";
                QUESTION=sqlite3_column_text(stmt,0);// this is: questions column in Hard table at column 0
                cout<<QUESTION;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Hard table at column 1
                MEANING=sqlite3_column_text(stmt,2);//this is : the meaning column in table hard at column 2
                HINT=sqlite3_column_text(stmt,3);
                cout<<"\nPlease enter your guess \n";
                cin>>guess;
                for(int i=0;i<guess.length();++i){
                guess[i]=tolower(guess[i]);}
                while(guess!=hard_answer[i]&&trial<3&&guess!="@") {
                   if(trial==1){
               cout<<"Incorrect guess.Please try again\n";
               cin>>guess;
               for(int i=0;i<guess.length();++i){
               guess[i]=tolower(guess[i]);}}
               if(trial==2){
               //cout<<"Here is hint please guess again\n";
               cout<<"Hint: "<<HINT<<endl;
               cin>>guess;
               for(int i=0;i<guess.length();++i){
               guess[i]=tolower(guess[i]);}}
               trial++;}
                if(guess=="@"){
                system("cls");
                goto
                menu2;
                }

         else if(guess==hard_answer[i]){
         cout<<"Awesome! you guessed correctly.\n";
         hard_score++;
         cout<<"*********************************\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t"<<MEANING<<endl; }


         else{
         cout<<"you loose!!\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t"<<MEANING<<endl;
           i++;}}}
           }}

            else if(level==4){
            total=easy_score+med_score+hard_score;
            cout<<"You have scored :"<<total<<"\nTHANK YOU FOR YOUR TIME!!\nSEE YOU NEXT TIME!!"<<endl<<endl;

            }
             else if(level==5)
                exit(0);
}







}
void Trivia()
{
 string answer;
 const unsigned char *ANSWER;
 const unsigned char *QUESTION;

   int level,easy_score=0,hard_score=0,total=0;
   while(true){
                menu:
                menu1:
    cout << "Welcome to the thrilling world of Ethiopian trivia!" << endl;
    cout << "Prepare to embark on a captivating journey through the rich history and breathtaking landscapes of Ethiopia" << endl;
    cout << "Get ready to test your knowledge and discover fascinating facts about this remarkable country. Let the adventure begin!" << endl;
    cout<<"\tMENU:\n\n\t1.Easy level\n\t2.hard level\n\t3.High_score\n\t4.Exit\n";
    cin>>level;
    system("cls");
if(level==1){
         cout<<"################################################\n";
         cout<<"Press @ key to exit this game\n";
         cout<<"This level is pretty simple enjoy!!\n\n";
         const char *query="SELECT Question FROM Easy_Trivia";//* selects all the given column
         Easy_Trivia=sqlite3_prepare_v2(db,query,-1, &stmt, nullptr);
               /*if(Easy!=SQLITE_OK)
                  {
                cout<<"Error: "<<sqlite3_errmsg(db)<<"\n";
                      }*/
                for(int i=0;i<12;){
                if(Easy_Trivia == SQLITE_OK){
                while(Easy_Trivia=sqlite3_step(stmt)== SQLITE_ROW)
                     {
                int trial=1;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Hard table at column 1
                QUESTION=sqlite3_column_text(stmt,0);
                cout<<QUESTION<<endl;
                cout<<"please enter your answer: "<<endl;
                //cin>>answer;
                getline(cin,answer);
                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}

               while(answer!=ans1[i]&&trial<3&&answer!="@") {
               cout<<"Incorrect answer.Please try again\n";
               //cin>>answer;
               getline(cin,answer);
               for(int i=0;i<answer.length();++i){
               answer[i]=tolower(answer[i]);}
               trial++;}
               if(answer=="@"){
                system("cls");
                goto
                menu1;
            }
            else if(answer==ans1[i]){
         cout<<"Awesome! your answer is correct.\n";
         easy_score++;
            }
         else{
         cout<<"opps you loose!!\n the answer is :\n";
         cout<<ANSWER<<endl;
          } i++;}}}

  }
         else if(level==2){

         cout<<"################################################\n";
         cout<<"Press @ key to exit this game\n";
         cout<<"WELCOME TO HARD LEVEL\n";
         const char *query="SELECT * FROM Hard_Trivia";//* selects all the given column
         Hard_Trivia=sqlite3_prepare_v2(db,query,-1, &stmt, nullptr);
          for(int i=0;i<7;){
                if(Hard_Trivia == SQLITE_OK){
                while(Hard_Trivia=sqlite3_step(stmt)== SQLITE_ROW)
                     {
                int trial=1;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Hard table at column 1
                QUESTION=sqlite3_column_text(stmt,0);
                cout<<QUESTION<<endl;
                cout<<"please enter your answer: "<<endl;
                //cin>>answer;
                getline(cin,answer);
                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}

               while(answer!=ans2[i]&&trial<3&&answer!="@") {
               cout<<"Incorrect answer.Please try again\n";
               //cin>>answer;
               getline(cin,answer);
               for(int i=0;i<answer.length();++i){
               answer[i]=tolower(answer[i]);}
               trial++;}
               if(answer=="@"){
                system("cls");
                goto
                menu1;
            }
            else if(answer==ans2[i]){
         cout<<"Awesome! your answer is correct.\n";
         easy_score++;
            }
         else{
         cout<<"opps you loose!!\n the answer is :\n";
         cout<<ANSWER<<endl;
          } i++;}}}

         }
        else if(level==3){
            total=easy_score+hard_score;
            cout<<"You have scored :"<<total<<"\nTHANK YOU FOR YOUR TIME!!\nSEE YOU NEXT TIME!!"<<endl<<endl;
        }
            else if(level==4){
                exit(0);
}}

}
void Riddle()
{
string answer;
 const unsigned char *ANSWER;
 const unsigned char *QUESTION;

   int level,easy_score=0,hard_score=0,total=0;
   string x;
   while(true){
      menu:
      menu1:
      menu2:
    cout<<"     WELCOME TO THE NH4 RIDDLE GAME"<<endl;
    cout<<"    if you wanna play  hit  any key!!"<<endl;
    cin>>x;
    system("cls");
    cout<<"       SELECT ANY LEVEL YOU WANT"<<endl;

 cout<<" 1.easy\n 2.medium\n 3.hard\n 4.score\n 0.to exit"<<endl;
    cin>>level;
      system("cls");

 cout<<"**************************************************************"<<endl;
if(level==1){
         cout << "You have 2 chances to answer the 5 riddles." << endl;
         cout<<"you can stop playing in the middle of the game by pressing(*)star"<<endl;
         const char *query="SELECT * FROM Easy_riddle";//* selects all the given column
         Easy_riddle=sqlite3_prepare_v2(db,query,-1, &stmt, nullptr);
               /*if(Easy!=SQLITE_OK)
                  {
                cout<<"Error: "<<sqlite3_errmsg(db)<<"\n";
                      }*/
                for(int i=0;i<5;){
                if(Easy_riddle == SQLITE_OK){
                while(Easy_riddle=sqlite3_step(stmt)== SQLITE_ROW)
                     {
                int trial=2;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Hard table at column 1
                QUESTION=sqlite3_column_text(stmt,0);
                cout<<QUESTION<<endl;
                cout<<"please enter your answer: "<<endl;
                cin>>answer;

                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}

               while(answer!=Ans1[i]&&trial<3&&answer!="*") {
               cout<<"Incorrect answer.Please try again\n";
               cin>>answer;

               for(int i=0;i<answer.length();++i){
               answer[i]=tolower(answer[i]);}
               trial++;}
               if(answer=="*"){
                system("cls");
                goto
                menu;
            }
         else if(answer==Ans1[i]){
         cout<<"Awesome! your answer is correct.\n";
         easy_score++;
            }
         else{
         cout<<"opps you loose!!\n the answer is :\n";
         cout<<ANSWER<<endl;
          } i++;}}}

  }
         else if(level==2){

         cout << "You have 3 chances to answer the 5 riddles." << endl;
         cout<<"Press (*) key to exit this Level\n";
         cout<<"WELCOME TO THIS LEVEL\n";
         const char *query="SELECT * FROM med_riddle";//* selects all the given column
         Med_riddle=sqlite3_prepare_v2(db,query,-1, &stmt, nullptr);
          for(int i=0;i<5;){
                if(Med_riddle == SQLITE_OK){
                while(Med_riddle=sqlite3_step(stmt)== SQLITE_ROW)
                     {
                int trial=1;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Hard table at column 1
                QUESTION=sqlite3_column_text(stmt,0);
                cout<<QUESTION<<endl;
                cout<<"please enter your answer: "<<endl;
                cin>>answer;

                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}

               while(answer!=Ans2[i]&&trial<3&&answer!="*") {
               cout<<"Incorrect answer.Please try again\n";
               cin>>answer;

               for(int i=0;i<answer.length();++i){
               answer[i]=tolower(answer[i]);}
               trial++;}
               if(answer=="*"){
                system("cls");
                goto
                menu1;
            }
            else if(answer==Ans2[i]){
         cout<<"Awesome! your answer is correct.\n";
         easy_score++;
            }
         else{
         cout<<"opps you loose!!\n the answer is :\n";
         cout<<ANSWER<<endl;
          } i++;}}}

         }
          else if(level==3){
         cout << "You have 4 chances to answer the 5 riddles." << endl;
         cout<<"Press (*) key to exit this game\n";
         cout<<"WELCOME TO HARD LEVEL\n";
         const char *query="SELECT * FROM Hard_riddle";//* selects all the given column
         Hard_riddle=sqlite3_prepare_v2(db,query,-1, &stmt, nullptr);
          for(int i=0;i<5;){
                if(Hard_riddle == SQLITE_OK){
                while(Hard_riddle=sqlite3_step(stmt)== SQLITE_ROW)
                     {
                int trial=1;
                ANSWER=sqlite3_column_text(stmt,1);// this is :answer column in Hard table at column 1
                QUESTION=sqlite3_column_text(stmt,0);
                cout<<QUESTION<<endl;
                cout<<"please enter your answer: "<<endl;
                cin>>answer;

                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}

               while(answer!=Ans2[i]&&trial<4&&answer!="*") {
               cout<<"You have 4 chances Please try again\n";
               cin>>answer;

               for(int i=0;i<answer.length();++i){
               answer[i]=tolower(answer[i]);}
               trial++;}
               if(answer=="*"){
                system("cls");
                goto
                menu2;
            }
            else if(answer==Ans2[i]){
         cout<<"Awesome! your answer is correct.\n";
         easy_score++;
            }
         else{
         cout<<"Opps you loose!!\n the answer is :\n";
         cout<<ANSWER<<endl;
          } i++;}}}


          }
        else if(level==4){
            total=easy_score+hard_score;
            cout<<"You have scored :"<<total<<"\nTHANK YOU FOR YOUR TIME!!\nSEE YOU NEXT TIME!!"<<endl<<endl;
        }
            else if(level==5){
                exit(0);
}}
   }

void connection()
{
if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
{
    Easy=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Easy(Question TEXT, Answer TEXT, Meaning TEXT);",-1, &stmt, NULL);


    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
   /*if(Easy!=SQLITE_OK)
    {
    cout<<"Error: "<<sqlite3_errmsg(db)<<"\n";
    }
   else{
       cout<<"Table is create successfully!!\n";}*/
if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
     Medium=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Medium(Question TEXT, Answer TEXT, Meaning TEXT);",-1, &stmt, NULL);
     sqlite3_step(stmt);
     sqlite3_finalize(stmt);}

/*
        if(Medium!=SQLITE_OK)
    {
       cout<<"Error: "<<sqlite3_errmsg(db)<<"\n";
    }
    else{
        cout<<"Table is create successfully!!\n";}*/
if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
    Hard=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Hard(Question TEXT, Answer TEXT, Meaning TEXT,Hint TEXT);",-1, &stmt, NULL);
    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}

/*
        if(Hard!=SQLITE_OK)
    {
       cout<<"Error: "<<sqlite3_errmsg(db)<<"\n";
    }
    else
        cout<<"Table is create successfully!!\n";*/
if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
    Easy_Trivia=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Easy_Trivia(Question TEXT, Answer TEXT);",-1, &stmt, NULL);
    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
    Hard_Trivia=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Hard_Trivia(Question TEXT, Answer TEXT);",-1, &stmt, NULL);
    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
    Easy_riddle=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Easy_riddle(Question TEXT, Answer TEXT);",-1, &stmt, NULL);
    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}



if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
    Med_riddle=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS med_riddle(Question TEXT, Answer TEXT);",-1, &stmt, NULL);
    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}


if (sqlite3_open("Word_Game.db", &db)== SQLITE_OK)
    {
    Hard_riddle=sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Hard_riddle(Question TEXT, Answer TEXT);",-1, &stmt, NULL);
    //instances
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
}

int main()
{
    system ("color 3E");

    while (true)
        {

cout<<"\n\t\t\tWELCOME TO NH4 GAMES\n";
cout<<"\t\tLET'S HAVE SOME FUN!!!\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"Enter player user name:\n";
getline(cin,user_name);
cout<<"Which Game Would You Prefer"<<endl;
cout<<"----------------------------------------\n---------------------------------------\n";
cout<<"1.Word Game\n2.Riddle\n3.Trivia\n4.Exit\n";
cin>>choice;
connection();
switch(choice)
{
 system("cls");
case 1:
    Word_Game();
    break;
case 2:
    Riddle();
    break;

case 3:
    Trivia();
    break;
case 4:
    exit(0);
}
}




 sqlite3_close(db);
 sqlite3_close(db);
    return 0;
}
