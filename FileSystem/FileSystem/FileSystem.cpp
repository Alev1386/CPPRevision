#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = filesystem;


void createFile(const string& _folder);
void writeToFile(const string& _folder);
vector<fs::path> showFiles(const string& _folder);
void readFile(const string& _folder);
void removeFile(const string& _folder);


int main()
{
    string folder = "./files";
	string filename;

	if (!fs::exists("files"))
	{
		fs::create_directory("files");
		cout << "Folder	'files' is been created!\n";
	}
	int option = 0;
	while (option != 6)
	{
		cout << "1.Create file\n2.Write to file\n3.Read file\n4.Remove file\n5.Show files\n6.Exit\n";
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (option)
		{
		case 1:
			createFile(folder);
			break;
		case 2:
			writeToFile(folder);
			break;
		case 3:
			readFile(folder);
			break;
		case 4:
			removeFile(folder);
			break;
		case 5:
			showFiles(folder);
			break;
		case 6:
			break;
		default:
			break;
		}
	}

	return 0;
}

void createFile(const string& _folder) {
	string name;
	cout << "Enter the name of file" << endl;
	getline(cin, name);
	ofstream outFile(_folder + "/" + name);
	outFile.close();
}
void writeToFile(const string& _folder){
	string name;
	string data;

	cout << "Enter the name of file" << endl;
	getline(cin, name);

	cout << "Enter the text" << endl;
	getline(cin, data);

	string filePath = _folder + "/" + name;

	ofstream outFile(filePath);
	outFile << data << endl;
	outFile.close();
}
vector<fs::path> showFiles(const string& _folder) {
	std::vector<fs::path> files;
	int counter = 1;
	for (const auto& entry : fs::directory_iterator(_folder))
	{
		if (fs::is_regular_file(entry)) {
			cout << counter << ". " << entry.path().filename() << endl;
			files.push_back(entry.path());
			++counter;
		}
	}
	cout << "\n\n\n";
	return files;
}
void readFile(const string& _folder) {
	vector<fs::path> files = showFiles(_folder);
	int option = 0;
	cout << "Enter the index of file! (1-" << files.size()+1 << ")" << endl;
	while (option < 1 || option > files.size())
	{
		cin >> option;
	}

	fs::path fileName = files[option - 1];

	cout << "Opening file: " << fileName << endl;

	ifstream file(fileName);
	if (file) {
		string line;
		while (getline(file, line)) {
			cout << line << std::endl;
		}
	}
	else {
		cerr << "Error opening the file!" << std::endl;
	}
}

void removeFile(const string& _folder) {
	vector<fs::path> files = showFiles(_folder);
	int option = 0;
	cout << "Enter the index of file! (1-" << files.size() + 1 << ")" << endl;
	while (option < 1 || option > files.size())
	{
		cin >> option;
	}

	fs::remove(files[option-1]);
}