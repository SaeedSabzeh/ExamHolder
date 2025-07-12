# 📝 ExamHolder

**ExamHolder** is a Windows-based C++/CLI application that enables professors to create and host timed exams, and allows students to securely take those exams. The software features a user-friendly GUI built using Windows Forms and is suitable for local network or single-machine use in academic or training environments.

---

## 🚀 Features

### For Professors:
- Create custom exams with multiple questions
- Secure login for exam management
- Set time limits and control access
- View and manage student submissions

### For Students:
- Simple login interface
- Answer questions within a set time limit
- Automatic submission when time expires

---

## 🛠️ Installation & Build

### 🔧 Requirements:
- **Visual Studio** (2019 or later)
- **Windows OS**
- **.NET Framework 4.x**
- C++/CLI support enabled

### 🏗️ Build Steps:
1. Open `Project4/Project4.vcxproj` in Visual Studio.
2. Set the configuration to `Release` or `Debug` as needed.
3. Build the solution using `Ctrl+Shift+B`.
4. Run the generated `.exe` from the `Release` or `Debug` folder.

---

## 📁 Project Structure

```
Project4/
│
├── MyForm*.cpp/.h/.resx     # Various forms and interface windows
├── PRO.cpp/.h/.resx         # Main dashboard or initial interface
├── Professor.cpp/.h         # Professor panel logic
├── PRO_SIGN.cpp/.h          # Professor sign-in/sign-up window
├── STU.cpp/.h               # Student interface and logic
├── *.vcxproj*               # Visual Studio project files
```

---

## 🧠 Design Notes

- The application separates the logic of student and professor modes clearly via dedicated forms.
- Timing, input validation, and exam submission are managed in the background using C++/CLI capabilities.
- Resource files (`.resx`) are used to manage GUI layouts in Windows Forms.

---

## 📌 Future Improvements

- Add encrypted local database support (e.g., SQLite)
- Integrate question formats like multiple choice, code, or essay
- Export student results to CSV or Excel
- Network-based syncing for remote exam hosting

---

## 👤 Author

**Saeed Sabzeh**  
AI & Computer Science Enthusiast  
GitHub: [@SaeedSabzeh](https://github.com/SaeedSabzeh)

---

## 📃 License

This project is released under the **MIT License**.  
Feel free to use, modify, and distribute as needed.
