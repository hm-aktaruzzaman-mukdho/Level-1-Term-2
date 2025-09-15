import java.util.Scanner;

/* This is the driver class for this project. You need to run this class with three command line arguments corresponding to the name, starting date and maxinum number of allowed events of a festival. For exmaple run the below command from the termincal:
java FestivalApp "CSE Fest 2023" "2023-07-15" 10*/
public class FestivalApp {

    public static void main(String[] args) {
        // Task: The program will be run with three command line arguements related to a
        // festival- (i) the festival's name, (ii) its starting date and (iii) the
        // maximum number of events allowed in the festival. Create a FestivalManager
        // object named 'festivalManager' and initialize it with the values passed from
        // the command line as: FestivalManager festivalManager = new
        // FestivalManager(...); Generate error if the required parameters are not
        // passed from the command line.

        // Write your code here

        int choice;
        Scanner scanner = new Scanner(System.in);
        if (args.length < 3) {
            System.out.println("Not enough arguments!!!");
            System.exit(1);
        }
        FestivalManager festivalManager = new FestivalManager(args[0], args[1], Integer.parseInt(args[2]));
        do {
            // the following lines of code show a menu to take user's choice
            System.out.println("Menu:");
            System.out.println("1. Add an event");
            System.out.println("2. Register student in an event");
            System.out.println("3. View festival details");
            System.out.println("4. View specific event");
            System.out.println("5. View Event on Date");
            System.out.println("6. View event with maximum participants");
            System.out.println("7. View events for students");
            System.out.println("8. Cancel registration");
            System.out.println("9. Exit");
            System.out.print("Enter option: ");

            choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            String studentname, studentid ,eventname,eventdate,eventlocation;
            switch (choice) {
                case 1: // Add an event
                    /*
                     * Task: using the scanner object, read the following information for an event:
                     * (i) name as a string, (ii) starting date as a string in 'YYYY-MM-DD' format,
                     * (iii) location as astring, and (iv) max number of participants allowed in the
                     * event as an integer. Invoke the function 'add event' of 'Festival Manager' to
                     * add the event, i.e., call festivalManager.addEvent(...)
                     */
                    System.out.print("Enter event name: ");
                    eventname = scanner.nextLine();
                    System.out.print("Enter event date (YYYY-MM-DD): ");
                    eventdate = scanner.nextLine();
                    System.out.print("Enter event location: ");
                    eventlocation = scanner.nextLine();
                    System.out.print("Enter maximum participants: ");
                    int maxparticipants = scanner.nextInt();
                    Event event = new Event(eventname, eventdate, eventlocation, maxparticipants);
                    festivalManager.addEvent(event);
                    // Write your code here

                    break;

                case 2:// Register a student in an event
                    /*
                     * Task: read the name and id of a student and an event name. Then register the
                     * student in the event by calling the function:
                     * festivalManager.registerStudent(...)
                     */
                    System.out.print("Enter student name: ");
                    studentname = scanner.nextLine();
                    System.out.print("Enter student ID: ");
                    studentid = scanner.nextLine();
                    Student student = new Student(studentname, studentid);
                    System.out.print("Enter event name: ");
                    eventname = scanner.nextLine();
                    festivalManager.registerStudent(eventname, student);
                    // Write your code here

                    break;

                case 3: // View festival details

                    festivalManager.showDetails();

                    break;

                case 4: // View event details
                    /*
                     * Task: read the name of an event and then show the details for the event by
                     * calling the function: festivalManager.showEvent(...);
                     */
                    System.out.print("Enter event name: ");
                    eventname = scanner.nextLine();
                    festivalManager.showEvent(eventname);
                    // Write your code here

                    break;
                case 5:
                    System.out.print("Enter event date: ");
                    eventdate=scanner.nextLine();
                    festivalManager.showEventsOnDate(eventdate);

                    break;
                case 6: // View event with maximum participants
                    festivalManager.eventWithHighestParticipants();
                    break;

                case 7: // View events for students
                    /*
                     * Task: read the id of a student and then show the events the student is
                     * participating in by calling the function:
                     * festivalManager.showEventsForStudent(...);
                     */
                    System.out.print("Enter student ID: ");
                    studentid = scanner.nextLine();
                    festivalManager.showEventsForStudent(studentid);
                    // Write your code here

                    break;

                case 8: // Cancel registration
                    /*
                     * Task: read the id of a student and an event name. Then remove the student
                     * from the participant list of the event by calling the function:
                     * festivalManager.cancelRegistration(...);
                     */
                    System.out.print("Enter student ID: ");
                    studentid = scanner.nextLine();
                    System.out.print("Enter event name: ");
                    eventname = scanner.nextLine();
                    festivalManager.cancelRegistration(eventname, studentid);
                    // Write your code here

                    break;

                case 9:
                    System.out.print("Exiting the program.");
                    break;

                default:
                    System.out.print("Invalid option. Please try again.");
            }
            System.out.println();
        } while (choice != 9);

        scanner.close();
    }
}
