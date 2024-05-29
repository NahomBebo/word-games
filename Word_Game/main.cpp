#include <iostream>
#include "sqlite3.h"
#include<cstring>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include <windows.h>
#include <cctype>
#include <fstream>
using namespace std;
 sqlite3 *db;
 sqlite3 *dbgk;
 sqlite3_stmt *stmt;
 sqlite3 *db1;
 sqlite3_stmt *stmt1;
 int Easy,Medium,Hard,Easy_Trivia,Hard_Trivia,Easy_riddle,Med_riddle,Hard_riddle,entertainment1,geography1,sport1,education1;
 int choice,entertainment2,geography2,sport2,education2,entertainment3,geography3,sport3,education3;
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
string questgk_e_t[]={"true","true","false","false","true","false"};
string questgk_e_m[]={"b","a","b","d","a","c"};
string questgk_e_s[]={"glass shoe","shake it up","famous disney channel","titanic","spongebob","harry styles","tom cruise"};
string questgk_s_t[]={"true","false","true","true","false","true"};
string questgk_s_m[]={"a","b","c","a","c","a"};
string questgk_s_s[]={"lionel messi","usa","abebe bikila","usain bolt","serena williams","sumo"};
string questgk_g_t[]={"true","false","true","true","true","true"};
string questgk_g_m[]={"a","d","b","a","b","a"};
string questgk_g_s[]={"mount everest","china","nile river","san fransisco","mexico","egypt"};
string questgk_ed_t[]={"true","false","false","true","true","false"};
string questgk_ed_m[]={"a","b","a","d","a","c"};
string questgk_ed_s[]={"egypt","duolingo","marie curie","skin","3","thomas jefferson"};
//********************************************************************************
int displaycolumn(sqlite3* db1, string tableName, const char* columnName) {
    int columns=0;
    string sql = "SELECT " + string(columnName) + " FROM " + string(tableName);
    int rc = sqlite3_prepare_v2(db1, sql.c_str(), -1, &stmt1, NULL);
    if (rc != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db1) << endl;
        return 0;
    }

// Execute the statement and fetch the results
    while (sqlite3_step(stmt1) == SQLITE_ROW) {
        columns++;
        cout<<columns<<".";

        const char* value = (const char*)sqlite3_column_text(stmt1, 0);
        cout << value;
//hidden words are not displayed in a line by line manner unlike category
        if(columnName=="hidden_words")
            cout<<"   ";
        else
            cout<<endl;
    if(columnName=="hidden_words")
        {
            if(columns==5||columns==10||columns==15)
                cout<<endl;
        }

    }

    // Finalize the statement
    sqlite3_finalize(stmt1);
    return columns;
}
//************************************************************************************************************************************************
string getvalue(sqlite3* db1, const char* tableName, const char* columnName, int searchValue, const char* searchColumn) {

    string sql = "SELECT " + string(columnName) + " FROM " + string(tableName) + " WHERE " + string(searchColumn) + " = " + to_string(searchValue);
    int rc = sqlite3_prepare_v2(db1, sql.c_str(), -1, &stmt1, NULL);
    if (rc != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db1) << endl;

    }

    // Execute the statement and fetch the result
    if (sqlite3_step(stmt1) == SQLITE_ROW) {
        const char* value = (const char*)sqlite3_column_text(stmt1, 0);

        return value;
    } else {
        cerr << "Error fetching result: " << sqlite3_errmsg(db1) << endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt1);
}
//******************************************************************************************************

void open_db1()
{
    sqlite3_open("database.db", &db1);
    int rc = sqlite3_open("database.db", &db1);
if (rc != SQLITE_OK)
    {
    // Database could not be opened
    cerr << "Error opening database: " << sqlite3_errmsg(db1) << endl;
    sqlite3_close(db1);

    }
    else {

             // Database opened successfully
            // We can now use the 'db' pointer to interact with the database
         }
}
//********************************************************************************************************************
void setConsoleFontSize(int size) {
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = size;
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = FW_NORMAL;
    wcscpy(fontInfo.FaceName, L"Consolas");

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
}
  //
 void update_list(sqlite3* db1, string name, string starts, string ends) {
    string resultMessage;

    // Construct the SELECT query with the specified condition
    std::string select_query = "SELECT * FROM " + name + " WHERE start = '" + starts + "' AND end = '" + ends + "';";

    sqlite3_stmt* stmt1;
    int rc = sqlite3_prepare_v2(db1, select_query.c_str(), -1, &stmt1, nullptr);

    if (rc != SQLITE_OK) {
        cerr << "Error preparing SELECT query: " << sqlite3_errmsg(db1) << endl;
        cout << "An error occurred while preparing the query.";
        return;
    }

    rc = sqlite3_step(stmt1);

    if (rc == SQLITE_ROW) {
        // Construct the DELETE query with variables
        string delete_query = "DELETE FROM " + name + " WHERE start = '" + starts + "' AND end = '" + ends + "';";
        int delete_result = sqlite3_exec(db1, delete_query.c_str(), nullptr, 0, nullptr);

        if (delete_result != SQLITE_OK) {
            cerr << "Error executing DELETE query" << endl;
        } else {
            system("cls");
            cout << "YOU HAVE BEEN SUCCESSFUL FINDING A WORD!" << endl;

        }
    } else {
        system("cls");
        cout << "Nope" << endl;

    }

    sqlite3_finalize(stmt1); // Finalize the prepared statement
}
bool exit (string exit)
{
    for (char& c : exit) {
        c = tolower(c);
    }
    if(exit=="exit")
        return 1;
    else
        return 0;
}

 //**********************************************************************************************************************************
