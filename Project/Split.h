#include <iostream>
#include <string>
using namespace std;
class Split{
	private:
		int key;
		const char* path;
	public:
		Split(const char*, int key);
		void getMessage();
};
