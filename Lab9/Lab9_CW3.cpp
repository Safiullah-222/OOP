#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
private:
    string name;
    string id;
    string dob;
    string medicalHistory;
    string treatment;
    string billing;

public:
    PatientRecord(string n, string i, string d) {
        name = n;
        id = i;
        dob = d;
        medicalHistory = "";
        treatment = "";
        billing = "";
    }

    string getPublicData() {
        return "Name: " + name + ", ID: " + id;
    }

    string getMedicalData(string role) {
        if (role == "doctor") {
            return "History: " + medicalHistory + ", Treatment: " + treatment;
        }
        return "Access Denied";
    }

    void updateMedicalHistory(string role, string h) {
        if (role == "doctor") {
            medicalHistory = h;
        }
    }

    void addBillingDetails(string role, string b) {
        if (role == "billing") {
            billing = b;
        }
    }

    string getBillingDetails(string role) {
        if (role == "billing") {
            return "Billing: " + billing;
        }
        return "Access Denied";
    }
};

int main() {
    PatientRecord patient("Zara", "P123", "2002-06-10");

    cout << patient.getPublicData() << endl;

    patient.updateMedicalHistory("doctor", "Diabetes");
    cout << patient.getMedicalData("doctor") << endl;

    patient.addBillingDetails("billing", "$1500");
    cout << patient.getBillingDetails("billing") << endl;

    cout << patient.getMedicalData("receptionist") << endl;
    cout << patient.getBillingDetails("doctor") << endl;

    return 0;
}
