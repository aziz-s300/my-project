
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

enum enMenu
{
    ShowProducts = 1,
    AddProduct = 2,
    RemoveProduct = 3,
    UpdateProduct = 4,
    ViewCart = 5,
    CreateInvoice = 6,
    EmptyCart = 7,
    Exit = 0
};
const int MAX = 50;
struct Product
{
    string Name;
    int Price;
    int Stock;
    int CartQty;
};
int ProductCount = MAX;
Product Products[MAX];
void LoadProducts()
{
    string Names[MAX] =
    {
        "Apple","Banana","Orange","Milk","Bread","Eggs","Rice","Sugar","Salt","Tea",
        "Coffee","Juice","Water","Cheese","Butter","Yogurt","Chicken","Beef","Fish","Tomato",
        "Potato","Onion","Carrot","Pepper","Mango","Lettuce","Soap","Shampoo","Paste","Brush",
        "Book","Pen","Pencil","Eraser","Ruler","Bag","Phone","Charger","Mic","board",
        "Mouse","Monitor","Laptop","Tablet","Printer","Camera","Speaker","Flash","SSD","USB"
    };

    int Prices[MAX] =
    {
        120,150,180,200,130,140,100,160,110,125,
        170,180,210,120,150,160,500,800,700,300,
        250,200,150,180,220,170,150,120,180,140,
        250,150,130,120,110,100,1000,150,200,300,
        150,500,300,900,800,1200,250,170,400,350
    };

    int Stocks[MAX] =
    {
        100,100,100,50,50,60,40,70,80,90,
        30,30,200,20,15,25,10,10,10,50,
        60,70,80,90,100,100,40,30,50,60,
        200,300,300,200,150,20,10,40,30,25,
        20,10,15,37,26,18,19,50,30,25
    };

    for (int i = 0; i < ProductCount; i++) {
        Products[i].Name = Names[i];
        Products[i].Price = Prices[i];
        Products[i].Stock = Stocks[i];
        Products[i].CartQty = 0;
    }
}
int ReadNumber(string Message)
{
	int Number;
	do
    {
		cout << Message;
		cin >> Number;
        if (cin.fail())
        {
            cin.clear();
			cin.ignore(1000, '\n') ;
			cout << "Invalid choice Please enter a number.\n\n";

			Number = -1;
        }
	} while (Number < 0);
	return Number;
}
void Loading()
{
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << "\n\n";
}
string Tabs(int NumberOfTabs)
{
    string Tabs = "";
    for (int i = 0; i < NumberOfTabs; i++)
        Tabs += "\t";
    return Tabs;
}
void showProducts()
{
    cout << "\n";

    cout << "   =================================================================================================================\n";
    cout << Tabs(7) << "PRODUCTS\n";
    cout << "   =================================================================================================================\n\n";

    cout << "   | "
        << setw(7) << "Index"
        << "| " << setw(18) << "Name"
        << "| " << setw(12) << "Price"
        << "| " << setw(10) << "Stock"

        << " || "

        << setw(7) << "Index"
        << "| " << setw(18) << "Name"
        << "| " << setw(12) << "Price"
        << "| " << setw(10) << "Stock"
        << "|\n";

    cout << "   -----------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 25; i++)
    {
        int RightSide = i + 25 ;

        cout << "   | "
            << setw(7) << i + 1
            << "| " << setw(18) << Products[i].Name
            << "| " << setw(12) << (to_string(Products[i].Price) + "$")
            << "| " << setw(10) << Products[i].Stock

            << " || "

            << setw(7) << RightSide + 1
            << "| " << setw(18) << Products[RightSide].Name
            << "| " << setw(12) << (to_string(Products[RightSide].Price) + "$")
            << "| " << setw(10) << Products[RightSide].Stock
            << "|\n";
    }

    cout << "====================================================================================================================\n";
}
void PrintProductCard(int Index)
{

    cout << Tabs(5) << "__________________________________\n";
    cout << Tabs(5) << " PRODUCT CARD : - \n";
    cout << Tabs(5) << "__________________________________\n";
    cout << Tabs(5) << "  Product     :" << Tabs(2) << Products[Index].Name << "\n";
    cout << Tabs(5) << "  Price       :" << Tabs(2) << ( to_string(Products[Index].Price) + "$") << "\n";
    cout << Tabs(5) << "  Quantity    :" << Tabs(2) << Products[Index].CartQty << "\n";
    cout << Tabs(5) << "__________________________________\n\n";
}
bool IsValidIndex(int Index)
{
    if (Index < 0 || Index >= ProductCount)
    {
        cout << Tabs(5) << "Invalid index\n";
        return false;
    }

    return true;
}
bool CheckQuantity(int Qty, int Stock)
{
    if (Qty <= 0)
    {
        cout << Tabs(5) << "Invalid quantity\n";
        return false;
    }

    if (Qty > Stock)
    {
        cout << Tabs(5) << "Not enough stock\n";
        return false;
    }

    return true;
}
void addProduct()
{

    cout << Tabs(5)
        << "====================\n"
        << Tabs(5)
        << " ADDING PRODUCT ...\n"
        << Tabs(5)
        << "====================\n";
    int Index, Qty;
	cout << "\n";
    Index = ReadNumber("\n\t\t\t\t\tEnter product index: ") ;
    Index -=  1;

    if (!IsValidIndex(Index))
    {
        return;
    }

    Qty = ReadNumber("\t\t\t\t\tEnter quantity: ");

    if (!CheckQuantity(Qty, Products[Index].Stock))
    {
        return;
    }
    cout << "\n";
    cout << Tabs(5) << "Adding product";
    Loading();

    Products[Index].CartQty += Qty;
    Products[Index].Stock -= Qty;
    cout << "\n";
    cout << Tabs(5) << " Product Added successfully : ) \n";
    PrintProductCard(Index);


}
void removeProduct()
{
    cout << Tabs(5)
        << "====================\n"
        << Tabs(5)
        << "   REMOVING ...\n"
        << Tabs(5)
        << "====================\n";
    cout << "\n";
    int Index = ReadNumber("\n\t\t\t\t\tEnter product index to remove: ") ;
    Index = Index - 1;

    if (!IsValidIndex(Index))
    {
        return;
    }

    if (Products[Index].CartQty == 0)
    {
        cout << Tabs(5) << "Product not found in cart.\n";
        return;
    }
    cout << "\n";
    cout << Tabs(5) << "Removing product";
    Loading();

    Products[Index].Stock += Products[Index].CartQty;
    Products[Index].CartQty = 0;

    cout << Tabs(5) << "Removed successfully\n";
}
void emptycart()
{
    cout << "\n";
    cout << Tabs(5) << "Emptying cart";
    Loading();
    for (int i = 0; i < ProductCount; i++)
    {
        Products[i].Stock += Products[i].CartQty;
        Products[i].CartQty = 0;
    }
    cout << "\n";
    cout << Tabs(5) << "=========================== \n";
    cout << Tabs(5) << "Cart emptied successfully.\n";
    cout << Tabs(5) << "=========================== \n";
}
void updateProduct()
{
    cout << Tabs(5)
        << "====================\n"
        << Tabs(5)
        << " UPDATING PRODUCT ...\n"
        << Tabs(5)
        << "====================\n";
    int Index, Qty;
    cout << "\n";
    Index = ReadNumber("\n\t\t\t\t\tEnter product index: ");
    Index = Index - 1;

    if (!IsValidIndex(Index))
    {
        return;
    }

    if (Products[Index].CartQty == 0)
    {
        cout << Tabs(5) << "Product not found in cart.\n";
        return;
    }
    Qty = ReadNumber("\n\t\t\t\t\tEnter new quantity: ");

    Products[Index].Stock += Products[Index].CartQty;

    if (!CheckQuantity(Qty, Products[Index].Stock))
    {
        Products[Index].Stock -= Products[Index].CartQty;
        return;
    }
    cout << "\n";
    cout << Tabs(5) << "Updating product";
    Loading();

    Products[Index].CartQty = Qty;
    Products[Index].Stock -= Qty;
    cout << Tabs(5) << "Updated successfully\n";
}
int CalculateTotal()
{
    int Total = 0;

    for (int i = 0; i < ProductCount; i++)
    {
        Total += Products[i].CartQty * Products[i].Price;
    }

    return Total;
}
void viewCart()
{
    cout << "\n";

    cout << "\t=================================================================================================\n";
    cout << Tabs(7) << "Cart\n";
    cout << "\t=================================================================================================\n\n";

    cout << "\t| "
        << setw(16) << "Index"
        << "| " << setw(25) << "Item"
        << "| " << setw(15) << "Quantity"
        << "| " << setw(15) << "Price"
        << "| " << setw(15) << "Total"
        << "|\n";

    cout << "\t-------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < ProductCount; i++)
    {
        if (Products[i].CartQty > 0)
        {
            int ItemTotal = Products[i].CartQty * Products[i].Price;

            cout << "\t| "
                << setw(16) << i + 1
                << "| " << setw(25) << Products[i].Name
                << "| " << setw(15) << Products[i].CartQty
                << "| " << setw(15) << Products[i].Price
                << "| " << setw(15) << ItemTotal
                << "|\n";
        }
    }

    cout << "\t=================================================================================================\n";

    cout << "\n"
         <<Tabs(6) <<"Total : " << CalculateTotal() << endl;
}
float ApplyDiscount(int Total)
{
    if (Total > 5000)
        return Total * 0.8;
    else if (Total > 1000)
        return Total * 0.9;

    return Total;
}
//void createinvoice()
//{
//    int total = CalculateTotal();
//    float finalTotal = ApplyDiscount(total);
//
//    if (total == 0)
//    {
//		cout << "\n\n";
//        cout << Tabs(5) << "Cart is empty.\n";
//        return;
//    }
//	cout << "\n";
//    cout << Tabs(5) << "Creating invoice";
//    Loading();
//    fstream file;
//    file.open("invoice.txt", ios::out);
//
//    if (file.is_open())
//    {
//        file << left;
//
//        file << "---------------- Invoice ----------------\n\n";
//
//        file << setw(15) << "Item"
//            << setw(10) << "Qty"
//            << setw(10) << "Price"
//            << setw(10) << "Total" << endl;
//
//        file << "-----------------------------------------\n";
//
//        for (int i = 0; i < ProductCount; i++)
//        {
//            if (Products[i].CartQty > 0)
//            {
//                file << setw(15) << Products[i].Name
//                    << setw(10) << Products[i].CartQty
//                    << setw(10) << Products[i].Price
//                    << setw(10) << Products[i].CartQty * Products[i].Price
//                    << endl;
//            }
//        }
//
//        file << "\n-----------------------------------------\n";
//
//        file << "Total: " << total << endl;
//        file << "Final after discount: " << finalTotal << endl;
//
//        file.close();
//
//        cout << "Invoice saved successfully.\n";
//    }
//    else
//    {
//        cout << "Can not open file.\n";
//    }
//}
void createinvoice()
{
    int total = CalculateTotal();
    float finalTotal = ApplyDiscount(total);

    if (total == 0)
    {
        cout << "\n\n";
        cout << Tabs(5) << "Cart is empty.\n";
        return;
    }

    cout << "\n";
    cout << Tabs(5) << "Creating invoice";
    Loading();

    fstream file;
    file.open("invoice.txt", ios::out);

    if (file.is_open())
    {


        file << "\t\t=============================================\n";
        file << "\t\t              MARKET SYSTEM\n";
        file << "\t\t             RECEIPT INVOICE\n";
        file << "\t\t=============================================\n\n";

        file << "\t\t"
            << setw(15) << "Product Name"
            << setw(10) << "Qty"
            << setw(10) << "Price"
            << setw(10) << "Total"
            << endl;

        file << "\t\t---------------------------------------------\n";

        for (int i = 0; i < ProductCount; i++)
        {
            if (Products[i].CartQty > 0)
            {
                file << "\t\t"
                    << setw(15) << Products[i].Name
                    << setw(10) << Products[i].CartQty
                    << setw(10) << Products[i].Price
                    << setw(10) << Products[i].CartQty * Products[i].Price
                    << endl;
            }
        }

        file << "\n\t\t---------------------------------------------\n\n";

        file << "\t\tSum Total : " << total << "$\n";

        if (finalTotal < total)
        {
            file << "\t\tDiscount  : "
                << total - finalTotal
                << "$\n";
        }

        file << "\t\tGrand Total : " << finalTotal << "$\n";

        file << "\n\t\t=============================================\n";
        file << "\t\t      Thank you for shopping with us!\n";
        file << "\t\t=============================================\n";

        file.close();

        cout << Tabs(5)
            << "Invoice saved successfully.\n";
    }
    else
    {
        cout << Tabs(5)
            << "Can not open file.\n";
    }
}
void ClearScreen()
{
    system("cls");
}
void LoginScreen(string& Username, string& Password)
{
    cout << "\n\n\n\n";

    cout << Tabs(5)<< "=====================================\n";
    cout << Tabs(5)<< "           LOGIN SYSTEM\n";
    cout << Tabs(5)<< "=====================================\n\n";

    cout << Tabs(5) << " Enter Username : ";
    getline(cin >> ws , Username);

    cout << Tabs(5) << " Enter Password : ";
    getline(cin, Password);

    cout << Tabs(5) << "=====================================\n";
}
void PauseAndClear()
{
    system("pause");
    system("cls");
}
void WelcomeScreen()
{
    cout << "\n\n\n";

    cout << Tabs(3) << "  __          __  ______   _         _____    ____    __  __   ______ " << endl;
    cout << Tabs(3) << "  \\ \\        / / |  ____| | |       / ____|  / __ \\  |  \\/  | |  ____|" << endl;
    cout << Tabs(3) << "   \\ \\  /\\  / /  | |__    | |      | |      | |  | | | \\  / | | |__   " << endl;
    cout << Tabs(3) << "    \\ \\/  \\/ /   |  __|   | |      | |      | |  | | | |\\/| | |  __|  " << endl;
    cout << Tabs(3) << "     \\  /\\  /    | |____  | |____  | |____  | |__| | | |  | | | |____ " << endl;
    cout << Tabs(3) << "      \\/  \\/     |______| |______|  \\_____|  \\____/  |_|  |_| |______|" << endl;

    cout << "\n";
    cout << Tabs(5) << "Welcome to Market System :)\n\n";

    PauseAndClear();
}
void ThankYouScreen()
{
    cout << "\n\n\n";

    cout << "  _______  _    _             _   _  _  __  __     __  ____   _    _  " << endl;
    cout << " |__   __|| |  | |    /\\     | \\ | || |/ /  \\ \\   / / / __ \\ | |  | | " << endl;
    cout << "    | |   | |__| |   /  \\    |  \\| || ' /    \\ \\_/ / | |  | || |  | | " << endl;
    cout << "    | |   |  __  |  / /\\ \\   | . ` ||  <      \\   /  | |  | || |  | | " << endl;
    cout << "    | |   | |  | | / ____ \\  | |\\  || . \\      | |   | |__| || |__| | " << endl;
    cout << "    |_|   |_|  |_|/_/    \\_\\ |_| \\_||_|\\_\\     |_|    \\____/  \\____/  " << endl;

    cout << "\n";
    cout << Tabs(5) << "Thanks for using Market System :)\n\n";

    PauseAndClear();
}
bool Login()
{
    fstream MyFile;
    MyFile.open("login.txt", ios::in);

    if (!MyFile)
    {
        cout << Tabs(5) << "Cannot open file.\n";
        return false;
    }

    string UserAndPass[2];
    string Line;
    int i = 0;


    while (getline(MyFile, Line) && i < 2)
    {
        UserAndPass[i] = Line;
        i++;
    }

    MyFile.close();

    string Username, Password;

    while (true)
    {
        int Attempts = 3;

        while (Attempts > 0)
        {
            LoginScreen(Username, Password);
            cout << "\n";
            cout << Tabs(5) << "Checking ";
            Loading();

            if (Username == UserAndPass[0] &&
                Password == UserAndPass[1])
            {
                cout << Tabs(5) << "Login successful\n";
                PauseAndClear();
                return true;
            }

            Attempts--;

            cout << Tabs(5) << "Invalid username or password\n";

            if (Attempts > 0)
                cout << Tabs(5) << "Attempts remaining: " << Attempts << " / 3\n";
            PauseAndClear();
        }

        cout << Tabs(5) << "\nToo many failed attempts.\n";
        cout << Tabs(5) << "System locked for 5 seconds...\n";
        Sleep(5000);
        cout << Tabs(5) << "You can try again now.\n";
    }

    return false;
}
void menu()
{
    cout << "\n\n\n\n";
    cout << Tabs(5) << "=========================\n";
    cout << Tabs(6) << "  MENU\n";
    cout << Tabs(5) << "=========================\n\n";
    cout << Tabs(5) << " 1. Show Products\n";
    cout << Tabs(5) << " 2. Add Product\n";
    cout << Tabs(5) << " 3. Remove Product\n";
    cout << Tabs(5) << " 4. Update Product\n";
    cout << Tabs(5) << " 5. View Cart\n";
    cout << Tabs(5) << " 6. Create Invoice\n";
    cout << Tabs(5) << " 7. Empty Cart\n";
    cout << Tabs(5) << " 0. Exit\n\n";
    cout << Tabs(5) << "=========================\n";
}
void RunMenu()
{
    int Choice;

    do
    {
        menu();

        Choice = ReadNumber("\n\t\t\t\t\tEnter choice: ");

        ClearScreen();

        switch (Choice)
        {
        case ShowProducts:
            showProducts();
            PauseAndClear();
            break;

        case AddProduct:
            addProduct();
            PauseAndClear();
            break;

        case RemoveProduct:
            removeProduct();
            PauseAndClear();
            break;

        case UpdateProduct:
            updateProduct();
            PauseAndClear();
            break;

        case ViewCart:
            viewCart();
            PauseAndClear();
            break;

        case CreateInvoice:
            createinvoice();
            PauseAndClear();
            break;

        case EmptyCart:
            emptycart();
            PauseAndClear();
            break;

        case Exit:
            ThankYouScreen();
            cout <<"\n\n\n\n\n\n" << Tabs(6) << "Exiting...\n";

            break;

        default:
            cout << "\n\n\n\n\n\n\n" << Tabs(5) << "Invalid choice Please try again.\n";
            PauseAndClear();
        }

    } while (Choice != Exit);
}
int main()
{
    LoadProducts();

    /*if (Login())*/
   /* {
        WelcomeScreen();*/
        RunMenu();
   /* }
    else*/
       return 0;
}

