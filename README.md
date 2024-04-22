# COMP 3004 - Neurofeedback Device
COMP 3004 Final project 2024 Winter


## Members of Group 21
- Karthiga Balasubramaniam - 100670854
- Isaac Arneill - 101222972
- Yanwei Su - 101209998
- Tina Cao - 101158711

## Breakdown of work
Karthiga:
- Use cases: 1.1, 1.2, 1.3
- Base Sequence diagrams: Session history, Time setting, Connection Lost  

Tina:
- Use cases: 1.4, 2, 3
- Sequence diagrams: Normal Scenario, Out of battery, Low battery
- Traceability Matrix
- Readme, design explanation
- State diagrams
- Revise Sequence diagrams
- Revise Class diagram
  
Isaac:
- Some general planning
- Neuraset Session code
- Neuraset Logs
- Display logs code
- Parts in battery
- Some UI code
- Headset code
- EEG, EEGArray code
  
Yanwei:
- Base Class diagram
- Some UI code
- Some battery code
- Functions in mainOperation 
- Functions in mainwindow
- Functions in menu
- Some EEG code
- Time and Date
- Test videos


## Files Included in this project
Header files:
- Battery.h
- eeg.h
- eegarray.h
- logs.h
- headset.h
- mainoperation.h
- mainwindow.h
- menu.h

Source files:
- *battery.cpp*: stores battery info
- *eeg.cpp*: stores individual eeg info
- *eegArray*.cpp: stores an array of eeg, manager class of eeg sites
- *headset.cpp*: functionalities of eeg sites
- *logs.cpp*: stores info of session logs
- *main.cpp*: main function
- *mainoperation.cpp*: contains system operations
- *mainwindow.cpp*: design and functions of the UI
- *menu.cpp*: functions for the three buttons(timeanddate, sessionlog, newsession)

Others:
- menu.png
- pause.png
- powerButton.png
- start.png
- stop.png
- switch.png
- up.png
- down.png
- image.qrc
- neuraset_logs.txt (created after running the program)
  
Documents:
- *Diagrams.pdf*: All diagrams required for the project
- *Use Case.pdf*: Use cases for the system
- *TraceabilityMatrix.pdf*: Traceability matrix for the system
- *Readme.txt*: Explanation of files included in the project, info of group members
- *diagrams*: Folder contains all diagram images

## Work procedure
Week 1:
- Use cases, UML class diagram draft
- Basic layout and design of code
  
Week 2:
- Sequence diagram drafts, State diagrams
- Code update, GUI

Week 3:
- Treaceability Matrix, Sequence diagrams update
- Code update

Week 4-5:
- Update all necessary diagrams, textual explanation of the code, readme file
- Code update


## Explanation of Design Decision

- Qt Framework: Utilizing Qt components such as QWidget(creating GUI components), QTimer(timing-related task), QListWidget(Managing lists of items with GUI), QGraphicScene(Managing 2D graphical items in the scene) for developing the application.

- Modular Structure: Readability and maintainability are enhanced by having distinct methods for UI updates, calculations, functionality logics, and error handling. This allows easier modifications.

- Safety features: Dealing with issues like device disconnection or out of battery is a practical part of the system design.

- Adaptive UI controls: Dynamic enabling and disabling of controls based on the system's state, such as disabling menu selections during treatment or preventing user interactions when the device is out of battery, ensure realistic opertions and sensible interactions for users.
 
- Real-time Visualization: Using QWidget, QTimer for real-time visualization of the timer that displays the remaining time for the session. This provides immediate visual feedback which makes the simulation more intuitive and engaging.


## Instruction to run the code
Open folder in Qt, open mainwindow.cpp and run