int findword(string name)
  {

     string s_col, s_row, e_col, e_row;
    cout<<"you can exit game anytime by inserting \"exit\"."<<endl;
    cout << "Insert" << endl;
    cout << "Starting Column: ";
    cin >> s_col;
    if(exit(s_col))
        return 0;
    cout << "Starting Row: ";
    cin >> s_row;
    if(exit(s_row))
        return 0;
    cout << "Ending Column: ";
    cin >> e_col;
    if(exit(e_col))
        return 0;
    cout << "Ending Row: ";
    cin >> e_row;
    if(exit(e_row))
        return 0;
    string starts = s_col + s_row;
    string ends = e_col + e_row;

for (char& c : starts) {
        c = tolower(c);
    }
   for (char& c : ends) {
        c = tolower(c);
    }

     update_list(db1, name, starts, ends);

  }

//**********************************************************************************************************************
void display_grid(string filename,string name, int choice)
{
    //GETTING GRID SIZE
    int rows=stoi(getvalue(db1,"categoryinfo","rows",choice,"roll"));
    int cols=stoi(getvalue(db1,"categoryinfo","columns",choice,"roll"));

    //GETTING THE GRID FROM A FILE
    ifstream input;
    input.open(filename);

    if (!input.is_open())
        {
           cout << "Failed to open the file." <<endl;

        }

    char grid[rows*cols];
    char ch;
    int i=0;
    while (input>>ch) {

        grid[i]=ch;
        i++;
    }


    int index = 0;
setConsoleFontSize(24);
//INDEXING THE GRID INTO COLUMNS***********************************************************************
cout<<"   ";
for(int i=0;i<cols;i++)
{
    char playing_index='A';
    if(i<10)
        cout<<i<<" ";
    if(i==10)
        cout<<'!'<<" ";
    if(i==11)
        cout<<'@'<<" ";
    if(i==12)
        cout<<'#'<<" ";
    if(i==13)
        cout<<'$'<<" ";
    if(i==14)
        cout<<'%'<<" ";
    if(i==15)
        cout<<'^'<<" ";
    if(i==16)
        cout<<'&'<<" ";
}
cout<<endl;
cout<<"   ";
for(int i=1;i<=cols;i++)
{
    cout<<'_'<<" ";
}
cout<<endl;
//*****************************************************************************************************

char playing_index='A';
    for (int i = 0; i < rows; i++) {
    //INDEXING THE GRID INTO ROWS
    cout<<static_cast<char>(playing_index+i)<<"<|";
        for (int j = 0; j < cols; j++) {
            if (index < (rows*cols) ){
                cout <<grid[index] << " ";
                index++;
            } else {
                cout << " ";
            }
        }
        cout <<endl;
    }

    input.close();
//GETTING THE NAME OF THE CATEGORY  FROM THE TABLE CATEGORYINFO TO PLAY ACCORDING TO INPUT 'CHOICE'
string category=getvalue(db1,"categoryinfo","category",choice,"roll");
//DISPLAYING THE HIDDEN WORDS TO BE SOUGHT IN THE GRID
displaycolumn(db1,name,"hidden_words");

}
//*********************************************************************************************************************
void save(string name, string category)
{
    string createTableQuery = "CREATE TABLE " + string(name) + " AS SELECT * FROM " + string(category);

    char* errorMsg;
   int rc = sqlite3_exec(db1, createTableQuery.c_str(), 0, 0, &errorMsg);

    if (rc != SQLITE_OK) {
        cerr << "Error creating new table: " << errorMsg << endl;
        sqlite3_free(errorMsg);
    }
}
//*********************************************************************************************************************
void record(string name1,string category1)
{
    char* zErrMsg=0;
    string sql = "INSERT INTO \"saved\" (name, category) VALUES ('" + name1 + "', '" + category1 + "')";

int rc = sqlite3_exec(db1, sql.c_str(), nullptr, nullptr, &zErrMsg);

if (rc != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
}
}
//********************************************************************************************
int countCallback(void* data, int argc, char** argv, char** azColName) {
    int* count = (int*)data;
    *count = std::stoi(argv[0]);
    return 0;
}
//***************************************************************************************************************
int remaining(string name)
{
    string count_query = "SELECT COUNT(*) FROM " + name + ";";

    int count = 0;
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db1, count_query.c_str(), countCallback, &count, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db1);
        return 1;
    }

  return count;
}

//****************************************************************************



//****************************************************************************
char menu()
{
    char choice;
    menu:
    {
        cout<<"1.Start New Game"<<endl;

        cout<<"2.Back To Menu"<<endl;
    }
    cin>>choice;
    if(choice=='1'||choice=='2')
    {
        system("cls");
        return choice;
    }

    else
    {
        cout<<"Please Enter A Valid Input"<<endl;
        goto menu;
    }

}
//**********************************************************************************************************************
void start()
{
    open_db1();
    string name, category;
    int choice;
    cout<<"Please Enter Your Name:";
    cin>>name;
    start:
    system("cls");
    cout<<"Please Choose Categories."<<endl;
    //displaying categories from the db
    displaycolumn(db1, "categoryinfo", "category");
    cin>>choice;
    system("cls");
    category=getvalue(db1,"categoryinfo","category",choice,"roll");
    //saving game progress in database
    record(name,category);
    save(name,category);
    // fetches filename from the database and assigns to the string
    string file=getvalue(db1,"categoryinfo","filename",choice,"roll");
    play:
    display_grid(file,name,choice);
    cout<<endl;
    if(findword(name)==0)
        return ;
    if(remaining(name))
        goto play;
    else
        {
            cout<<"congrats!"<<endl;
            cout<<"Do you want to play again?"<<endl;
            cout<<"1.yes"<<endl;
            cout<<"2.no"<<endl;
            cin>>choice;
            if(choice==1)
                goto start;
            else
                return ;

        }


}

//****************************************************************************
void Word_Game();
void Trivia();
void Riddle();
void general_knowledge();
void connection();
int main()
{
    system ("color BE");

    while (true)
        {
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"\n\t\t\tWELCOME TO NH4 GAMES\n";
cout<<"\t\t\tLET'S HAVE SOME FUN!!!\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"Enter player user name:\n";
getline(cin,user_name);
cout<<"Hello "<<user_name <<" ,Which Game Would You Prefer"<<endl;
cout<<"----------------------------------------\n---------------------------------------\n";
cout<<"1.Word Game\n2.Riddle\n3.Trivia\n4.General_Knowledge\n5.WordSearch\n6.Exit\n";
cin>>choice;
connection();
switch(choice)
{
 system("cls");
case 1:
    system("cls");
    Word_Game();
    break;
case 2:
    system("cls");
    Riddle();
    break;

case 3:
    system("cls");
    Trivia();
    break;
case 4:
    system("cls");
    general_knowledge();
    break;
case 5:
    system("cls");
    start();
case 6:
    cout<<"THANK YOU FOR YOUR TIME!!";
    exit(0);
 system("cls");
}
}





 sqlite3_close(db);
    return 0;
}
void Word_Game()
{

system ("color DE");

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

         cout<<"\tMENU:\n\n\t1.Easy level\n\t2.Medium level\n\t3.Advanced level\n\t4.High_score\n\t5.Back to main menu\n\t6.Exit\n";

         cin>>level;
         system("cls");
        if(level==1){


         cout<<"************************************\n";
         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
         cout<<"\tThis level is pretty simple enjoy!!\n\n";

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
                while(guess!=easy_answer[i]&&trial<3&&guess!="@"&&guess!="*") {
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
                else if(guess=="*"){
                system("cls");
                main();
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
           main();
        }


         else if(level==2){
            cout<<"************************************\n";
            cout<<"\tPress (@) key to exit this level\n";
            cout<<"\tPress (*)key to go to main menu\n";
            cout<<"\tWELCOME TO MEDIUM LEVEL\n";
            cout<<"\tThis Might be Little Challenging, Keep Up The Good Work!!\n";
            cout<<"\tLets get ready!!\n";

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
                while(guess!=Med_answer[i]&&trial<3&&guess!="@"&&guess!="*") {
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
                else if(guess=="*"){
                system("cls");

                main();
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
         cout<<"************************************\n";
         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
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
                while(guess!=hard_answer[i]&&trial<3&&guess!="@"&&guess!="*") {
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
                else if(guess=="*"){
                system("cls");

                main();
                 }

         else if(guess==hard_answer[i]){
         cout<<"Awesome! you guessed correctly.\n";
         hard_score++;
         cout<<"*********************************\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t"<<MEANING<<endl; }


         else{
         cout<<"*********************\n";
         cout<<"you loose!!\n";
         cout<<"WORD\t\tDEFINITION"<<endl;
         cout<<ANSWER<<"\t"<<MEANING<<endl;
           }i++;}}
           }}

else if(level==4){
    total=easy_score+med_score+hard_score;
    cout<<"\tYou have scored :"<<total<<"\nTHANK YOU FOR YOUR TIME!!\nSEE YOU NEXT TIME!!"<<endl<<endl;

            }
else if(level==5){
    main();
             }
else if(level==6){
 cout<<"\nSEE YOU NEXT TIME!!"<<endl;
    exit(0);}
else
    main();
}







}
void Trivia()
{
system ("color 3E");
 string answer;
 const unsigned char *ANSWER;
 const unsigned char *QUESTION;

   int level,easy_score=0,hard_score=0,total=0;
   while(true){
                menu:
                menu1:
    cout<<"\t\t\t\t***********************\n";
    cout<<"\t\t\t**************************************\n";
    cout<<"\t\t******************************************************\n";
    cout << "\tWelcome to the thrilling world of Ethiopian trivia!" << endl;
    cout << "\tPrepare to embark on a captivating journey through the rich history and breathtaking landscapes of Ethiopia" << endl;
    cout << "\tGet ready to test your knowledge and discover fascinating facts about this remarkable country. Let the adventure begin!" << endl;
    cout<<"\tMENU:\n\n\t1.Easy \n\t2.Hard \n\t3.High_score\n\t4.Back to main menu\n\t5.Exit\n";
    cin>>level;
    system("cls");
if(level==1){
         cout<<"************************************\n";
         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
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

                while(answer!=ans1[i]&&trial<3&&answer!="@"&&answer!="*") {
                cout<<"Incorrect answer.Please try again\n";

                getline(cin,answer);
                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}
                trial++;}
                if(answer=="@"){
                system("cls");
                goto
                menu1;
                }
                else if(answer=="*"){
                system("cls");

                main();
                 }
            else if(answer==ans1[i]){
            cout<<"------------------------------------------\n";
            cout<<"Awesome! your answer is correct.\n";
           easy_score++;
            }
         else{
         cout<<"------------------------------------------\n";
         cout<<"opps you loose!!\n the answer is :\n";
         cout<<ANSWER<<endl;
          } i++;}}}

  }
