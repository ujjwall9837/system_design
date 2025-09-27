#include <iostream>
using namespace std;
class XMLData
{
    string xmlData;

public:
    XMLData(string pXmlData)
    {
        xmlData = pXmlData;
    };
    string getXMLData()
    {
        return xmlData;
    }
};

class DataTool
{
    string jsonData;

public:
    DataTool() {}
    DataTool(string pJsonData)
    {
        jsonData = pJsonData;
    }
    virtual void analyseData()
    {
        cout << "Analysing data: " << jsonData << endl;
    }
};



class Adapter : public DataTool
{
    XMLData *xmlData;

public:
    Adapter(XMLData *xmlData)
    {
        xmlData = xmlData;
    };
    void analyseData() override
    {
        string json = xmlData->getXMLData();
        // Simple conversion from XML to JSON for demonstration purposes

        cout << "Converted XML to JSON: " << json << endl;
    }
};

class Client
{
public:
    void ProcessData(DataTool *dataTool)
    {
        dataTool->analyseData();
    }
};
int main()
{
    XMLData *xmlData = new XMLData("sample data");
    // need json data
    DataTool *dataTool = new Adapter(xmlData);
    Client *client = new Client();
    client->ProcessData(dataTool);
    return 0;
}