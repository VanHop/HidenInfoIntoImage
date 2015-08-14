#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Information_Hiding.h"
#include "Split.h"
using namespace std;
void InformationHidingScreen(){
	system("cls");
	cout << endl;
	cout << "\t|----------------------------------------------------------------|" << endl;
	cout << "\t|              Welcome To Program Of Covered Writing             |" << endl;
	cout << "\t|----------------------------------------------------------------|" << endl << endl << endl;
	cout << "\t--------------------------Hiding Code----------------------------" << endl;
	cout << endl << endl;
	
	string pathImage;
	cout << "\tPath of image file: (require type of file .bmp)\n\n\t\t";
	cin >> pathImage;
	if(!(pathImage[pathImage.length()-1] == 'p' && pathImage[pathImage.length()-2] == 'm' && pathImage[pathImage.length()-3] == 'b')){
		cout << "\n\tType of file is not .bmp";
		return;
	}
	
	
	string pathText;
	cout << "\tPath of text file: \n\n\t\t";
	cin >> pathText;
	if(!(pathText[pathText.length()-1] == 't' && pathText[pathText.length()-2] == 'x' && pathText[pathText.length()-3] == 't')){
		cout << "\n\tType of file is not .txt";
		return;
	}
	
	
	cout << "\n\t\tExecuting";
	for(int i = 0;i < 5; i++){
		Sleep(500);
		cout << ".";
	}
	
	ifstream input;
	input.open(pathText.c_str(), ios::binary);
	if(!input){
		cout << "\n\t\tPath of Text File is incorrect!";
		return;
	}
	string s;
	while(input.good()){
		char c = input.get();
		if(c != 10)
			s += c;
	}
	cout << "Key: " << (s.length() - 1)* 8;
	Information_Hiding hiding(pathImage.c_str(),s);
	hiding.Start();
}
void SplitScreen(){
	system("cls");
	string path;
	cout << endl;
	cout << "\t|----------------------------------------------------------------|" << endl;
	cout << "\t|              Welcome To Program Of Covered Writing             |" << endl;
	cout << "\t|----------------------------------------------------------------|" << endl << endl << endl;
	cout << "\t---------------------------Get Code------------------------------" << endl;
	cout << endl << endl;
	cout << "\tPath of image file: (require type of file .bmp)\n\n\t\t";
	cin >> path;
	int key;
	cout << "\tType Value Of Key: \n\n\t\t";
	cin >> key;
	cout << "\n\t\tExecuting";
	for(int i = 0;i < 5; i++){
		Sleep(500);
		cout << ".";
	}
	Split split(path.c_str(), key);
	split.getMessage();
}
int main(){
	bool out = false;
	while(true){
		system("cls");
		cout << endl;
		cout << "\t|----------------------------------------------------------------|" << endl;
		cout << "\t|              Welcome To Program Of Covered Writing             |" << endl;
		cout << "\t|----------------------------------------------------------------|" << endl;
		cout << endl << endl;
		cout << "\t|+++++++++++++++++++++++++++++++MENU+++++++++++++++++++++++++++++|" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|       Make a choice, please!                                   |"<< endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|                 + 1 : Infomation Hiding                        |" << endl;
		cout << "\t|                 + 2 : Infomation Spliting                      |" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
		cout << endl << endl;
		int choice;
		while(true){
			bool check = false;
			cout << "\t\tChoice: ";
			cin >> choice;
			switch(choice){
				case 1:
					InformationHidingScreen();
					break;
				case 2:
					SplitScreen();
					break;
				default:
					if(choice == 27)	out = true;
					else{
						cout << "\t\tChoice isn't Invalid, Please type again!" << endl;
						check = true;
					}
					break;
			}
			cin.clear();
			fflush(stdin);
			if(check == false) break;
		}
		
		cout << "\n\n\tPress Enter to continue...\n";
		cin.get();
		if(out)	break;
	}
}
