# 🚆 Railway Reservation System

A simple **Railway Reservation System** developed in **C++** as a beginner-level programming project. The system allows users to view trains, book tickets, search tickets using PNR, cancel tickets, and view an admin dashboard.

## 📌 Project Overview

The Railway Reservation System is a console-based C++ application designed to demonstrate important programming concepts such as:

* Classes and Objects
* Arrays
* Functions
* Conditional Statements
* Loops
* Switch Case
* File Handling
* Random Number Generation
* String Handling
* Basic Admin Authentication

The project supports **5 trains** and manages ticket bookings with a maximum capacity of **100 tickets** and **50 seats**.

## ✨ Features

### 👤 User Features

1. **Show Available Trains**

   * Displays train number
   * Train name
   * Source
   * Destination

2. **Show Seat Map**

   * Displays all 50 seats
   * `[XX]` represents a booked seat
   * Available seats are displayed with their seat numbers

3. **Book Ticket**

   * Select a train
   * Enter passenger name
   * Enter passenger age
   * Enter journey date
   * Select travel class
   * Automatically assigns an available seat
   * Generates a random PNR
   * Displays the e-ticket

4. **Search Ticket**

   * Search a ticket using its PNR number
   * Displays complete ticket details

5. **Cancel Ticket**

   * Cancel a confirmed ticket using PNR
   * The cancelled seat becomes available again

### 🔐 Admin Features

Admin login provides:

* Total bookings
* Confirmed tickets
* Cancelled tickets
* Available seats
* Total revenue

### 💾 File Handling

Booked ticket information is stored in:

```text
tickets.txt
```

This demonstrates basic file handling using C++ `fstream`.

## 🚆 Available Trains

| Train No. | Train Name          | From      | To          |
| --------- | ------------------- | --------- | ----------- |
| 12001     | Rajdhani Express    | Dibrugarh | New Delhi   |
| 12505     | North East Express  | Guwahati  | Anand Vihar |
| 15909     | Avadh Assam Express | Dibrugarh | Lalgarh     |
| 15685     | Brahmaputra Mail    | Kamakhya  | Delhi       |
| 15617     | Dibrugarh Express   | Dibrugarh | Tinsukia    |

## 💰 Travel Classes

| Class   | Fare |
| ------- | ---: |
| General | ₹150 |
| Sleeper | ₹300 |
| AC      | ₹600 |

## 🛠️ Technologies Used

* **Language:** C++
* **Compiler:** GCC / MinGW
* **IDE:** Dev-C++, Code::Blocks, VS Code, or any C++ IDE
* **File Handling:** `fstream`
* **Random Number Generation:** `cstdlib`, `ctime`

## 📂 Project Structure

```text
Railway-Reservation-System/
│
├── RailwayReservation.cpp
├── tickets.txt
└── README.md
```

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone YOUR_GITHUB_REPOSITORY_LINK
```

### 2. Open the Project

Open `RailwayReservation.cpp` in your preferred C++ IDE.

### 3. Compile the Program

Using g++:

```bash
g++ RailwayReservation.cpp -o RailwayReservation
```

### 4. Run

```bash
./RailwayReservation
```

On Windows:

```bash
RailwayReservation.exe
```

## 🔑 Admin Login

The default admin credentials are:

```text
Username: admin
Password: 1234
```

> This login is included only for demonstration purposes and is not intended for real-world security.

## 🧠 Concepts Demonstrated

This project helped demonstrate the following C++ concepts:

```text
✓ Classes & Objects
✓ Arrays
✓ Functions
✓ Loops
✓ if-else
✓ switch-case
✓ Strings
✓ References
✓ File Handling
✓ Random Number Generation
✓ Basic Authentication
✓ Menu-driven Programming
```

## 📸 Sample Menu

```text
+==========================================+
|       RAILWAY RESERVATION SYSTEM         |
+==========================================+
| 1. Show Available Trains                 |
| 2. Show Seat Map                         |
| 3. Book Ticket                           |
| 4. Search Ticket by PNR                  |
| 5. Cancel Ticket                         |
| 6. Admin Dashboard                       |
| 7. Exit                                  |
+==========================================+
```

## 🚀 Future Improvements

The project can be improved by adding:

* Multiple passenger booking
* Different seats for each passenger
* Login system for users
* Database connectivity
* Online payment simulation
* Train schedule and timings
* Ticket printing
* Better input validation
* GUI interface
* MySQL database integration
* Waiting list system

## 🎯 Purpose

This project was created for **learning and practicing C++ programming concepts** and understanding how a basic real-world reservation system can be implemented using a console application.

## 👨‍💻 Author

**Samir Tanti**

B.Tech Student | C++ Beginner Project

---

⭐ If you found this project useful, consider giving the repository a **star**!
