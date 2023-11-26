#include <iostream>
#include <string>
#define MAXSUB 5 // Five subjects
#define MAXSTUDENT 70
using namespace std;

struct Date
{
	int dd{}, mm{}, yy{};
};
struct Snode
{
	int regNum{};
	string name;
	string fname;
	int marks[MAXSUB]{};
	Date dob{}, doa{};
	float cgpa{};
	Snode* next{};
};
void create_database(Snode*& first, int nn) {
	Snode* cur{ NULL }, * prev{ NULL };
	for (int i = 0; i < nn; i++)
	{
		cur = new Snode;
		cur->next = NULL;
		cout << "Enter Data for Student Number: " << i + 1 << endl;
		cout << "Enter student reg number: ";
		cin >> cur->regNum;
		cout << "Enter student name: ";
		cin >> cur->name;
		cin.ignore(30, '\n');
		cout << "Enter student father name: ";
		cin >> cur->fname;
		cin.ignore(30, '\n');
		cout << "Enter marks (out of 100):" << endl;
		for (int j = 0; j < MAXSUB; j++)
		{
			cout << "Marks in Subject " << j + 1 << ": ";
			cin >> cur->marks[j];
		} // end of for - j
		cout << "Enter Date of Birth: " << endl;
		cout << "Enter Day: ";
		cin >> cur->dob.dd;
		cout << "Enter Month: ";
		cin >> cur->dob.mm;
		cout << "Enter Year: ";
		cin >> cur->dob.yy;
		cout << "Enter Date of Admission: " << endl;
		cout << "Enter Day: ";
		cin >> cur->doa.dd;
		cout << "Enter Month: ";
		cin >> cur->doa.mm;
		cout << "Enter Year: ";
		cin >> cur->doa.yy;
		cout << "Enter CGPA: ";
		cin >> cur->cgpa;
		if (!first) {
			first = prev = cur;
		}
		else {
			prev->next = cur;
			prev = cur;
		}
		cout << "Student added successfully!" << endl;
	} // end of for - i
}
void append_record(Snode*& first, int& nn) {
	if (!first) {
		return;
	}
	Snode* cur{ NULL }, * prev{ NULL };
	cur = new Snode;
	cur->next = NULL;
	cur = new Snode;
	cur->next = NULL;
	cout << "Enter Data for Student Number: " << nn + 1 << endl;
	cout << "Enter student reg number: ";
	cin >> cur->regNum;
	cout << "Enter student name: ";
	cin >> cur->name;
	cin.ignore(30, '\n');
	cout << "Enter student father name: ";
	cin >> cur->fname;
	cin.ignore(30, '\n');
	cout << "Enter marks (out of 100):" << endl;
	for (int j = 0; j < MAXSUB; j++)
	{
		cout << "Marks in Subject " << j + 1 << ": ";
		cin >> cur->marks[j];
	} // end of for - j
	cout << "Enter Date of Birth: " << endl;
	cout << "Enter Day: ";
	cin >> cur->dob.dd;
	cout << "Enter Month: ";
	cin >> cur->dob.mm;
	cout << "Enter Year: ";
	cin >> cur->dob.yy;
	cout << "Enter Date of Admission: " << endl;
	cout << "Enter Day: ";
	cin >> cur->doa.dd;
	cout << "Enter Month: ";
	cin >> cur->doa.mm;
	cout << "Enter Year: ";
	cin >> cur->doa.yy;
	cout << "Enter CGPA: ";
	cin >> cur->cgpa;
	prev = first;
	while (prev->next) {
		prev = prev->next;
	}
	if (!prev->next) {
		prev->next = cur;
		prev = cur;
		nn = nn + 1;
		cout << "Student added successfully!" << endl;
	}
}
int search_record(Snode* first, int sinfo) {
	int position{};
	while (first) {
		position += 1;
		if (first->regNum == sinfo) {
			return position;
		}
		first = first->next;
	}
	return 0;
}
int delete_record(Snode*& first, int sinfo, int& nn) {
	Snode* cur{}, * prev{};
	cur = prev = first;
	if (first->regNum == sinfo) {
		first = first->next;
		nn = nn - 1;
		delete prev;
		return 1;
	}
	while (cur) {
		if (cur->regNum == sinfo) {
			prev->next = cur->next;
			delete cur;
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}
	return 0;
}
int updating_record(Snode*& first, int sinfo) {
	Snode* cur{};
	cur = first;
	while (cur) {

		if (cur->regNum == sinfo) {
			cout << "Updating the record of Student reg Number: " << cur->regNum << " Name: " << cur->name << endl;
			cout << "======================================\n";
			cout << "Enter student reg number: ";
			cin >> cur->regNum;
			cout << "Enter student name: ";
			cin >> cur->name;
			cin.ignore(30, '\n');
			cout << "Enter student father name: ";
			cin >> cur->fname;
			cin.ignore(30, '\n');
			cout << "Enter marks (out of 100):" << endl;
			for (int j = 0; j < MAXSUB; j++)
			{
				cout << "Marks in Subject " << j + 1 << ": ";
				cin >> cur->marks[j];
			} // end of for - j
			cout << "Enter Date of Birth: " << endl;
			cout << "Enter Day: ";
			cin >> cur->dob.dd;
			cout << "Enter Month: ";
			cin >> cur->dob.mm;
			cout << "Enter Year: ";
			cin >> cur->dob.yy;
			cout << "Enter Date of Admission: " << endl;
			cout << "Enter Day: ";
			cin >> cur->doa.dd;
			cout << "Enter Month: ";
			cin >> cur->doa.mm;
			cout << "Enter Year: ";
			cin >> cur->doa.yy;
			cout << "Enter CGPA: ";
			cin >> cur->cgpa;
			cout << "Student added successfully!" << endl;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}
void display_result(Snode* first) {
	while (first) {
		cout << "Result Card of Student's regNO: " << first->regNum << endl;
		cout << "-----------------------------------------------------\n";
		cout << "| Name: " << first->name << " " << first->regNum << endl;
		cout << "| Father Name: " << first->fname << endl;
		cout << endl;
		cout << "| Subject " << "| Marks " << endl;
		int sum{};
		for (int j{ 0 }; j < MAXSUB; j++) {
			cout << "| Subject" << j + 1 << " " << "| " << first->marks[j]
				<< endl;
			sum += first->marks[j];
		}
		cout << "======================================================\n";
		cout << "| Total Marks: " << "| " << sum << endl;
		cout << "| CGPA: " << "| " << first->cgpa << endl;
		first = first->next;
	}
}
int main() {
	int ch{};
	int n{}, sinfo{}, index{};
	Snode* head{ nullptr };
	do {
		cout << "\n\nStudent Database Menu:" << endl
			<< "1. Create Data Base" << endl
			<< "2. Append a record" << endl
			<< "3. Search a record" << endl
			<< "4. Delete a record" << endl
			<< "5. Update a record" << endl
			<< "6. Display Result" << endl
			<< "7. Exit" << endl
			<< "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: // Create DB
			while (true) {
				cout << "Enter how many students are [MAX. 70]: ";
				cin >> n;
				if (n < 0 ||n > MAXSTUDENT) {
					cout << "Please provide correct number of student, number of student[MAX. 70] " << endl;
				}
				else {
					break;
				}
			}
			create_database(head, n);
			break;
		case 2: // Append
			if (!head) {
				cout << "No Database found, Please first create one." << endl;
				break;
			}
			append_record(head, n);
			break;
		case 3: // Searching
			if (!head) {
				cout << "No Database found, Please first create one." << endl;
				break;
			}
			cout << "Enter reg. number to search: ";
			cin >> sinfo;
			index = search_record(head, sinfo);
			if (index) {
				cout << "Found at Position: " << index << endl;
			}
			else {
				cout << "Not found\n";
			}
			break;
		case 4: // Deletion
			if (!head) {
				cout << "No Database found, Please first create one." << endl;
				break;
			}
			cout << "Enter reg. number to Delete record: ";
			cin >> sinfo;
			index = delete_record(head, sinfo, n);
			if (index) {
				cout << "Sucessfully Deleted" << endl;
			}
			else {
				cout << "Not found\n";
			}
			break;
		case 5:
			if (!head) {
				cout << "No Database found, Please first create one." << endl;
				break;
			}
			cout << "Updating Record" << endl;
			cout << "Enter reg. number to update Record: ";
			cin >> sinfo;
			index = updating_record(head, sinfo);
			if (index) {
				cout << "Sucessfully Updated" << endl;
			}
			else {
				cout << "Not found\n";
			}
			break;
		case 6:
			if (!head) {
				cout << "No Database found, Please first create one." << endl;
				break;
			}
			cout << "Displaying Students result Card\n";
			display_result(head);
			break;
		case 7: // Exit
			cout << " ALLAH HAFIZ..." << endl;
			while (head) {
				Snode* temp = head;
				head = head->next;
				delete temp;
			}
			return 0;
		default:
			cout << "Invalid choice. Enter again..." << endl;
			break;
		} // end of switch
	} while (true);
	return 0;
}
