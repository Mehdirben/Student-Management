#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
	string nom;
	
public:
	void ShowData(){
        ifstream database("student.txt", ios::in);
        string ligne;
        while (getline(database,ligne)){
            cout << ligne << endl ;
        }
        if (!database.is_open()){
        	cout<<"Error in opening! File Not Found!"<<endl;
		}
        database.close();
    }
    
    void SearchRecord(){
	    int ns, nr;
	    string ligne2;
	    vector<string> vec;
	    cout << " ************** Menue de recherche **************" << endl;
	    fstream database("student.txt", ios::in);
	    if (database.is_open()){
	        nr = 0;
	        while (getline(database, ligne2)){
	            nr++;
	            vec.push_back(ligne2);
	        }
	        cout << "The number of registered students is : " << nr << endl; 
	        cout << "Enter the number to search: ";
	        cin >> ns;
	        if (ns > 0 && ns <= nr){ 
	            cout << "The student with the number" << ns << " is " << vec[ns - 1] << endl;
	        }
	        else{
	            cout << "No student recorded with this number" << endl;
	        }
	        nr = 0;
	        database.close();
	    }
	    else{
	        cout << "Error in opening! File Not Found!" << endl;
	    }
	}
	
	void DeleteRecord(){
		int ns4, nr4;
	    string ligne4;
	    vector<string> vec3;
	    cout << " ************** Menue de Suppression **************" << endl;
	    fstream database("student.txt", ios::in);
	    if (database.is_open()){
	        nr4 = 0;
	        while (getline(database, ligne4)){
	            nr4++;
	            vec3.push_back(ligne4);
	        }
	        cout << "The number of registered students is : " << nr4 << endl;
	        cout << "Enter the number to delete : ";
			cin >> ns4;
			cin.ignore();
	        if (ns4 > 0 && ns4 <= nr4){
	            vec3.erase(vec3.begin() + ns4 - 1);
		        fstream UpdateFile("student.txt", ios::out);
	            if (UpdateFile.is_open()) {
	                for (int i = 0; i < nr4; i++) {
	                    UpdateFile << vec3[i] << endl;
	                }
	                UpdateFile.close();
	                cout << "Deleted" << endl;
	            } else {
	                cout << "Error in opening the file for deleting" << endl;
	            }
	        } else {
	            cout << "No student recorded with this number" << endl;
	        }
	        nr4 = 0;
	        database.close();
	    } else {
	        cout << "Error in opening! File Not Found!" << endl;
	    }
	}
	
	
};

class Student : public Person {
public:
    string cours;
    string section;
    
    Student(){
	}
    
    void AddRecord() {
        ofstream database("student.txt", ios::app);
        if (database.is_open()) {
            database << nom << "  " << cours << "  " << section << endl;
            database.close();
            cout << "Saved" << endl;
        } else {
            cout << "Error in opening! File Not Found!" << endl;
        }
    }
    
    void entrer(){
        cout << "Enter name : \n";
        getline(cin,nom);
        cout <<"Enter cours : \n";
        getline(cin,cours);
        cout <<"Enter section : \n";
        getline(cin,section);
        AddRecord();
	}
	
	void EditRecord() {
        int ns2, nr2;
        string ligne3,a,b,c;
        vector<string> vec2;
        cout << " ************** Menu de modification ************** " << endl;
        fstream database("student.txt", ios::in);
        if (database.is_open()) {
            nr2 = 0;
            while (getline(database, ligne3)) {
                nr2++;
                vec2.push_back(ligne3);
            }
            cout << "The number of registered students is : " << nr2 << endl;
            cout << "Enter the number to edit : ";
            cin >> ns2;
            cin.ignore();
            if (ns2 > 0 && ns2 <= nr2) {
                cout << "The student with the number" << ns2 << " is " << vec2[ns2 - 1] << endl;
                cout << "Enter new name : ";
                getline(cin, a);
                cout << "Enter new cours : ";
                getline(cin, b);
                cout << "Enter new section : ";
                getline(cin, c);
                vec2[ns2 - 1] = a + "  " + b + "  " + c;
                fstream UpdateFile("student.txt", ios::out);
                if (UpdateFile.is_open()) {
                    for (int i = 0; i < nr2; i++) {
                        UpdateFile << vec2[i] << endl;
                    }
                    UpdateFile.close();
                    cout << "Updated" << endl;
                } else {
                    cout << "Error in opening the file for update" << endl;
                }
            } else {
                cout << "No student recorded with this number" << endl;
            }
            nr2 = 0;
            database.close();
        } else {
            cout << "Error in opening! File Not Found!" << endl;
        }
    }
};

int main() {
    Student student;
    int choice;
    do {
        cout << "\nStudent Database Management System\n";
        cout << "1. Add Record\n";
        cout << "2. List Records\n";
        cout << "3. Search Record\n";
        cout << "4. Edit Record\n";
        cout << "5. Delete Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                student.entrer();
                break;
            case 2:
                student.ShowData();
                break;
            case 3:
                student.SearchRecord();
                break;
            case 4:
                student.EditRecord();
                break;
            case 5:
                student.DeleteRecord();
                break;
            case 0:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}
