#pragma once
#include <string>
#include<fstream>
#include<vector>

using namespace std;   //надо разработать

template<class T>
class FileManager
{
public:
	FileManager(string nameSh);
	void readFile(vector<T> &vec);
	void writeFile(vector<T> &vec);
	~FileManager() {}

private:
	string name;
};

template<class T>
inline FileManager<T>::FileManager(string nameSh) : name(nameSh)
{
	ofstream fout(name, ios_base::app);
	fout.close();
}

template<class T>
inline void FileManager<T>::readFile(vector<T>& vec)
{
	ifstream fin(name);

}

template<class T>
inline void FileManager<T>::writeFile(vector<T>& vec)
{
}
