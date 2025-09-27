#include <iostream>
#include <list>
using namespace std;

class ISubscriber
{
public:
    virtual void notify(string &message) = 0;
};

class User : public ISubscriber
{
private:
    int userId;

public:
    User(int id)
    {
        this->userId = id;
    }
    void notify(string &message)
    {
        cout << "User " << userId << ": " << message << endl;
    }
};
class Group
{
private:
    list<ISubscriber *> users;

public:
    void subcribe(ISubscriber *user)
    {
        users.push_back(user);
    }
    void unsubcribe(ISubscriber *user)
    {
        users.remove(user);
    }
    void notify(string message)
    {
        for (ISubscriber *user : users)
        {
            user->notify(message);
        }
    }
};

int main()
{
    Group *group = new Group;
    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);

    group->subcribe(user1);
    group->subcribe(user2);
    group->subcribe(user3);

    group->notify("Hello, Users!");
    group->unsubcribe(user2);
    group->notify("notifcation after unsubcribe");
    cout << "Observer Design Pattern Example" << endl;
    return 0;
}