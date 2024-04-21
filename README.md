# COMP 3004 - Neurofeedback Device
COMP 3004 Final project 2024 Winter


## Members of Group 21:
- Karthiga Balasubramaniam
- Isaac Arneill - 101222972
- Yanwei Su - 101209998
- Tina Cao - 101158711

## Breakdown of work
Karthiga:
- Use cases: 1.1, 1.2, 1.3
- Sequence diagrams: Session history, Time setting, Connection lost
  
Tina:
- Use cases: 1.4, 2, 3
- Sequence diagrams: Mew session, Low battery and No battery
- Traceability Matrix
- Readme
- State diagrams: Overall and EEG
- Revise sequence diagrams
  
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
- Timer code
- Time and Date
  
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
- *eegarray*.cpp: stores an array of eeg, manager class of eeg sites
- *headset.cpp*: functionalities of eeg sites
- *logs.cpp*: stores info of session logs
- *main.cpp*: main function
- *mainoperation.cpp*: contains system operations
- *mainwindow.cpp*: design and functions of the UI
- *menu.cpp*: functions for the three buttons(timeanddate, sessionlog, newsession)
  
Documents:
- *EEGStateDiagram.png*: State diagram for EEG sites
- *OverallStateDiagram.png*: State diagram for the overall system
- *NewSessionSequenceDiagram.png*: Sequence diagram for normal scenario (including 1.1,1.2,1.3,1.4 in use cases)
- *OutOfBatterySequenceDiagram.png*: Sequence diagram for out of battery scenario
- *ConnectionLostSequenceDiagram.png*: Sequence diagram for connection lost scenario
- *Use Case.pdf*: Use cases for the system
- *TraceabilityMatrix.pdf*: Traceability matrix for the system
- *Readme.txt*: Explanation of files included in the project, info of group members

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
- Update all necessary diagrams, textual explanation of the code, readme files
- Code update

## Explanation

## Instruction to run the code
Open folder in Qt, open mainwindow.cpp and run
