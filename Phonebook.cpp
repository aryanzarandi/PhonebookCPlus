#include <bits/stdc++.h>
#include"conio.h"
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Contact{
public:
string name;
string phone;
void ReadAll(){

fstream file_name;

  file_name.open("Contacts.txt", ios::in);
  if (file_name.fail()){
    cout << "Error !";
    exit( 1 );

  }
  else{
    char str[80];

  while (!file_name.eof())
  {
    file_name.getline(str, 81);
    cout << str << endl;
    cout<<"****************"<<endl;

}
file_name.close();

  }

}
void Add()
{

cout<<"Enter The Name Continusly not Seperated"<<endl;
cin>>name;
cout<<"Enter The Phone"<<endl;
cin>>phone;


ofstream myFile;
myFile.open("Contacts.txt",ios::app);
  if (myFile.fail())
  cout << "Error !";
   myFile << name << ' ';
   myFile << phone <<'\n';

  myFile.close();
  cout<<"Added"<<endl;

}
string SerachContacts(){
 ifstream file_name("Contacts.txt");

    string number;
    string  name, search_name;
    bool found = false;

    cout << "Enter a name Or phone number To Search: ";
    cin >> search_name;
    cout << endl;

    while(file_name >> number) {

        file_name >> name;

        if(name == search_name||number==search_name) {
            cout << name << " : " << number << endl;
            found = true;
            return (number);
            break;
        }
    }

    if(found == false){


        cout << search_name << " NOT EXIST" << endl;
        return("NOTFOUND");
    }
file_name.close();
}



 int Get_line(const char *file_name,string _serach)

 {
  unsigned int curLine = 0;
 int count = 0;
    string line;

    ifstream file(file_name);
    while (getline(file, line))
        {
        curLine++;
        count++;
        if (line.find(_serach, 0) != string::npos) {
        cout << "found:  " << _serach << "  in  line: " << curLine << endl;
       return curLine;
    }

        }

 }



void delete_line(const char *file_name, int n)
{
	// open file in read mode or in mode
	ifstream is(file_name);

	// open file in write mode or out mode
	ofstream ofs;
	ofs.open("temp.txt", ofstream::out);

	// loop getting single characters
	char c;
	int line_no = 1;
	while (is.get(c))
	{
		// if a newline character
		if (c == '\n')
		line_no++;

		// file content not to be deleted
		if (line_no != n)
			ofs << c;
	}

	// closing output file
	ofs.close();

	// closing input file
	is.close();

	// remove the original file
	remove(file_name);

	// rename the file
	rename("temp.txt", file_name);
}



void DeleteContacts()
{

    cout<<"DELETE"<<endl;
   string s= SerachContacts();
   cout << endl;
if(s=="NOTFOUND"){

      cout <<" NOT EXIST Such User" << endl;

}
else
{

int linenumber= Get_line("Contacts.txt",s);
 delete_line("Contacts.txt",linenumber);
 cout<<"DELETED SUCCSEFULLY"<<endl;


}
}


void EditContacts()
{
 cout<<"EDIT"<<endl;
   string s= SerachContacts();
   cout << endl;
if(s=="NOTFOUND"){

      cout <<" NOT EXIST Such User" << endl;

}
else
{

int linenumber= Get_line("Contacts.txt",s);
 delete_line("Contacts.txt",linenumber);

Add();
cout<<"EDITED SUCCSEFULLY"<<endl;

}


}




};



int main() {




   system("cls");
   Contact c1;
   int fontcolor;
   cout<<"Choose Font Color Code Please"<<endl;
   cout << "1.Red" << endl;
   cout << "2.Light Blue" << endl;
   cout << "3.Light Green" << endl;
   cout << "4.Light Yellow" << endl;
   cout << "5.Light Aqua" << endl;
   cout << "6.White" << endl;
   cin>>fontcolor;

   switch(fontcolor){
   case 1:{system("color C");break;}
    case 2:{system("color 9");break;}
     case 3:{system("color A");break;}
      case 4:{system("color E");break;}
       case 5:{system("color B");break;}
   case 6:{system("color F");break;}
   default:{
       cout<<"Not Valid Input Run App Again And Choose Correctly"<<endl;
       getch();
       exit(1);
      }
   }
tryagain:




    system("cls");
   int choise=0;
   cout << "-----------In Memories Of All Rained Flower--------" << endl;
   cout << "***************Sepehr Najariyan PhoneBook*********" << endl;
   cout << "MENU" << endl;
   cout << "1.SHOW ALL CONTACTS" << endl;
   cout << "2.ADD CONTACT" << endl;
   cout << "3.Delete CONTACT" << endl;
   cout << "4.Edit CONTACT" << endl;
   cout << "5.SEARCH CONTACTS" << endl;
   cout << "6.EXIT" << endl<< endl<< endl;
   cout << "Enter Your Choise" << endl;
   cin>>choise;

   switch(choise)

   {
   case 1:{
       c1.ReadAll();
       getch();
       goto tryagain;
        break;
        }
   case 2:{
       c1.Add();
       getch();
       goto tryagain;
       break;
       }
   case 3:{
       c1.DeleteContacts();
       getch();
       goto tryagain;
        break;
        }

      case 4:{
          c1.EditContacts();
          getch();
          goto tryagain;
           break;}
   case 5:{

          c1.SerachContacts();
          getch();
          goto tryagain;
           break;}
   case 6:{ cout<<"YOU WILL BE EXITED"<<endl;
   exit(0);
   break;}

   default:{ cout<<"NOT VALID CHOISE";
   getch();
   system("cls");
   goto tryagain;
    break;

    }


}



   return 0;
   }


