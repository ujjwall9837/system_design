#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FileSystemItem
{
public:
    virtual ~FileSystemItem() {}
    virtual void ls(int indent = 0) = 0;
    virtual void openAll(int indent = 0) = 0;
    virtual FileSystemItem *cd(const string &name) = 0;
    virtual string getName() = 0;
    virtual int getSize() = 0;
    virtual bool isFolder() = 0;
};

class File : public FileSystemItem
{
    string name;
    int size;

public:
    File(const string &name, int size)
    {
        this->name = name;
        this->size = size;
    }
    void ls(int indent) override
    {
        cout << string(indent, ' ') << name << endl;
    }

    void openAll(int indent) override
    {
        cout << string(indent, ' ') << name << endl;
    }

    int getSize() override
    {
        return size;
    }
    string getName() override
    {
        return name;
    }
    bool isFolder() override
    {
        return false;
    }

    FileSystemItem *cd(const string &dirName)
    {
        return nullptr;
    }
};

class Folder : public FileSystemItem
{
    string name;
    vector<FileSystemItem *> files;

public:
    Folder(const string &name)
    {
        this->name = name;
    }
    void add(FileSystemItem *item)
    {
        files.push_back(item);
    }
    void ls(int indent) override
    {
        for (auto f : files)
        {
            if (f->isFolder())
            {
                cout << string(indent, ' ') << "+ " << f->getName() << endl;
            }
            else
            {
                cout << string(indent, ' ') << f->getName() << endl;
            }
        }
    }
    void openAll(int indent) override
    {
        cout << string(indent, ' ') << "+ " << name << endl;
        for (auto f : files)
        {
            f->openAll(indent + 4);
        }
    }
    string getName() override
    {
        return name;
    }
    int getSize() override
    {
        int total = 0;
        for (auto f : files)
        {
            total += f->getSize();
        }
        return total;
    }
    FileSystemItem *cd(const string &target) override
    {
        for (auto f : files)
        {
            if (f->isFolder() && f->getName() == target)
            {
                return f;
            }
        }
        return nullptr;
    }
    bool isFolder() override
    {
        return true;
    }
};
int main()
{
    Folder *root = new Folder("root");
    root->add(new File("file1.txt", 1));
    root->add(new File("file2.txt", 1));
    root->add(new File("file3.txt", 1));

    Folder *docs = new Folder("docs");
    docs->add(new File("resume.pdf", 1));
    docs->add(new File("notes.pdf", 1));
    root->add(docs);
    Folder *images = new Folder("images");
    images->add(new File("photo.jpg", 1));
    root->add(images);

    root->openAll(2);
    root->ls(2);
    cout << root->getSize() << images->getSize();
    return 0;
}
