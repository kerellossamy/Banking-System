# Banking System with Currency Exchange – C++ Console Application

A secure, console-based banking system developed in C++ that supports currency exchange, user management, encrypted transactions, and detailed system logging. Built as a Visual Studio project using file-based storage (no external databases).

---

## 🔧 Features

- **User & Client Management**  
  Perform full CRUD (Create, Read, Update, Delete) operations on users and clients.

- **Permissions & Roles**  
  Implements role-based access control to restrict data visibility and operations.

- **Secure Authentication**  
  Passwords are encrypted before being stored in files for enhanced security.

- **Transactions Support**  
  Clients can:
  - Deposit and withdraw funds
  - Transfer money to other clients (within the system)
  - Exchange currencies

- **System Logging**  
  Tracks:
  - User login events
  - All financial transactions

- **Currency Exchange**  
  Clients can convert between different currencies (static rates defined in code).

---

## 💻 Technologies Used

- **C++** (Core language)
- **Visual Studio** (Development environment)
- **File I/O** (Storage and logging)
- **Encryption** (Basic password encryption for security)

---

## 📁 Project Structure (with filters in Visual Studio)
![Project Structure](https://github.com/user-attachments/assets/9b783c07-8910-46fb-a439-9b54d49a3f86)

---
## 📸 Screenshots

### 1. Login Screen
![2025-05-23 22_21_46-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/4742340f-5872-4fd2-833b-a2ca07015924)
![2025-05-23 22_20_48-Microsoft Visual Studio Debug Console](https://github.com/user-attachments/assets/81a3e008-8877-43aa-a239-981576742786)

### 2. Main Menu Screen
![2025-05-23 22_22_34-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/383a85e5-f83a-48ec-b716-aaf4a88e0bed)

### 3. Clients List Screen
![2025-05-23 22_22_54-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/4620c64a-94f4-41b1-b370-aed9c955405b)

### 5. Add Client Screen
![2025-05-23 22_24_43-Select C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank P](https://github.com/user-attachments/assets/300df8c4-8e35-492d-8841-74f9f74bb501)

### 6. Update Client Screen
![2025-05-23 22_26_19-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/009c3bd2-de4a-4c64-8aa9-9edec3ff867a)

### 7. Find Client Screen
![2025-05-23 22_28_38-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/0b5c2350-1be0-4831-9a44-21716c8bf39b)

### 8. Transactions Screen
![2025-05-23 22_29_17-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/48dec554-d384-414a-8a1d-466c336de367)

### 9. Deposit Screen
![2025-05-23 22_29_47-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/4dd48ae4-9b7b-44ce-af5d-7ac27541d33b)

### 10. Withdraw Screen
![2025-05-23 22_30_27-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/4cfa4f7a-394e-44f0-aeac-222a6b7f6efb)

### 11. Balances List Screen
![2025-05-23 22_30_58-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/2d740f89-e0af-4269-988d-c77e2e32d00b)

### 12. Transfer Balance Screen
![2025-05-23 22_31_59-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/ff3f2ed2-41f3-47e7-95de-4271037e51d2)

### 13. Transfer Log List Screen
![2025-05-23 22_32_23-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/465f3342-4271-461b-aef5-e1f8c675efaf)

### 14. Manage Users Screen
![2025-05-23 22_33_06-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/432d2100-a260-4c75-a769-6c1eefebdf70)

### 15. Users List Screen
![2025-05-23 22_33_21-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/8f79cfe1-bd34-4ee0-96a6-15bef8943149)

### 16. Add New User Screen
![2025-05-23 22_35_34-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/1035b383-964f-4392-8ca7-0fa2fca5b566)

### 17. Access Denied Screen
![2025-05-23 22_37_05-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/24b9969e-faf0-485d-93e1-e4138522cac3)

### 18. Login Logs Screen
![2025-05-23 22_38_34-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/0a0731e8-8420-4242-b868-a68b7c28d211)

### 19. Currency Exchange Main Screen
![2025-05-23 22_39_05-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/7d9e73ea-1384-4f6e-b319-7844a4838a64)

### 20. Currencies List Screen
![2025-05-23 22_39_30-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/1678a58f-c040-4c8f-859c-914d395e4023)

### 21. Find Currency Screen
![2025-05-23 22_40_20-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/cbf9ce1d-aac3-44b8-b856-af1064d04f53)

### 22. Update Currency Rate Screen
![2025-05-23 22_41_17-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/63698890-5c06-42b8-8e54-2d6195130a9e)

### 23. Currency Calculator Screen
![2025-05-23 22_42_05-C__Users_Kerellos Samy_Desktop_Bank Project_Bank Project_x64_Debug_Bank Project](https://github.com/user-attachments/assets/53e9d68d-082f-4249-998a-35aec88783cb)
