#include <iostream>
using namespace std;

class User
{
private:
    int id;
    string password;

public:
    string userName;

    User(int id)
    {
        this->id = id;
    }

    // Getter
    string getPassword()
    {
        return password;
    }
    // Setter
    void setPassword(string password)
    {
        this->password = password;
    }
};

int main()
{
    User user1(101);
    user1.userName = "Miskat Ahmmed";
    user1.setPassword("abcd");

    cout << "username: " << user1.userName << endl;
    cout << "password: " << user1.getPassword() << endl;

    return 0;
}