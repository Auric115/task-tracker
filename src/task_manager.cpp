// task_manager.cpp
#include "task_manager.h"
#include <iostream>
#include <iomanip>

Task::Task(int taskId, const std::string& taskDescription)
    : id(taskId), description(taskDescription), status("todo"), deleted(false) {
    createdAt = std::time(nullptr);
    updatedAt = createdAt;
}

int Task::getId() const {
    return id;
}

bool Task::getDeleted() const {
    return deleted;
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getStatus() const {
    return status;
}

std::string Task::getCreatedAt() const {
    return std::ctime(&createdAt);
}

std::string Task::getUpdatedAt() const {
    return std::ctime(&updatedAt);
}

void Task::deleteTask() {
    deleted = true;
}

void Task::restore() {
    deleted = false;
}

void Task::updateDescription(const std::string& newDescription) {
    description = newDescription;
    updatedAt = std::time(nullptr);
}

void Task::updateStatus(const std::string& newStatus) {
    if (newStatus == "todo" || newStatus == "in-progress" || newStatus == "done") {
        status = newStatus;
        updatedAt = std::time(nullptr);
    } else {
        std::cerr << "Invalid status: " << newStatus << std::endl;
    }
}

void Task::display() const {
    std::cout << std::setw(5) << id << " | " << description << "\n"
              << "\tStatus: " << status << "\n"
              << "\tCreated At: " << getCreatedAt()
              << "\tUpdated At: " << getUpdatedAt()
              << std::endl;
}

