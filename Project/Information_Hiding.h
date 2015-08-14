#include <iostream>
#include <string>
using namespace std;
class Information_Hiding{
	private:
		string message;
		const char* path;
	public:
		Information_Hiding(const char*,string);
		~Information_Hiding();
		void Start();
		void Execute(ifstream &, ofstream &);
};
