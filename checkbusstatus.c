void show_bus_details()
{
    int BusNumber;
    int bookedSeats;
    int cancelledSeats;
    
    if (BusNumber == 101)
    {
        printf("Bus Number: 101\nSource: Aligarh\nDestination: Mathura\nTotal Seats: 60\nAvailable Seats: %d\nTotal Fare: %d\n", 60 - bookedSeats + cancelledSeats, bookedSeats * 300);
    }
    else if (BusNumber == 102)
    {
        printf("Bus Number: 102\nSource: Delhi\nDestination: Agra\nTotal Seats: 50\nAvailable Seats: %d\nTotal Fare: %d\n", 50 - bookedSeats + cancelledSeats, bookedSeats * 500);
    }
    else if (BusNumber == 103)
    {
        printf("Bus Number: 103\nSource: Gurgaon\nDestination: Lucknow\nTotal Seats: 70\nAvailable Seats: %d\nTotal Fare: %d\n", 70 - bookedSeats + cancelledSeats, bookedSeats * 900);
    }
    else if (BusNumber == 104)
    {
        printf("Bus Number: 104\nSource: Bangalore\nDestination: Hyderabad\nTotal Seats: 80\nAvailable Seats: %d\nTotal Fare: %d\n", 80 - bookedSeats + cancelledSeats, bookedSeats * 1000);
    }
    else
    {
        printf("Please enter correct bus number!\n");
    }
}