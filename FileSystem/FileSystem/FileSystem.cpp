#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

int main()
{
    string folder = "./files";
	string filename = "text";

	if (!fs::exists("files"))
	{
		fs::create_directory("files");
		cout << "Folder	'files' is been created!\n";
	}
	for (int i = 0; i < 10; i++)
	{
		ofstream outFile(folder + "/" + filename + to_string(i) + ".txt");
		outFile << "Hello world!\n";
		outFile.close();
	}


    cout << "Files at: " << folder << ":\n";

	for (const auto& entry : fs::directory_iterator(folder))
	{
		cout << entry.path().filename() << endl << "It contains:\n";
		ifstream inFile(folder + "/" + filename);
		string content;
		getline(inFile, content);
		cout << content << endl;
		inFile.close();

	}
	return 0;
}