# main.cpp
# Event Manager (C++ Console Application)

## 📌 Project Description
This project is a console-based event management system developed in C++.  
It allows users to create, store, search, and delete event records.  

All information is saved in a local file, which ensures data persistence between program runs.  
The application was created as part of educational practice to improve programming skills in C++.

---

## ⚙️ Main Features
The program includes the following functionality:

- ➕ Add new event (ID, title, date, location)
- 📋 Display all saved events in a structured format
- 🔎 Search events by title keyword
- ❌ Delete event by ID
- 💾 Automatic saving of data to file
- 📂 Loading data on program start

---

## 🧠 Program Logic
The system works in a simple loop-based menu:

1. User selects an action from the menu
2. Program performs the selected operation
3. Data is updated in memory
4. Changes are saved to a file (events.txt)

This ensures that no data is lost after closing the application.

---

## 💾 Data Storage
All event data is stored in a text file:
