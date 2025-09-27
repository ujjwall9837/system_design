#include <iostream>
using namespace std;
class ITextBox
{
public:
    virtual void showText() = 0;
};

class IButton
{
public:
    virtual void press() = 0;
};
class IFactory
{
public:
    virtual IButton *CreateButton() = 0;
    virtual ITextBox *CreateTextBox() = 0;
};

class MacButton : public IButton
{
public:
    void press()
    {
        cout << "Mac Button pressed" << endl;
    }
};
class WindowsButton : public IButton
{
public:
    void press()
    {
        cout << "Windows Button pressed" << endl;
    }
};

class MacTextBox : public ITextBox
{
public:
    void showText()
    {
        cout << "Mac TEXT completed" << endl;
    }
};
class WindowsTextBox : public ITextBox
{
public:
    void showText()
    {
        cout << "Windows TExt Completed" << endl;
    }
};

class MacFactory : public IFactory
{
public:
    IButton *CreateButton()
    {
        return new MacButton();
    }
    ITextBox *CreateTextBox()
    {
        return new MacTextBox();
    }
};
class WindowsFactory : public IFactory
{
public:
    IButton *CreateButton()
    {
        return new WindowsButton();
    }
    ITextBox *CreateTextBox()
    {
        return new WindowsTextBox();
    }
};
class GUIAbstractFactory
{
public:
    static IFactory *CreateFactory(string osType)
    {
        if (osType == "Mac")
        {
            return new MacFactory();
        }
        else if (osType == "Windows")
        {
            return new WindowsFactory();
        }
        else
        {
            return new WindowsFactory();
        }
    }
};
int main()
{
    cout << "Hello, Abstract Design Pattern!" << endl;
    cout << "Enter your OS type" << endl;
    string osType;
    cin >> osType;
    IFactory *fact = GUIAbstractFactory::CreateFactory(osType);
    IButton *button = fact->CreateButton();
    button->press();
    ITextBox *textBox = fact->CreateTextBox();
    textBox->showText();
    return 0;
}