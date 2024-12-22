// task_manager.h
#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <ctime>

class Task {
private:
    int id;
    bool deleted;
    std::string description;
    std::string status;
    std::time_t createdAt;
    std::time_t updatedAt;

public:
    // Constructor to initialize a new task
    Task(int taskId, const std::string& taskDescription);

    // Getters for Task values
    int getId() const;
    bool getDeleted() const;
    std::string getDescription() const;
    std::string getStatus() const;
    std::string getCreatedAt() const;
    std::string getUpdatedAt() const;

    // Setters for Task values
    void deleteTask();
    void restore();
    void updateDescription(const std::string& newDescription);
    void updateStatus(const std::string& newStatus);

    // Display task info
    void display() const;
};

#endif