else if(level==2){

         cout<<"************************************\n";
         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
         cout<<"\tWELCOME TO HARD LEVEL\n";
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

                while(answer!=ans2[i]&&trial<3&&answer!="@"&&answer!="*") {
                cout<<"Incorrect answer.Please try again\n";

                getline(cin,answer);
                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}
                trial++;}
                if(answer=="@"){
                system("cls");
                goto
                menu1;
                  }
                else if(answer=="*"){
                system("cls");

                main();
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
  cout<<"You have scored :"<<total<<"\nTHANK YOU FOR YOUR TIME!!"<<endl<<endl;
        }
else if(level==4){
    main();}
else if(level==5){
    cout<<"\nSEE YOU NEXT TIME!!";
    exit(0);}

else
    main();
}

}
void Riddle()
{
    system ("color 5E");
string answer;
 const unsigned char *ANSWER;
 const unsigned char *QUESTION;

   int level,easy_score=0,hard_score=0,total=0;
   string x;
   while(true){
      menu:
      menu1:
      menu2:
    cout<<"\tWELCOME TO THE NH4 RIDDLE GAME"<<endl;
    cout<<"\tIf you wanna play  hit  any key!!"<<endl;
    cin>>x;
    system("cls");
    cout<<"\tSELECT ANY LEVEL YOU WANT"<<endl;

 cout<<"\n\tMENU:\n\n\t1.Easy\n\t2.Medium\n\t3.Hard\n\t4.Back to main menuu\n\t5.Score\n\t0.Exit"<<endl;
    cin>>level;
    system("cls");


if(level==1){
         cout<<"*********************************************\n";
         cout <<"\tYou have 2 chances to answer the 5 riddles." << endl;

         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
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

                while(answer!=Ans1[i]&&trial<3&&answer!="@"&&answer!="*") {
                cout<<"Incorrect answer.Please try again\n";
                cin>>answer;

                for(int i=0;i<answer.length();++i){
                answer[i]=tolower(answer[i]);}
                trial++;}
                if(answer=="@"){
                system("cls");
                goto
                menu;
                 }
                else if(answer=="*"){
                system("cls");

                main();
                 }
              else if(answer==Ans1[i]){
              cout<<"---------------------------------------------\n";
              cout<<"Awesome! your answer is correct.\n";
              easy_score++;
                  }
              else{
                 cout<<"------------------------------------------\n";
                 cout<<"opps you loose!!\n the answer is :\n";
                 cout<<ANSWER<<endl;
                 } i++;}}}

  }
else if(level==2){
         cout<<"*********************************************\n";
         cout <<"\tYou have 3 chances to answer the 5 riddles." << endl;
         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
         cout<<"\tWELCOME TO THIS LEVEL\n";
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

               while(answer!=Ans2[i]&&trial<3&&answer!="@"&&answer!="*") {
               cout<<"Incorrect answer.Please try again\n";
               cin>>answer;

               for(int i=0;i<answer.length();++i){
               answer[i]=tolower(answer[i]);}
               trial++;}
               if(answer=="@"){
                system("cls");
                goto
                menu1;
               }
               else if(answer=="*"){
               system("cls");

                main();
                 }
              else if(answer==Ans2[i]){
             cout<<"------------------------------------------\n";
              cout<<"Awesome! your answer is correct.\n";
              easy_score++;
              }
             else{
             cout<<"------------------------------------------\n";
             cout<<"opps you loose!!\n the answer is :\n";
             cout<<ANSWER<<endl;
             } i++;}}}

         }
