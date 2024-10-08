#include <iostream>
#include<random>
#include <cstdlib>
using namespace std;


enum enChoices{STONE =1,PApER =2,SCISSORS =3};

int RandomNumber(int From, int To){

//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

int Read_Number_Rounds(){



int number;

cout<<"How Many Rounds 1 to 10 ? \n";
cin>>number;
return number;
}
int Choice_Computer(){
int choiceComputer=RandomNumber(1,3);
return choiceComputer;
}

int Choice_Person(){
int ChoicePerson;
 cout<<"Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
    cin>>ChoicePerson;
    return ChoicePerson;
}

string Determind_Winner(int choice_computer,int choice_person){
  if(choice_computer==choice_person)return "[Equal]";

if(choice_computer==1&&choice_person==2){return "[Person]";}
if(choice_computer==1&&choice_person==3){return "[Computer]";}
if(choice_computer==2&&choice_person==1){return "[omputer]";}
if(choice_computer==2&&choice_person==3){return "[Person]";}
if(choice_computer==3&&choice_person==1){return "[Person]";}
if(choice_computer==3&&choice_person==2){return "[Computer]";}

}

 bool Do_Repeat_Game(){
  char repeat_game;
cout<<"Do you want repeat game if yes enter (y) else (n) ?\n\n";
cin>>repeat_game;
if (int(repeat_game)==89||int(repeat_game)==121)
{
  cout<<"\n\n";
  system("cls");
  system("color 0");
return true;
}

return false;
}

void Print_Result_Rounds(int number_round,int won_person,int won_computer){
cout<<"\t__________________________________________________________________\n";
cout<<"\t                *** G a m e  O v e r ***\n";
cout<<"\t__________________________________________________________________\n";
cout<<"\t_____________________[ Game Results ]_________________________\n";
cout<<"\tGame rounds:"<<number_round<<" \n";
cout<<"\tPerson won time:"<<won_person<<" \n";
cout<<"\tcomputer won times:"<<won_computer<<" \n";
if(won_computer==won_person){cout<<"\tFinal Winner: No Thing\n";
     system("color 67");  }
else if(won_computer>won_person){

cout<<"\tFinal Winner:Computer \n";
system("color 4F");
cout<<"\a";}

else {cout<<"\tFinal Winner: Person \n";
system("color 2F");}
cout<<"\t__________________________________________________________________\n\n";
//Do_Repeat_Game();
}

  void PrintResultEveryRound(){
int won_person=0;
int won_computer=0;

int number_rounds=Read_Number_Rounds();

int i=1;
while(i<=number_rounds){
  cout<<"Round ["<<i<<"] begins :\n";

int   choice_person=  Choice_Person();
int  choice_computer=  Choice_Computer();
string determind_winner=Determind_Winner(choice_computer,choice_person);
    cout<<"\n\n";
   cout<<"____________________Round ["<<i<<"]_____________________\n";
    cout<<"Player choice :"<<(enChoices)choice_person<<endl;
    cout<<"Computer choice :"<<(enChoices)choice_computer<<endl;
    cout<<"Round Winner :"<<determind_winner<<"\n\n";
    cout<<"______________________________________________________\n\n";

if(determind_winner=="[Computer]"){
        cout<<"\a";
        system("color 4F");
        won_computer++;}
else {won_person++;
system("color 2E");}

 i++;
}

Print_Result_Rounds(number_rounds,won_person,won_computer);
}







int main()
{

 do{

   PrintResultEveryRound();

 }while(Do_Repeat_Game());









    return 0;
}
