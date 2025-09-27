#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DocumentEditor
{
private:
    vector<string> documentElements;
    string renderedDocument;

public:
    void addText(string text)
    {
        // Add text to the document
        documentElements.push_back(text);
    }

    void addImage(string imagePath)
    {
        // Add image to the document
        documentElements.push_back(imagePath);
    }
    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            string result;
            for (auto element : documentElements)
            {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" || element.substr(element.size() - 1) == ".png"))
                {
                    result += "[Image: " + element + "]\n";
                }
                else
                {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile()
    {
        // Save the rendered document to a file
        ofstream file("docs.txt");
        if (file.is_open())
        {
            file << renderDocument();
            file.close();
            cout << "Document saved to " << "docs.txt" << endl;
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }
    }
};
int main()
{ 
    cout << "Start saving the data" << endl;
    DocumentEditor editor;
    editor.addText("Hello, this is a sample document.");
    editor.addImage("image1.jpg");
    editor.addText("This document contains both text and images.");
    string text = editor.renderDocument();
    cout << text;
    editor.saveToFile();   
    return 0;
}