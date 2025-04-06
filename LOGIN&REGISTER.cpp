#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    string username, password;

public:
    void registerUser() {
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;
        
        if (isUserExists(username)) {
            cout << "Username already taken! Try again.\n";
            return;
        }
        
        ofstream file(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "Registration successful!\n";
    }
    
    bool loginUser() {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        
        ifstream file(username + ".txt");
        if (!file) {
            cout << "User not found! Register first.\n";
            return false;
        }
        
        string storedUser, storedPass;
        getline(file, storedUser);
        getline(file, storedPass);
        file.close();
        
        if (storedUser == username && storedPass == password) {
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Incorrect credentials!\n";
            return false;
        }
    }
    
    bool isUserExists(const string &user) {
        ifstream file(user + ".txt");
        return file.good();
    }
};

int main() {
    User user;
    int choice;
    
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                user.registerUser();
                break;
            case 2:
                user.loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);
    
    return 0;
}
