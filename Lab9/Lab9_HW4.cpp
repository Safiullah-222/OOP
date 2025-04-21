#include <iostream>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) {
        if (status == "undergraduate") return creditHours * 200;
        if (status == "graduate") return creditHours * 300;
        if (status == "doctoral") return creditHours * 400;
        return 0;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("AI in Healthcare");

    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition (Graduate, 10 credits): $" << gs.getTuition("graduate", 10) << endl;

    return 0;
}
