# TaskList CLI

A tiny C++ console app to create, view, and update a list of tasks with priorities, time estimates, and completion status. It also renders a simple proportional "time bar" so you can see how your total time is distributed across tasks.

## Features

- Add tasks with:
  - **Name**
  - **Description**
  - **Time estimate** (minutes)
  - **Priority** (1–5)
- Mark tasks as **DONE**
- Edit a task’s **name**, **description**, or **priority**
- Visual **time bar** showing each task’s share of the total time
- Auto-incrementing **IDs** for tasks

> ⚠️ Note: Data is **not persisted**; exiting the app clears the list.

## Build & Run

### Prerequisites
- A C++ compiler with C++11 support (e.g., `g++` on Linux/macOS, `clang++`, or MSVC on Windows)

### Linux/macOS
```bash
g++ -std=c++11 -O2 -Wall -Wextra -o task_tracker task_tracker.cpp
./task_tracker
