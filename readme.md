# 🎓 College Management System (C Language)

This repository contains **two versions** of the College Management System:

✅ **1) Console / CMD Version (C)**  
✅ **2) Website Version (C + CGI + XAMPP + HTML/CSS)**  

---

# ✅ Version 1: Console / CMD Project

## 📌 Project Description
This is a **College Management System** built using **C Programming** as a **console-based application**.  
It manages student records using structured programming and file handling.

---

## 🚀 Features
✅ Add Student  
✅ Search Student  
✅ Update Student  
✅ Delete Student  
✅ Count Students  
✅ Data saved in file (`students.dat`)  

---

## 🛠 Technologies Used
- Language: C  
- Concepts: Structure, Functions, Switch Case, File Handling  
- IDE: VS Code  
- Version Control: Git & GitHub  

---

## ▶️ How to Run (Console)
### 1) Compile
```bash
gcc college.c -o college
2) Run
bash
Copy code
./college
✅ Windows:

bash
Copy code
college.exe
💾 Data Storage
Records are saved in:

students.dat

✅ Data remains saved even after program closes.

✅ Version 2: Website / XAMPP + CGI Project
📌 Project Description
This is a Web-based College Management System built using:

✅ C Programming (CGI Backend)
✅ HTML + CSS (Frontend UI)
✅ Apache Server (XAMPP)
✅ File Handling for Persistent Storage

It performs student record operations through a website interface.

🚀 Features
✅ Add Student (UID based)
✅ View Students (Table)
✅ Search Student by UID
✅ Update Student by UID
✅ Delete Student by UID
✅ Count Total Students
✅ Data stored in file (students.dat)

🛠 Technologies Used
Backend: C (CGI Executables)

Frontend: HTML, CSS

Server: Apache (XAMPP)

Storage: File Handling (students.dat)

IDE: VS Code

📂 Website Project Structure (XAMPP)
Frontend (UI Pages)
txt
Copy code
C:\xampp4\htdocs\college\
  index.html
  view.html
  search.html
  delete.html
  update.html
  count.html
Data Storage
txt
Copy code
C:\xampp4\htdocs\data\
  students.dat
Backend (CGI Programs)
txt
Copy code
C:\xampp4\cgi-bin\
  addstudent.c / addstudent.exe
  viewstudents.c / viewstudents.exe
  searchstudent.c / searchstudent.exe
  deletestudent.c / deletestudent.exe
  updatestudent.c / updatestudent.exe
  countstudents.c / countstudents.exe
▶️ How to Run (Website)
Step 1: Start Apache
Open XAMPP Control Panel → Start Apache

Step 2: Open Website
Run in browser:

txt
Copy code
http://localhost/college/
💾 Data Storage
Student records are stored in:

txt
Copy code
C:\xampp4\htdocs\data\students.dat
👨‍💻 Author
Sudhanshu Pandey
GitHub: https://github.com/sudhanshupandey1234

⭐ This project was developed for academic learning to understand structured programming and file handling concepts in C

