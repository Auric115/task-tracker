## Project Specifications

### Task Tracker CLI

Build a Command Line Interface (CLI) application to manage your tasks and to-do list effectively.

#### Link to Project Description
[Task Tracker Project Description](https://roadmap.sh/projects/task-tracker)

---

### Features and Requirements

#### Core Features:
- **Add, Update, and Delete tasks**
- **Mark tasks as**:
  - In progress
  - Done
- **List tasks**:
  - All tasks
  - Tasks by status: Done, To-Do, In Progress

#### Implementation Details:
1. **Input Handling**: 
   - Accept user actions and inputs as command-line arguments.
   - Use positional arguments to structure commands.

2. **Data Storage**: 
   - Store tasks in a JSON file located in the current directory.
   - Automatically create the JSON file if it does not exist.

3. **Task Properties**:
   - `id`: Unique identifier for each task.
   - `description`: A short description of the task.
   - `status`: Status of the task (`todo`, `in-progress`, `done`).
   - `createdAt`: Date and time when the task was created.
   - `updatedAt`: Date and time when the task was last updated.

4. **Constraints**:
   - Use native filesystem modules of your programming language.
   - Do not use external libraries or frameworks.
   - Handle errors and edge cases gracefully.

#### Command Usage Examples
```bash
# Adding a new task
task-cli add "Buy groceries"
# Output: Task added successfully (ID: 1)

# Updating and deleting tasks
task-cli update 1 "Buy groceries and cook dinner"
task-cli delete 1

# Marking a task as in progress or done
task-cli mark-in-progress 1
task-cli mark-done 1

# Listing all tasks
task-cli list

# Listing tasks by status
task-cli list done
task-cli list todo
task-cli list in-progress
