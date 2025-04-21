#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger {
private:
    vector<string> logs;
    int maxLogs;

    void addLog(const string& type, const string& message) {
        string full = "[" + type + "] " + message;
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin());
        }
        logs.push_back(full);
    }

public:
    Logger() {
        maxLogs = 1000;
    }

    void logInfo(const string& msg) {
        addLog("INFO", msg);
    }

    void logWarning(const string& msg) {
        addLog("WARN", msg);
    }

    void logError(const string& msg) {
        addLog("ERROR", msg);
    }

    vector<string> getLogs(const string& role) {
        if (role == "auditor") {
            return logs;
        } else {
            return {};
        }
    }
};

int main() {
    Logger logger;

    logger.logInfo("Network module started");
    logger.logWarning("Database response delayed");
    logger.logError("File not found in Storage module");

    vector<string> auditLogs = logger.getLogs("auditor");

    for (string log : auditLogs) {
        cout << log << endl;
    }

    vector<string> blockedLogs = logger.getLogs("guest");

    if (blockedLogs.empty()) {
        cout << "Access denied for unauthorized role." << endl;
    }

    return 0;
}
