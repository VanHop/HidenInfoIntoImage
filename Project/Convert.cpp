#include "Convert.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

char Convert::ConvertToChar(char encode[],bool isChange){
	int code = 0;
	for(int i=0;i<8;i++)
		code += (encode[i] - '0') * pow(2,7-i);
	if(isChange)	code = 0-code;
	return (char)code;
}
void Convert::ConvertToBinary(int ascii, char binary[])
{
	char reversed_binary[8];
	int index = 0;
	if(ascii == 0)
		for(int i = 0; i < 8; i++)
			binary[i] = '0';
	else{
		while(ascii != 1)	{
			if(ascii % 2 == 0)		reversed_binary[index] = '0';	
			else if(ascii % 2 == 1)		reversed_binary[index] = '1';
			index++;
			ascii /= 2;
		}
		if(ascii == 1){
			reversed_binary[index] = '1';
			index++;
		}
		while (index < 8){
			reversed_binary[index] = '0';
			index++;
		}
		for(int a = 0; a < 8; a++)
			binary[a] = reversed_binary[7 - a];
	}
}
