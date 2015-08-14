#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "Split.h"
#include "Convert.h"
Split::Split(const char* path,int key){
	this->path = path;
	this->key = key;
}
void Split::getMessage(){
	ifstream CoverData;
	CoverData.open(path, ios::binary);
	if(!CoverData){
		cout << "\n\t\tPath of File is incorrect!";
		return;
	}
	Convert convert;
	char CharOfMessBinary[8] = {'\0'};
	int index = 0;
	int counter = 0;
	int a =0;
	string s = "";
	bool loop = true;
	while(loop)
	{
		bool isChange = false;
		char CharOfImageBinary[8] = {'\0'};
		char c = CoverData.get();
		
		if(a >= 55 && counter < key){
			int ascii = (int)c;
			int _ascii = abs(ascii);
			if(ascii != _ascii)	isChange = true;
			convert.ConvertToBinary(_ascii, CharOfImageBinary);
			CharOfMessBinary[index] = CharOfImageBinary[7];
			index++;
			if(index == 8) {
				s += convert.ConvertToChar(CharOfMessBinary, false);
				//CharOfMessBinary[8] = {'\0'};
				index = 0;
			}
			counter++;
		}
		else{
			if(counter >= key) loop = false;
		}
		a++;
	}
	string ss = s + "";
	ofstream output;
	output.open("../text/Information_Hiding/text.txt");
	output << ss.c_str();
	output.close();
	cout << "\n\t\tComplete !^^" << endl;
}
