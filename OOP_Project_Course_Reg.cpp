#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Student{          // Base(Parent) Class to store the Student Details
protected:
    string Name;
    string Program;
    int UID;
    
public:
    Student(string name, string program, int uid){     // Student Class constructor to aquire the details
        Name = name;
        Program = program;
        UID = uid;
        cout << endl << "Welcome " << Name << endl;     // A welcome message
    }
};

class CourseRegistration:Student{           // Derived class for Course Registration
public:
    CourseRegistration(string name, string program, int uid):Student(name, program, uid){}  // Constructor for Derived Class
    
    vector<string> Courses;         // Vector to store the courses
    vector<string> Section;         // Vector to store the sections
    
    void Add_ENPM660(string section){           // Method to add course ENPM660
        Courses.push_back("ENPM660");           // Add respective course to registered list
        Section.push_back(section);             // Add respective section to registered list
        cout << endl << "Course ENPM660 for section " << section << " has been added" << endl;
    }
    void Remove_ENPM660(string section){        // Method to remove course ENPM660
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM660"));   // Remove respective course to registered list
        Section.erase(find(Section.begin(),Section.end(),section));     // Remove respective section to registered list
        cout << endl << "Course ENPM660 has been removed" << endl;
    }

    void Add_ENPM662(string section){           // Method to add course ENPM662
        Courses.push_back("ENPM662");
        Section.push_back(section);
        cout << endl << "Course ENPM662 for section " << section << " has been added" << endl;
    }
    void Remove_ENPM662(string section){        // Method to remove course ENPM662
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM662"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM662 has been removed" << endl;
    }

    void Add_ENPM809Y(string section){          // Method to add course ENPM809Y
        Courses.push_back("ENPM809Y");
        Section.push_back(section);
        cout << endl << "Course ENPM809Y for section " << section << " has been added" << endl;
    }
    void Remove_ENPM809Y(string section){       // Method to remove course ENPM809Y
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM809Y"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM809Y has been removed" << endl;
    }

    void Add_ENPM808X(string section, string permission){       // Method to add course ENPM808X
        if (permission == "ENPM809Y" || permission == "Yes"){   // Condition to check if prerequisite conditions are met
            Courses.push_back("ENPM808X");
            Section.push_back(section);
            cout << endl << "Course ENPM808X for section " << section << " has been added" << endl;
        }
        else
            cout << endl << "You cannot register for ENPM808X" << endl;
    }
    void Remove_ENPM808X(string section){                       // Method to remove course ENPM808X
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM808X"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM808X has been removed" << endl;
    }

    void Registered_Courses(){                                  // Method to list all the registered courses
        cout << endl << "Name : " << Name << endl;
        cout << "Program : " << Program << endl;
        cout << "UID : " << UID << endl;
        cout << "-------------------------" << endl;
        cout << "Course\t\tSection" << endl;
        cout << "-------------------------" << endl;
        for(int i=0; i < Courses.size(); i++)
            std::cout << Courses.at(i) << "  \t  " << Section.at(i) << endl;
        cout << endl;
    }
};

int main(){
    CourseRegistration Pratik = CourseRegistration("Pratik Acharya", "PMRO", 117513615); // Creating Object for class CourseRegistration
    Pratik.Add_ENPM660("0101");
    Pratik.Add_ENPM662("0101");
    Pratik.Add_ENPM809Y("0101");
    Pratik.Registered_Courses();
    Pratik.Remove_ENPM809Y("0101");
    Pratik.Add_ENPM808X("0101", "No");
    Pratik.Registered_Courses();

}
