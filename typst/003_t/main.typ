#import "@preview/cleanified-hpi-research-proposal:0.0.1": *

#show: project.with(
  title: "My Very Long, Informative, Expressive, and Definitely Fancy Title",
  author: "Max Mustermann",
  date: "17. Juli, 2025",
  chair: "Data-Intensive Internet Computing",
)


#set heading(numbering: "1.a.i")
#outline()
#set par(justify: true) // Justify paragraph
#set text(
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

#set par(
  first-line-indent: 1em,
  spacing: 0.65em,
  justify: true,
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

#align(center)[
  #set par(justify: false)
  #text(weight: "bold")[Abstract] \
    Many people find it hard to keep track of their money. They often forget where they

    spent it or lose their notes. The Personal Expense Tracker is a simple tool that helps

    people record their income and expenses so they can better understand how they spend

    their money. With this app, users can add and organize their spending into categories

    like food, rent, or transport. hey can also see helpful charts and reports that

    show their spending habits each week or month. The app is easy to use

    and works on both computers and phones. It is built using common tools like React,

    Express-JS, and MySQL to keep everything safe and organized. This tracker makes it

    easier for anyone to manage their money, avoid overspending,

    and build better financial habits.
]

#align(center)[
  #set par(justify: false)
  #align(left)[
    = Introduction
      Managing personal finances is crucial for maintaining financial health and achieving long-term goals. However, many individuals struggle to keep track of their daily expenses and often lack awareness of their spending patterns. The Personal Expense Tracker is a simple yet powerful application designed to help users monitor their income and expenditures efficiently. By categorizing transactions and generating visual reports, this tool enables users to make informed financial decisions and develop better budgeting habits.
  ]
]

#align(center)[
  #set par(justify: false)
  #align(left)[
    = Problem Statement
    Most people do not systematically track their expenses, relying instead on memory, paper notes,
    or spreadsheets. These methods are often inconsistent, time-consuming, and prone to errors.
    Without a clear view of where money is going, users may overspend in certain categories
    (like food or entertainment) and fail to save adequately. There is a clear need for an
    easy-to-use, reliable, and accessible digital solution that allows individuals to log, manage,
    and analyze their personal finances in real time.
  ]
]

#align(center)[
  #set par(justify: true)
  #align(left)[
    = Objectives
    The main objectives of the Personal Expense Tracker are:
    #list(
      indent: 20pt,
      [Allow users to add, view, edit, and delete income and expense entries (CRUD operations).],
      [Enable categorization of transactions (e.g., Food, Bills, Transport, Entertainment).],
      [Support search and filter functionality by date range, category, or keywords.],
      [Generate monthly and weekly reports with visual charts to illustrate spending trends.],
      [Store user data securely using a MySQL database.],
      [Provide a simple and intuitive user interface for seamless user experience.],
    )
  ]
]

#align(center)[
  #set par(justify: true)
  #align(left)[
    = Methodology
    == Requirement Identification
    === Study of Existing System
    #align(left)[
      Current expense tracking methods include:
      #list(
        indent: 20pt,
        [Manual logging in notebooks.],
        [Excel or Google Sheets.],
        [Third-party apps like Mint, YNAB, or Splitwise.],
      )
      While these tools are functional, they often come with a steep learning curve, excessive features, or subscription costs. A lightweight, customizable, and offline-friendly solution is missing for average users.
    ]
    === Requirement Collection
    #align(left)[
      Current expense tracking methods include:
      #list(
        indent: 20pt,
        [Fast entry of expenses.],
        [Category-based filtering.],
        [Monthly spending summary.],
        [Data export (PDF/CSV).],
        [Secure login and data privacy.],
      )
      All components are open-source, well-documented, and easy to integrate.
    ]
  ]
]

#align()[
  #set par(justify: true)
  #align(left)[
    == Feasibility Study
    === Technical Feasibility
    #align(left)[
      The system will be built using widely supported technologies:
      #list(
        indent: 20pt,
        [*Frontend*: HTML, CSS, JavaScript (or React for enhanced UI).],
        [*Backend*: Node.js with Express or Python with Flask.],
        [*Database*: MySQL for structured storage of transactions and user data.],
      )
      All components are open-source, well-documented, and easy to integrate.
    ]
    === Operational Feasibility
    The app is designed for individuals, students, freelancers, and small business owners. Its simple interface ensures minimal training is required. It can run on personal devices or be hosted online for broader access.

    === Economic Feasibility
    Development uses free and open-source tools. Hosting can be done on low-cost platforms (e.g., Render, Vercel, or shared hosting). No major investment is required, making the project economically viable even as a free tool.
  ]
]

#align()[
  #set par(justify: true)
  #align(left)[
    == High-Level Design of the System
    === System Architecture
    The application follows a *three-tier architecture*:
    #list(
      indent:20pt,

      [
        *Presentation Layer (Frontend)*
          - User interface for adding, viewing, and filtering transactions.
          - Responsive design for desktop and mobile use.
      ],

      [
        *Application Layer (Backend)*
          - Handles business logic, authentication, and request processing.
          - Exposes APIs for frontend communication.
      ],

      [
        *Data Layer (Database)*
          - MySQL stores all user and transaction data securely.
      ],

      [
        *System Flow*
          - User logs in or registers.
          - Adds an expense/income with amount, date, category, and description.
          - Data is validated and saved to the database.
          - User can view all transactions, filter by date/category, or generate reports.
          - Reports are displayed using charts (e.g., Chart.js or D3.js).
        ],
      )
    === Database Schema (Key Tables)
    *users*
    #list(
      indent: 20pt,
      [id (`PK`)],
      [name],
      [email],
      [password_hash],
    )

    *categories*
    #list(
      indent: 20pt,
      [id (`PK`)],
      [name (`e.g., Food, Rent, Utilities`)],
    )

    *transactions*
    #list(
      indent: 20pt,
      [id (`PK`)],
      [user_id (`FK`)],
      [amount],
      [type (`income, expense`)],
      [category_id (`FK`)],
      [date],
      [description],
    )
  ]
]

= Gantt chart
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
    caption: [Time Line],
  )
]
