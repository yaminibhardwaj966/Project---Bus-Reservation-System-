void cancel_ticket()
{
    int BusNumber;
    int cancelledSeats;
    
    printf("Enter Bus Number from which you want to cancel ticket: ");
    scanf(" %d", &BusNumber);
    printf("Please enter the no. of seats you want to cancel: ");
    scanf(" %d", &cancelledSeats);

    printf("\nTickets Cancellation Successful! %d Tickets cancelled on Bus Number %d.\n", cancelledSeats, BusNumber);
}
