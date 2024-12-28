/**
 * @file RobotControler.cpp
 * @brief Implementation of the RobotControler class.
 */

#include "RobotControler.h"
#include <string>
using namespace std;

/**
 * @brief Default constructor for the RobotControler class.
 * 
 * Initializes the RobotControler object with default values.
 */
RobotControler::RobotControler() : robotAPI(nullptr), position(new Pose()), connected(false) {
    cout << "RobotControler created via default constructor.\n";
}

/**
 * @brief Constructs a RobotControler object with a given API.
 * 
 * Initializes the RobotControler object with the provided FestoRobotAPI pointer.
 * 
 * @param api Pointer to the FestoRobotAPI object.
 */
RobotControler::RobotControler(FestoRobotAPI* api)
    : robotAPI(api), connected(false)
{
    position = new Pose();
    cout << "RobotControler constructed with single API parameter.\n";
}

/**
 * @brief Constructs a RobotControler object with a given API and initial pose.
 * 
 * Initializes the RobotControler object with the provided FestoRobotAPI pointer and initial pose.
 * 
 * @param api Pointer to the FestoRobotAPI object.
 * @param initialPose The initial pose of the robot.
 */
RobotControler::RobotControler(FestoRobotAPI* api, const Pose& initialPose)
    : robotAPI(api), connected(false)
{
    position = new Pose(initialPose);
    if (robotAPI != nullptr) {
        connected = connectRobot();
        cout << "RobotControler connected with provided pose.\n";
    } else {
        cout << "Error: Robot API is null.\n";
    }
}

/**
 * @brief Destructor for the RobotControler class.
 * 
 * Cleans up the dynamically allocated position object.
 */
RobotControler::~RobotControler() {
    delete position;
    cout << "RobotControler destructed.\n";
}

/**
 * @brief Turns the robot left.
 * 
 * This function sends a command to the robot API to rotate the robot to the left.
 */
void RobotControler::turnLeft() {
    if (connected) {
        robotAPI->rotate(LEFT);
        cout << "Turning left.\n";
    } else {
        cout << "Not connected.\n";
    }
}

/**
 * @brief Turns the robot right.
 * 
 * This function sends a command to the robot API to rotate the robot to the right.
 */
void RobotControler::turnRight() {
    if (connected) {
        robotAPI->rotate(RIGHT);
        cout << "Turning right.\n";
    } else {
        cout << "Not connected.\n";
    }
}

/**
 * @brief Moves the robot forward.
 * 
 * This function sends a command to the robot API to move the robot forward.
 */
void RobotControler::moveForward() {
    if (connected) {
        robotAPI->move(FORWARD);
        cout << "Moving forward.\n";
    } else {
        cout << "Not connected.\n";
    }
}

/**
 * @brief Moves the robot right.
 * 
 * This function sends a command to the robot API to move the robot to the right.
 */
void RobotControler::moveRight() {
    if (connected) {
        robotAPI->move(RIGHT);
        cout << "Moving right.\n";
    } else {
        cout << "Not connected.\n";
    }
}

/**
 * @brief Stops the robot.
 * 
 * This function sends a command to the robot API to stop the robot.
 */
void RobotControler::stop() {
    if (connected) {
        robotAPI->stop();
        cout << "Robot halted.\n";
    }
}

/**
 * @brief Gets the current pose of the robot.
 * 
 * This function retrieves the current X, Y coordinates and orientation (theta) of the robot from the API.
 * 
 * @return Pose The current pose of the robot.
 */
Pose RobotControler::getPose() {
    cout << "Fetching pose.\n";
    double x, y, th;
    robotAPI->getXYTh(x, y, th);
    position->setX(x);
    position->setY(y);
    position->setTh(th);
    return *position;
}

/**
 * @brief Prints the current status and pose of the robot.
 * 
 * This function prints the connection status and the current pose (X, Y, theta) of the robot.
 */
void RobotControler::print() {
    cout << "-------------------------------------------------\n";
    cout << "Connected: " << (connected ? "Yes" : "No") << "\n";
    cout << "Pose: " << position->getX() << ", "
         << position->getY() << ", "
         << position->getTh() << "\n";
    cout << "-------------------------------------------------\n";
}

/**
 * @brief Connects to the robot.
 * 
 * This function establishes a connection to the robot using the API.
 * 
 * @return bool Returns true if the connection is successful, false otherwise.
 */
bool RobotControler::connectRobot() {
    if (!connected && robotAPI) {
        robotAPI->connect();
        connected = true;
        cout << "Connection successful.\n";
    }
    return connected;
}

/**
 * @brief Disconnects from the robot.
 * 
 * This function terminates the connection to the robot using the API.
 * 
 * @return bool Returns true if the disconnection is successful, false otherwise.
 */
bool RobotControler::disconnectRobot() {
    if (connected && robotAPI) {
        robotAPI->disconnect();
        connected = false;
        cout << "Disconnected successfully.\n";
    }
    return connected;
}