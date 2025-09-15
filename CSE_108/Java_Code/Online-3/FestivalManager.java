/* This class stores information of a festival which are name, starting date and list of events that will take place during the festival. */
public class FestivalManager {
    private String name;
    private String startDate;
    private Event[] events;
    private int maxEventCount;
    int eventsAdded = 0;

    // Task: Write code for the constructor below to initialize the member variables
    // properly
    public FestivalManager(String name, String startDate, int maxEventCount) {
        // write your code here
        this.name = name;
        this.startDate = startDate;
        this.maxEventCount = maxEventCount;
        events = new Event[maxEventCount];
    }

    // Task: Write code for the function below. This function adds an event to this
    // festival.
    // Check for the following case: (i) total event count does not exceed the
    // maximum number of events allowed for this festival
    public void addEvent(Event e) {
        // write your code here
        if (eventsAdded < maxEventCount) {
            events[eventsAdded] = e;
            eventsAdded++;
            System.out.println("\nEvent added successfully!\n");
        } else {
            System.out.println("\nMaximum numbers of events already added.\n");
        }

    }

    // Task: Write code for the function below. This function registers a student
    // for an event
    // in this festival. Check for the following case: (i) event does not exist
    public void registerStudent(String eventName, Student s) {
        // Write your code here
        boolean flag = false;
        int i;
        for (i = 0; i < eventsAdded; i++) {
            if (eventName.equals(events[i].geteventName())) {
                flag = true;
                break;
            }
        }
        if (flag) {
            if (events[i].isRegistered(s.getid())) {
                System.out.println(s.getid() + " already registered in event " + eventName);
            } else {
                events[i].addParticipant(s);
                System.out.println("\nStudent registration completed.\n");
            }
        } else {
            System.out.println("\nEvent does not exist.\n");
        }
    }

    // Task: Write code for the function below. The function shows the details of
    // this festival.
    // Make sure the output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here
        System.out.println("Festival Name:" + this.name);
        System.out.println("Festival Starting Date:" + this.startDate);
        System.out.println("Festival Events:\n");
        for (int i = 0; i < eventsAdded; i++) {
            events[i].showDetails();
            System.out.println();
        }
        System.out.println();
    }

    // Task: Write code for the function below. This function shows details of the
    // event
    // in the argument. Check for the following case: (i) event does not exist
    public void showEvent(String eventName) {
        // Write your code here
        boolean flag = false;
        int i = 0;
        for (; i < eventsAdded; i++) {
            if (events[i].geteventName().equals(eventName)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            events[i].showDetails();
        } else {
            System.out.println("Event does not exist.\n");
        }
    }

    // Task: Write code for the function below. This function shows details of the
    // events
    // that will start on the date passed as its argument. Check for the following
    // case:
    // (i) event does not exist
    public void showEventsOnDate(String eventDate) {
        // Write your code here
        int count = 0;
        System.out.println("Events on date "+eventDate+" :");
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].geteventDate().equals(eventDate)) {
                System.out.println(events[i].geteventName());
                System.out.println();
                count++;
            }
        }
        if (count == 0) {
            System.out.println("No event on current date.\n");
        }

    }

    // Task: Write code for the function below. This function shows the details of
    // the
    // events with maximum number of participants. If there are multiple events,
    // show all.
    public void eventWithHighestParticipants() {
        // Write your code here
        int maximumParticipants = 0;
        for (int i = 0; i < eventsAdded; i++) {
            if (maximumParticipants < events[i].getparticipants()) {
                maximumParticipants = events[i].getparticipants();
            }
        }
        System.out.println("Events with maximum participants :");
        for (int i = 0; i < eventsAdded; i++) {
            if (maximumParticipants == events[i].getparticipants()) {
                events[i].showDetails();
                System.out.println();
            }
        }

    }

    // Task: Write code for the function below. This function takes a student Id as
    // input and then lists all the events this particular student has registered
    // for.
    // Make sure your output matches the supplied sample output.
    public void showEventsForStudent(String studentId) {
        // Write your code here
        System.out.println("Student " + studentId + " is regestered in :\n");
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].isRegistered(studentId)) {
                System.out.println(events[i].geteventName());
            }
        }
    }

    // Task: Write code for the function below. This functions takes an event's
    // name and a student's ID as arguments and then removes the student from the
    // registered student list of the event. Check for the following cases:
    // (i) event does not exist, (ii) student is not registered for the event
    public void cancelRegistration(String eventName, String studentId) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].geteventName().equals(eventName)) {
                if (events[i].isRegistered(studentId)) {
                    events[i].removeParticipant(studentId);
                }
                break;
            }
        }

    }


    public void eventbetweendates(String date1,String date2)
    {
        int count=0;
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].geteventDate().compareTo(date1)>=0&&events[i].geteventDate().compareTo(date2)<=0)
            {
                System.out.println(events[i].geteventName()+"   "+events[i].geteventDate());
                count++;
            }
        }
        System.out.println("The total number of events between"+date1+" and "+date2+" is "+count);
    }

    public void chronologicalorder()
    {
        String smalldate=events[0].geteventDate(),bigdate=events[0].geteventDate();
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].geteventDate().compareTo(smalldate)>0)
            {
                smalldate=events[i].geteventDate();
            }
            if(events[i].geteventDate().compareTo(bigdate)<0)
            {
                bigdate=events[i].geteventDate();
            }
        }
        //System.out.println(smalldate+" "+bigdate);
        int diff=0;
        while(true)
        {
            for(int i=0;i<eventsAdded;i++)
            {
                if(events[i].geteventDate().compareTo(bigdate)==diff)
                {
                    System.out.println(events[i].geteventName()+"   "+events[i].geteventDate());
                }
            }
            diff++;
            if(diff>smalldate.compareTo(bigdate))
            {
                break;
            }
        }
    }
}
