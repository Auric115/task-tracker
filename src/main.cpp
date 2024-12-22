// main.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include "task_manager.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<Task> load_tasks();
void save_tasks(const std::vector<Task>& tasks);
void add_task(const std::string& description);
void update_task(int taskId, const std::string& newDescription);
void delete_task(int taskId);
void mark_task(int taskId, const std::string& status);
void list_tasks(const std::string& filter = "");

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <command> [args]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "add" || command == "a") {
        if (argc < 3) {
            std::cerr << "Please provide a task description." << std::endl;
            return 1;
        }
        add_task(argv[2]);
    } else if (command == "update" || command == "u") {
        if (argc < 4) {
            std::cerr << "Please provide a task ID and new description." << std::endl;
            return 1;
        }
        update_task(std::stoi(argv[2]), argv[3]);
    } else if (command == "delete" || command == "d") {
        if (argc < 3) {
            std::cerr << "Please provide a task ID to delete." << std::endl;
            return 1;
        }
        delete_task(std::stoi(argv[2]));
    } else if (command == "mark" || command == "m") {
        if (argc < 4) {
            std::cerr << "Please provide a task ID and status." << std::endl;
            return 1;
        }
        mark_task(std::stoi(argv[2]), argv[3]);
    } else if (command == "list" || command == "l") {
        std::string filter = (argc > 2) ? argv[2] : "";
        list_tasks(filter);
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}

// Implementing helper functions for file operations and task management

std::vector<Task> load_tasks() {
    std::ifstream file("tasks.json");
    json j;
    std::vector<Task> tasks;
    
    if (file.is_open()) {
        file >> j;
        for (auto& element : j) {
            Task task(element["id"], element["description"]);
            task.updateStatus(element["status"]);
            tasks.push_back(task);
        }
    }

    return tasks;
}

void save_tasks(const std::vector<Task>& tasks) {
    json j;
    for (const auto& task : tasks) {
        j.push_back({
            {"id", task.getId()},
            {"description", task.getDescription()},
            {"status", task.getStatus()},
            {"createdAt", task.getCreatedAt()},
            {"updatedAt", task.getUpdatedAt()}
        });
    }
    
    std::ofstream file("tasks.json");
    file << j.dump(4);
}

void add_task(const std::string& description) {
    std::vector<Task> tasks = load_tasks();
    int newId = tasks.empty() ? 1 : tasks.back().getId() + 1;
    Task newTask(newId, description);
    tasks.push_back(newTask);
    save_tasks(tasks);
    std::cout << "Task added successfully (ID: " << newId << ")" << std::endl;
}

void update_task(int taskId, const std::string& newDescription) {
    std::vector<Task> tasks = load_tasks();
    for (auto& task : tasks) {
        if (task.getId() == taskId) {
            task.updateDescription(newDescription);
            save_tasks(tasks);
            std::cout << "Task updated successfully" << std::endl;
            return;
        }
    }
    std::cerr << "Task not found" << std::endl;
}

void delete_task(int taskId) {
    std::vector<Task> tasks = load_tasks();
    auto it = std::remove_if(tasks.begin(), tasks.end(), [taskId](Task& task) {
        return task.getId() == taskId;
    });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        save_tasks(tasks);
        std::cout << "Task deleted successfully" << std::endl;
    } else {
        std::cerr << "Task not found" << std::endl;
    }
}

void mark_task(int taskId, const std::string& status) {
    std::vector<Task> tasks = load_tasks();
    for (auto& task : tasks) {
        if (task.getId() == taskId) {
            task.updateStatus(status);
            save_tasks(tasks);
            std::cout << "Task status updated to " << status << std::endl;
            return;
        }
    }
    std::cerr << "Task not found" << std::endl;
}

void list_tasks(const std::string& filter) {
    std::vector<Task> tasks = load_tasks();
    for (const auto& task : tasks) {
        if (filter.empty() || task.getStatus() == filter) {
            task.display();
        }
    }
}

