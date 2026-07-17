# Electricity Management System
## SSUET — Introduction to Programming (C++) Semester Project
### Algorithm, Flowchart Description & Concept Explanation

---

## ✅ C++ CONCEPTS USED (With Examples from Code)

| # | Concept | How Used in Project |
|---|---------|---------------------|
| 1 | **Variables** | `double totalBill`, `int units`, `string customerName` |
| 2 | **Built-in Data Types** | `int`, `double`, `string`, `char`, `bool` all used |
| 3 | **Input / Output** | `cin >> currentReading`, `cout << totalBill` |
| 4 | **Conditional Statements** | `if-else` for login, slab rates, payment status |
| 5 | **User Defined Functions** | `login()`, `calculateBill()`, `displayBill()`, etc. |
| 6 | **Built-in Functions** | `setprecision()`, `fixed`, `getline()` from `<iomanip>` |

---

## 📋 ALGORITHM (Step-by-Step)

### MAIN ALGORITHM

```
START

Step 1: Call login()
    - Input username, password
    - IF username == "admin" AND password == "ssuet123"
        → login successful = true
      ELSE
        → login successful = false
        → Print error, END program

Step 2: Input Customer Information
    - Input customerName (string)
    - Input meterNumber (string)
    - Input previousReading (double)
    - Input currentReading (double)

Step 3: Call calculateUnits(currentReading, previousReading)
    - units = currentReading - previousReading
    - IF units < 0 → Print error, END
    - RETURN units

Step 4: Call calculateBill(units)
    - IF units <= 100
        baseAmount = units × 3.95
    - ELSE IF units <= 200
        baseAmount = (100 × 3.95) + ((units - 100) × 7.74)
    - ELSE IF units <= 300
        baseAmount = (100 × 3.95) + (100 × 7.74) + ((units - 200) × 10.06)
    - ELSE IF units <= 400
        baseAmount = ... + ((units - 300) × 12.15)
    - ELSE
        baseAmount = ... + ((units - 400) × 19.71)
    - gstAmount = baseAmount × 0.17
    - totalBill = baseAmount + gstAmount + 75.0 (fixed)
    - RETURN totalBill

Step 5: Call displayBill(...)
    - Print customer details
    - Print units consumed
    - Print breakdown (energy + GST + fixed)
    - Print total bill

Step 6: Input paymentAmount

Step 7: Call paymentStatus(totalBill, paymentAmount)
    - IF paymentAmount >= totalBill
        → Print "PAID"
    - ELSE IF paymentAmount > 0
        → Print "PARTIALLY PAID"
        → Print remaining amount
    - ELSE
        → Print "UNPAID"

END
```

---

## 🔁 FLOWCHART (Text Description)

```
[START]
   |
   ▼
[Login Screen]
   |
[Input: username, password]
   |
[IF credentials correct?]
   |         |
  YES        NO
   |          └──► [Show Error] ──► [END]
   ▼
[Customer Info Input]
   |
[Input: Name, Meter No, Prev Reading, Curr Reading]
   |
[Calculate Units = Curr - Prev]
   |
[IF Units < 0?]
   |        |
  YES       NO
   |         └──► [Calculate Bill (Slab Rates)]
   |                      |
[Error]            [IF units ≤ 100?]
                          |
                   [Apply Rate Rs.3.95/unit]
                          |
                   [Add GST 17%]
                          |
                   [Add Fixed Rs.75]
                          |
                   [Display Bill]
                          |
                   [Input Payment Amount]
                          |
                   [IF payment >= total?]
                    /     |     \
                  YES    PART    NO
                   |      |      |
                [PAID] [PARTIAL] [UNPAID]
                          |
                       [END]
```

---

## 📊 SLAB RATE CALCULATION TABLE

| Units Range | Rate/Unit | Base Bill Example (exact units) |
|-------------|-----------|----------------------------------|
| 0 – 100     | Rs. 3.95  | 80 units = Rs. 316.00           |
| 101 – 200   | Rs. 7.74  | 150 units = Rs. 772.00          |
| 201 – 300   | Rs. 10.06 | 250 units = Rs. 1,269.00        |
| 301 – 400   | Rs. 12.15 | 350 units = Rs. 1,878.50        |
| 401+        | Rs. 19.71 | 500 units = Rs. 3,847.00        |

**Additional Charges on every bill:**
- GST: 17% of base amount
- Fixed Charges: Rs. 75.00

**Formula:**
```
Total Bill = Base Amount + (Base Amount × 0.17) + 75
```

---

## 🔧 FUNCTION DESCRIPTIONS

### 1. `bool login()`
- **Purpose:** Validates username and password
- **Concepts:** string comparison, if-else, bool return type
- **Returns:** true (success) or false (fail)

### 2. `double calculateUnits(double curr, double prev)`
- **Purpose:** Subtracts previous from current reading
- **Concepts:** double data type, arithmetic, if-else for negative check
- **Returns:** units consumed (double)

### 3. `double calculateBill(double units)`
- **Purpose:** Applies NEPRA slab rates and GST
- **Concepts:** if-else if chain, multiplication, addition
- **Returns:** total bill amount (double)

### 4. `void displayBill(string name, string meter, double prev, double curr, double units, double total)`
- **Purpose:** Prints formatted bill to screen
- **Concepts:** cout, setprecision, string output, multiple parameters
- **Returns:** void (nothing)

### 5. `void paymentStatus(double total, double payment)`
- **Purpose:** Compares payment vs bill, shows status
- **Concepts:** if-else, comparison operators (>=, >, ==)
- **Returns:** void (nothing)

---

## 📌 DATA TYPES USED

```cpp
string customerName;     // Text data
string meterNumber;      // Alphanumeric meter ID
double previousReading;  // Decimal number (kWh)
double currentReading;   // Decimal number (kWh)
double unitsConsumed;    // Result of subtraction
double billAmount;       // Base electricity charges
double gstAmount;        // 17% tax
double totalBill;        // Final payable amount
double paymentAmount;    // User input payment
bool   loginSuccess;     // true/false login result
```

---

## 📁 FILES SUBMITTED

| File | Description |
|------|-------------|
| `electricity_management.cpp` | Beginner C++ source code (~200 lines) |
| `index.html` | Frontend HTML with JS logic |
| `styles.css` | K-Electric style CSS |
| `ALGORITHM_AND_CONCEPTS.md` | This document |

---

*Sir Syed University of Engineering and Technology (SSUET)*
*Subject: Introduction to Programming (C++)*
*Semester Project — Beginner Level*
