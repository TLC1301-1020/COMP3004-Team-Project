# COMP 3004 - Neurofeedback Device
COMP 3004 Final project 2024 Winter

## Members of Group 21
- Karthiga Balasubramaniam
- Isaac Arneill
- Yanwei Su
- Tina Cao

## Explanation of Design Decision

- Qt Framework: Utilizing Qt components such as QWidget(creating GUI components), QTimer(timing-related task), QListWidget(Managing lists of items with GUI), QGraphicScene(Managing 2D graphical items in the scene) for developing the application.

- Modular Structure: Readability and maintainability are enhanced by having distinct methods for UI updates, calculations, functionality logics, and error handling. This allows easier modifications.

- Safety features: Dealing with issues like device disconnection or out of battery is a practical part of the system design.

- Adaptive UI controls: Dynamic enabling and disabling of controls based on the system's state, such as disabling menu selections during treatment or preventing user interactions when the device is out of battery, ensure realistic opertions and sensible interactions for users.
 
- Real-time Visualization: Using QWidget, QTimer for real-time visualization of the timer that displays the remaining time for the session. This provides immediate visual feedback which makes the simulation more intuitive and engaging.


## Instruction to run the code
Open folder in Qt, open mainwindow.cpp and run
