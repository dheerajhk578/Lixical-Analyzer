# Lixical-Analyzer
Tokenization of program(datatypes, identifiers, Symbols, Operators etc..) and finding the Basic errors.
Here’s a **professional and concise README description** you can use for your **C Project – Lexical Analyzer** on GitHub:

---

## 🔍 Lexical Analyzer in C

This project is a **Lexical Analyzer** implemented in **C programming language**. It reads a source code file and breaks it down into a sequence of **tokens** such as keywords, identifiers, operators, constants, and special symbols — forming the first phase of a compiler.

### 🧠 Project Overview

The **Lexical Analyzer** (also known as a scanner) is responsible for converting the input program into a stream of tokens, which are then passed to the syntax analyzer. This project demonstrates how lexical analysis works internally in compilers.

### ⚙️ Features

* Detects and classifies:

  * **Keywords**
  * **Identifiers**
  * **Operators**
  * **Special characters**
  * **Preprocessor directives**
  * **Numbers and constants**
* Displays the type of each token found in the input source file.
* Easy-to-understand code structure for learning compiler design concepts.

### 🧩 Technologies Used

* **Language:** C
* **Compiler:** GCC / Turbo C
* **File Handling** used to read input program
* **String and Character operations** for token recognition

### 📄 How to Run

1. Clone this repository:

   ```bash
   git clone https://github.com/<your-username>/Lexical-Analyzer.git
   ```
2. Navigate to the project folder:

   ```bash
   cd Lexical-Analyzer
   ```
3. Compile the code:

   ```bash
   gcc lexical_analyzer.c -o lexical_analyzer
   ```
4. Run the executable:

   ```bash
   ./lexical_analyzer
   ```
5. Provide an input source code file (e.g., `input.c`) when prompted.

### 📊 Sample Output

```
Keyword              : int
Identifier           : main
Special Character    : (
Special Character    : )
Special Character    : {
Identifier           : printf
Special Character    : (
String Literal       : "Hello World"
Special Character    : )
Special Character    : ;
Special Character    : }
```

### 🎯 Learning Outcome

This project helped in understanding:

* The **working principle of lexical analysis** in compiler design.
* **Tokenization and pattern matching** using C.
* How to handle **file input and string parsing** efficiently.

