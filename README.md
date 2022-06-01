# Hotel Booking System (Course work)
**Author: Taylor Leong**

***About This Program*** \
The program provides a hotel booking system for input file with the following format: \
Check In Date, Customer ID, Number of Beds Requested, Duration \
16/1/2015, AK3B623TEJ, 3, 15 \
31/1/2015, MW7OJ8W4GP, 1, 4 \
11/2/2015, L88E850PRO, 2, 7 \
15/8/2016, 7UAF635GR5, 1, 3 \
22/7/2020, JD11M67LAN, 2, 1 \
2/12/2021, ON99HOU7AH, 2, 30 

The booking system is designed for a hotel with limited rooms, with 3 bedroom types: one-bed, two-bed rooms, and three-bed type. I divided the system into mainly 3 objects, room, customer, and hotel. Apart from these three objects, I had also created the Date object. 

The program assigns rooms to customers according to their requested number of beds. If all available rooms has less beds than the customer requested, the system will assign multiple rooms to customers. the system will assign more room than requested if there's no room contains the exact number of beds requested. 



