#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string getInput(string prompt) {
    cout << prompt << ": ";
    string input;
    cin >> input;
    return input;
}

class Task {
private:
    string name;
    string description;
    int id;
    int priority;
    int time;
    bool done = false;
public:
    Task(int num, string newName, string newDesc, int level, int t) {
        id = num;
        name = newName;
        description = newDesc;
        priority = level;
        time = t;
    }
    string getName() {
        return name;
    }
    int getPriority() {
        return priority;
    }

    int getId() {
        return id;
    }

    int getTime() {
        return time;
    }

    string getDesc() {
        return description;
    }
    string getFormattedTime() {
        int minutes = time % 60;
        int hours = time / 60;
        string timeString = to_string(minutes) + " mins";
        if (hours > 0) {
            timeString = to_string(hours) + " hours " + timeString;
        }
        return timeString;
    }
    string getStatus() {
        return done ? "DONE" : "INCOMPLETE";
    }
    void markAsDone() {
        done = true;
    }
    void setPriority(int lvl) {
        priority = lvl;
    }
    void setName(string newName) {
        name = newName;
    }
    void setDesc(string d) {
        description = d;
    }
};

class TaskList {
    vector<Task> list;
public:
    void addTask(int id, string name, string desc, int lvl, int time) {
        Task t(id, name, desc, lvl, time);
        list.push_back(t);
    }

    void markTaskAsDone(int i) {
        list[i - 1].markAsDone();
    }
    void modifyTaskName(int i, string n) {
        list[i - 1].setName(n);
    }
    void modifyTaskPriority(int i, int lvl) {
        list[i - 1].setPriority(lvl);
    }
    void modifyTaskDescription(int i, string n) {
        list[i - 1].setDesc(n);
    }

    int genId() {
        return list.size() + 1;
    }

    void displayTasks() {
        
        cout << "\nList of tasks: " << endl;
        if (list.size() == 0) {
            cout << "\t--- List is Empty ---" << endl;
        }
        int totalTime = 0;
        int maxNameLength = 0;
        int maxTimeLength = 0;
        for (int i = 0; i < list.size(); i++) {
            totalTime += list[i].getTime();
            if (list[i].getName().length() > maxNameLength) {
                maxNameLength = list[i].getName().length();
            }
            if (list[i].getFormattedTime().length() > maxTimeLength) {
                maxTimeLength = list[i].getFormattedTime().length();
            }
        }
        int timePos = 0;
        for (int i = 0; i < list.size(); i++) {
            string bar = "";
            for (int j = 0; j < totalTime / 10; j++) {
                if (j >= timePos && j < timePos + list[i].getTime() / 10) {
                    bar += "#";
                }
                else {
                    bar += "_";
                }
            }
            timePos += list[i].getTime() / 10;
            cout << "\t" << "ID: " << list[i].getId() << ") " << list[i].getName() << "\t" << list[i].getFormattedTime() << "\t" << bar << "\t" << list[i].getDesc() << "\t" << list[i].getStatus() << "\t" << list[i].getPriority() << endl;
        }
        cout << endl;
    }
};

int main() {

    TaskList taskList;
    bool running = true;

    while (running) {
        
        taskList.displayTasks();
        int option = 1;
        cout << "Do you want to:\n\t1) Add a task\n\t2) Mark tasks as done\n\t3) Modify a Task's Name\n\t4) Modify a Task's Description\n\t5) Modify a Task's Priority \n\t6) Exit the program\nEnter a number: ";
        cin >> option;
        cin.ignore();
        switch (option) {
        case 1:
        {
            cout << "Enter a task: ";
            string taskName;
            getline(cin, taskName);
            cout << "Enter description for this task: ";
            string taskDesc;
            getline(cin, taskDesc);
            cout << "Enter a time (minutes): ";
            int time;
            cin >> time;
            int priorityLevel;
            cout << "Enter a priority level (1-5): ";
            cin >> priorityLevel;
            taskList.addTask(taskList.genId(), taskName, taskDesc, priorityLevel, time);
            break;
        }
        case 2:
        {
            int index = 0;
            cout << "Choose a task index to mark as done: ";
            cin >> index;
            taskList.markTaskAsDone(index);
            break;
        }
        case 3:
        {
            cout << "Enter Task ID: ";
            int thisId;
            cin >> thisId;
            cout << "Enter new Name: ";
            string newName;
            cin >> newName;
            taskList.modifyTaskName(thisId, newName);
            break;
        }
        case 4:
        {
            cout << "Enter Task ID: ";
            int thisId;
            cin >> thisId;
            cout << "Enter new description: ";
            string newDesc;
            cin >> newDesc;
            taskList.modifyTaskDescription(thisId, newDesc);
            break;
        }
        case 5:
        {
            cout << "Enter Task ID: ";
            int thisId;
            cin >> thisId;
            cout << "Enter new priority level (1-5): ";
            int thisLvl;
            cin >> thisLvl;
            taskList.modifyTaskPriority(thisId, thisLvl);
            break;
        }
        case 6:
            running = false;
            break;
        default:
            cout << "Please enter either 1 - 5." << endl;
        }

    }
}
