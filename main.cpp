#include <iostream>
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
    // Constructor to init a new task
    Task(int taskId, const std::string& taskDescription)
        : id(taskId), description(taskDescription), status("todo") {
        createdAt = std::time(nullptr);
        updatedAt = createdAt;
    }

    // Getters for Task values
    int getId() const {
        return id;
    }
    
    int getDeleted() const {
	return deleted;
    }

    std::string getDescription() const {
        return description;
    }

    std::string getStatus() const {
        return status;
    }

    std::string getCreatedAt() const {
        return std::ctime(&createdAt);
    }

    std::string getUpdatedAt() const {
        return std::ctime(&updatedAt);
    }

    // Setters for Task values
    void delete() { deleted = true; }
    
    void restore() { deleted = false; }

    void updateDescription(const std::string& newDescription) {
        description = newDescription;
        updatedAt = std::time(nullptr);
    }

    void updateStatus(const std::string& newStatus) {
        if (newStatus == "todo" || newStatus == "in-progress" || newStatus == "done") {
            status = newStatus;
            updatedAt = std::time(nullptr);
        } else {
            std::cerr << "Invalid status: " << newStatus << std::endl;
        }
    }

    void display() const {
        std::cout << id << " | " 
                  << "Description: " << description << "\n"
                  << "\tStatus: " << status << "\n"
                  << "\tCreated At: " << getCreatedAt()
                  << "\tUpdated At: " << getUpdatedAt()
                  << std::endl;
    }
};


int main(int argc, char* argv[]) {
    if argc < 2 {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2> ... <argN>" << std::endl;
	return 1;
    }
    
    // Init JSON file if does not exist
    
    if (argv[1] == "add" || argv[1] == "a") {
        // Add new task
    } else if (argv[1] == "update" || argv[1] == "u") { 
        // Update name of task
    } else if (argv[1] == "mark" || argv[1] == "m") {
        // Update status of task
    } else if (argv[1] == "delete" || argv[1] == "d") {
        // Delete task
    } else if (argv[1] == "list" || argv[1] == "l") {
        // List tasks
    } else {
    	// Handle error
    }
}    
