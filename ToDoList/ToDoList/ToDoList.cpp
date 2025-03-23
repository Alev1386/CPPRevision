#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addTask(vector<string>& tasks);
void showTasks(vector<string>& tasks);
void removeTask(vector<string>& tasks);

int main()
{
    vector<string> list;
    int option = 0;
    while (option != 4)
    {
        cout << "1. Add task\n2. Show tasks\n3. Delete task\n4. Exit\n\n\n";
        cin >> option;

        switch (option)
        {
        case 1:
            addTask(list);
            break;
        case 2:
            showTasks(list);
            break;
        case 3:
            removeTask(list);
        case 4:
            break;
        default:
            break;
        }
    }

}

void addTask(vector<string>& tasks) {
    string inp;
    cout << "Enter the task:" << endl;
    getline(cin >> ws, inp);
    tasks.push_back(inp);
    cout << "Task '" << inp << "' added successfully!\n\n" << endl;
}

void showTasks(vector<string>& tasks) {
    cout << "Your tasks: " << endl;
    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks.at(i) << endl;
    }
}

void removeTask(vector<string>& tasks) {
    showTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the number of task to delete:";
    int index;
    cin >> index;

    if (index > 0 && index < tasks.size())
    {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task successfully removed!\n\n" << endl;
    }
    else {
        cout << "Invalid task number!\n\n" << endl;
    }
}

