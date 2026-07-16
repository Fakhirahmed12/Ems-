# ⚡ Electricity Management System (EMS)

A console-based **C++** application that simulates the electricity billing process used by utility companies like K-Electric in Pakistan, based on NEPRA slab rates.

## 📖 About

EMS automates electricity bill generation: it lets an admin log in securely, enter customer meter readings, calculates the bill using NEPRA's tiered slab rates plus GST and fixed charges, and processes payment with real-time status.

## ✨ Features

- Secure admin login (username/password verification)
- Customer info entry — name, meter number, previous & current readings
- Automatic unit calculation from meter readings
- NEPRA slab-rate billing across 5 pricing tiers
- Detailed bill breakdown: energy charges, 17% GST, fixed charges
- Payment processing with **Paid / Partially Paid / Unpaid** status
- Change calculation for overpayment

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Language | C++ |
| Concepts Used | Variables & Data Types, Conditionals, User-Defined Functions, `<iomanip>` formatting |
| Functions | `login()`, `calculateUnits()`, `calculateBill()`, `displayBill()`, `paymentStatus()` |

## 🚀 How to Run

```bash
g++ ems.cpp -o ems
./ems
```

**Demo login:** `admin` / `ssuet123`

## 🎯 How It Works

1. Admin logs in with a username and password.
2. Admin enters customer name, meter number, previous reading, and current reading.
3. `calculateUnits()` computes units consumed (current − previous reading).
4. `calculateBill()` applies NEPRA slab rates to those units, then adds 17% GST and a fixed PKR 75 charge.
5. `displayBill()` prints a fully formatted bill statement.
6. Admin enters the payment amount, and `paymentStatus()` reports Paid, Partially Paid, or Unpaid — with change shown for overpayment.

## ⚠️ Limitations

- Handles one customer per run (no multi-customer records)
- No persistent storage — data isn't saved between sessions
- Console-only interface, no GUI
- Login credentials are hardcoded in source
- Single administrator only

## 🔮 Future Improvements

- File handling (`ofstream`/`ifstream`) to save customer & billing history
- Support multiple customers per session using arrays/loops
- GUI version using the Qt Framework
- SQLite database for persistent storage
- Monthly bill history retrieval
- SMS/email notification simulation
- In-app credential management
- Input validation for non-numeric entries

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
