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
    
    void Add_ENPM660(string section){
        Courses.push_back("ENPM660");   
        Section.push_back(section);
        cout << endl << "Course ENPM660 for section " << section << " has been added" << endl;
    }
    void Remove_ENPM660(string section){
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM660"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM660 has been removed" << endl;
    }

    void Add_ENPM662(string section){
        Courses.push_back("ENPM662");
        Section.push_back(section);
        cout << endl << "Course ENPM662 for section " << section << " has been added" << endl;
    }
    void Remove_ENPM662(string section){
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM662"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM662 has been removed" << endl;
    }

    void Add_ENPM809Y(string section){
        Courses.push_back("ENPM809Y");
        Section.push_back(section);
        cout << endl << "Course ENPM809Y for section " << section << " has been added" << endl;
    }
    void Remove_ENPM809Y(string section){
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM809Y"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM809Y has been removed" << endl;
    }

    void Add_ENPM808X(string section, string permission){
        if (permission == "ENPM809Y" || permission == "Yes"){
            Courses.push_back("ENPM808X");
            Section.push_back(section);
            cout << endl << "Course ENPM808X for section " << section << " has been added" << endl;
        }
        else
            cout << endl << "You cannot register for ENPM808X" << endl;
    }
    void Remove_ENPM808X(string section){
        Courses.erase(find(Courses.begin(),Courses.end(),"ENPM808X"));
        Section.erase(find(Section.begin(),Section.end(),section));
        cout << endl << "Course ENPM808X has been removed" << endl;
    }

    void Registered_Courses(){
        cout << endl << "Name : " << Name << endl;
        cout << "Program : " << Program << endl;
        cout << "UID : " << UID << endl;
        cout << "-----------------------" << endl;
        cout << "Course     Section" << endl;
        cout << "-----------------------" << endl;
        for(int i=0; i < Courses.size(); i++)
            std::cout << Courses.at(i) << "     " << Section.at(i) << endl;
    }
};

int main(){
    CourseRegistration Pratik = CourseRegistration("Pratik Acharya", "PMRO", 117513615);
    Pratik.Add_ENPM660("0101");
    Pratik.Add_ENPM662("0101");
    Pratik.Add_ENPM809Y("0101");
    Pratik.Registered_Courses();
    Pratik.Remove_ENPM809Y("0101");
    Pratik.Add_ENPM808X("0101", "No");
    Pratik.Registered_Courses();

}