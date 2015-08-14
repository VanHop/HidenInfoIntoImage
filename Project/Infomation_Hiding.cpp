#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include "Information_Hiding.h"
#include "Convert.h"
Information_Hiding::Information_Hiding(const char* path, string message){
	this->path = path;
	this->message = message;
}
Information_Hiding::~Information_Hiding(){}
void Information_Hiding::Start(){
	
	
	ifstream CoverData;
	ofstream StegoData;
	StegoData.open("../image/HidingData/StagoData.bmp", ios::binary);
	CoverData.open(path, ios::binary);
	if(!CoverData){
		cout << "\n\t\tPath of Image File is incorrect!";
		return;
	}

	Execute(CoverData,StegoData);
	if(StegoData.is_open()){
		StegoData.close();
	}
	if(CoverData.is_open())	{
		CoverData.close();
		cout<<"\n\n\t\tComplete !^^";
	}
}
void Information_Hiding::Execute(ifstream &CoverData, ofstream &StegoData){
	Convert convert;
	int in = 0;
	int index = 0;
	int counter = 0;
	char CharOfMessBinary[8] = {'\0'};
	while(CoverData.good())
	{
		bool isChange = false;
		char CharOfImageBinary[8] = {'\0'};
		char c = CoverData.get();
		int ascii = (int)c;
		int _ascii = abs(ascii);
		if(ascii != _ascii)	isChange = true;
		convert.ConvertToBinary(_ascii, CharOfImageBinary);
		if(counter >= 55){
			bool flag = false;
			//-----------------------------------------------------//
			if(index == 0 && in < message.length()-1){
				char encodeChar = message[in];
				int asc = (int)encodeChar;
				convert.ConvertToBinary(asc, CharOfMessBinary);
				flag = true;
			}
			if(in >= message.length() -1 ){
				index = -1;
			}	
			//------------------------------------------------------//
			if(index != -1){
				CharOfImageBinary[7] = CharOfMessBinary[index];
				StegoData << convert.ConvertToChar(CharOfImageBinary,isChange);
			}
			else	StegoData << c;
			if(index != -1){
				index++;
				if(index == 8){
					index = 0;
					in++;
				}
			}
			
		}
		if(counter < 55)
			StegoData << c;
		counter++;
	}
}
