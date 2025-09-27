#include <iostream>
#include <vector>
using namespace std;

class Product
{
private:
    string name;
    int price;

public:
    Product(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{
private:
    vector<Product*> products;

public:
    void addProduct(Product* product)
    {
        products.push_back(product);
    }
    vector<Product*> &getProducts() {
        return products;
    };
};
int main()
{

    cout << "Single Responsibility Principle" << endl;
    return 0;
}