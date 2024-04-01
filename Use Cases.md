## NORMAL CASE























## DEVICE CONNECTION LOST
*Use Case*: 
Device lost connection

*Primary Actor*: 
Device

*Precondition*: 
Session started, but the contact is not initiated due to loss of connection.

*Success guarantee*: 
The connection is reestablished, device back in session.

*Main Success Scenario*:
- 1. User starts the new session, and the timer opens.
- 2. Connection to the EEG sites fails, session pauses with red light flashes, and alert beeps.
- 3. Device tries to reconnect.
- 4. Fail to reconnect in 5 mins.
- 5. Device shuts down, session log deleted.
     
*Extension*:
2a: Connection fails but session is not paused.
- Device system control is not functioning.
- Signal not sent to session successfully.
  
3a: Device reconnected, but the signal/alert is still on.
- Control system is not functioning.
- Reconnection not detected.
 
 
## DEVICE AT LOW BATTERY (10%)
*Use Case*: 
Device at low battery
*Primary Actor*:
Device: Delivers treatments to user
User: Receives treatments from the EGG sites
*Precondition*:
Device at low battery
*Success guarantee*:
Device displays an alert to the user, but the device can still function.
*Main Success Scenario*:
1.       Device system detects the battery is below a range.
2.       Device system manages to alert the user.
3.       User charges the device.
4.       Control system detects the battery is within the range.
5.       Display message removed.
*Extension*:
   	3a. Device not being charged.
1.       Charging port on the device is not working.
2.       Device fails to detect the charging signal.
3.       Device detects charging signal, fails to change the state.
   	34a. Device battery within range but display message is not removed.
1.       Device system not working properly.

##DEVICE RAN OUT OF BATTERY (0%)
*Use Case*:
Device battery drained (0%)
*Primary Actor*:
Device
*Precondition*:
Device battery is at 0%
*Success guarantee*:
Device displays a message to the user, the device cannot be used.
*Main Success Scenario*:
1.       Device system detects the battery is completely out.
2.       Device system manages to alert the user, and all the functions cannot be used.
3.       User recharges the device.
4.       Device system detects a low battery.
5.       Functions can be used, while a low battery message displays.
*Extension*:
3a. Device not being charged.
1.       Charging port on the device is not working.
2.       Device fails to detect the charging signal.
3.       Device detects charging signal, fails to change the state.
34a. Device battery is not completely out but the display message is not changed.
1.       Device system not working properly.
5a. Device battery within range but display message is not removed.
1.       Device system not working properly.

