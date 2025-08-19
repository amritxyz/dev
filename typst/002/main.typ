#set heading(numbering: "1.1.1")
#outline()
#set par(justify: true) // Justify paragraph
#set text(
  font: "DejaVu Sans",
  size: 11pt,
)

#let title = [
  Personal Expense Tracker
]

#set page(
  header: align(
    right + horizon,
    title
  ),
)

#align(center, text(17pt)[
  *#title*
])

#grid(
  columns: (1fr, 1fr),
  align(center)[
    Amrit Bhattarai \
    Devinagar, Butwal\
    #link("mailto:amrit44404@proton.me")
  ],
  align(center)[
    Susma Tandan \
    Sankhanagar, Butwal \
    #link("mailto:susma33@gmail.com")
  ]
)

= Introduction
Managing personal finances is important for staying financially healthy and achieving long-term goals. However, many people struggle to track their daily expenses or understand their spending habits. The *Personal Expense Tracker* is a simple yet powerful tool designed to help users monitor their income and expenses efficiently. By categorizing transactions and generating clear reports, this app helps users make better financial decisions and develop good budgeting habits.

= Problem Statement
Most people do not track their expenses systematically. They rely on memory, paper notes, or spreadsheets, which are often inconsistent, time-consuming, and prone to errors. Without a clear view of where money is going, users may overspend in certain areas (like food or entertainment) and fail to save enough. There is a need for an easy-to-use, reliable, and accessible digital solution that lets individuals log, manage, and analyze their finances in real-time.

= Objectives
The main objectives of the Personal Expense Tracker are:
#list(
  indent: 10pt,
  [Allow users to add, view, edit, and delete income and expense entries (CRUD operations).],
  [Enable categorization of transactions (e.g., Food, Bills, Transport, Entertainment).],
  [Support search and filter functionality by date range, category, or keywords.],
  [Generate monthly and weekly reports with visual charts to show spending trends.],
  [Store user data securely using a MySQL database.],
  [Provide a simple and intuitive user interface for a seamless experience.],
)

= Methodology

== Requirement Identification

=== Study of Existing System
Current expense tracking methods include:
#list(
  indent: 10pt,
  [Manual logging in notebooks.],
  [Excel or Google Sheets.],
  [Third-party apps like Mint, YNAB, or Splitwise.],
)
While these tools work, they often have a steep learning curve, too many features, or subscription costs. A lightweight, customizable, and offline-friendly solution is missing for average users.

=== Requirement Collection
Key requirements identified are:
#list(
  indent: 10pt,
  [Fast entry of expenses.],
  [Category-based filtering.],
  [Monthly spending summary.],
  [Data export (PDF/CSV).],
  [Secure login and data privacy.],
)

== Feasibility Study

=== Technical Feasibility
The system will use widely supported technologies:
#list(
  indent: 10pt,
  [*Frontend*: HTML, CSS, JavaScript (or React for enhanced UI).],
  [*Backend*: Node.js with Express or Python with Flask.],
  [*Database*: MySQL for storing transactions and user data.],
)
All components are open-source, well-documented, and easy to integrate.

=== Operational Feasibility
The app is designed for individuals, students, freelancers, and small business owners. Its simple interface ensures minimal training is required. It can run on personal devices or be hosted online for broader access.

=== Economic Feasibility
Development uses free and open-source tools. Hosting can be done on low-cost platforms (e.g., Render, Vercel, or shared hosting). No major investment is needed, making the project economically viable even as a free tool.

== High-Level Design of the System

=== System Architecture
The application follows a *three-tier architecture*:

==== Presentation Layer (Frontend)
#list(
  indent: 10pt,
  [User interface for adding, viewing, and filtering transactions.],
  [Responsive design for desktop and mobile use.],
)

==== Application Layer (Backend)
#list(
  indent: 10pt,
  [Handles business logic, authentication, and request processing.],
  [Exposes APIs for frontend communication.],
)

==== Data Layer (Database)
#list(
  indent: 10pt,
  [MySQL stores all user and transaction data securely.],
)

=== System Flow
#list(
  indent: 10pt,
  [User logs in or registers.],
  [Adds an expense/income with amount, date, category, and description.],
  [Data is validated and saved to the database.],
  [User can view all transactions, filter by date/category, or generate reports.],
  [Reports are displayed using charts (e.g., Chart.js or D3.js).],
)

=== Database Schema (Key Tables)

*users*
#list(
  indent: 10pt,
  [id (`PK`)],
  [name],
  [email],
  [password_hash],
)

*categories*
#list(
  indent: 10pt,
  [id (`PK`)],
  [name (`e.g., Food, Rent, Utilities`)],
)

*transactions*
#list(
  indent: 10pt,
  [id (`PK`)],
  [user_id (`FK`)],
  [amount],
  [type (`income, expense`)],
  [category_id (`FK`)],
  [date],
  [description],
)

= Gantt Chart
#align(center)[
  #figure(
    table(
      columns: (1fr,)+ 1 * (.4fr,),
      align: left,
      [*Phase*], [*Duration*],
      [Requirement Analysis],           [ Jan 1  – Jan 10   ],
      [Feasibility Study],              [ Jan 11 – Jan 15   ],
      [System Design],                  [ Jan 16 – Jan 25   ],
      [Frontend & Backend Development], [ Jan 26 – Feb 20   ],
      [Database Integration],           [ Feb 21 – Feb 28   ],
      [Testing & Debugging],            [ Mar 1  – Mar 10   ],
      [Report Generation & UI Polish],  [ Mar 11 – Mar 20   ],
      [Deployment & Documentation],     [ Mar 21 – Mar 31   ],
      [*Total Duration*], [*~3 months*]
    ),
    caption: [Project Timeline],
  )
]

= Expected Outcome
The Personal Expense Tracker will provide users with a simple, efficient, and secure way to manage their finances. Key outcomes include:
#list(
  indent: 10pt,
  [Improved awareness of spending habits.],
  [Better control over personal finances.],
  [Increased savings through informed decision-making.],
  [A user-friendly tool suitable for individuals and small businesses.],
)

= References
#list(
  indent: 10pt,
  ["Modern Web Development with Node.js and Express" by Ethan Brown.],
  ["MySQL Cookbook" by Paul DuBois.],
  ["React Up and Running" by Stoyan Stefanov.],
  ["Chart.js Documentation" – https://www.chartjs.org/docs/latest/.],
)
