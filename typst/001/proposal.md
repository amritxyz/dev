# Personal Expense Tracker

## Introduction

Managing personal finances is crucial for maintaining financial health and achieving long-term goals. However, many individuals struggle to keep track of their daily expenses and often lack awareness of their spending patterns. The *Personal Expense Tracker* is a simple yet powerful application designed to help users monitor their income and expenditures efficiently. By categorizing transactions and generating visual reports, this tool enables users to make informed financial decisions and develop better budgeting habits.

> **Note**: A chart showing monthly or weekly expenses can be inserted here (e.g., bar chart or pie chart).

---

## Problem Statement

Most people do not systematically track their expenses, relying instead on memory, paper notes, or spreadsheets. These methods are often inconsistent, time-consuming, and prone to errors. Without a clear view of where money is going, users may overspend in certain categories (like food or entertainment) and fail to save adequately. There is a clear need for an easy-to-use, reliable, and accessible digital solution that allows individuals to log, manage, and analyze their personal finances in real time.

---

## Objectives

The main objectives of the Personal Expense Tracker are:

- Allow users to **add, view, edit, and delete** income and expense entries (CRUD operations).
- Enable **categorization** of transactions (e.g., Food, Bills, Transport, Entertainment).
- Support **search and filter** functionality by date range, category, or keywords.
- Generate **monthly and weekly reports** with visual charts to illustrate spending trends.
- Store user data securely using a **MySQL database**.
- Provide a **simple and intuitive user interface** for seamless user experience.

---

## Methodology

### 1. Requirement Identification

#### i. Study of Existing System
Current expense tracking methods include:
- Manual logging in notebooks.
- Excel or Google Sheets.
- Third-party apps like Mint, YNAB, or Splitwise.

While these tools are functional, they often come with a steep learning curve, excessive features, or subscription costs. A lightweight, customizable, and offline-friendly solution is missing for average users.

#### ii. Requirement Collection
Requirements were gathered through user interviews and surveys. Key features requested:
- Fast entry of expenses.
- Category-based filtering.
- Monthly spending summary.
- Data export (PDF/CSV).
- Secure login and data privacy.

---

### 2. Feasibility Study

#### i. Technical Feasibility
The system will be built using widely supported technologies:
- **Frontend**: HTML, CSS, JavaScript (or React for enhanced UI).
- **Backend**: Node.js with Express or Python with Flask.
- **Database**: MySQL for structured storage of transactions and user data.
All components are open-source, well-documented, and easy to integrate.

#### ii. Operational Feasibility
The app is designed for individuals, students, freelancers, and small business owners. Its simple interface ensures minimal training is required. It can run on personal devices or be hosted online for broader access.

#### iii. Economic Feasibility
Development uses free and open-source tools. Hosting can be done on low-cost platforms (e.g., Render, Vercel, or shared hosting). No major investment is required, making the project economically viable even as a free tool.

---

### 3. High-Level Design of the System

#### System Architecture
The application follows a **three-tier architecture**:

1. **Presentation Layer (Frontend)**  
   - User interface for adding, viewing, and filtering transactions.
   - Responsive design for desktop and mobile use.

2. **Application Layer (Backend)**  
   - Handles business logic, authentication, and request processing.
   - Exposes APIs for frontend communication.

3. **Data Layer (Database)**  
   - MySQL stores all user and transaction data securely.

#### System Flow
1. User logs in or registers.
2. Adds an expense/income with amount, date, category, and description.
3. Data is validated and saved to the database.
4. User can view all transactions, filter by date/category, or generate reports.
5. Reports are displayed using charts (e.g., Chart.js or D3.js).

#### Database Schema (Key Tables)

- `users`
  - `id` (PK)
  - `name`
  - `email`
  - `password_hash`

- `categories`
  - `id` (PK)
  - `name` (e.g., Food, Rent, Utilities)

- `transactions`
  - `id` (PK)
  - `user_id` (FK)
  - `amount`
  - `type` (income/expense)
  - `category_id` (FK)
  - `date`
  - `description`

---

## Gantt Chart (Project Timeline)

| Phase                          | Duration         |
|--------------------------------|------------------|
| Requirement Analysis           | Jan 1 – Jan 10   |
| Feasibility Study              | Jan 11 – Jan 15  |
| System Design                  | Jan 16 – Jan 25  |
| Frontend & Backend Development | Jan 26 – Feb 20  |
| Database Integration           | Feb 21 – Feb 28  |
| Testing & Debugging            | Mar 1 – Mar 10   |
| Report Generation & UI Polish  | Mar 11 – Mar 20  |
| Deployment & Documentation     | Mar 21 – Mar 31  |

*Total Duration: ~3 months*

---

## Expected Outcome

Upon completion, the Personal Expense Tracker will:
- Provide a user-friendly platform for tracking daily financial activities.
- Support full CRUD operations and data filtering.
- Visualize spending trends through interactive charts and reports.
- Store data securely in a relational database.
- Serve as a foundation for future enhancements (e.g., mobile app, cloud sync, multi-user support).

This tool will empower users to take control of their finances, reduce unnecessary spending, and build healthier financial habits.

---

## References

- MySQL Documentation. https://dev.mysql.com/doc/
- Flask Framework Guide. https://flask.palletsprojects.com/
- React Official Docs. https://react.dev/
- Chart.js Library. https://www.chartjs.org/
- Pressman, R. S. (2014). *Software Engineering: A Practitioner’s Approach*.
- Sommerville, I. (2011). *Software Engineering*. Pearson Education.
