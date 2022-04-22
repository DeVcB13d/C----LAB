#include <iostream>
using namespace std;

class Slist
{
    string itemName;
    int itemCode;
    float itemPrice;
    int itemQuantity;
    float totalSum;

public:
    void addItem()
    {
        cout << "Item Name : ";
        cin >> itemName;
        cout << "Item Code : ";
        cin >> itemCode;
        cout << "Item Quantity : ";
        cin >> itemQuantity;
        cout << "Item Price : ";
        cin >> itemPrice;
    }
    void displayItem()
    {
        cout << itemCode << "\t\t" << itemName << "\t\t" << itemPrice << "\t\t" << itemQuantity << endl;
    }
    void alterQuantity(int decrement)
    {
        itemQuantity = itemQuantity - decrement;
    }
    int checkCode()
    {
        return itemCode;
    }
    int checkQuantity()
    {
        return itemQuantity;
    }
    void updateQuantity(int newQuantity)
    {
        itemQuantity = itemQuantity + newQuantity;
    }
    float generateSum()
    {
        return itemQuantity * itemPrice;
    }
    void newQuantity(int newQuantity)
    {
        itemQuantity = newQuantity;
    }
};

Slist *stock = new Slist[10];
Slist *shoppingSList = new Slist[10];
int stockCount = 0;
int shoppingCount = 0;

int main()
{
    int option;
    int choice = 0;
    int keyPosition;
    bool found;
    cout << "MENU\n";
    cout << "1.Add Item\n2.Delete Item\n3.Update Item\n4.Display Items\n5.Purchase Item\n\n";
    cout << "6.Exit\n";
    while (choice != 6)
    {
        cout << "Choose an option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            stock[stockCount].addItem();
            cout << "Item Added Successfully" << endl;
            stockCount++;
            break;
        case 2:
        {
            int searchKey;
            cout << "Item Code : ";
            cin >> searchKey;
            for (int i = 0; i < stockCount; ++i)
            {
                if (searchKey == stock[i].checkCode())
                {
                    found = true;
                    keyPosition = i;
                    cout << "Successfully Deleted" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Invalid Code" << endl;
            }
            else
            {
                for (int i = keyPosition; i < stockCount; ++i)
                {
                    stock[i] = stock[i + 1];
                }
                stockCount--;
            }
        }
        break;
        case 3:
        {
            bool found = false;
            cout << "Item Code\tItem Name\tItem Price\tItem Quantity" << endl;
            for (int i = 0; i < stockCount; ++i)
            {
                stock[i].displayItem();
            }
            int searchKey;
            cout << "Enter the Item Code : ";
            cin >> searchKey;
            for (int i = 0; i < stockCount; ++i)
            {
                if (searchKey == stock[i].checkCode())
                {
                    int x;
                    cout << "Enter the Amount of Quantity : ";
                    cin >> x;
                    stock[i].updateQuantity(x);
                    found = true;
                    cout << "Successfully Updated" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Invalid Code" << endl;
            }
        }
        break;
        case 4:
            cout << "Item Code\tItem Name\tItem Price\tItem Quantity" << endl;
            for (int i = 0; i < stockCount; ++i)
            {
                stock[i].displayItem();
            }
            break;
        case 5:
            int choice = 1;
            while (choice == 1)
            {
                bool purchased = false;
                int tempItemCode, tempItemQuantity;
                cout << "Enter the Item Code" << endl;
                cin >> tempItemCode;
                cout << "Quantity you want to purchase" << endl;
                cin >> tempItemQuantity;
                for (int i = 0; i < stockCount; ++i)
                {
                    if (tempItemCode == stock[i].checkCode())
                    {
                        if (tempItemQuantity > stock[i].checkQuantity())
                        {
                            cout << "Insufficient Stock" << endl;
                            break;
                        }
                        cout << "Came" << endl;
                        purchased = true;
                        shoppingSList[shoppingCount] = stock[i];
                        shoppingSList[shoppingCount].newQuantity(tempItemQuantity);
                        stock[i].alterQuantity(tempItemQuantity);
                        shoppingSList[shoppingCount].displayItem();
                        shoppingCount++;
                        break;
                    }
                }
                cout << "1.Add Items\n2.Generate Bill" << endl;
                cin >> choice;
                float totalSum;
                if (choice == 2 and purchased == true)
                {
                    cout << "Your Purchase Bill" << endl;
                    cout << "Item Code\tItem Name\tItem Price\tItem Quantity" << endl;
                    for (int i = 0; i < shoppingCount; ++i)
                    {
                        shoppingSList[i].displayItem();
                        totalSum = totalSum + shoppingSList[i].generateSum();
                    }
                    cout << "Total Sum = " << totalSum << endl;
                }
            }
            break;
        }
    }
    return 0;
}