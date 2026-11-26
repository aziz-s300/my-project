# 🛒 E-Commerce Store System (C++)

A console-based **E-Commerce Store System** developed in C++. The application simulates a complete online shopping experience, allowing users to log in, browse products, manage their shopping cart, benefit from conditional discount offers, and generate purchase invoices.

---

## ✨ Key Features

- **User Login System:** Authenticates users using stored credentials (`login.txt`).
- **Product Catalog:** Displays available store products with their prices and details.
- **Shopping Cart Management:**
  - Add products to the shopping cart.
  - Remove products from the shopping cart.
  - Review cart items and calculate the total cost.
- **Conditional Discount Offers:** Automatically applies special discounts when specific purchasing conditions are met.
- **Purchase & Invoicing:** Completes the checkout process and records the final receipt in `invoice.txt`.

---

## 📂 Project Files

- `project with c++.cpp` — Main C++ source code containing the store logic.
- `project with c++.vcxproj` / `.slnx` — Visual Studio project and solution files.
- `login.txt` — Stores user login credentials.
- `invoice.txt` — Stores generated customer purchase invoices.
- `README.md` — Project overview and documentation.

---

## 🚀 How to Run

1. Open the project in **Visual Studio** (using `project with c++.slnx` or `.vcxproj`) or compile `project with c++.cpp` using any C++ compiler (`g++`).
2. Make sure `login.txt` and `invoice.txt` are in the same directory as the executable file.
3. Run the application and follow the on-screen menu options to log in, shop, and check out.

---

## 🛠️ Technologies Used

- **Programming Language:** C++
- **File Handling:** C++ Standard File Streams (`fstream`) for reading user data and saving invoices