else if(level==3){
         cout<<"*********************************************\n";
         cout <<"\tYou have 4 chances to answer the 5 riddles." << endl;
         cout<<"\tPress (@) key to exit this level\n";
         cout<<"\tPress (*)key to go to main menu\n";
         cout<<"\tWELCOME TO THIS LEVEL\n";
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

               while(answer!=Ans2[i]&&trial<4&&answer!="@"&&answer!="*") {
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
                else if(answer=="*"){
                system("cls");

                main();
                 }
               else if(answer==Ans2[i]){
               cout<<"---------------------------------------------\n";
               cout<<"Awesome! your answer is correct.\n";
               easy_score++;
                }
               else{
               cout<<"---------------------------------------------\n";
               cout<<"Opps you loose!!\n the answer is :\n";
               cout<<ANSWER<<endl;
               } i++;}}}


          }
else if(level==4){
    total=easy_score+hard_score;
    cout<<"You have scored :"<<total<<"\nTHANK YOU FOR YOUR TIME!!"<<endl<<endl;
        }
else if(level==5)
    {
    main();
  }
else if(level==0){
    exit(0);
cout<<"\nSEE YOU NEXT TIME!!"<<endl;
    }
else
main();
}

   }


void general_knowledge(){
    const unsigned char *ANSWER;
    const unsigned char *QUESTION;
    const unsigned char *CHOICE;
   char press_key;
   int high_score_gk;
   int ch_gk1,ch_gk_e_2;
   int counter_gk_e1_t=0,counter_gk_e1_m=0,counter_gk_e1_s=0;
   int counter_gk_s1_t=0,counter_gk_s1_m=0,counter_gk_s1_s=0;
   int counter_gk_g1_t=0,counter_gk_g1_m=0,counter_gk_g1_s=0;
   int counter_gk_ed1_t=0,counter_gk_ed1_m=0,counter_gk_ed1_s=0;
   int counter_gk_tot1=0;
   int trials_e_s=0;
   string tf_e_1,multiple_e_1,short_gk_e_1;
   string ans_gk1;
   string sure_1,sure_2;
  while(true){
cout<<"\n\t\t\tGENERAL KNOWLEDGE\n";
cout<<"\t\tLET'S CHALLENGE YOUR GENERAL KNOWLEDGE!!!\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"Which Category Would You Prefer"<<endl;
cout<<"----------------------------------------\n---------------------------------------\n";
cout<<"1.Entertainment\n2.Sport\n3.Geography\n4.Educational\n5.Exit\n6.Back To Main Menu\n7.Total Score\n";
cin>>ch_gk1;
if(ch_gk1==1){
system("cls");
//case 1:
cout<<"ENTER TRUE OR FALSE TO SUBMMIT YOUR ANSWER\n\n";
cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
cout<<"ENTERTAINMENT\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"LET'S HAVE SOME FUN\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n\n";
cout<<"1.True or False\n2.Multiple Choice\n3.Short Answer\n";
cin>>ch_gk_e_2;
system("cls");}
if (ch_gk_e_2==1){

//true or false for entertainment
//****************************************************************************

//case 1:
cout<<"ENTER TRUE OR FALSE TO SUBMMIT YOUR ANSWER\n\n";
cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
const char *query="SELECT * FROM entertain_1";//* selects all the given column
entertainment1=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(entertainment1== SQLITE_OK){
    while(entertainment1=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,1);
 cout<<QUESTION<<": ";
 cin>>tf_e_1;
 for(int i=0;i<tf_e_1.length();i++){
 tf_e_1[i]=tolower(tf_e_1[i]);
 }
// tf_1=toupper(tf_1);
 if(tf_e_1==questgk_e_t[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_e1_t++;

}
else if(tf_e_1=="*")
main();
else
cout<<"\nWRONG ANSWER!!\n\n";

i++;
}
}
}

   cout<<"----------------------------------------\n---------------------------------------\n";
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_e1_t<<"!!!"<<endl<<endl;
   cout<<"\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");

}
else if (ch_gk_e_2==2){
 cout<<"ENTER ONE OF THE CHOICES TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
 const char *query="SELECT * FROM entertain_2";//* selects all the given column
entertainment2=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(entertainment2== SQLITE_OK){
    while(entertainment2=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
 cout<<QUESTION<<": "<<endl;
CHOICE=sqlite3_column_text(stmt,2);
cout<<CHOICE<<endl;
 cin>>multiple_e_1;
 for(int i=0;i<multiple_e_1.length();i++){
 multiple_e_1[i]=tolower(multiple_e_1[i]);
 }                    //accepting answer
 if(multiple_e_1==questgk_e_m[i]){
 cout<<"\nAMAZING!!!"<<endl<<endl;
 counter_gk_e1_m++;

}
else if(multiple_e_1=="*")
main();
else{
cout<<"\nWRONG ANSWER!!\n\n";
cout<<"The correct answer is:"<<questgk_e_m[i]<<endl<<endl;}

  i++;}
}

system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_e1_m<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}

