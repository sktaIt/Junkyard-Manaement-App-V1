#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;
int random = 247;
bool choosecarindex = true;
bool minimizeindex = true;
class car {
	string model, color, damagedPart;
	int seats, year, code;
public:
	void setcar(string m, string c, string d, int y, int s) {
		this->model = m; this->color = c; this->damagedPart = d; this->year = y; this->seats = s;
		this->code=random+37;
		random+=37;
	}
	void getinfo() {
		cout << "\n********************************************";
		printf("\ncar information:");
		printf("\ncar model: %-15s", this->getmodel().c_str());
		printf("\ncar color: %-10s", this->getcolor().c_str());
		printf("\ncar damaged part: %-25s", this->getdamage().c_str());
		printf("\ncar manufacture year: %-20d", this->getyear());
		printf("\ncar seat count: %-16d", this->getseats());
		printf("\ncar code: %-7d", this->getcode());
		cout << "\n********************************************";
		cout << "\n\n";
	}
	string getmodel() {
		return this->model;
	}
	string getcolor() {
		return this->color;
	}
	string getdamage() {
		return this->damagedPart;
	}
	int getyear() {
		return year;
	}
	int getseats() {
		return seats;
	}
	int getcode() {
		return code;
	}
	void setcode(int num) {
		this->code = num;
	}
};
void viewall(vector<car> *vector1) {
	int number = 1;
	cout << "car#      model          color     damaged part        manufacture year       seats count           code\n"
		<<"************************************************************************************************************\n";
	for (car e : *vector1) {
		printf("car#%-6d", number);
		printf("%-15s", e.getmodel().c_str());
		printf("%-13s", e.getcolor().c_str());
		printf("%-23s", e.getdamage().c_str());
		printf("%-23d", e.getyear());
		printf("%-16d", e.getseats());
		printf("%-7d", e.getcode());
		cout << "\n\n";
		number++;
	}
}
void add(vector<car> *vector1, string m, string c, string d, int y, int s) {
	car Newcar;  car* newcar= new car();
	transform(m.begin(), m.end(), m.begin(), ::tolower);
	transform(c.begin(), c.end(), c.begin(), ::tolower);
	transform(d.begin(), d.end(), d.begin(), ::tolower);
	(*newcar).setcar( m,  c,  d,  y,  s);
	Newcar = *newcar;
	(* vector1).push_back(Newcar);
}
void search(vector<car> *vector1, vector<car>*temp, string value) {
	transform(value.begin(), value.end(), value.begin(), ::tolower);
	bool found = false;
	for (car e : *vector1) {
		if (e.getmodel() == value) {
			found = true;
			(*temp).push_back(e);
			cout << "\nA car with specified information was found";
			e.getinfo();
		}
		else if (e.getcolor() == value) {
			found = true;
			(*temp).push_back(e);
			cout << "\nA car with specified information was found";
			e.getinfo();
		}
		else if (e.getdamage() == value) {
			found = true;
			(*temp).push_back(e);
			cout << "\nA car with specified information was found";
			e.getinfo();
		}
	}
	if (found == false) {
		cout << "A car with provided specification can not be found" << endl;
		choosecarindex = false;
		minimizeindex = false;
	}
}
void search(vector<car> *vector1, vector<car>* temp, int value) {
	bool found = false;
	for (car e : *vector1) {
		if (e.getseats() == value) {
			found = true;
			(*temp).push_back(e);
			cout << "\nA car with specified information was found";
			e.getinfo();
		}
		else if (e.getyear() == value) {
			found = true;
			(*temp).push_back(e);
			cout << "\nA car with specified information was found";
			e.getinfo();
		}
		else if (e.getcode() == value) {
			found = true;
			(*temp).push_back(e);
			cout << "\nA car with specified information was found";
			e.getinfo();
		}
	}
	if (found = false) {
		cout << "A car with provided specification can not be found" << endl;
		choosecarindex = false;
		minimizeindex = false;
	}
}
void readDatabase(vector<car>* vector1) {
	string model3, color3, damage3, asterisks;
	int year3, seats3, counter=0, counter2 = 0;
	fstream file; file.open("junkyardDatabase.txt", ios::in);
	while (asterisks !="*******************"&&counter<200) {
		getline(file, asterisks);
		if (asterisks == "*******************") {
			goto label1;
		}
		counter++;
		//cout <<"iteration#"<<counter << endl;
	}
	label1:
	while (counter2 < 200) {
		if (asterisks == "*******************") {
			getline(file, model3);
			getline(file, color3);
			getline(file, damage3);
			file >> year3;
			file >> seats3;
			add(vector1, model3, color3, damage3, year3, seats3);
			getline(file, asterisks);
			getline(file, asterisks);
			getline(file, asterisks);
			counter = 0;
		}
		else {
			getline(file, asterisks);
			counter2++;
			//cout << counter2 << endl;
		}
	}
	file.close();
}
void updateSystemDatabase(vector<car>* vector1){
	fstream file;  file.open("junkyardDatabase.txt", ios::out);
	for (car e : (*vector1)) {
		file << "\n";
		file << "*******************" << endl;
		file << e.getmodel() << endl;
		file << e.getcolor() << endl;
		file << e.getdamage() << endl;
		file << e.getyear() << endl;
		file << e.getseats() << endl;
		file << e.getcode() << endl;
	}
	file.close();
}
void updateUserDatabase(vector<car>* vector1){
	int index = 1;
	fstream file;  file.open("userDatabase.txt", ios::out);
	for (car e : (*vector1)) {
		file << "*******************" << endl;
		file << "Car #" << index<< " information: " << endl;
		file <<"car model: "<< e.getmodel() << endl;
		file << "car color: " << e.getcolor() << endl;
		file << "car damaged part: " << e.getdamage() << endl;
		file << "car manufacture year: " << e.getyear() << endl;
		file << "car seats count: " << e.getseats() << endl;
		file << "car code: " << e.getcode() << endl;
		//file << "car code: " <<::hex<< e.getcode() << endl;
		index++;
	}
	file.close();
}
void starting(vector<car>* vector1) {
	car ford; ford.setcar("ford mustang", "black", "engine", 2022, 4);
	car toyota; toyota.setcar("toyota corola", "silver", "trunk", 2007, 5);
	car audi; audi.setcar("audi R8", "orange", "tires", 2020, 6);
	car toyota2; toyota2.setcar("toyota corola", "green", "engine", 2007, 6);
	(*vector1).push_back(ford);
	(*vector1).push_back(toyota);
	(*vector1).push_back(audi);
	(*vector1).push_back(toyota2);
	updateSystemDatabase(&*vector1);
}
void Remove(vector<car>* vector1, int value) {
	int place = 0;
	for (car e : (*vector1)) {
		if (e.getcode() == value) {
			(*vector1).erase((*vector1).begin()+place);
			cout << "\nPlease head to slot " << ::hex << e.getcode() << "  to take the selected car, thank you ^_^\n\n";
		}
		place++;
	}
}
void chooseCar(vector<car>* vector1) {
	int value = 0;
	cout << "from the cars above, please choose a car by entering its corresponding code: \n"
		<< "you can enter 0 if you do not want any of the cars above.";
	cin >> value;
	if (value != 0) {
		Remove(&(*vector1), value);
	}
}
void sortbycode(vector<car>* vector1) {
	for (int i = 0; i < (*vector1).size(); i++) {
		for (int j = i; j < (*vector1).size(); j++) {
			if ((*vector1)[i].getcode() > (*vector1)[j].getcode()) {
				swap((*vector1)[i], (*vector1)[j]);
			}
		}
	}
}
void sortbyyear(vector<car>* vector1) {
	for (int i = 0; i < (*vector1).size(); i++) {
		for (int j = i; j < (*vector1).size(); j++) {
			if ((*vector1)[i].getyear() > (*vector1)[j].getyear()) {
				swap((*vector1)[i], (*vector1)[j]);
			}
		}
	}
	viewall(&*vector1);
	sortbycode(&*vector1);
}
void sortbyseats(vector<car>* vector1) {
	for (int i = 0; i < (*vector1).size(); i++) {
		for (int j = i; j < (*vector1).size(); j++) {
			if ((*vector1)[i].getseats() > (*vector1)[j].getseats()) {
				swap((*vector1)[i], (*vector1)[j]);
			}
		}
	}
	viewall(&*vector1);
	sortbycode(&*vector1);
}
void vectorswap(vector<car>* temp, vector<car>* temp2) {
	(*temp).clear();
	for (car e : *temp2) {
		(*temp).push_back(e);
	}
	(*temp2).clear();
}
void minimizeSearch(vector<car>* vector1,vector<car>* temp, vector<car>* temp2) {
	string model5, color5, damage5;
	int option3, seats5, year5, code5;
	cout << "\nplease choose an option from below to minimize cars list according to:"
		<< "\n1) model\n2) color\n3) damaged part\n4) manufacture year\n5) seat count\n6) code\n";
	cin >> option3;
	if (option3 == 1) {
		cout << "please enter model you are searching for: " << endl;
		getline(cin, model5);
		getline(cin, model5);
		search(&*temp, &*temp2, model5);
	}
	else if (option3 == 2) {
		cout << "please enter color you are searching for: ";
		getline(cin, color5);
		getline(cin, color5);
		search(&*temp, &*temp2, color5);
	}
	else if (option3 == 3) {
		cout << "please enter damaged part you are searching for: ";
		getline(cin, damage5);
		getline(cin, damage5);
		search(&*temp, &*temp2, damage5);
	}
	else if (option3 == 4) {
		cout << "please enter manufacture year you are searching for (please enter numbers only) : ";
		cin >> year5;
		search(&*temp, &*temp2, year5);
	}
	else if (option3 == 5) {
		cout << "please enter seats count you are searching for (please enter numbers only) : ";
		cin >> seats5;
		search(&*temp, &*temp2, seats5);
	}
	else if (option3 == 6) {
		cout << "please enter the car code (please enter numbers only) : ";
		cin >> code5;
		search(&*temp, &*temp2, code5);
	}
	vectorswap(&*temp, &*temp2);
}
void Ask(vector<car>* vector1, vector<car>* temp, vector<car>* temp2) {
	int option, option2, seats1, year1, seats2, year2, code2, option4;
	string model1, color1, damage1, model2, color2, damage2;
	cout << "\n                     **** Welcome to the junkyard management program ****"
		<< "\n              This program is designed to provide proper management for reusable cars\n"
		<< "              and to help people find the cars they want to encoutage them to recycle cars\n"
		<< "\nplease select one of the options below by entering the option number\n"
		<< "1) add a car to the junkyard\n"
		<< "2) search for a specified car\n"
		<< "3) view cars database\n"
		<< "4) view cars database sorted by manufacture year\n"
		<< "5) view cars database sorted by seats count\n";
	label:
	cin >> option;

	if (option == 1) {
		cout << "Please enter the car model\n";
		getline(cin, model1);
		getline(cin, model1);
		cout << "Please enter the car color\n";
		getline(cin, color1);
		cout << "Please enter the car damaged part\n";
		getline(cin, damage1);
		cout << "Please enter the car manufacture year\n";
		cin >> year1;
		cout << "Please enter the number of car seats\n";
		cin >> seats1;
		add(&*vector1, model1, color1, damage1, year1, seats1);
	}
	else if (option == 2) {
		cout << "\nplease choose an option from below to search cars according to:"
			<< "\n1) model\n2) color\n3) damaged part\n4) manufacture year\n5) seat count\n6) code\n";
		cin >> option2;
		if (option2 == 1) {
			cout << "please enter model you are searching for: " << endl;
			getline(cin, model2);
			getline(cin, model2);
			search(&*vector1,&*temp, model2);
			if (minimizeindex) {
				cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
				cin >> option4;
				if (option4 == 1) {
					minimizeSearch(&*vector1, &*temp, &*temp2);
					cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
					cin >> option4;
					if (option4 == 1) {
						minimizeSearch(&*vector1, &*temp, &*temp2);
						cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
						cin >> option4;
						if (option4 == 1) {
							minimizeSearch(&*vector1, &*temp, &*temp2);
							cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
							cin >> option4;
							if (option4 == 1) {
								minimizeSearch(&*vector1, &*temp, &*temp2);
							}
						}
					}
				}
			}
			if (choosecarindex) {
				chooseCar(&*vector1);
			}
		}
		else if (option2 == 2) {
			cout << "please enter color you are searching for: ";
			getline(cin, color2);
			getline(cin, color2);
			search(&*vector1, &*temp, color2);
			if (minimizeindex) {
				cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
				cin >> option4;
				if (option4 == 1) {
					minimizeSearch(&*vector1, &*temp, &*temp2);
					cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
					cin >> option4;
					if (option4 == 1) {
						minimizeSearch(&*vector1, &*temp, &*temp2);
						cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
						cin >> option4;
						if (option4 == 1) {
							minimizeSearch(&*vector1, &*temp, &*temp2);
							cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
							cin >> option4;
							if (option4 == 1) {
								minimizeSearch(&*vector1, &*temp, &*temp2);
							}
						}
					}
				}
			}
			if (choosecarindex) {
				chooseCar(&*vector1);
			}
		}
		else if (option2 == 3) {
			cout << "please enter damaged part you are searching for: ";
			getline(cin, damage2);
			getline(cin, damage2);
			search(&*vector1, &*temp, damage2);
			if (minimizeindex) {
				cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
				cin >> option4;
				if (option4 == 1) {
					minimizeSearch(&*vector1, &*temp, &*temp2);
					cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
					cin >> option4;
					if (option4 == 1) {
						minimizeSearch(&*vector1, &*temp, &*temp2);
						cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
						cin >> option4;
						if (option4 == 1) {
							minimizeSearch(&*vector1, &*temp, &*temp2);
							cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
							cin >> option4;
							if (option4 == 1) {
								minimizeSearch(&*vector1, &*temp, &*temp2);
							}
						}
					}
				}
			}
			if (choosecarindex) {
				chooseCar(&*vector1);
			}
		}
		else if (option2 == 4) {
			cout << "please enter manufacture year you are searching for (please enter numbers only) : ";
			cin >> year2;
			search(&*vector1, &*temp, year2);
			if (minimizeindex) {
				cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
				cin >> option4;
				if (option4 == 1) {
					minimizeSearch(&*vector1, &*temp, &*temp2);
					cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
					cin >> option4;
					if (option4 == 1) {
						minimizeSearch(&*vector1, &*temp, &*temp2);
						cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
						cin >> option4;
						if (option4 == 1) {
							minimizeSearch(&*vector1, &*temp, &*temp2);
							cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
							cin >> option4;
							if (option4 == 1) {
								minimizeSearch(&*vector1, &*temp, &*temp2);
							}
						}
					}
				}
			}
			if (choosecarindex) {
				chooseCar(&*vector1);
			}
		}
		else if (option2 == 5) {
			cout << "please enter seats count you are searching for (please enter numbers only) : ";
			cin >> seats2;
			search(&*vector1, &*temp, seats2);
			if (minimizeindex) {
				cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
				cin >> option4;
				if (option4 == 1) {
					minimizeSearch(&*vector1, &*temp, &*temp2);
					cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
					cin >> option4;
					if (option4 == 1) {
						minimizeSearch(&*vector1, &*temp, &*temp2);
						cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
						cin >> option4;
						if (option4 == 1) {
							minimizeSearch(&*vector1, &*temp, &*temp2);
							cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
							cin >> option4;
							if (option4 == 1) {
								minimizeSearch(&*vector1, &*temp, &*temp2);
							}
						}
					}
				}
			}
			if (choosecarindex) {
				chooseCar(&*vector1);
			}
		}else if (option2 == 6) {
			cout << "please enter the car code (please enter numbers only) : ";
			cin >> code2;
			search(&*vector1, &*temp, code2);
			if (minimizeindex) {
				cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
				cin >> option4;
				if (option4 == 1) {
					minimizeSearch(&*vector1, &*temp, &*temp2);
					cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
					cin >> option4;
					if (option4 == 1) {
						minimizeSearch(&*vector1, &*temp, &*temp2);
						cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
						cin >> option4;
						if (option4 == 1) {
							minimizeSearch(&*vector1, &*temp, &*temp2);
							cout << "do you wish to minimize the available option? enter 1 for yes OR 0 is no:\n";
							cin >> option4;
							if (option4 == 1) {
								minimizeSearch(&*vector1, &*temp, &*temp2);
							}
						}
					}
				}
			}
			if (choosecarindex) {
				chooseCar(&*vector1);
			}
		}
	}
	else if (option == 3) {
		viewall(&*vector1);
	}
	else if (option == 4) {
		sortbyyear(&*vector1);
	}
	else if (option == 5) {
		sortbyseats(&*vector1);
	}
	else {
		cout << "choose an option from those provided above" << endl;
		goto label;
	}
}


int main() {
	//opening text files, creating it if it doesn't exist
	fstream file;
	file.open("junkyardDatabase.txt", ios::in);
	fstream userFile;
	userFile.open("userDatabase.txt", ios::in);
	file.close();
	userFile.close();
	//creating program loop index
	int index = 0;

	//creating database and intializing 4 objects as start
	vector<car> vector1;
	vector<car> temp;
	vector<car> temp2;
	readDatabase(&vector1);
	//cout << vector1.empty();
	if (vector1.empty()) {
		starting(&vector1);
	}
	

	//program loop
	while (index == 0) {
		Ask(&vector1, &temp, &temp2);
		cout << "\nPlease enter 0 if you wish to use the program again. " << endl;
		cout << "or enter any other number if you wish to exit (please only enter a number). " << endl;
		cin >> index;
		temp.clear();
		choosecarindex = true;
		minimizeindex = true;
	}
	
	updateSystemDatabase(&vector1);
	updateUserDatabase(&vector1);

	system("pause>0");
}
