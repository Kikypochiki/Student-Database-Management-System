# Student Database Management System

## Features

* **Add Student:** Add new students to the database.
* **Delete Student:** Remove existing students from the database.
* **Edit Student:** Modify information of existing students.
* **View Students:** Display a list of all students.
* **Sort Students:** Sort the student list by various criteria (e.g., name, ID, etc.).

## Prerequisites

* **XAMPP**
* **phpMyAdmin**
* **Code::Blocks**

## Installation and Setup

### XAMPP
1. Download and install XAMPP from the official website.
2. Follow the on-screen instructions to complete the installation.

### phpMyAdmin
1. Start XAMPP and ensure the Apache and MySQL services are running.
2. Open phpMyAdmin in your web browser by entering `http://localhost/phpmyadmin` in the address bar.

### Code::Blocks
1. Download and install Code::Blocks from the official website.
2. Follow the on-screen instructions to complete the installation.

## Database Setup

1. **Copy Libraries and Header Files:**
   - Copy the `mysql` library and header files from the provided directory.
   - Paste them into the appropriate directory in your Code::Blocks installation.

2. **Import SQL Database:**
   - In phpMyAdmin, import the `dbms.sql` file into your MySQL database.

## Running the Application

1. **Open Project in Code::Blocks:**
   - Open the `dbms.cbp` project file in Code::Blocks.

2. **Build and Run:**
   - Build the project to compile the source code.
   - Run the executable to start the application.

3. **Enter IP Address:**
   - When prompted, open a command prompt and type `ipconfig`.
   - Copy the IPv4 address and paste it into the application.

## Additional Notes

* **Database Configuration:**
   - Ensure the database connection details in the code match your MySQL database settings.
* **Error Handling:**
   - Implement proper error handling mechanisms to catch and display error messages.
* **Security:**
   - Secure your database by using strong passwords and limiting access.
   - Consider using prepared statements to prevent SQL injection attacks.
* **User Interface:**
   - Design a user-friendly interface to interact with the database.
   - Provide clear instructions and feedback to the user.
* **Data Validation:**
   - Validate user input to ensure data integrity.
   - Implement input validation checks for fields like name, ID, and contact information.
* **Data Backup:**
   - Regularly back up your database to prevent data loss.