//*************************************************************************************
//short answer for entertainment category
}
 else if (ch_gk_e_2==3){
 cout<<"ENTER YOUR ANSWER ON THE PROVIDED SPACE TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT RETURN TO MENU....................\n\n";
 const char *query="SELECT * FROM entertain_3";//* selects all the given column
entertainment3=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(entertainment3== SQLITE_OK){
    while(entertainment2=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
 cout<<QUESTION<<": "<<endl;
 while(trials_e_s<3&&short_gk_e_1!=questgk_e_s[i]){
 getline(cin,short_gk_e_1);
 for(int i=0;i<short_gk_e_1.length();i++){
 short_gk_e_1[i]=tolower(short_gk_e_1[i]);
 }
 if(short_gk_e_1==questgk_e_s[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_e1_s++;
goto label_e2;
}

else if(short_gk_e_1=="*")
   main();
else if(short_gk_e_1!=questgk_e_s[i]){
   if(trials_e_s==0){
   cout<<"\nINCORRECT!!!\n\nTRY AGAIN!!!\n";}
   if(trials_e_s==1){
   cout<<"\nINCORRECT!!!\n\nTRY AGAIN!!!\n";
   }
   //cout<<"\nHint: "<<questgk_e_s[i][2]<<endl<<endl;}
   else if(trials_e_s==2){
   cout<<"\nINCORRECT!!!\n"<<endl;
   cout<<"The correct answer is:"<<questgk_e_s[i][1]<<endl<<endl;}
    }}
   label_e2:
   label_e:
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
}
system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_e1_s<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
i++;}}

  }
else if(ch_gk1==2){

system("cls");
cout<<"SPORT\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"LET'S HAVE SOME FUN\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n\n";
cout<<"1.True or False\n2.Multiple Choice\n3.Short Answer\n";
cin>>ch_gk_e_2;
system("cls");

//************************************************************************************
//true or false for sport

if (ch_gk_e_2==1){
cout<<"ENTER TRUE OR FALSE TO SUBMMIT YOUR ANSWER\n\n";
cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
const char *query="SELECT * FROM sport_1";//* selects all the given column
sport1=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(sport1== SQLITE_OK){
    while(sport1=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,1);
 cout<<QUESTION<<": ";
 for(int i=0;i<tf_e_1.length();i++){
 tf_e_1[i]=tolower(tf_e_1[i]);
 }
// tf_1=toupper(tf_1);
 if(tf_e_1==questgk_s_t[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_s1_t++;
}
else if(tf_e_1=="*")
main();
else
cout<<"\nWRONG ANSWER!!\n\n";


}}i++;
}
   cout<<"----------------------------------------\n---------------------------------------\n";
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_s1_t<<"!!!"<<endl<<endl;
   cout<<"\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}


else if (ch_gk_e_2==2){
 cout<<"ENTER ONE OF THE CHOICES TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
 const char *query="SELECT * FROM sport_2";//* selects all the given column
sport2=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(sport2== SQLITE_OK){
    while(sport2=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
CHOICE=sqlite3_column_text(stmt,2);
 cout<<QUESTION<<": "<<endl;
 cout<<CHOICE<<endl;
 cin>>multiple_e_1;
 for(int i=0;i<multiple_e_1.length();i++){
 multiple_e_1[i]=tolower(multiple_e_1[i]);
 }                    //accepting answer
 if(multiple_e_1==questgk_s_m[i]){
 cout<<"\nAMAZING!!!"<<endl<<endl;
 counter_gk_s1_m++;

}
else if(multiple_e_1=="*")
main();
else{
cout<<"\nWRONG ANSWER!!\n\n";
cout<<"The correct answer is:"<<questgk_s_m[i]<<endl<<endl;}


}
i++;}
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_s1_m<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}

//**************************************************************************************
//short answer for sport category
}
 else if (ch_gk_e_2==3){
 cout<<"ENTER YOUR ANSWER ON THE PROVIDED SPACE TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT RETURN TO MENU....................\n\n";
  const char *query="SELECT * FROM sport_3";//* selects all the given column
sport3=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(sport3== SQLITE_OK){
    while(sport3=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
 cout<<QUESTION<<": "<<endl;
 for(int j=0;j<2;j++){
 getline(cin,short_gk_e_1);
 for(int i=0;i<short_gk_e_1.length();i++){
 short_gk_e_1[i]=tolower(short_gk_e_1[i]);
 }
 if(short_gk_e_1==questgk_s_s[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_s1_s++;
break;
}

else if(short_gk_e_1=="*")
    main();

else{
   if(j==1){
   cout<<"\nINCORRECT!!!\n\nTRY AGAIN!!!\n";
  // cout<<"\nHint: "<<questgk_s_s[i][2]<<endl<<endl;}
}
   else if(j==2){
   cout<<"\nINCORRECT!!!\n"<<endl;
   cout<<"The correct answer is:"<<questgk_s_s[i]<<endl<<endl;}
    }}}
   label_s:
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
i++;}}
system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_s1_s<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");

}


}
else if(ch_gk1==3){
             system("cls");
cout<<"GEOGRAPHY\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"LET'S HAVE SOME FUN\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n\n";
cout<<"1.True or False\n2.Multiple Choice\n3.Short Answer\n";
cin>>ch_gk_e_2;
system("cls");

//************************************************************************************
//true or false for geography


if (ch_gk_e_2==1){
cout<<"ENTER TRUE OR FALSE TO SUBMMIT YOUR ANSWER\n\n";
cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
const char *query="SELECT * FROM geography_1";//* selects all the given column
geography1=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(geography1== SQLITE_OK){
    while(geography1=sqlite3_step(stmt)== SQLITE_ROW)
{
 QUESTION=sqlite3_column_text(stmt,1);
 cout<<QUESTION<<": ";
 cin>>tf_e_1;
 for(int i=0;i<tf_e_1.length();i++){
 tf_e_1[i]=tolower(tf_e_1[i]);
 }
// tf_1=toupper(tf_1);
 if(tf_e_1==questgk_g_t[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_g1_t++;
}
else if(tf_e_1=="*")
main();
else
cout<<"\nWRONG ANSWER!!\n\n";

i++;}}}
   cout<<"----------------------------------------\n---------------------------------------\n";
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_g1_t<<"!!!"<<endl<<endl;
   cout<<"\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}
else if (ch_gk_e_2==2){
 cout<<"ENTER ONE OF THE CHOICES TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
 const char *query="SELECT * FROM geography_2";//* selects all the given column
geography2=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(geography2== SQLITE_OK){
    while(geography2=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
CHOICE=sqlite3_column_text(stmt,2);
 cout<<QUESTION<<": "<<endl;
 cout<<CHOICE<<endl;
 cin>>multiple_e_1;
 for(int i=0;i<multiple_e_1.length();i++){
 multiple_e_1[i]=tolower(multiple_e_1[i]);
 }                    //accepting answer
 if(multiple_e_1==questgk_g_m[i]){
 cout<<"\nAMAZING!!!"<<endl<<endl;
 counter_gk_g1_m++;

}
else if(multiple_e_1=="*")
main();
else{
cout<<"\nWRONG ANSWER!!\n\n";
cout<<"The correct answer is:"<<questgk_g_m[i]<<endl<<endl;}


}
i++;}
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_g1_m<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}

//**************************************************************************************
//short answer for geography category
}
 else if (ch_gk_e_2==3){
 cout<<"ENTER YOUR ANSWER ON THE PROVIDED SPACE TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT RETURN TO MENU....................\n\n";
 const char *query="SELECT * FROM geography_3";//* selects all the given column
geography3=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(geography3== SQLITE_OK){
    while(geography3=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
 cout<<QUESTION<<": "<<endl;
 for(int j=0;j<3;j++){
 getline(cin,short_gk_e_1);
 for(int i=0;i<short_gk_e_1.length();i++){
 short_gk_e_1[i]=tolower(short_gk_e_1[i]);
 }
 if(short_gk_e_1==questgk_g_s[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_g1_s++;
break;
}

else if(short_gk_e_1=="*")
    main();

else{
   if(j==1){
   cout<<"\nINCORRECT!!!\n\nTRY AGAIN!!!\n";
   //cout<<"\nHint: "<<questgk_g_s[i][2]<<endl<<endl;}
}
   else if(j==2){
   cout<<"\nINCORRECT!!!\n"<<endl;
   cout<<"The correct answer is:"<<questgk_g_s[i]<<endl<<endl;}
    }}
   label_g:
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
i++;}}}
system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_g1_s<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");


}
}
else if(ch_gk1==4){


system("cls");
cout<<"EDUCATIONAL\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
cout<<"LET'S HAVE SOME FUN\n";
cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n\n";
cout<<"1.True or False\n2.Multiple Choice\n3.Short Answer\n";
cin>>ch_gk_e_2;

system("cls");

//************************************************************************************
//true or false for educational

if (ch_gk_e_2==1){
cout<<"ENTER TRUE OR FALSE TO SUBMMIT YOUR ANSWER\n\n";
cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
const char *query="SELECT * FROM education_1";//* selects all the given column
education1=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(education1== SQLITE_OK){
    while(education1=sqlite3_step(stmt)== SQLITE_ROW)
{
 QUESTION=sqlite3_column_text(stmt,1);
 cout<<QUESTION<<": ";
 cin>>tf_e_1;
 for(int i=0;i<tf_e_1.length();i++){
 tf_e_1[i]=tolower(tf_e_1[i]);
 }
// tf_1=toupper(tf_1);
 if(tf_e_1==questgk_ed_t[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_ed1_t++;
}
else if(tf_e_1=="*")
main();
else
cout<<"\nWRONG ANSWER!!\n\n";

i++;}}
   cout<<"----------------------------------------\n---------------------------------------\n";
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_ed1_t<<"!!!"<<endl<<endl;
   cout<<"\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}}
//**************************************************************************************
//multiple choice for educational category

 if (ch_gk_e_2==2){
 cout<<"ENTER ONE OF THE CHOICES TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT AND RETURN TO MENU....................\n\n";
  const char *query="SELECT * FROM education_2";//* selects all the given column
education2=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(education2== SQLITE_OK){
    while(education2=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
CHOICE=sqlite3_column_text(stmt,2);
 cout<<QUESTION<<": "<<endl;
 cout<<CHOICE<<endl;
 cin>>multiple_e_1;
 for(int i=0;i<multiple_e_1.length();i++){
 multiple_e_1[i]=tolower(multiple_e_1[i]);
 }                    //accepting answer
 if(multiple_e_1==questgk_ed_m[i]){
 cout<<"\nAMAZING!!!"<<endl<<endl;
 counter_gk_ed1_m++;

}
else if(multiple_e_1=="*")
main();
else{
cout<<"\nWRONG ANSWER!!\n\n";
cout<<"The correct answer is:"<<questgk_ed_m[i]<<endl<<endl;}



i++;}}}
   system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_ed1_s<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
}

//**************************************************************************************
//short answer for educational category

 if (ch_gk_e_2==3){
 cout<<"ENTER YOUR ANSWER ON THE PROVIDED SPACE TO SUBMMIT YOUR ANSWER\n\n";
 cout<<"ENTER * KEY TO EXIT RETURN TO MENU....................\n\n";
 const char *query="SELECT * FROM education_3";//* selects all the given column
education3=sqlite3_prepare_v2(dbgk,query,-1, &stmt, nullptr);
for(int i=0;i<6;){
    if(education3== SQLITE_OK){
    while(education3=sqlite3_step(stmt)== SQLITE_ROW)
{
QUESTION=sqlite3_column_text(stmt,0);
 cout<<QUESTION<<": "<<endl;

 for(int j=0;j<3;j++){
 getline(cin,short_gk_e_1);
 for(int i=0;i<short_gk_e_1.length();i++){
 short_gk_e_1[i]=tolower(short_gk_e_1[i]);
 }
 if(short_gk_e_1==questgk_ed_s[i]){
cout<<"\nAMAZING!!!"<<endl<<endl;
counter_gk_ed1_s++;
break;
}

else if(short_gk_e_1=="*")
   main();

else{
   if(j==1){
   cout<<"\nINCORRECT!!!\n\nTRY AGAIN!!!\n";
  // cout<<"\nHint: "<<questgk_ed_s[i][2]<<endl<<endl;}
}
   else if(j==2){
   cout<<"\nINCORRECT!!!\n"<<endl;
   cout<<"The correct answer is:"<<questgk_ed_s[i]<<endl<<endl;}
    }}
   label_ed:
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
i++;}}}
system("cls");
   cout<<"\n\n\n\n\t\tCOMPLETE!!!\n\n";
   cout<<"\t\tYOU HAVE SCORED\n\n";
   cout<<"\t\t"<<counter_gk_ed1_s<<"!!!"<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");

 }}
else if(ch_gk1==5){

exit(0);}
else if(ch_gk1==6){

    main();

}
else if(ch_gk1==7){


counter_gk_tot1=counter_gk_e1_t+counter_gk_e1_m+counter_gk_e1_s+counter_gk_s1_t+counter_gk_s1_m+counter_gk_s1_s+counter_gk_g1_t+counter_gk_g1_m+counter_gk_g1_s+counter_gk_ed1_t+counter_gk_ed1_m+counter_gk_ed1_s;
   system("cls");
   cout<<"\n\n\n\n\t\t\tTOTAL SCORE\n\n";
   cout<<"------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------\n";
   cout<<"\n\t\t\tYOU HAVE SCORED:\n\n";
   cout<<"\t\t\t\t"<<counter_gk_tot1<<endl<<endl;
   cout<<"\t\tPRESS ANY KEY TO RETURN TO THE MENU...............\n";
   cin>>press_key;
   system("cls");
  }
  }
  }// choice 4





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
    if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   entertainment1=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS entertain_1(question_id INT,question TEXT, answer TEXT, hint TEXT, choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   entertainment2=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS entertain_2(question TEXT, answer TEXT,choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   entertainment3=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS entertain_3(question TEXT, answer TEXT,hint TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}

if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   sport1=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS sport_1(question_id INT,question TEXT, answer TEXT, hint TEXT, choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   sport2=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS sport_2(question TEXT, answer TEXT,choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   sport3=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS sport_3(question TEXT, answer TEXT,hint TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}

if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   geography1=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS geography_1(question_id INT,question TEXT, answer TEXT, hint TEXT, choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
    if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   geography2=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS geography_2(question TEXT, answer TEXT,choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
    if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   geography3=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS geography_3(question TEXT, answer TEXT, hint TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}

if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   education1=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS education_1(question_id INT,question TEXT, answer TEXT, hint TEXT, choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   education2=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS education_2(question TEXT, answer TEXT,choice TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
if (sqlite3_open("questions_1.db", &dbgk)== SQLITE_OK)
{
   education3=sqlite3_prepare_v2(dbgk,"CREATE TABLE IF NOT EXISTS education_1(question TEXT, answer TEXT, hint TEXT);",-1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);}
}


